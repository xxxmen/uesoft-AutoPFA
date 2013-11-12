// MOCTrigerReliefStateStrategy.h: interface for the MOCTrigerReliefStateStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERRELIEFSTATESTRATEGY_H__14E889FF_F241_4767_B8F7_9008C3A6CA92__INCLUDED_)
#define AFX_MOCTRIGERRELIEFSTATESTRATEGY_H__14E889FF_F241_4767_B8F7_9008C3A6CA92__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerReliefStateStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerReliefStateStrategy();
	virtual ~MOCTrigerReliefStateStrategy();

};

#endif // !defined(AFX_MOCTRIGERRELIEFSTATESTRATEGY_H__14E889FF_F241_4767_B8F7_9008C3A6CA92__INCLUDED_)
