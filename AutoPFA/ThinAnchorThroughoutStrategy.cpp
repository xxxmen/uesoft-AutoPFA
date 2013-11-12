// ThinAnchorThroughoutStrategy.cpp: implementation of the ThinAnchorThroughoutStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ThinAnchorThroughoutStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ThinAnchorThroughoutStrategy::ThinAnchorThroughoutStrategy()
{

}

ThinAnchorThroughoutStrategy::~ThinAnchorThroughoutStrategy()
{

}
ISupportStrategy* ThinAnchorThroughoutStrategy::Creator()
{
	static ThinAnchorThroughoutStrategy strategy;
	return &strategy;
}

double ThinAnchorThroughoutStrategy::GetC1(const WavespeedCalc &ref)
{
	return 1 - pow(ref.u(),2);
}
