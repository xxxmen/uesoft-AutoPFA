// ThickAnchorThroughoutStrategy.cpp: implementation of the ThickAnchorThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ThickAnchorThroughoutStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ThickAnchorThroughoutStrategy::ThickAnchorThroughoutStrategy()
{

}

ThickAnchorThroughoutStrategy::~ThickAnchorThroughoutStrategy()
{

}

ISupportStrategy* ThickAnchorThroughoutStrategy::Creator()
{
	static ThickAnchorThroughoutStrategy strategy;
	return &strategy;
}

double ThickAnchorThroughoutStrategy::GetC1(const WavespeedCalc &ref)
{
	double dRet = 0;
	if(ref.Dia()>0 && ref.e()>0)
	{ 
		dRet = 2*ref.e()/ref.Dia()*(1+ref.u())
		+ ref.Dia()/(ref.Dia()+ref.e())*(1 - pow(ref.u(),2));
	}
	return dRet;
}
