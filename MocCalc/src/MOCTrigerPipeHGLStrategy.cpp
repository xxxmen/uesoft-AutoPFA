// MOCTrigerPipeHGLStrategy.cpp: implementation of the MOCTrigerPipeHGLStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerPipeHGLStrategy.h"
#include "MOCPipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerPipeHGLStrategy::MOCTrigerPipeHGLStrategy()
{

}

MOCTrigerPipeHGLStrategy::~MOCTrigerPipeHGLStrategy()
{

}

MOCTrigerStrategy* MOCTrigerPipeHGLStrategy::Creator()
{
	static MOCTrigerPipeHGLStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerPipeHGLStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	return Triger(HGL,mgr,dCurTime,dStartTime);;
}

BOOL MOCTrigerPipeHGLStrategy::HGL(MOCTrigerStrategyMgr &mgr,double &dValue)
{
	int nKey = mgr.ComponentID1();
	int nPort = mgr.Port1();//1：入口2：出口
	MOCPipe *pPipe = dynamic_cast<MOCPipe*>(mgr.LookUpPipe(nKey));
	if(pPipe != NULL)
	{
		if(nPort==1)
		{
			dValue = pPipe->GetInEnd()->GetHGL();
		}
		else
		{
			dValue = pPipe->GetOutEnd()->GetHGL();
		}
		return TRUE;
	}
	return FALSE;
}
