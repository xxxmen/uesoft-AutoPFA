// MOCTrigerPipeStagDiffStrategy.cpp: implementation of the MOCTrigerPipeStagDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeStagDiffStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeStagDiffStrategy::MOCTrigerPipeStagDiffStrategy()
{

}

MOCTrigerPipeStagDiffStrategy::~MOCTrigerPipeStagDiffStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeStagDiffStrategy::Creator()
{
	static MOCTrigerPipeStagDiffStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeStagDiffStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(StagDiff,mgr,dCurTime,dStartTime);;
}

BOOL MOCTrigerPipeStagDiffStrategy::StagDiff(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	double Temp1=0;
	double Temp2=0;
	int nKey1 = mgr.ComponentID1();
	int nPort1 = mgr.Port1();//1：入口2：出口
	int nKey2 = mgr.ComponentID2();
	int nPort2 = mgr.Port2();//1：入口2：出口
	MOCPipe *pPipe1 = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey1));
	MOCPipe *pPipe2 = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey2));
	if(pPipe1 != NULL && pPipe2 != NULL)
	{
		if(nPort1==1)
		{
			Temp1 = pPipe1->GetInEnd()->GetStagPress();
		}
		else
		{
			Temp1 = pPipe1->GetOutEnd()->GetStagPress();
		}
		////
		if(nPort2==1)
		{
			Temp2 = pPipe2->GetInEnd()->GetStagPress();
		}
		else
		{
			Temp2 = pPipe2->GetOutEnd()->GetStagPress();
		}
		dValue = fabs(Temp1-Temp2);
		return TRUE;
	}
	return FALSE;
}