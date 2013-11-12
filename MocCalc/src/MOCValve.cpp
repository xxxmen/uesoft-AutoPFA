// MOCValve.cpp: implementation of the MOCValve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCValve.h"
#include "CalcValve.h"
#include "MOCFluid.h"
#include "LocalRStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCValve::MOCValve()
{
	m_nLossType = 0;                    
	m_dKOrCv = 0;
	m_nBasisAreaType = 0;
	m_dBasisArea = 0;						
	m_nType = 0;						    
	m_dExitPress = 0;
	m_dOutFlow = 0;
}

MOCValve::~MOCValve()
{
	
}

MOCJun* MOCValve::Creator()
{
	MOCValve *pData = new MOCValve;
	return pData;
}

BOOL MOCValve::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcValve *pValveData = dynamic_cast<CalcValve*>(pData);
	ASSERT(pValveData != NULL);
	m_nLossType = pValveData->LossType();                    
	m_dKOrCv = pValveData->KOrCv();
	m_nBasisAreaType = pValveData->BasisAreaType();
	m_dBasisArea = pValveData->BasisArea();						
	m_nType = pValveData->Type();						    
	m_dExitPress = pValveData->ExitPress();
	if(0==pValveData->ExitPressType())
		m_dExitPress = MOCFluid::TranHGLToPress(m_dExitPress);
	m_tranData.Read(pValveData->m_TranData);
	m_tranData.TranRel(RelToAbs,m_dKOrCv);
	return TRUE;
}

BOOL MOCValve::InitEndInfo()
{
	if( 0 == m_nLossType )
	{
		double dArea = BasisArea( m_nBasisAreaType, m_dBasisArea );
		m_dLossK = K( m_dKOrCv, dArea );
	}
	else if ( 1 == m_nLossType )
	{
		//Add by Liuck [3/21/2009]当损失模型为K系数恒定时
		m_dLossK = m_dKOrCv ;
	}

	if ( JunStatus() == 1 )
	{
		m_dLossK = 0 ;
	}
	return InitInOutEle();
}

void MOCValve::CalcStm()
{
	//Modify by Liuck [3/21/2009] K系数必须还乘上摩擦损失因子
	if(m_nLossType == 0)
	{
		ASSERT( m_dDesignFactor > 1.0e-6 ) ;
		CalcStmCv( m_dKOrCv * sqrt( 1 / m_dDesignFactor ) ) ;
	}
	else
	{
		CalcStmK( m_dKOrCv * m_dDesignFactor );
	}
	
}

void MOCValve::CalcStmK(double dK)
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
    //类型(0：普通阀门，1：选中阀门为出口阀门)
	if(0==m_nType)
	{
		m_EndList.KStrategy(dK,dArea);
	}
	else if(1==m_nType)
	{
		m_EndList.KStrategy(m_dExitPress,dK,dArea,m_dOutFlow);
	}
	else
	{
		ASSERT(FALSE);
	}
}

void MOCValve::CalcStmCv(double dCv)
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	 //类型(0：普通阀门，1：选中阀门为出口阀门)
	if(0==m_nType)
	{  
		m_EndList.CvStrategy(dCv,dArea);
	}
	else if(1==m_nType)
	{
		m_EndList.CvStrategy(m_dExitPress,dCv,dArea,m_dOutFlow);
	}
	else
	{
		ASSERT(FALSE);
	}
}
void MOCValve::UpdataEnd()
{
//	UpdataTwoEnd();
	EndInfo *pEnd = m_EndList.GetInEnd(); 
	if(pEnd != NULL)
	{
		MOCJun::UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
	}
	pEnd = m_EndList.GetOutEnd();
	if(pEnd != NULL)
	{
		MOCJun::UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
	}
	if(1==m_nType)
	{
		double dMass = fabs(m_EndList.GetInMass()-m_EndList.GetOutMass());
		m_dBasisArea=BasisArea(m_nBasisAreaType,m_dBasisArea);
	    double dStaticPress = m_dExitPress-MOCFluid::CalcPressLoss(dMass,m_dBasisArea);
		UpdataPress(m_dExitPress,dStaticPress,m_dOutEle,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
//		UpdataPress(dStaticPress,m_dExitPress,m_dOutEle,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
	}
}

BOOL MOCValve::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	if(JunStatus() ==1)
	{
		if(m_nLossType == 0)
		{
			m_dKOrCv = 0;
		}
		else
		{
			m_dKOrCv = -1;
		}
	}
	return TRUE;
}

void MOCValve::CalcImpulse(MOCTrans &trans, double dTime)
{
	double dKOrCv = m_tranData.GeTransY(dTime,m_dKOrCv,trans.StartTime());
	dKOrCv = GetK(dKOrCv);//k= -1 表示无穷大
	//Modify by Liuck [3/23/2009] K系数必须还乘上摩擦损失因子
	if(m_nLossType == 0)
	{
// 		CalcStmCv( dKOrCv * m_dDesignFactor );
		CalcStmCv( dKOrCv * sqrt( 1 / m_dDesignFactor ) ) ;
	}
	else
	{
		CalcStmK( dKOrCv * m_dDesignFactor );
	}
}
