// MOCTrigerControlStateStrategy.cpp: implementation of the MOCTrigerControlStateStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerControlStateStrategy.h"
#include "MOCControl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerControlStateStrategy::MOCTrigerControlStateStrategy()
{

}

MOCTrigerControlStateStrategy::~MOCTrigerControlStateStrategy()
{

}

MOCTrigerStrategy* MOCTrigerControlStateStrategy::Creator()
{
	static MOCTrigerControlStateStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerControlStateStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	int nType = mgr.ConditionType();
	int nKey = mgr.ComponentID1();
	MOCControl *pJun = dynamic_cast<MOCControl*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		if(pJun->ValveStatus() == nType)
		{
			mgr.TrigerTime(dCurTime);
			return TRUE;
		}
	}
	return FALSE;
}
