// TransientSet.cpp: implementation of the TransientSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "TransientSet.h"
#include "TransControlPerisistent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


NameArray TransientSet::s_StateName;
NumFlyWeight TransientSet::ms_StartTime;
NumFlyWeight TransientSet::ms_StopTime;
StrFlyWeight TransientSet::ms_Frequency;
StrFlyWeight TransientSet::ms_ModelCavitation;
StrFlyWeight TransientSet::ms_VariableR;
StrFlyWeight TransientSet::ms_StopOnArtificialTrans;
StrFlyWeight TransientSet::ms_Criteria;
NumFlyWeight TransientSet::ms_CriteriaMinFlow;
StrFlyWeight TransientSet::ms_TotalSteps;

void TransientSet::Instance()
{
	ScenarioObject::InitAttr(s_StateName,1,2);
	ScenarioObject::InitAttr(s_StateName,2,2);
	ScenarioObject::InitAttr(s_StateName,3,1);
	ScenarioObject::InitAttr(s_StateName,4,1);
	ScenarioObject::InitAttr(s_StateName,5,1);
	ScenarioObject::InitAttr(s_StateName,6,1);
	ScenarioObject::InitAttr(s_StateName,7,1);
	ScenarioObject::InitAttr(s_StateName,8,2);
	ScenarioObject::InitAttr(s_StateName,9,1);
}

TransientSet::TransientSet()
{

}

TransientSet::~TransientSet()
{

}

ScenarioObject* TransientSet::CreatTransientSet()
{
	TransientSet *pTransientSet = new TransientSet;
	pTransientSet->Init();
	ms_StartTime.SetValue(_T("0"));
	ms_StartTime.SetUnit(_T("seconds"));			
	ms_StopTime.SetValue(_T("1"));
	ms_StopTime.SetUnit(_T("seconds"));
	ms_Frequency.SetValue(_T("1"));
	ms_ModelCavitation.SetValue(_T("1"));
	ms_VariableR.SetValue(_T("0"));
	ms_StopOnArtificialTrans.SetValue(_T("-1"));
	ms_Criteria.SetValue(_T("0.5"));
	ms_CriteriaMinFlow.SetValue(_T("0"));
	ms_CriteriaMinFlow.SetUnit(_T("kg/sec"));
	ms_TotalSteps.SetValue(_T("0"));
	pTransientSet->SaveData();
	return pTransientSet;
}

ScenarioObject* TransientSet::DoClone()
{
	return new TransientSet(*this);
}

void TransientSet::InitData()
{
	GetValue(ms_StartTime,1);
	GetValue(ms_StopTime,2);
	GetValue(ms_Frequency,3);
	GetValue(ms_ModelCavitation,4);
	GetValue(ms_VariableR,5);
	GetValue(ms_StopOnArtificialTrans,6);
	GetValue(ms_Criteria,7);
	GetValue(ms_CriteriaMinFlow,8);
	GetValue(ms_TotalSteps,9);
}

void TransientSet::SaveData()
{
	SetValue(ms_StartTime,1);
	SetValue(ms_StopTime,2);
	SetValue(ms_Frequency,3);
	SetValue(ms_ModelCavitation,4);
	SetValue(ms_VariableR,5);
	SetValue(ms_StopOnArtificialTrans,6);
	SetValue(ms_Criteria,7);
	SetValue(ms_CriteriaMinFlow,8);
	SetValue(ms_TotalSteps,9);
}

BOOL TransientSet::Read(TransControlPerisistent &persistent)
{
	ms_StartTime.SetValue(persistent.StartTime());
	ms_StartTime.SetUnit(persistent.TimeUnit());			
	ms_StopTime.SetValue(persistent.StopTime());	
	ms_StopTime.SetUnit(persistent.TimeUnit());	
	ms_Frequency.SetValue(persistent.Frequency());	
	ms_ModelCavitation.SetValue(persistent.Cavitation());	
	ms_VariableR.SetValue(persistent.VariableR());
	ms_StopOnArtificialTrans.SetValue(persistent.Artificial());	
	ms_Criteria.SetValue(persistent.Criteria());	
	ms_CriteriaMinFlow.SetValue(persistent.MinFlow());	
	ms_CriteriaMinFlow.SetUnit(persistent.MinFlowUnit());
	ms_TotalSteps.SetValue(persistent.TotalSteps());
	SaveData();
	return TRUE;
}

BOOL TransientSet::Save(TransControlPerisistent &persistent)
{
	InitData();
	persistent.StartTime(ms_StartTime.GetValue());
	persistent.TimeUnit(ms_StartTime.GetUnit());			
	persistent.StopTime(ms_StopTime.GetValue());	
	persistent.Frequency(ms_Frequency.GetValue());	
	persistent.Cavitation(ms_ModelCavitation.GetValue());	
	persistent.VariableR(ms_VariableR.GetValue());
	persistent.Artificial(ms_StopOnArtificialTrans.GetValue());	
	persistent.Criteria(ms_Criteria.GetValue());	
	persistent.MinFlow(ms_CriteriaMinFlow.GetValue());	
	persistent.MinFlowUnit(ms_CriteriaMinFlow.GetUnit());
	persistent.TotalSteps(ms_TotalSteps.GetValue());
	return TRUE;
}

BOOL TransientSet::IsDefine()
{
	InitData();
	if(ms_TotalSteps.GetnValue()<=0)
		return FALSE;
	return TRUE;
}
