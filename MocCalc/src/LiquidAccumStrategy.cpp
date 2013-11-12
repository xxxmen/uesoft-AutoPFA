// LiquidAccumStrategy.cpp: implementation of the LiquidAccumStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "LiquidAccumStrategy.h"
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

LiquidAccumStrategy::LiquidAccumStrategy()
{

}

LiquidAccumStrategy::~LiquidAccumStrategy()
{

}

LiquidAccumStrategy* LiquidAccumStrategy::Instance()
{
	static LiquidAccumStrategy strategy;
	return &strategy;
}

void LiquidAccumStrategy::Calc(EndListRef &jun,double dK,double &dVolume,double &dMass)
{
	double dSc = jun.Sc();
	double dSb = jun.Sb();
	double dOldPress = jun.GetPress();
	double dTemp = 2*dVolume*MOCFluid::Density()/dK/MOCFluid::SetpTime();
	double dPress = (dSc+dOldPress*dTemp-dMass)/(dSb+dTemp);
	dMass = (dOldPress-dPress)/dTemp-dMass;
	jun.StagPressStrategy(dPress);
}
