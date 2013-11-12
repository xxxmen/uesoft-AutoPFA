// MOCTrigerSurgeLiquidHStrategy.cpp: implementation of the MOCTrigerSurgeLiquidHStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerSurgeLiquidHStrategy.h"
#include "MOCSurge.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerSurgeLiquidHStrategy::MOCTrigerSurgeLiquidHStrategy()
{

}

MOCTrigerSurgeLiquidHStrategy::~MOCTrigerSurgeLiquidHStrategy()
{

}

MOCTrigerStrategy* MOCTrigerSurgeLiquidHStrategy::Creator()
{
	static MOCTrigerSurgeLiquidHStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerSurgeLiquidHStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(LiquidH,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerSurgeLiquidHStrategy::LiquidH(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCSurge *pJun = dynamic_cast<MOCSurge*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		dValue = pJun->GetLiquldHeight();
		return TRUE;
	}
	return FALSE;
}
