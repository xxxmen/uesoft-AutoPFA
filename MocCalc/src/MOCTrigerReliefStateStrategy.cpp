// MOCTrigerReliefStateStrategy.cpp: implementation of the MOCTrigerReliefStateStrategy class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTrigerReliefStateStrategy.h"
#include "MOCRelief.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTrigerReliefStateStrategy::MOCTrigerReliefStateStrategy()
{

}

MOCTrigerReliefStateStrategy::~MOCTrigerReliefStateStrategy()
{

}

MOCTrigerStrategy* MOCTrigerReliefStateStrategy::Creator()
{
	static MOCTrigerReliefStateStrategy strategy;
	return &strategy;
}

BOOL MOCTrigerReliefStateStrategy::IsTriger(MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime)
{
	int nType = mgr.ConditionType();
	int nKey = mgr.ComponentID1();
	MOCRelief *pJun = dynamic_cast<MOCRelief*>(mgr.LookUpJun(nKey));
	if(pJun != NULL)
	{
		if(pJun->ReliefStatus() == nType)
		{
			mgr.TrigerTime(dCurTime);
			if(!mgr.HasTranData())
			{
				if(3==nType)//开始打开
				{
					pJun->Crack(TRUE);
				}
				if(4==nType)//开始关闭
				{
					pJun->Crack(FALSE);
				}
			}
			return TRUE;
		}
	}
	return FALSE;
}
