// MOCTrigerPipeMassStrategy.cpp: implementation of the MOCTrigerPipeMassStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeMassStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeMassStrategy::MOCTrigerPipeMassStrategy()
{

}

MOCTrigerPipeMassStrategy::~MOCTrigerPipeMassStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeMassStrategy::Creator()
{
	static MOCTrigerPipeMassStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeMassStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(EndMass,mgr,dCurTime,dStartTime);;
}

BOOL MOCTrigerPipeMassStrategy::EndMass(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	int nPort = mgr.Port1();//1：入口2：出口
	MOCPipe *pPipe = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey));
	if(pPipe != NULL)
	{
		if(nPort==1)
		{
			dValue = pPipe->GetInEnd()->GetMass();
		}
		else
		{
			dValue = pPipe->GetOutEnd()->GetMass();
		}
		return TRUE;
	}
	return FALSE;
}
