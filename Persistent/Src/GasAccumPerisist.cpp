// GasAccumPerisist.cpp: implementation of the GasAccumPerisist class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GasAccumPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GasAccumPerisist::GasAccumPerisist()
{

}

GasAccumPerisist::~GasAccumPerisist()
{

}

Junperisist* GasAccumPerisist::CreatGasAccumulator()
{
	//22
	GasAccumPerisist *pGasAccum = new GasAccumPerisist;
	return pGasAccum;
}
