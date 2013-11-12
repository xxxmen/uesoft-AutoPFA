// MOCTrigerRelTimeStrategy.cpp: implementation of the MOCTrigerRelTimeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerRelTimeStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerRelTimeStrategy::MOCTrigerRelTimeStrategy()
{

}

MOCTrigerRelTimeStrategy::~MOCTrigerRelTimeStrategy()
{

}

MOCTrigerStrategy* MOCTrigerRelTimeStrategy::Creator()
{
	static MOCTrigerRelTimeStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerRelTimeStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return TimeTriger(RelTime,mgr,dCurTime,dStartTime);
}

double MOCTrigerRelTimeStrategy::RelTime(double dCurTime, double dStartTime)
{
	return dCurTime-dStartTime;
}