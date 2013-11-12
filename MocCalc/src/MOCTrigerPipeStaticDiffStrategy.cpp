// MOCTrigerPipeStaticDiffStrategy.cpp: implementation of the MOCTrigerPipeStaticDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeStaticDiffStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeStaticDiffStrategy::MOCTrigerPipeStaticDiffStrategy()
{

}

MOCTrigerPipeStaticDiffStrategy::~MOCTrigerPipeStaticDiffStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeStaticDiffStrategy::Creator()
{
	static MOCTrigerPipeStaticDiffStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeStaticDiffStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(StaticDiff,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerPipeStaticDiffStrategy::StaticDiff(MOCTrigerStrategyMgr &mgr,double &dValue)
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
			Temp1 = pPipe1->GetInEnd()->GetStaticPress();
		}
		else
		{
			Temp1 = pPipe1->GetOutEnd()->GetStaticPress();
		}
		////
		if(nPort2==1)
		{
			Temp2 = pPipe2->GetInEnd()->GetStaticPress();
		}
		else
		{
			Temp2 = pPipe2->GetOutEnd()->GetStaticPress();
		}
		dValue = fabs(Temp1-Temp2);
		return TRUE;
	}
	return FALSE;
}