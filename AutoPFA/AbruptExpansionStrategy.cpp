// AbruptExpansionStrategy.cpp: implementation of the AbruptExpansionStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "AbruptExpansionStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AbruptExpansionStrategy::AbruptExpansionStrategy()
{

}

AbruptExpansionStrategy::~AbruptExpansionStrategy()
{

}

ILossCalcStrategy* AbruptExpansionStrategy::Creator()
{
	static AbruptExpansionStrategy strategy;
	return &strategy;
}

double AbruptExpansionStrategy::CalcK(const AreaChangeLossCalc &ref)
{
	double dK = 0;
	if(ref.AreaDown()<=0)
		return dK;
	double dAreaRatio = ref.AreaUp() / ref.AreaDown();
	dK = pow(1-dAreaRatio,2);
	return dK;
}
