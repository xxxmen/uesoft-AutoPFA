// MOCTrigerJunStaticDiffStrategy.cpp: implementation of the MOCTrigerJunStaticDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerJunStaticDiffStrategy.h"
#include "MOCJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerJunStaticDiffStrategy::MOCTrigerJunStaticDiffStrategy()
{

}

MOCTrigerJunStaticDiffStrategy::~MOCTrigerJunStaticDiffStrategy()
{

}

MOCTrigerStrategy* MOCTrigerJunStaticDiffStrategy::Creator()
{
	static MOCTrigerJunStaticDiffStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerJunStaticDiffStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(StaticDiff,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerJunStaticDiffStrategy::StaticDiff(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCJun *pJun = dynamic_cast<MOCJun*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		EndInfo* pIn = pJun->GetInEnd();
		EndInfo *pOut = pJun->GetOutEnd();
		if(pIn==NULL || pOut ==NULL)
			return FALSE;
		dValue = fabs(pIn->GetStaticPress()-pOut->GetStaticPress());
		return TRUE;
	}
	return FALSE;
}