// MOCTrigerStrategy.cpp: implementation of the MOCTrigerStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerStrategy::MOCTrigerStrategy()
{

}

MOCTrigerStrategy::~MOCTrigerStrategy()
{

}

BOOL MOCTrigerStrategy::Triger(PFUNVALUE pFun,MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	double dTrigerValue = mgr.Value();
	int nType = mgr.ConditionType();
	double dValue =0;
	if(pFun(mgr,dValue))
	{
		if(nType==0||nType==1)
		{
			if(dValue>=dTrigerValue)
			{
				mgr.TrigerTime(dCurTime);
				return TRUE;
			}
		}
		if(nType==3||nType==4)
		{
			if(dValue<=dTrigerValue)
			{
				mgr.TrigerTime(dCurTime);
				return TRUE;
			}
		}
	}
	return FALSE;
}

BOOL MOCTrigerStrategy::TimeTriger(PFUNTIME pFun,MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	double dTrigerTime = mgr.Value();
	int nType = mgr.ConditionType();
	double dValue = pFun(dCurTime,dStartTime);
	if(nType==0||nType==1||nType==2)
	{
		if(dValue>=dTrigerTime)
		{
			mgr.TrigerTime(dTrigerTime);
			return TRUE;
		}
	}
	if(nType==3||nType==4)
	{
		if(dValue<=dTrigerTime)
		{
			mgr.TrigerTime(dTrigerTime);
			return TRUE;
		}
	}
	return FALSE;
}