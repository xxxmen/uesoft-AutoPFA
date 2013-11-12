// MOCTrigerControlStateStrategy.h: interface for the MOCTrigerControlStateStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERCONTROLSTATESTRATEGY_H__E62ABA00_7D60_4FBB_BE48_D7C7F1E6F79F__INCLUDED_)
#define AFX_MOCTRIGERCONTROLSTATESTRATEGY_H__E62ABA00_7D60_4FBB_BE48_D7C7F1E6F79F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerControlStateStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerControlStateStrategy();
	virtual ~MOCTrigerControlStateStrategy();

};

#endif // !defined(AFX_MOCTRIGERCONTROLSTATESTRATEGY_H__E62ABA00_7D60_4FBB_BE48_D7C7F1E6F79F__INCLUDED_)
