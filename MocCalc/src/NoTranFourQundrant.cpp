// NoTranFourQundrant.cpp: implementation of the NoTranFourQundrant class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "NoTranFourQundrant.h"
#include "PumpTransModelMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NoTranFourQundrant::NoTranFourQundrant()
{

}

NoTranFourQundrant::~NoTranFourQundrant()
{

}

void NoTranFourQundrant::CalcImpulse(PumpTransModelMgr &mgr, MOCTrans &trans, double dTime, double dSpeedRatio, int nSet)
{
	if(mgr.IsFourQundrant())
	{
		mgr.m_WhitoutInertiaFourQundrant.CalcFourQundrant(mgr,dTime,nSet);
	}
	else
	{
		mgr.m_WhitoutInertia.CalcImpulse(mgr,trans,dTime,dSpeedRatio,nSet);
	}	
}
