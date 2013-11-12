// ThinAnchorUpstreamStrategy.cpp: implementation of the ThinAnchorUpstreamStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "ThinAnchorUpstreamStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ThinAnchorUpstreamStrategy::ThinAnchorUpstreamStrategy()
{

}

ThinAnchorUpstreamStrategy::~ThinAnchorUpstreamStrategy()
{

}
ISupportStrategy* ThinAnchorUpstreamStrategy::Creator()
{
	static ThinAnchorUpstreamStrategy strategy;
	return &strategy;
}

double ThinAnchorUpstreamStrategy::GetC1(const WavespeedCalc &ref)
{
	return 1 - ref.u()/2;
}
