// MOCTrigerSpryVolumeStrategy.cpp: implementation of the MOCTrigerSpryVolumeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerSpryVolumeStrategy.h"
#include "MOCSpray.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerSpryVolumeStrategy::MOCTrigerSpryVolumeStrategy()
{

}

MOCTrigerSpryVolumeStrategy::~MOCTrigerSpryVolumeStrategy()
{

}

MOCTrigerStrategy* MOCTrigerSpryVolumeStrategy::Creator()
{
	static MOCTrigerSpryVolumeStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerSpryVolumeStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(SpryOutFlow,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerSpryVolumeStrategy::SpryOutFlow(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCSpray *pJun = dynamic_cast<MOCSpray*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		dValue = pJun->GetOutVolumeFlow();
		return TRUE;
	}
	return FALSE;
}
