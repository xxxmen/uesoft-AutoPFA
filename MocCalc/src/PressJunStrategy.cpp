// PressJunStrategy.cpp: implementation of the PressJunStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PressJunStrategy.h"
#include "EndListRef.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PressJunStrategy::PressJunStrategy()
{

}

PressJunStrategy::~PressJunStrategy()
{

}

PressJunStrategy* PressJunStrategy::Instance()
{
	static PressJunStrategy strategy;
	return &strategy;
}

void PressJunStrategy::CalcStatic(EndListRef &jun,double dStaticPress)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(jun.CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		CalcStatic(*pEnd,dStaticPress);
	}
}


void PressJunStrategy::CalcStag(EndListRef &jun,double dStagPress)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(jun.CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		CalcStag(*pEnd,dStagPress);
	}
}
void PressJunStrategy::CalcStag(EndListRef &jun)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(jun.CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		CalcStag(*pEnd);
	}
}

void PressJunStrategy::CalcStag(EndInfo &end)
{
	double dNewMass = end.CalcMass();
	end.SetMass(dNewMass);
}

void PressJunStrategy::CalcStag(EndInfo &end,double dStagPress)
{
	end.SetPress(dStagPress);
	double dNewMass = end.CalcMass();
	end.SetMass(dNewMass);
}

void PressJunStrategy::CalcStatic(EndInfo &end,double dStaticPress)
{
	double dNewMass = end.CalcStaicMass(dStaticPress);
	end.SetMass(dNewMass);
}

