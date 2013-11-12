// GasAccumStrategy.cpp: implementation of the GasAccumStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GasAccumStrategy.h"
#include "EndListRef.h"
#include "MOCLumpedInertia.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GasAccumStrategy::GasAccumStrategy()
{

}

GasAccumStrategy::~GasAccumStrategy()
{

}

GasAccumStrategy* GasAccumStrategy::Instance()
{
	static GasAccumStrategy strategy;
	return &strategy;
}

void GasAccumStrategy::Calc(EndListRef &jun,MOCLumpedInertia &Inertia,double dPolytropic,double dCA,double &dMass,double &dPress,double &dVolume)
{
	double dFun =0;
	double dGrad = 0;
	double dNewMass = 0;
	double dStep = 5;
	double dSign = 0;

	Calc(jun,Inertia,dPolytropic,dCA,dMass,dPress,dVolume,dNewMass,dSign,dGrad);
	while(TRUE)
	{//查找根区间
		dNewMass = dNewMass - dStep*dSign/fabs(dSign);
		Calc(jun,Inertia,dPolytropic,dCA,dMass,dPress,dVolume,dNewMass,dFun,dGrad);
		if(dFun/dSign <0)
			break;
	}

	while(TRUE)
	{//二分法
		dStep = dStep / 2;
		if(dFun > 0)
		{
			dNewMass = dNewMass - dStep;
		}
		else
		{
			dNewMass = dNewMass + dStep;
		}	
		Calc(jun,Inertia,dPolytropic,dCA,dMass,dPress,dVolume,dNewMass,dFun,dGrad);
		if(dStep < 0.01||fabs(dFun)<1E-2)
		{
			break;	 
		}
	}
	int n=0;
	while (n<100)
	{//牛顿迭代
		dNewMass = dNewMass -dFun/dGrad;
		Calc(jun,Inertia,dPolytropic,dCA,dMass,dPress,dVolume,dNewMass,dFun,dGrad);
		if(-1E-10<dFun&&dFun<1E-10)
			break;
		n++;
	}
	jun.BranchStrategy(dNewMass);
	dVolume += MOCFluid::TranMassToV((dNewMass+dMass)/2);
	dMass = dNewMass;
	dPress = dCA/pow(dVolume,dPolytropic);
}

double GasAccumStrategy::CalcC3(EndListRef &jun,MOCLumpedInertia &Inertia,double dPress,double dMass)
{
	double dSc = jun.Sc();
	double dSb = jun.Sb();
	double dPOld3 = jun.GetPress();
	double dC1 = Inertia.CalcC1(dPress,dPOld3,dMass);
	return (dSc/dSb + dC1);
}
double GasAccumStrategy::CalcC4(EndListRef &jun,MOCLumpedInertia &Inertia,double dMass,BOOL bInSys)
{
	double dSb = jun.Sb();
	double dC2 = Inertia.CalcC2(dMass,bInSys);
	return (1/dSb + dC2);
}
double GasAccumStrategy::CalcC5(double dMass,double dVolume)
{
	return (dVolume + dMass*CalcC6());
}
double GasAccumStrategy::CalcC6()
{
	return (0.5*MOCFluid::SetpTime()/MOCFluid::Density());
}
double GasAccumStrategy::CalcC7(double dPolytropic,double dCA)
{
	return (dPolytropic*dCA*CalcC6());
}

void GasAccumStrategy::Calc(EndListRef &jun,MOCLumpedInertia &Inertia,double dPolytropic,double dCA,double dOldMass,double dPress,double dVolume,double dNewMass,double &dFun,double &dGrad)
{
	BOOL bInSys = TRUE;
	if(dNewMass<0)
		bInSys = FALSE;
	double dC3 = CalcC3(jun,Inertia,dPress,dOldMass);
	double dC4 = CalcC4(jun,Inertia,dOldMass,bInSys);
	double dC5 = CalcC5(dOldMass,dVolume);
	double dC6 = CalcC6();
	double dC7 = CalcC7(dPolytropic,dCA);
	double dTemp1 = dC3 + dC4*dNewMass;
	double dTemp2 = dC5 + dC6*dNewMass;
	double dTemp3 = pow(dTemp2,dPolytropic);	
	dFun = dTemp1*dTemp3-dCA;
	dGrad = dC7/dTemp2 + dC4*dTemp3;
}