// MOCTrigerCheckStateStrategy.h: interface for the MOCTrigerCheckStateStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERCHECKSTATESTRATEGY_H__1FF41476_983B_47ED_946C_A4D3316155F6__INCLUDED_)
#define AFX_MOCTRIGERCHECKSTATESTRATEGY_H__1FF41476_983B_47ED_946C_A4D3316155F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerCheckStateStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerCheckStateStrategy();
	virtual ~MOCTrigerCheckStateStrategy();

};

#endif // !defined(AFX_MOCTRIGERCHECKSTATESTRATEGY_H__1FF41476_983B_47ED_946C_A4D3316155F6__INCLUDED_)
