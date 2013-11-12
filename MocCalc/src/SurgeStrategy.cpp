// SurgeStrategy.cpp: implementation of the SurgeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SurgeStrategy.h"
#include "MOCFluid.h"
#include "EndListRef.h"
#include "MOCLumpedInertia.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SurgeStrategy::SurgeStrategy()
{

}

SurgeStrategy::~SurgeStrategy()
{

}

SurgeStrategy* SurgeStrategy::Instance()
{
	static SurgeStrategy strategy;
	return &strategy;
}

void SurgeStrategy::Calc(EndListRef &jun,MOCLumpedInertia &Inertia,double dSurfacePress,double dArea,double &dH,double &dMass)
{
	double dSc = jun.Sc();
	double dSb = jun.Sb();
	double dPOld1 = dSurfacePress+MOCFluid::TranHToPress(dH);
	double dPOld3 = jun.GetPress();
	double dC1 = Inertia.CalcC1(dPOld1,dPOld3,dMass);
	double dDatalL = 0.5*dMass*MOCFluid::SetpTime()/MOCFluid::Density()/dArea;
	dH = dH -dDatalL;
	double dLPress = MOCFluid::TranHToPress(dH);
	double dTemp = dSc/dSb - dSurfacePress - dLPress + dC1;
	BOOL bInToSys = FALSE;
	if(dTemp < 0)
		bInToSys = TRUE;
	double dC2 = Inertia.CalcC2(dMass,bInToSys);
	dMass = -dTemp/(dC2 + 0.5*MOCFluid::Gravity()*MOCFluid::SetpTime()/dArea + 1/dSb);
	jun.BranchStrategy(dMass);
}
