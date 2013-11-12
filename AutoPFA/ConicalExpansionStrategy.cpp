// ConicalExpansionStrategy.cpp: implementation of the ConicalExpansion45Strategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ConicalExpansionStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ConicalExpansion45Strategy::ConicalExpansion45Strategy()
{

}

ConicalExpansion45Strategy::~ConicalExpansion45Strategy()
{

}
ILossCalcStrategy* ConicalExpansion45Strategy::Creator()
{
	static ConicalExpansion45Strategy strategy;
	return &strategy;
}

double ConicalExpansion45Strategy::CalcK(const AreaChangeLossCalc &ref)
{
	double dK = 0;
	if(ref.AreaDown()<=0||ref.Angel()<=0)
		return dK;
	double dAreaRatio = ref.AreaUp() / ref.AreaDown();
	double dSin = sin(ref.Angel()/360.0*PI);
	dK = 2.6*dSin*pow(1-dAreaRatio,2)*ref.BaseArea();
	return dK;
}
