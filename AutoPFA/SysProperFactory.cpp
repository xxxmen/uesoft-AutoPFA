// SysProperFactory.cpp: implementation of the SysProperFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "SysProperFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Fuild.h"
#include "Condition.h"
#include "SectionSet.h"
#include "SteadySet.h"
#include "TransientSet.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SysProperFactory::SysProperFactory()
{
	Fuild::Instance();
	Condition::Instance();
	SteadySet::Instance();
	SectionSet::Instance();
	TransientSet::Instance();
	Register(1,Fuild::CreatFuild);
    Register(2,Condition::CreatCondition);
	Register(10,SteadySet::CreatSteadySet);
	Register(11,SectionSet::CreatSectionSet);
	Register(12,TransientSet::CreatTransientSet);
}

SysProperFactory::~SysProperFactory()
{
}

SysProperFactory* SysProperFactory::Instance()
{
	static SysProperFactory factory;
	return &factory;
}

