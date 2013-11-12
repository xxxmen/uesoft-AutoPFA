// MOCTrigerSpeedStrategy.cpp: implementation of the MOCTrigerSpeedStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerSpeedStrategy.h"
#include "MOCPump.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerSpeedStrategy::MOCTrigerSpeedStrategy()
{

}

MOCTrigerSpeedStrategy::~MOCTrigerSpeedStrategy()
{

}

MOCTrigerStrategy* MOCTrigerSpeedStrategy::Creator()
{
	static MOCTrigerSpeedStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerSpeedStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(PumpSpeed,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerSpeedStrategy::PumpSpeed(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCPump *pJun = dynamic_cast<MOCPump*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		dValue = pJun->GetSpeed();
		return TRUE;
	}
	return FALSE;
}
