// ConicalContraction45Strategy.cpp: implementation of the ConicalContraction45Strategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ConicalContraction45Strategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ConicalContraction45Strategy::ConicalContraction45Strategy()
{

}

ConicalContraction45Strategy::~ConicalContraction45Strategy()
{

}
ILossCalcStrategy* ConicalContraction45Strategy::Creator()
{
	static ConicalContraction45Strategy strategy;
	return &strategy;
}

double ConicalContraction45Strategy::CalcK(const AreaChangeLossCalc &ref)
{
	double dK = 0;
	double dAreaRatio = 0;
	if(ref.AreaUp()<=0||ref.Angel()<=0)
		return dK;
	double dSin = sin(ref.Angel()/360.0*PI);
	switch (ref.GetnRetype()){
	case 0:
		dAreaRatio = ref.AreaDown() / ref.AreaUp();
		dK = 0.8*dSin*(1-dAreaRatio)/pow(dAreaRatio,2);
		break;
	case 1:
		dAreaRatio = ref.AreaUp() / ref.AreaDown();
		dK = 0.8*dSin*(1-dAreaRatio);
		break;
	case 2:
	case 3:
		dAreaRatio = ref.AreaUp() / ref.AreaDown();
		dK = 0.8*dSin*(1-dAreaRatio)*ref.BaseArea();
		break;
	default:
		break;
	}
	return dK;
}
