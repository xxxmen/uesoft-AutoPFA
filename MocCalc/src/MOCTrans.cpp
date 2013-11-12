// MOCTrans.cpp: implementation of the MOCTrans class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrans.h"
#include "CalcTrans.h"
#include "TransOutModel.h"
#include "MOCComponentMgr.h"
#include "MOCFluid.h"
#include "dlgSolveControl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrans::MOCTrans()
{
	m_StartTime = 0;			
	m_StopTime = 0;				
	m_Frequency = 0;				
	m_Cavitation = 0;				
	m_VariableR = 0;				
	m_Artificial = 0;				
	m_Criteria = 0;				
	m_MinFlow = 0;				
	m_TotalSteps = 0;
	m_TimeStep = 0;
}

MOCTrans::~MOCTrans()
{

}

BOOL MOCTrans::Read(CalcTrans &data)
{
	m_StartTime = data.StartTime();			
	m_StopTime = data.StopTime();				
	m_Frequency = data.Frequency();				
	m_Cavitation = data.Cavitation();				
	m_VariableR = data.VariableR();				
	m_Artificial = data.Artificial();				
	m_Criteria = data.Criteria();				
	m_MinFlow = data.MinFlow();				
//	m_TotalSteps = data.TotalSteps();
	m_TimeStep = data.TimeStep();
	m_TotalSteps =int((m_StopTime+m_TimeStep/2)/m_TimeStep);//如果开始时间不为0
	return TRUE;
}

void MOCTrans::CalcImpulse(MOCComponentMgr &mgr,TransOutModel &model)
{
	MOCFluid::VaporModel(m_Cavitation);
	MOCFluid::SetpTime(m_TimeStep);
	MOCFluid::VariableR(m_VariableR);
	BOOL bInitTranSetOk = InitTrans(mgr);
	if(bInitTranSetOk)
	{
		dlgSolveControl *dlg = new dlgSolveControl;
		dlg->Create(dlgSolveControl::IDD);
		dlg->SetTotal(int(m_TotalSteps));
		dlg->SetNowStep(1);
		dlg->ShowWindow(SW_SHOW);
		int i = 0;
		for(i=1;i<m_TotalSteps+1;i++)
		{
			dlg->SetNowStep(i);
			ASSERT(m_Frequency != 0);
			if(((i-1)%m_Frequency)==0)
				mgr.Result(model.ComponentOutMgr(),i-1);
			double dCurTime = m_StartTime + i*m_TimeStep;
			mgr.CalcImpulse(*this,dCurTime);
			if (true == dlg->GetStop())
				break;
		}
		if(((i-1)%m_Frequency)==0)
			mgr.Result(model.ComponentOutMgr(),i-1);
		model.ComponentOutMgr().TimeStep(m_TimeStep);
		model.ComponentOutMgr().PipeOutMgr().InitMaxMin();
		if (NULL != dlg)
			delete dlg;
	}
}

BOOL MOCTrans::InitTrans(MOCComponentMgr &mgr)
{
	return mgr.InitTransModel();
}

/*------------------------------------------------*/
int MOCTrans::Frequency()
{
	return m_Frequency;
}
/*------------------------------------------------*/
BOOL MOCTrans::Cavitation()
{
	if(1==m_Cavitation)
		return TRUE;
	return FALSE;
}
/*------------------------------------------------*/
BOOL MOCTrans::VariableR()
{
	if(1==m_VariableR)
		return TRUE;
	return FALSE;
}
/*------------------------------------------------*/
BOOL MOCTrans::Artificial()
{
	if(1==m_Artificial)
		return TRUE;
	return FALSE;
}
/*------------------------------------------------*/
double MOCTrans::Criteria()
{
	return m_Criteria;
}
/*------------------------------------------------*/
double MOCTrans::MinFlow()
{
	return m_MinFlow;
}
/*------------------------------------------------*/
double MOCTrans::StartTime()
{
	return m_StartTime;
}
/*------------------------------------------------*/


