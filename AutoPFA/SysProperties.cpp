// SysProperties.cpp: implementation of the SysProperties class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "SysProperties.h"
#include "Fuild.h"
#include "Condition.h"
#include "SysProperFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SysProperties::SysProperties()
{
	m_factory = SysProperFactory::Instance();
	m_pFuild = dynamic_cast<Fuild*>(m_factory->CreatObject(1));
	m_pCondition = dynamic_cast<Condition*>(m_factory->CreatObject(2));
}

SysProperties::~SysProperties()
{
	delete m_pFuild;
	delete m_pCondition;
}

SysProperties::SysProperties(const SysProperties &ref)
{
	m_pCondition = dynamic_cast<Condition*>(ref.m_pCondition->Clone()); 
	m_pFuild = dynamic_cast<Fuild*>(ref.m_pFuild->Clone());
}

SysProperties& SysProperties::operator=(const SysProperties &ref)
{
	if(this == &ref)
		return *this;

	delete m_pFuild;
	delete m_pCondition;
	m_pCondition = NULL;
	m_pFuild = NULL;

	m_pCondition = dynamic_cast<Condition*>(ref.m_pCondition->Clone()); 
	m_pFuild = dynamic_cast<Fuild*>(ref.m_pFuild->Clone());

	return *this;

}

void SysProperties::DelState()
{
	m_pFuild->DelShareState();
	m_pCondition->DelShareState();
}

FlyWeight* SysProperties::LookUp(int nObjectType,int nObjectKey, int nStateKey)
{
	switch(nObjectType)
	{
	case 10:
		return m_pFuild->GetPrivate(nStateKey);
		break;
    case 11:
		return m_pCondition->GetPrivate(nStateKey);
	default:
		return NULL;
		break;
	}
}

void SysProperties::InitState(Scenario *pCurScenario)
{
	m_pCondition->InitState(pCurScenario);
	m_pFuild->InitState(pCurScenario);
}

void SysProperties::CloneChild(const SysProperties &parent)
{
	assert(m_pCondition != NULL && m_pFuild != NULL);
	delete m_pCondition;
	m_pCondition = dynamic_cast<Condition*>(parent.m_pCondition->CloneChild());
	delete m_pFuild;
	m_pFuild = dynamic_cast<Fuild*>(parent.m_pFuild->CloneChild());
}

void SysProperties::Promote(const SysProperties &parent)
{
	m_pCondition->Promote(parent.m_pCondition);
	m_pFuild->Promote(parent.m_pFuild);
}



BOOL SysProperties::Read(PropertyPersistent &persistent)
{
	BOOL bRet = FALSE;
	if(m_pFuild->Read(persistent)
		&&m_pCondition->Read(persistent))
	{
		bRet = TRUE;
	}
	return bRet;
}

BOOL SysProperties::Save(PropertyPersistent &persistent)
{
	BOOL bRet = FALSE;
	if(m_pFuild->Save(persistent)
		&&m_pCondition->Save(persistent))
	{
		bRet = TRUE;
	}
	return bRet;
}

double SysProperties::Gravity()
{
	return m_pCondition->Gravity();
}

double SysProperties::Density()
{
	return m_pFuild->Density();
}

double SysProperties::BulkModulus()
{
	return m_pFuild->BulkModulus();
}

BOOL SysProperties::IsFuildDefine()
{
	return m_pFuild->IsDefine();
}
