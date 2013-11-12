// PressDropStrategy.cpp: implementation of the PressDropStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PressDropStrategy.h"
#include "EndListRef.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PressDropStrategy::PressDropStrategy()
{

}

PressDropStrategy::~PressDropStrategy()
{

}

PressDropStrategy* PressDropStrategy::Instance()
{
	static PressDropStrategy strategy;
	return &strategy;
}

double PressDropStrategy::Calc(EndListRef &jun,double dPressDelta)
{
	double dNewMass = CalcMass(jun,dPressDelta);
	jun.FlowStrategy(dNewMass);
	return dNewMass;
}

double PressDropStrategy::Calc(EndListRef &jun,double dPressUp,double dPressDelta)
{
	double dNewMass = CalcMass(jun,dPressUp,dPressDelta);
	jun.FlowStrategy(dNewMass);
	return dNewMass;
}

double PressDropStrategy::CalcMass(EndListRef &jun,double dPressUp,double dPressDelta)
{
	double dNewMass = 0;
	EndInfo *pOutEnd = jun.GetOutEnd();
	if(pOutEnd==NULL)
	{
		ASSERT(FALSE);
		return dNewMass;
	}
	double dCm = pOutEnd->GetCpm();
	double dBm = pOutEnd->GetBpm();
	if (-0.000001<dBm&&dBm<0.000001)
	{
		ASSERT(FALSE);//B大于0
		return dNewMass;

	}
	dNewMass = (dPressUp-dCm-dPressDelta)/dBm;
	return dNewMass;
}

double PressDropStrategy::CalcMass(EndListRef &jun, double dPressDelta)
{
	double dNewMass = 0;
	EndInfo *pInEnd = jun.GetInEnd();
	EndInfo *pOutEnd = jun.GetOutEnd();
	if(pInEnd==NULL ||pOutEnd==NULL)
	{
		ASSERT(FALSE);
		return dNewMass;
	}
	double dCp = pInEnd->GetCpm();
	double dBp = pInEnd->GetBpm();
	double dCm = pOutEnd->GetCpm();
	double dBm = pOutEnd->GetBpm();
	double dTemp = dBp + dBm;
	if (-0.000001<dTemp&&dTemp<0.000001)
	{
		ASSERT(FALSE);//B大于0
		return dNewMass;

	}
	dNewMass = (dCp-dCm-dPressDelta)/dTemp;
	return dNewMass;
}
