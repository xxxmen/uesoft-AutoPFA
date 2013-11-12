// MOCControl.cpp: implementation of the MOCControl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCControl.h"
#include "CalcControl.h"
#include "MOCFluid.h"
#include "PressDropStrategy.h"
#include "LocalRStrategy.h"
#include "FlowJunStrategy.h"
#include "PressJunStrategy.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCControl::MOCControl()
{
	m_nType = 0;							
	m_nAlwayControl = 0;					
	m_nUpInsuffic = 0;							
	m_nDownExcess = 0;						
	m_nPressType = 0;						
	m_dControlValue = 0;					
	m_nLossType = 0;					
	m_dKOrCv = 0;	
	m_nBasisAreaType = 0;
	m_dBasisArea = 0;
	m_nValveStatus = 0;
}

MOCControl::~MOCControl()
{

}

MOCJun* MOCControl::Creator()
{
	MOCControl *pData = new MOCControl;
	return pData;
}

BOOL MOCControl::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcControl *pControlValveData = dynamic_cast<CalcControl*>(pData);
	ASSERT(pControlValveData != NULL);
	
	m_nType = pControlValveData->Type();							
	m_nAlwayControl = pControlValveData->AlwayControl();					
	m_nUpInsuffic = pControlValveData->UpInsuffic();							
	m_nDownExcess = pControlValveData->DownExcess();						
	m_nPressType = pControlValveData->PressType();						
	m_dControlValue = pControlValveData->ControlValue();
	m_tranData.Read(pControlValveData->m_TranData);
	m_fialTranData.Read(pControlValveData->m_FailTranData);
	m_tranData.TranRel(RelToAbs,m_dControlValue);
	if(0==pControlValveData->ControlType())
	{
		if(2 == m_nType)
		{//流量控制阀
			m_dControlValue = MOCFluid::TranQToMass(m_dControlValue);
			m_tranData.Tran(MOCFluid::TranQToMass);
		}
		else if ( 3 == m_nType )
		{
			m_dControlValue = MOCFluid::TranHToPress(m_dControlValue);
			m_tranData.Tran(MOCFluid::TranHToPress);
		}
		else
		{
			m_dControlValue = MOCFluid::TranHGLToPress(m_dControlValue - m_dInEle );
			m_tranData.Tran(MOCFluid::TranHToPress);
		}
	}
	m_nLossType = pControlValveData->LossType();					
	m_dKOrCv = pControlValveData->KOrCv();	
	m_nBasisAreaType = pControlValveData->BasisAreaType();
	m_dBasisArea = pControlValveData->BasisArea();
	return TRUE;
}

double MOCControl::GetCvFromCvTable()
{//从Cv表中找到打开白分比为100%的Cv和面积如果面积不等于0使用表中面积，否则使用上游面积计算K
	double dCv = 0;
	double dArea = 0;
	StrArray<3> CvData;
	IteratorPtr<StrArray<3> > ItPtr(m_CvTable.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		CvData = ItPtr->CurrentItem();
		if(100 == CvData.nData(0))
		{
			dCv = CvData.fData(1);
			dArea = CvData.fData(2);
			break;
		}
	}
	if(-0.000001<dArea&&dArea<0.000001)
		dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	return dCv;
}

BOOL MOCControl::InitEndInfo()
{
	if(m_nLossType == -2)
		m_dKOrCv = GetCvFromCvTable();
	m_fialTranData.TranRel(RelToAbs,m_dKOrCv);
	return InitInOutEle();
}

void MOCControl::CalcStm()
{
	if(2==JunStatus())
	{//总是打开
		FullOpenValve(m_dKOrCv);
		return;
	}
	if(1 == m_nAlwayControl)
	{//稳定状态总是控制
		FixStatus(m_dControlValue);
	}
	else
	{
		SwitchStatus(m_dKOrCv,m_dControlValue);
	}
}

void MOCControl::CalcPRV(double dControlValue)
{
	EndInfo *pInEnd = GetInEnd();
	EndInfo *pOutEnd = GetOutEnd();
	PressControl(pOutEnd,pInEnd,dControlValue);
}

void MOCControl::CalcPSV(double dControlValue)
{
	EndInfo *pInEnd = GetInEnd();
	EndInfo *pOutEnd = GetOutEnd();
	PressControl(pInEnd,pOutEnd,dControlValue);
}

void MOCControl::CalcFCV(double dControlValue)
{
	m_EndList.FlowStrategy(dControlValue);
}

void MOCControl::CalcPDCV(double dControlValue)
{
	m_EndList.FixDropStrategy(dControlValue);
}

