// SteadySet.cpp: implementation of the SteadySet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "SteadySet.h"
#include "SteadyPersistent.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const CmbDataItem  SteadySet::ms_Method[]=
{
	    CmbDataItem(0,"高斯消去法"),
		CmbDataItem(1,"选主元素的高斯消去法"),
		CmbDataItem(2,"矩阵的三角分解")
};

NameArray SteadySet::s_StateName;
StrFlyWeight SteadySet::ms_AnalysisType;
StrFlyWeight SteadySet::ms_PresTolType;				
NumFlyWeight SteadySet::ms_PresAbsTol;	
StrFlyWeight SteadySet::ms_PresRelTol;		
StrFlyWeight SteadySet::ms_FlowTolType;	
NumFlyWeight SteadySet::ms_FlowAbsTol;	
StrFlyWeight SteadySet::ms_FlowRelTol;	
StrFlyWeight SteadySet::ms_FlowRelaxation;	
StrFlyWeight SteadySet::ms_PresRelaxation;	
StrFlyWeight SteadySet::ms_MaxIterations;	
StrFlyWeight SteadySet::ms_KeepHistory;	
StrFlyWeight SteadySet::ms_MatrixMethod;	
StrFlyWeight SteadySet::ms_AutoDetect;

void SteadySet::Instance()
{
	ScenarioObject::InitAttr(s_StateName,1,1);
	ScenarioObject::InitAttr(s_StateName,2,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPRESABSTOL,3,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPRESRELTOL,4,1);
	ScenarioObject::InitAttr(s_StateName,5,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFLOWABSTOL,6,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFLOWRELTOL,7,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFLOWRELAX,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPRESRELAX,9,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRMAXITERATIONS,10,1);
	ScenarioObject::InitAttr(s_StateName,11,1);
	ScenarioObject::InitAttr(s_StateName,12,1);
	ScenarioObject::InitAttr(s_StateName,13,1);
}

SteadySet::SteadySet()
{

}

SteadySet::~SteadySet()
{

}

ScenarioObject* SteadySet::CreatSteadySet()
{
	SteadySet *pSteadySet = new SteadySet;
	pSteadySet->Init();
    ms_AnalysisType.SetValue(0);
	ms_PresTolType.SetValue(1);			
	ms_PresAbsTol.SetValue(_T(""));	
	ms_PresRelTol.SetValue(_T("0.00001"));	
	ms_FlowTolType.SetValue(1);	
	ms_FlowAbsTol.SetValue(_T(""));	
	ms_FlowRelTol.SetValue(_T("0.00001"));	
	ms_FlowRelaxation.SetValue(_T("0.9"));
	ms_PresRelaxation.SetValue(_T("0.9"));
	ms_MaxIterations.SetValue(50000);	
	ms_KeepHistory.SetValue(0);	
	ms_MatrixMethod.SetValue(0);	
	ms_AutoDetect.SetValue(100);
	pSteadySet->SaveData();
	return pSteadySet;
}

ScenarioObject* SteadySet::DoClone()
{
	return new SteadySet(*this);
}

void SteadySet::InitData()
{
	GetValue(ms_AnalysisType,1);
	GetValue(ms_PresTolType,2);
	GetValue(ms_PresAbsTol,3);
	GetValue(ms_PresRelTol,4);
	GetValue(ms_FlowTolType,5);
	GetValue(ms_FlowAbsTol,6);
	GetValue(ms_FlowRelTol,7);
	GetValue(ms_FlowRelaxation,8);
	GetValue(ms_PresRelaxation,9);
	GetValue(ms_MaxIterations,10);
	GetValue(ms_KeepHistory,11);
	GetValue(ms_MatrixMethod,12);
	GetValue(ms_AutoDetect,13);
}

