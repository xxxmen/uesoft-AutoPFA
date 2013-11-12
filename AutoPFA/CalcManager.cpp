// alcManager.cpp: implementation of the CalcManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "CalcManager.h"
#include "SteadySet.h"
#include "SectionSet.h"
#include "TransientSet.h"
#include "SysProperFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcManager::CalcManager()
{
	m_factory = SysProperFactory::Instance();
	m_pSteadySet = dynamic_cast<SteadySet*>(m_factory->CreatObject(10));
	m_pSectionSet = dynamic_cast<SectionSet*>(m_factory->CreatObject(11));
	m_pTransientSet = dynamic_cast<TransientSet*>(m_factory->CreatObject(12));
}

CalcManager::~CalcManager()
{
	delete m_pSteadySet;
	delete m_pSectionSet;
	delete m_pTransientSet;		
}

CalcManager::CalcManager(const CalcManager &ref)
{
	m_pSteadySet = dynamic_cast<SteadySet*>(ref.m_pSteadySet->Clone());
	m_pSectionSet = dynamic_cast<SectionSet*>(ref.m_pSectionSet->Clone());
	m_pTransientSet = dynamic_cast<TransientSet*>(ref.m_pTransientSet->Clone());
}

CalcManager& CalcManager::operator=(const CalcManager &ref)
{
	if(this == &ref)
		return *this;

	delete m_pSteadySet;
	delete m_pSectionSet;
	delete m_pTransientSet;	
    m_pSteadySet = NULL;
	m_pSectionSet = NULL;
	m_pTransientSet = NULL;

	m_pSteadySet = dynamic_cast<SteadySet*>(ref.m_pSteadySet->Clone());
	m_pSectionSet = dynamic_cast<SectionSet*>(ref.m_pSectionSet->Clone());
	m_pTransientSet = dynamic_cast<TransientSet*>(ref.m_pTransientSet->Clone());

	return *this;

}

void CalcManager::DelState()
{
	m_pSteadySet->DelShareState();
	m_pSectionSet->DelShareState();
	m_pTransientSet->DelShareState();
}

FlyWeight* CalcManager::LookUp(int nObjectType,int nObjectKey, int nStateKey)
{
	switch(nObjectType)
	{
	case 20:
		return m_pSteadySet->GetPrivate(nStateKey);
		break;
    case 21:
		return m_pSectionSet->GetPrivate(nStateKey);
	case 22:
		return m_pTransientSet->GetPrivate(nStateKey);
	default:
		return NULL;
		break;
	}
}

void CalcManager::InitState(Scenario *pCurScenario)
{
	m_pSteadySet->InitState(pCurScenario);
	m_pSectionSet->InitState(pCurScenario);
	m_pTransientSet->InitState(pCurScenario);
}

void CalcManager::CloneChild(const CalcManager &parent)
{
	assert(m_pSteadySet != NULL && m_pSectionSet != NULL && m_pTransientSet != NULL);
	delete m_pSteadySet;
	m_pSteadySet = dynamic_cast<SteadySet*>(parent.m_pSteadySet->CloneChild());
	delete m_pSectionSet;
	m_pSectionSet = dynamic_cast<SectionSet*>(parent.m_pSectionSet->CloneChild());
	delete m_pTransientSet;
	m_pTransientSet = dynamic_cast<TransientSet*>(parent.m_pTransientSet->CloneChild());
}

void CalcManager::Promote(const CalcManager &parent)
{
	m_pSteadySet->Promote(parent.m_pSteadySet);
	m_pSectionSet->Promote(parent.m_pSectionSet);
	m_pTransientSet->Promote(parent.m_pTransientSet);
}

int CalcManager::AnalysisType()
{
	return m_pSteadySet->AnalysisType();
}

void CalcManager::AnalysisType(int nType)
{
	m_pSteadySet->AnalysisType(nType);
}
