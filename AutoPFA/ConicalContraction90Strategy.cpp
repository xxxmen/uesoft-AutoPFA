// ConicalContraction90Strategy.cpp: implementation of the ConicalContraction90Strategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ConicalContraction90Strategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ConicalContraction90Strategy::ConicalContraction90Strategy()
{

}

ConicalContraction90Strategy::~ConicalContraction90Strategy()
{

}
ILossCalcStrategy* ConicalContraction90Strategy::Creator()
{
	static ConicalContraction90Strategy strategy;
	return &strategy;
}

double ConicalContraction90Strategy::CalcK(const AreaChangeLossCalc &ref)
{
	double dK = 0;
	double dAreaRatio = 0;
	if(ref.AreaUp()<=0||ref.Angel()>180)
		return dK;
	double dSin = sqrtf(sin(ref.Angel()/360.0*PI));
	switch (ref.GetnRetype()){
	case 0:
		dAreaRatio = ref.AreaDown() / ref.AreaUp();
		dK = 0.5*dSin*(1-dAreaRatio)/pow(dAreaRatio,2);
		break;
	case 1:
		dAreaRatio = ref.AreaUp() / ref.AreaDown();
		dK = 0.5*dSin*(1-dAreaRatio);
		break;
	case 2:
	case 3:
		dAreaRatio = ref.AreaUp() / ref.AreaDown();
		dK = 0.5*dSin*(1-dAreaRatio)*ref.BaseArea();
		break;
	default:
		break;
	}
// 	double dAreaRatio = ref.AreaDown() / ref.AreaUp();
// 	double dSin = sin(ref.Angel()/360.0*PI);
// 	ASSERT(dSin >=0);
// 	dK = 0.5*sqrt(dSin)*(1-dAreaRatio)/pow(dAreaRatio,2);
	return dK;
}
