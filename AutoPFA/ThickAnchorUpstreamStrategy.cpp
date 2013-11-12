// ThickAnchorUpstreamStrategy.cpp: implementation of the ThickAnchorUpstreamStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ThickAnchorUpstreamStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ThickAnchorUpstreamStrategy::ThickAnchorUpstreamStrategy()
{

}

ThickAnchorUpstreamStrategy::~ThickAnchorUpstreamStrategy()
{

}
ISupportStrategy* ThickAnchorUpstreamStrategy::Creator()
{
	static ThickAnchorUpstreamStrategy strategy;
	return &strategy;
}

double ThickAnchorUpstreamStrategy::GetC1(const WavespeedCalc &ref)
{
	double dRet = 0;
	if(ref.Dia()>0 && ref.e()>0)
	{ 
		dRet = 2*ref.e()/ref.Dia()*(1+ref.u())
		+ ref.Dia()/(ref.Dia()+ref.e())*(1 - ref.u()/2);
	}
	return dRet;
}
