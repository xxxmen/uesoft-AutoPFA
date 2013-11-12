// MOCTrigerSurgeGLStrategy.cpp: implementation of the MOCTrigerSurgeGLStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerSurgeGLStrategy.h"
#include "MOCSurge.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerSurgeGLStrategy::MOCTrigerSurgeGLStrategy()
{

}

MOCTrigerSurgeGLStrategy::~MOCTrigerSurgeGLStrategy()
{

}

MOCTrigerStrategy* MOCTrigerSurgeGLStrategy::Creator()
{
	static MOCTrigerSurgeGLStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerSurgeGLStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(SurgeGL,mgr,dCurTime,dStartTime);
}

BOOL MOCTrigerSurgeGLStrategy::SurgeGL(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	MOCSurge *pJun = dynamic_cast<MOCSurge*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		dValue = pJun->GetGL();
		return TRUE;
	}
	return FALSE;
}