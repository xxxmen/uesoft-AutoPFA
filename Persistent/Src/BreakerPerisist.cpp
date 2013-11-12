// BreakerPerisist.cpp: implementation of the BreakerPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "BreakerPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BreakerPerisist::BreakerPerisist()
{

}

BreakerPerisist::~BreakerPerisist()
{

}

Junperisist* BreakerPerisist::CreatBreaker()
{
	//25
	BreakerPerisist *pBreaker = new BreakerPerisist;
	return pBreaker;
}
