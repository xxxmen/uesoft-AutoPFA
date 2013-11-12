// MOCCheck.cpp: implementation of the MOCCheck class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCCheck.h"
#include "CalcCheck.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCCheck::MOCCheck()
{
	m_nLossType = 0;						    	                                           
	m_dKOrCv = 0;					        
    m_nBasisAreaType = 0;		
	m_dBasisArea = 0;					
	m_dReOpenPress = 0;				
	m_dCloseVel = 0;
	m_nCheckStatus = 0;
	m_bClose = FALSE;
}

MOCCheck::~MOCCheck()
{

}

MOCJun* MOCCheck::Creator()
{
	MOCCheck *pData = new MOCCheck;
	return pData;
}

BOOL MOCCheck::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcCheck *pCheckValveData = dynamic_cast<CalcCheck*>(pData);
	ASSERT(pCheckValveData != NULL);
	m_nLossType = pCheckValveData->LossType();                    
	m_dKOrCv = pCheckValveData->KOrCv();
	m_nBasisAreaType = pCheckValveData->BasisAreaType();
	m_dBasisArea = pCheckValveData->BasisArea();											    
	m_dReOpenPress = pCheckValveData->ReOpenPress();
	if(0==pCheckValveData->ReOpenPressType())
		m_dReOpenPress = MOCFluid::TranHGLToPress(m_dReOpenPress);
	m_dCloseVel = pCheckValveData->CloseVel();
	m_tranData.Read(pCheckValveData->m_TranData);
	m_tranData.TranRel(RelToAbs,m_dKOrCv);
	return TRUE;
}

BOOL MOCCheck::InitEndInfo()
{
	//Modify by Liuck [3/24/2009] 当选择不同的损失模型时，设定不同的m_dLossK值
	if( 0 == m_nLossType )
	{
		double dArea = BasisArea( m_nBasisAreaType, m_dBasisArea );
		m_dLossK = K( m_dKOrCv, dArea );
	}
	else if ( 1 == m_nLossType )
	{
		m_dLossK = m_dKOrCv ;
	}
	return InitInOutEle();
}

void MOCCheck::CalcStm()
{
	//Modify by Liuck [3/24/2009]K系数必须还乘上摩擦损失因子
	if(m_nLossType == 0)
	{
		ASSERT( m_dDesignFactor > 1.0e-6 ) ;
// 		CalcStmCv( m_dKOrCv * m_dDesignFactor );
		CalcStmCv( m_dKOrCv * sqrt( 1 / m_dDesignFactor ) ) ;
	}
	else
	{
		CalcStmK( m_dKOrCv * m_dDesignFactor );
	}
}

void MOCCheck::CalcStmK(double dK)
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	m_EndList.KStrategy(dK,dArea);
}

void MOCCheck::CalcStmCv(double dCv)
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	m_EndList.CvStrategy(dCv,dArea);
}

void MOCCheck::UpdataEnd()
{
	UpdataTwoEnd();
}

BOOL MOCCheck::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.InitFixTrans(mgr,Key(),8);
	return TRUE;
}

void MOCCheck::CalcImpulse(MOCTrans &trans, double dTime)
{
	TestStatus();
	double dKOrCv = m_tranData.GeTransY(dTime,m_dKOrCv,trans.StartTime());
	dKOrCv = GetK(dKOrCv);//k= -1 表示无穷大
	if(m_nLossType == 0)
	{
		if(m_bClose)
		{
			CalcStmCv(0);
		}
		else
		{
// 			CalcStmCv( dKOrCv * m_dDesignFactor );
			CalcStmCv( dKOrCv * sqrt( 1 / m_dDesignFactor ) ) ;
		}
	}
	else
	{
		if(m_bClose)
		{
			CalcStmK(-1);
		}
		else
		{
			CalcStmK( dKOrCv * m_dDesignFactor );
		}
	}
}

void MOCCheck::TestStatus()
{
	if(0==CheckStatus()&&IsCloseTriger())
	{//打开状态并且关闭状态触发
		m_nCheckStatus = 3;//开始关闭
		return;
	}
	if(1==CheckStatus()&&IsCloseTriger())
	{//关闭状态并且打开状态触发
		m_nCheckStatus = 4;//开始打开
		return;
	}
	if(3==CheckStatus()&&!m_bClose)
	{//开始打开状态
		m_nCheckStatus = 0;//打开
		return;
	}
	if(4==CheckStatus()&&m_bClose)
	{//开始关闭状态
		m_nCheckStatus = 1;//关闭
		return;
	}
}

int MOCCheck::CheckStatus()
{
	return m_nCheckStatus;
}
void MOCCheck::Close(BOOL bClose)
{
	m_bClose = bClose;
}
BOOL MOCCheck::IsCloseTriger()
{
	return (m_EndList.GetInMass()<m_dCloseVel);
}
BOOL MOCCheck::IsReOpenTriger()
{
	return (m_EndList.GetDetalPress()>m_dReOpenPress);
}


