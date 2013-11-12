// MOCTrigerJunStagStrategy.cpp: implementation of the MOCTrigerJunStagStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerJunStagStrategy.h"
#include "MOCJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerJunStagStrategy::MOCTrigerJunStagStrategy()
{

}

MOCTrigerJunStagStrategy::~MOCTrigerJunStagStrategy()
{

}

MOCTrigerStrategy* MOCTrigerJunStagStrategy::Creator()
{
	static MOCTrigerJunStagStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerJunStagStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(StagPress,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerJunStagStrategy::StagPress(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCJun *pJun = dynamic_cast<MOCJun*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		dValue = pJun->GetEndList().GetPress();
		return TRUE;
	}
	return FALSE;
}
