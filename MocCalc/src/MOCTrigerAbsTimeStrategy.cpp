// MOCTrigerAbsTimeStrategy.cpp: implementation of the MOCTrigerAbsTimeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerAbsTimeStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerAbsTimeStrategy::MOCTrigerAbsTimeStrategy()
{

}

MOCTrigerAbsTimeStrategy::~MOCTrigerAbsTimeStrategy()
{

}

MOCTrigerStrategy* MOCTrigerAbsTimeStrategy::Creator()
{
	static MOCTrigerAbsTimeStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerAbsTimeStrategy::IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime)
{
	return TimeTriger(AbsTime,mgr,dCurTime,dStartTime);
}

double MOCTrigerAbsTimeStrategy::AbsTime(double dCurTime, double dStaerTime)
{
	return dCurTime;
}
