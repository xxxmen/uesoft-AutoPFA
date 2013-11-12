// SupportStrategyFactory.cpp: implementation of the SupportStrategyFactory class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "SupportStrategyFactory.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
#include "ThickAnchorThroughoutStrategy.h"
#include "ThickAnchorUpstreamStrategy.h"
#include "ThickExpandThroughoutStrategy.h"
#include "ThinAnchorThroughoutStrategy.h"
#include "ThinAnchorUpstreamStrategy.h"
#include "ThinExpandThroughoutStrategy.h"
#include "CircularTunnel.h"


SupportStrategyFactory::SupportStrategyFactory()
{
	Register(1,ThinAnchorUpstreamStrategy::Creator);
	Register(2,ThinAnchorThroughoutStrategy::Creator);
	Register(3,ThinExpandThroughoutStrategy::Creator);
	Register(4,ThickAnchorUpstreamStrategy::Creator);
	Register(5,ThickAnchorThroughoutStrategy::Creator);
	Register(6,ThickExpandThroughoutStrategy::Creator);
	Register(7,CircularTunnelStrategy::Creator);
}

SupportStrategyFactory::~SupportStrategyFactory()
{

}

SupportStrategyFactory* SupportStrategyFactory::Instance()
{
	static SupportStrategyFactory factory;
	return &factory;
}
