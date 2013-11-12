// MOCTrigerPipeEGLStrategy.cpp: implementation of the MOCTrigerPipeEGLStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeEGLStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeEGLStrategy::MOCTrigerPipeEGLStrategy()
{

}

MOCTrigerPipeEGLStrategy::~MOCTrigerPipeEGLStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeEGLStrategy::Creator()
{
	static MOCTrigerPipeEGLStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeEGLStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(EGL,mgr,dCurTime,dStartTime);;
}

BOOL MOCTrigerPipeEGLStrategy::EGL(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	int nPort = mgr.Port1();//1：入口2：出口
	MOCPipe *pPipe = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey));
	if(pPipe != NULL)
	{
		if(nPort==1)
		{
			dValue = pPipe->GetInEnd()->GetEGL();
		}
		else
		{
			dValue = pPipe->GetOutEnd()->GetEGL();
		}
		return TRUE;
	}
	return FALSE;
}