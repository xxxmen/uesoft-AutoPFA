// MOCTrigerPipeStagStrategy.cpp: implementation of the MOCTrigerPipeStagStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeStagStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeStagStrategy::MOCTrigerPipeStagStrategy()
{

}

MOCTrigerPipeStagStrategy::~MOCTrigerPipeStagStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeStagStrategy::Creator()
{
	static MOCTrigerPipeStagStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeStagStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(StagPress,mgr,dCurTime,dStartTime);;
}

BOOL MOCTrigerPipeStagStrategy::StagPress(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	int nPort = mgr.Port1();//1：入口2：出口
	MOCPipe *pPipe = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey));
	if(pPipe != NULL)
	{
		if(nPort==1)
		{
			dValue = pPipe->GetInEnd()->GetStagPress();
		}
		else
		{
			dValue = pPipe->GetOutEnd()->GetStagPress();
		}
		return TRUE;
	}
	return FALSE;
}