// ThickExpandThroughoutStrategy.cpp: implementation of the ThickExpandThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ThickExpandThroughoutStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ThickExpandThroughoutStrategy::ThickExpandThroughoutStrategy()
{

}

ThickExpandThroughoutStrategy::~ThickExpandThroughoutStrategy()
{

}
ISupportStrategy* ThickExpandThroughoutStrategy::Creator()
{
	static ThickExpandThroughoutStrategy strategy;
	return &strategy;
}

double ThickExpandThroughoutStrategy::GetC1(const WavespeedCalc &ref)
{
	double dRet = 0;
	if(ref.Dia()>0 && ref.e()>0)
	{ 
		dRet = 2*ref.e()/ref.Dia()*(1+ref.u())
		+ ref.Dia()/(ref.Dia()+ref.e());
	}
	return dRet;
}