void SteadySet::SaveData()
{
	SetValue(ms_AnalysisType,1);
	SetValue(ms_PresTolType,2);
	SetValue(ms_PresAbsTol,3);
	SetValue(ms_PresRelTol,4);
	SetValue(ms_FlowTolType,5);
	SetValue(ms_FlowAbsTol,6);
	SetValue(ms_FlowRelTol,7);
	SetValue(ms_FlowRelaxation,8);
	SetValue(ms_PresRelaxation,9);
	SetValue(ms_MaxIterations,10);
	SetValue(ms_KeepHistory,11);
	SetValue(ms_MatrixMethod,12);
	SetValue(ms_AutoDetect,13);
}

int SteadySet::AnalysisType()
{
	GetValue(ms_AnalysisType,1);
	return ms_AnalysisType.GetnValue();
}

void SteadySet::AnalysisType(int nType)
{
	ms_AnalysisType.SetValue(nType);
	SetValue(ms_AnalysisType,1);
}

BOOL SteadySet::Read(SteadyPersistent &persistent)
{
	ms_AnalysisType.SetValue(persistent.AnalysisType());
	ms_PresTolType.SetValue(persistent.PresTolType());			
	ms_PresAbsTol.SetData(persistent.PresAbsTol());	
	ms_PresRelTol.SetValue(persistent.PresRelTol());	
	ms_FlowTolType.SetValue(persistent.FlowTolType());	
	ms_FlowAbsTol.SetData(persistent.FlowAbsTol());	
	ms_FlowRelTol.SetValue(persistent.FlowRelTol());
	if(_ttoi(persistent.RelaxationType()) == 1)
	{
		ms_FlowRelaxation.SetValue(persistent.FlowRelaxation());
		ms_PresRelaxation.SetValue(persistent.PresRelaxation());
	}
	ms_MaxIterations.SetValue(persistent.MaxIterations());	
	ms_KeepHistory.SetValue(persistent.KeepHistory());	
	ms_MatrixMethod.SetValue(persistent.MatrixMethod());	
	ms_AutoDetect.SetValue(persistent.AutoDetect());
	SaveData();
	return TRUE;
}

BOOL SteadySet::Save(SteadyPersistent &persistent)
{
	InitData();
	persistent.AnalysisType(ms_AnalysisType.GetValue());
	persistent.PresTolType(ms_PresTolType.GetValue());			
	persistent.PresAbsTol(ms_PresAbsTol.GetData());	
	persistent.PresRelTol(ms_PresRelTol.GetValue());	
	persistent.FlowTolType(ms_FlowTolType.GetValue());	
	persistent.FlowAbsTol(ms_FlowAbsTol.GetData());	
	persistent.FlowRelTol(ms_FlowRelTol.GetValue());
	persistent.RelaxationType(_T("1"));
	persistent.FlowRelaxation(ms_FlowRelaxation.GetValue());
	persistent.PresRelaxation(ms_PresRelaxation.GetValue());
	persistent.MaxIterations(ms_MaxIterations.GetValue());	
	persistent.KeepHistory(ms_KeepHistory.GetValue());	
	persistent.MatrixMethod(ms_MatrixMethod.GetValue());	
	persistent.AutoDetect(ms_AutoDetect.GetValue());
	return TRUE;
}

BOOL SteadySet::IsDefine()
{
	InitData();
	if(ms_PresTolType.GetnValue() != 0)
	{
		if(ms_PresRelTol.GetfValue()<=0)
			return FALSE;
	}
	if(ms_PresTolType.GetnValue() != 1)
	{
		if(ms_PresAbsTol.GetfValue()<=0)
			return FALSE;
	}

	if(ms_FlowTolType.GetnValue() != 0)
	{
		if(ms_FlowRelTol.GetfValue()<=0)
			return FALSE;
	}
	if(ms_FlowTolType.GetnValue() != 1)
	{
		if(ms_FlowAbsTol.GetfValue()<=0)
			return FALSE;
	}
	if(ms_MaxIterations.GetnValue()<=0)
		return FALSE;
	return TRUE;
}
