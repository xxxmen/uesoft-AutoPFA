// MOCTrigerJunStagDiffStrategy.cpp: implementation of the MOCTrigerJunStagDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerJunStagDiffStrategy.h"
#include "MOCJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerJunStagDiffStrategy::MOCTrigerJunStagDiffStrategy()
{

}

MOCTrigerJunStagDiffStrategy::~MOCTrigerJunStagDiffStrategy()
{

}

MOCTrigerStrategy* MOCTrigerJunStagDiffStrategy::Creator()
{
	static MOCTrigerJunStagDiffStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerJunStagDiffStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(StagDiff,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerJunStagDiffStrategy::StagDiff(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCJun *pJun = dynamic_cast<MOCJun*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		EndInfo* pIn = pJun->GetInEnd();
		EndInfo *pOut = pJun->GetOutEnd();
		if(pIn==NULL || pOut ==NULL)
			return FALSE;
		dValue = fabs(pIn->GetPress()-pOut->GetPress());
		return TRUE;
	}
	return FALSE;
}