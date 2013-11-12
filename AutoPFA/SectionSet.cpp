// SectionSet.cpp: implementation of the SectionSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "SectionSet.h"
#include "SectionPipePersistent.h"
#include "Pipe.h"
#include "ComponentManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


NameArray SectionSet::s_StateName;
StrFlyWeight SectionSet::ms_Search;
StrFlyWeight SectionSet::ms_MaxSections;
StrFlyWeight SectionSet::ms_MinSections;
StrFlyWeight SectionSet::ms_MaxError;
StrFlyWeight SectionSet::ms_PctIncrement;
StrFlyWeight SectionSet::ms_Sort;
StrFlyWeight SectionSet::ms_IdealSections;
StrFlyWeight SectionSet::ms_TimeStep;

SectionSet::SectionSet()
{

}

SectionSet::~SectionSet()
{

}

void SectionSet::Instance()
{
	ScenarioObject::InitAttr(s_StateName,1,1);
	ScenarioObject::InitAttr(s_StateName,2,1);
	ScenarioObject::InitAttr(s_StateName,3,1);
	ScenarioObject::InitAttr(s_StateName,4,1);
	ScenarioObject::InitAttr(s_StateName,5,1);
	ScenarioObject::InitAttr(s_StateName,6,1);
	ScenarioObject::InitAttr(s_StateName,7,1);
	ScenarioObject::InitAttr(s_StateName,8,1);
}


ScenarioObject* SectionSet::CreatSectionSet()
{
	SectionSet *pSectionSet = new SectionSet;
	pSectionSet->Init();
	ms_Search.SetValue(_T("-1"));
	ms_MaxSections.SetValue(_T("1"));			
	ms_MinSections.SetValue(_T("1"));
	ms_MaxError.SetValue(_T("1"));
	ms_PctIncrement.SetValue(_T("0.05"));
	ms_Sort.SetValue(_T("-1"));
	ms_IdealSections.SetValue(_T("1"));
	ms_TimeStep.SetValue(_T("1"));
	pSectionSet->SaveData();
	return pSectionSet;
}

ScenarioObject* SectionSet::DoClone()
{
	return new SectionSet(*this);
}

void SectionSet::InitData()
{
	GetValue(ms_Search,1);
	GetValue(ms_MaxSections,2);
	GetValue(ms_MinSections,3);
	GetValue(ms_MaxError,4);
	GetValue(ms_PctIncrement,5);
	GetValue(ms_Sort,6);
	GetValue(ms_IdealSections,7);
	GetValue(ms_TimeStep,8);
}

void SectionSet::SaveData()
{
	SetValue(ms_Search,1);
	SetValue(ms_MaxSections,2);
	SetValue(ms_MinSections,3);
	SetValue(ms_MaxError,4);
	SetValue(ms_PctIncrement,5);
	SetValue(ms_Sort,6);
	SetValue(ms_IdealSections,7);
	SetValue(ms_TimeStep,8);
}

BOOL SectionSet::Read(SectionPipePerisistent &persistent)
{
	ms_Search.SetValue(persistent.Search());
	ms_MaxSections.SetValue(persistent.MaxSections());			
	ms_MinSections.SetValue(persistent.MinSections());	
	ms_MaxError.SetValue(persistent.MaxError());	
	ms_PctIncrement.SetValue(persistent.PctIncrement());	
	ms_Sort.SetValue(persistent.Sort());	
	ms_IdealSections.SetValue(persistent.IdealSections());
	ms_TimeStep.SetValue(persistent.TimeStep());
	
	SaveData();
	return TRUE;
}

BOOL SectionSet::Save(SectionPipePerisistent &persistent)
{
	InitData();
	persistent.Search(ms_Search.GetValue());
	persistent.MaxSections(ms_MaxSections.GetValue());			
	persistent.MinSections(ms_MinSections.GetValue());	
	persistent.MaxError(ms_MaxError.GetValue());	
	persistent.PctIncrement(ms_PctIncrement.GetValue());	
	persistent.Sort(ms_Sort.GetValue());	
	persistent.IdealSections(ms_IdealSections.GetValue());
	persistent.TimeStep(ms_TimeStep.GetValue());

	return TRUE;
}


BOOL SectionSet::IsSection(ComponentManager &Manager)
{
	Component *pComponent = NULL;
	Pipe *pPipe = NULL;
	int nSectionNum = 0;
	double dError = 0;
	double dMaxError = MaxError();
	double dTimeStep = TimeStep();
	if(dTimeStep <= 0 ||Manager.GetPipeNum()==0)
	{
		return FALSE;
	}
	IteratorPtr<Component> PipeitPtr(Manager.CreatPipeIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pComponent = &PipeitPtr->CurrentItem();
		pPipe = dynamic_cast<Pipe*>(pComponent);
		if(pPipe->CalcSection(nSectionNum,dError,dTimeStep,dMaxError))
		{
			if(nSectionNum != pPipe->SectionNum())
			{
				return FALSE;
			}
		}
		else
		{
			return FALSE;
		}
	}
	return TRUE;
}

double SectionSet::MaxError()
{
	GetValue(ms_MaxError,4);
	return ms_MaxError.GetfValue();
}

double SectionSet::TimeStep()
{
	GetValue(ms_TimeStep,8);
	return ms_TimeStep.GetfValue();
}

void SectionSet::SearchSection(ListImp<StrArray<5> > &table,ComponentManager &Manager,int nMin,int nMax,double dIncrement,double dMaxError)
{
	double dIdealTime = 0;
	int n = 1;
	Pipe *pControlPipe = NULL;
	if(!Manager.SearchControlPipe(pControlPipe))
	{
		ASSERT(FALSE);
	}
	double dMax=0.0;
	double dMin=0.0;
	double dStep = 0;
	StrArray<5> array;
	for(int i=nMax; i>=nMin;i--)
	{
		dStep = dIncrement / 100.0;
		for(int j=0;j<10;j++)
		{//优化查询，逐步增加控制管道的误差。
			dMin = i * (dMaxError*j/10) /100.0;
			dMax = i * (dMaxError*(j+1)/10) /100.0;
			dMin = int(dMin/dStep)*dStep;
			dMax = int(dMax/dStep)*dStep;
			for(;dMin<dMax;dMin+=dStep)
			{
				dIdealTime = pControlPipe->StepTime()/(i+dMin);
				if(Manager.SearchSection(array,dIdealTime,dMaxError))
				{
					array.Data(float(i+dMin),1);
					table.AddItem(array);
					if(++n > 500)
						return;
				}
				if(-0.000001<dMin&&dMin<0.000001)
					continue;
				dIdealTime = pControlPipe->StepTime()/(i-dMin);
				if(Manager.SearchSection(array,dIdealTime,dMaxError))
				{
					array.Data(float(i-dMin),1);
					table.AddItem(array);
					if(++n > 500)
						return;
				}
			}
		}
	}
}

BOOL SectionSet::TimeStep(float &fTime,ComponentManager &Manager)
{
	if(IsSection(Manager))
	{
		fTime = TimeStep();
		return TRUE;
	}
	else
	{
		fTime = -1;
		return FALSE;
	}
}
