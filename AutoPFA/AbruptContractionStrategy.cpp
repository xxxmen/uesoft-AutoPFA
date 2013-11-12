// AbruptContractionStrategy.cpp: implementation of the AbruptContractionStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "AbruptContractionStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AbruptContractionStrategy::AbruptContractionStrategy()
{

}

AbruptContractionStrategy::~AbruptContractionStrategy()
{

}

ILossCalcStrategy* AbruptContractionStrategy::Creator()
{
	static AbruptContractionStrategy strategy;
	return &strategy;
}

double AbruptContractionStrategy::CalcK(const AreaChangeLossCalc &ref)
{
	double dK = 0;
	if(ref.AreaUp()<=0)
		return dK;
	double dAreaRatio = ref.AreaDown() / ref.AreaUp();
	dK = 0.5*pow(1-dAreaRatio,0.75)/pow(dAreaRatio,2);
	return dK;
}
