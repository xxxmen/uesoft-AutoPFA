// CircularTunnel.cpp: implementation of the CircularTunnelStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "CircularTunnel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CircularTunnelStrategy::CircularTunnelStrategy()
{

}

CircularTunnelStrategy::~CircularTunnelStrategy()
{

}

ISupportStrategy* CircularTunnelStrategy::Creator()
{
	static CircularTunnelStrategy strategy;
	return &strategy;
}

double CircularTunnelStrategy::GetC1(const WavespeedCalc &ref)
{
	double dRet = 0;
	if(ref.Dia()>0)
	{ 
		dRet = 2*ref.e()/ref.Dia()*(1+ref.u());
	}
	return dRet;
}
