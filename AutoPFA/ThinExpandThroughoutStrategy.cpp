// ThinExpandThroughoutStrategy.cpp: implementation of the ThinExpandThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ThinExpandThroughoutStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ThinExpandThroughoutStrategy::ThinExpandThroughoutStrategy()
{

}

ThinExpandThroughoutStrategy::~ThinExpandThroughoutStrategy()
{

}

ISupportStrategy* ThinExpandThroughoutStrategy::Creator()
{
	static ThinExpandThroughoutStrategy strategy;
	return &strategy;
}

double ThinExpandThroughoutStrategy::GetC1(const WavespeedCalc &ref)
{
	return 1;
}
