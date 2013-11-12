// MOCTrigerJunEGLDiffStrategy.cpp: implementation of the MOCTrigerJunEGLDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerJunEGLDiffStrategy.h"
#include "MOCJun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerJunEGLDiffStrategy::MOCTrigerJunEGLDiffStrategy()
{

}

MOCTrigerJunEGLDiffStrategy::~MOCTrigerJunEGLDiffStrategy()
{

}

MOCTrigerStrategy* MOCTrigerJunEGLDiffStrategy::Creator()
{
	static MOCTrigerJunEGLDiffStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerJunEGLDiffStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(EGLDiff,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerJunEGLDiffStrategy::EGLDiff(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCJun *pJun = dynamic_cast<MOCJun*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		EndInfo* pIn = pJun->GetInEnd();
		EndInfo *pOut = pJun->GetOutEnd();
		if(pIn==NULL || pOut ==NULL)
			return FALSE;
		dValue = fabs(pIn->GetEGL()-pOut->GetEGL());
		return TRUE;
	}
	return FALSE;
}