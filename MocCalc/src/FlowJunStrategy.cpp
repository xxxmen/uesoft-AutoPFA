// FlowJunStrategy.cpp: implementation of the FlowJunStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FlowJunStrategy.h"
#include "EndListRef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

FlowJunStrategy::FlowJunStrategy()
{

}

FlowJunStrategy::~FlowJunStrategy()
{

}

FlowJunStrategy* FlowJunStrategy::Instance()
{
	static FlowJunStrategy strategy;
	return &strategy;
}

void FlowJunStrategy::Calc(EndListRef &jun,double dMass)
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(jun.CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		Calc(jun,*pEnd,dMass);
	}
}

void FlowJunStrategy::Calc(EndListRef &jun,EndInfo &end,double dMass)
{
	end.SetMass(dMass);
	double dNewPress = end.CalcPress();
	dNewPress = end.CheckVaporPress(dNewPress,dMass);
	if(end.IsVapor())
	{//形成气穴
		jun.StaticPressStrategy(end,dNewPress);
		end.VaporVolume(end.DetalVaporVolume(dMass)+end.VaporVolume());
	}
	else
	{
		double dCollapseMass = end.CollapseMass();
		end.SetMass(dMass+dCollapseMass);
		dNewPress = end.CalcPress();
		dNewPress = end.CheckVaporPress(dNewPress,dMass+dCollapseMass);
		if(end.IsVapor())
		{//气穴缩小
			jun.StaticPressStrategy(end,dNewPress);
			end.VaporVolume(end.DetalVaporVolume(dMass+dCollapseMass));
		}
		else
		{//气穴消失
			end.Collapse();
			end.SetPress(dNewPress);
		}
		
	}
}


