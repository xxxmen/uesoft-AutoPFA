// MOCTrigerPipeVolumeStrategy.cpp: implementation of the MOCTrigerPipeVolumeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeVolumeStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeVolumeStrategy::MOCTrigerPipeVolumeStrategy()
{

}

MOCTrigerPipeVolumeStrategy::~MOCTrigerPipeVolumeStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeVolumeStrategy::Creator()
{
	static MOCTrigerPipeVolumeStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeVolumeStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(EndVolumeFlow,mgr,dCurTime,dStartTime);;
}

BOOL MOCTrigerPipeVolumeStrategy::EndVolumeFlow(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	int nPort = mgr.Port1();//1：入口2：出口
	MOCPipe *pPipe = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey));
	if(pPipe != NULL)
	{
		if(nPort==1)
		{
			dValue = pPipe->GetInEnd()->GetVolumeFlow();
		}
		else
		{
			dValue = pPipe->GetOutEnd()->GetVolumeFlow();
		}
		return TRUE;
	}
	return FALSE;
}
