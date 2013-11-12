// MOCPump.cpp: implementation of the MOCPump class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPump.h"
#include "MOCFluid.h"
#include "CalcPump.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPump::MOCPump()
:m_mgr(m_EndList,m_Model,m_Inertia,m_FourQuadrantData,m_config,m_tranData)
{			
	m_nPumpSet = 1;			
	m_nTranModel = 0;		
	m_nPumpType = 0;	
	m_dPumpFlow = 0;	
	m_dSpeedRatio = 0;		
	m_dControlValue = 0;		
}

MOCPump::~MOCPump()
{

}

MOCJun* MOCPump::Creator()
{
	MOCPump *pData = new MOCPump;
	return pData;
}

BOOL MOCPump::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcPump *pPumpData = dynamic_cast<CalcPump*>(pData);
	ASSERT(pPumpData != NULL);
	m_tranData.Read(pPumpData->m_TranData);
	m_Model.Read(pPumpData);
	m_nPumpSet = pPumpData->PumpSet();			
	m_nTranModel = pPumpData->TranModel();		
	m_nPumpType = pPumpData->PumpType();	
	m_dPumpFlow = pPumpData->PumpFlow();
	if(1==m_nPumpType ||2==m_nPumpType)
	{
		m_tranData.TranRel(RelToAbs,m_dPumpFlow);
		if(1==m_nPumpType )
		{
			m_dPumpFlow = MOCFluid::TranQToMass(m_dPumpFlow);
			m_tranData.Tran(MOCFluid::TranQToMass);
		}	
	}
	m_dSpeedRatio = pPumpData->SpeedRatio();
	m_dControlValue = pPumpData->ControlValue();	
	m_Control.ControlType(pPumpData->PumpControl());		
	m_Control.PressType(pPumpData->PressType());		
	m_Control.ControlApply(pPumpData->ControlApply());        
	m_Inertia.RotateInertia(pPumpData->RotateInertia());		
	m_Inertia.Speed(pPumpData->Speed());			
	m_FourQuadrantData.AngleType(pPumpData->FourQuadrantAngle());
	m_FourQuadrantData.FH(pPumpData->FHData());
	m_FourQuadrantData.FB(pPumpData->FBData());
	m_config.Read(pPumpData->m_Config);
	TranControlValue(pPumpData->PumpControl());
	return TRUE;
}

void MOCPump::TranControlValue(int nControl)
{
	switch(nControl) {
	case 1:
	case 3:
		m_tranData.TranRel(RelToAbs,m_dControlValue);
		m_dControlValue = MOCFluid::TranHToPress(m_dControlValue);
		m_tranData.Tran(MOCFluid::TranHToPress);
		break;
	case 5:
		m_tranData.TranRel(RelToAbs,m_dControlValue);
		m_dControlValue = MOCFluid::TranQToMass(m_dControlValue);
		m_tranData.Tran(MOCFluid::TranQToMass);
		break;
	default:
		break;
	}
}

BOOL MOCPump::InitEndInfo()
{
	return InitInOutEle();
}

void MOCPump::UpdataEnd()
{
	UpdataTwoEnd();
	if(m_Model.IsSubmerge())
	{
		double dMass = fabs(m_EndList.GetInMass()-m_EndList.GetOutMass());
		double dPress = m_Model.SuctionPress();
	    double dStaticPress = dPress-MOCFluid::CalcPressLoss(dMass,m_EndList.GetOneEndArea());
		UpdataPress(dPress,dStaticPress,m_dInEle,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
	}
	m_Model.RisePress(m_dOutStagPress-m_dInStagPress,m_nPumpSet);
	m_Model.MassFlow(m_EndList.GetOutMass(),m_nPumpSet);
}

BOOL MOCPump::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	m_nSpecialMark = 0;
	m_mgr.SetStmSpeed(m_nTranModel,m_dSpeedRatio);
	return TRUE;
}

void MOCPump::CalcStm()
{
	if(JunStatus() ==2)
	{//泵关闭允许流量通过
		if(m_Model.IsSubmerge())
		{
			m_EndList.StagPressStrategy(m_Model.SuctionPress());
		}
		else
		{
			m_EndList.BranchStrategy(0);
		}
		return;
	}
	if(m_nPumpType==0)
	{
		if(!m_Control.IsControlPump())
		{//泵曲线
			m_Model.CalcStm(m_EndList,m_config,m_dSpeedRatio,m_nPumpSet);
		}
		else
		{//控制泵
			m_Control.CalcStm(m_EndList,m_dControlValue,m_nPumpSet);
		}
		
	}
	else
	{
		m_Control.FlowControl(m_EndList,m_dPumpFlow,m_nPumpSet);
	}
}

void MOCPump::CalcImpulse(MOCTrans &trans, double dTime)
{//测试使用
	if(0==m_nTranModel)
	{
		CalcStm();
	}
	else
	{
		if(m_nPumpType==0)
		{
			if(!m_Control.IsControlPump())
			{//泵曲线
				m_mgr.CalcImpulse(trans,dTime,m_nTranModel,m_dSpeedRatio,m_nPumpSet);
			}
			else
			{//控制泵
				double dControlValue = m_tranData.GeTransY(dTime,m_dControlValue,trans.StartTime());
				m_Control.CalcStm(m_EndList,dControlValue,m_nPumpSet);
			}
			
		}
		else
		{
			double dPumpFlow = m_tranData.GeTransY(dTime,m_dPumpFlow,trans.StartTime());
			m_Control.FlowControl(m_EndList,dPumpFlow,m_nPumpSet);
		}
	}
}

double MOCPump::GetSpeed()
{
	if(!m_Control.IsControlPump())
	{
		return m_mgr.GetCurSpeedRatio()*100;
	}
	else
	{
		return 100;
	}
}

void MOCPump::Result(JunTranOut &out, int nStep)
{
	JunOut *pOut = out.Creator(nStep);
	pOut->SetTime(nStep*MOCFluid::SetpTime());
	pOut->SetSpeed(GetSpeed());
}
