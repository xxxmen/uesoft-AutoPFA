// MOCTrigerPipeVelStrategy.cpp: implementation of the MOCTrigerPipeVelStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeVelStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeVelStrategy::MOCTrigerPipeVelStrategy()
{

}

MOCTrigerPipeVelStrategy::~MOCTrigerPipeVelStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeVelStrategy::Creator()
{
	static MOCTrigerPipeVelStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeVelStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(EndVelocity,mgr,dCurTime,dStartTime);;
}

BOOL MOCTrigerPipeVelStrategy::EndVelocity(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	int nPort = mgr.Port1();//1：入口2：出口
	MOCPipe *pPipe = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey));
	if(pPipe != NULL)
	{
		if(nPort==1)
		{
			dValue = pPipe->GetInEnd()->GetVelocity();
		}
		else
		{
			dValue = pPipe->GetOutEnd()->GetVelocity();
		}
		return TRUE;
	}
	return FALSE;
}
