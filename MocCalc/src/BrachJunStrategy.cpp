// BrachJunStrategy.cpp: implementation of the BrachJunStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BrachJunStrategy.h"
#include "EndListRef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BrachJunStrategy::BrachJunStrategy()
{

}

BrachJunStrategy::~BrachJunStrategy()
{

}

BrachJunStrategy* BrachJunStrategy::Instance()
{
	static BrachJunStrategy strategy;
	return &strategy;
}

void BrachJunStrategy::Calc(EndListRef &jun,double dOutMass)
{
	double dNewPress = CalcPress(jun,dOutMass);
	dNewPress = jun.CheckVaporPress(dNewPress);
	if(jun.IsVapor())
	{//形成气穴
		jun.StaticPressStrategy(dNewPress);
		jun.VaporVolume(jun.DetalVaporVolume(dOutMass)+jun.VaporVolume());
	}
	else
	{
		double dMass = jun.CollapseMass();
		dNewPress = CalcPress(jun,dOutMass-dMass);
		dNewPress = jun.CheckVaporPress(dNewPress);
		if(jun.IsVapor())
		{//气穴缩小
			jun.StaticPressStrategy(dNewPress);
			jun.VaporVolume(jun.DetalVaporVolume(dOutMass-dMass));
		}
		else
		{//气穴消失
			jun.Collapse();
			jun.StagPressStrategy(dNewPress);
		}
	}
}


double BrachJunStrategy::CalcPress(EndListRef &jun,double dOutMass)
{
	double dSc = jun.Sc();
	double dSb = jun.Sb();
	return (dSc + dOutMass) / dSb;
}
