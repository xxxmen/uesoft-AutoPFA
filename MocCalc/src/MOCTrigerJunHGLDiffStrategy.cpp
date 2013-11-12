// MOCTrigerJunHGLDiffStrategy.cpp: implementation of the MOCTrigerJunHGLDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerJunHGLDiffStrategy.h"
#include "MOCJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerJunHGLDiffStrategy::MOCTrigerJunHGLDiffStrategy()
{

}

MOCTrigerJunHGLDiffStrategy::~MOCTrigerJunHGLDiffStrategy()
{

}

MOCTrigerStrategy* MOCTrigerJunHGLDiffStrategy::Creator()
{
	static MOCTrigerJunHGLDiffStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerJunHGLDiffStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(HGLDiff,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerJunHGLDiffStrategy::HGLDiff(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCJun *pJun = dynamic_cast<MOCJun*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		EndInfo* pIn = pJun->GetInEnd();
		EndInfo *pOut = pJun->GetOutEnd();
		if(pIn==NULL || pOut ==NULL)
			return FALSE;
		dValue = fabs(pIn->GetHGL()-pOut->GetHGL());
		return TRUE;
	}
	return FALSE;
}