void MOCControl::PressControl(EndInfo *pControlEnd,EndInfo *pEnd,double dControlValue)
{
	ASSERT(pControlEnd != NULL && pEnd != NULL);
	if(0==m_nPressType)
	{
		m_EndList.StagPressStrategy(*pControlEnd,dControlValue);
	}
	else
	{
		m_EndList.StaticPressStrategy(*pControlEnd,dControlValue);
	}
	FlowControl(pEnd,pControlEnd->GetMass());
}

void MOCControl::CloseValve()
{
	m_EndList.DeadStrategy();
	m_nValveStatus = 1;
}


void MOCControl::FullOpenValve(double dKOrCv)
{
	double dArea = BasisArea(m_nBasisAreaType,m_dBasisArea);
	if(m_nLossType==1)
	{
		m_EndList.KStrategy(dKOrCv,dArea);
	}
	else
	{
		m_EndList.CvStrategy(dKOrCv,dArea);
	}
	m_nValveStatus = 0;
}

void MOCControl::SwitchStatus(double dKOrCv,double dControlValue)
{
	EndInfo *pInEnd = GetInEnd();
	EndInfo *pOutEnd = GetOutEnd();
	ASSERT(pInEnd != NULL);
	ASSERT(pOutEnd != NULL);
	if(m_nType==0 || m_nType==1)
	{
		double dInPress = pInEnd->GetPress() ;
		double dOutPress = pOutEnd->GetPress() ;
		if ( 1 == m_nPressType )
		{
			//Modify by Liuck [4/20/2009]当选择的类型为静压的时候，必须把上下游压力均减去动压
			double dTemp = 0.5*pow(pInEnd->GetMass(),2)/MOCFluid::Density()/pow( pInEnd->Area(),2);
			dInPress -= dTemp ;
			dOutPress -= dTemp ;
		}
		//上游压力低于控制压力
		if(dInPress - m_dControlValue < 1.0e-6 )
		{
			Action(m_nUpInsuffic,dKOrCv);
		}
		//下游压力超过控制压力
		else if(dOutPress - m_dControlValue > 1.0e-6 )
		{
			Action(m_nDownExcess,dKOrCv);
		}
		else
		{
			FixStatus(m_dControlValue);
		}
	}
	if(m_nType==2)
	{//上游压力低于下游压力
		if(pInEnd->GetPress()<pOutEnd->GetPress())
		{
			Action(m_nUpInsuffic,dKOrCv);
		}
		else
		{
			FixStatus(m_dControlValue);
		}
	}
	if(m_nType ==3)
	{
		FixStatus(m_dControlValue);
	}
}

void MOCControl::Action(int nType,double dKOrCv)
{
	if(0 == nType)
	{
		FullOpenValve(dKOrCv);
	}
	else
	{
		CloseValve();
	}
}

void MOCControl::FixStatus(double dControlValue)
{
	switch(m_nType) {
	case 0:
		CalcPRV(dControlValue);
		break;
	case 1:
		CalcPSV(dControlValue);
		break;
	case 2:
		CalcFCV(dControlValue);
		break;
	case 3:
		CalcPDCV(dControlValue);
		break;
	default:
		ASSERT(FALSE);
		break;
	}
}

void MOCControl::UpdataEnd()
{
	UpdataTwoEnd();
}

void MOCControl::FlowControl(EndInfo *pControlEnd,double dFlow)
{
	m_EndList.FlowStrategy(*pControlEnd,dFlow);
}

BOOL MOCControl::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	m_fialTranData.InitFixTrans(mgr,Key(),10);
	return TRUE;
}

void MOCControl::CalcImpulse(MOCTrans &trans, double dTime)
{
	if(2==JunStatus())
	{//总是打开
		FullOpenValve(m_dKOrCv);
		return;
	}
	double dKorCv = m_fialTranData.GeTransY(dTime,m_dKOrCv,trans.StartTime());
	double dControlValue = m_tranData.GeTransY(dTime,m_dKOrCv,trans.StartTime());
	SwitchStatus(dKorCv,dControlValue);
}
int MOCControl::ValveStatus()
{
	return m_nValveStatus;
}

void MOCControl::CalculateK()
{
	try
	{
		double dP = m_dInStaticPress - m_dOutStaticPress;
		double density = MOCFluid::Density();
		double dVelocity = GetInEnd()->GetVelocity();
		
		m_dLossK = 2*dP/( density*pow( dVelocity, 2 ) );
	}
	catch( ... )
	{
#ifdef NDEBUG	
		
#else
		AfxMessageBox( _T( "计算Valve的K值时出错!" ) );	
#endif
		
	}
	
}