// MOCTrigerStrategy.h: interface for the MOCTrigerStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERSTRATEGY_H__7BB3A7CD_74CA_4608_A761_6B12BCDD4F30__INCLUDED_)
#define AFX_MOCTRIGERSTRATEGY_H__7BB3A7CD_74CA_4608_A761_6B12BCDD4F30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCTrigerStrategyMgr.h"
class MOCTrigerStrategyMgr;

typedef BOOL(*PFUNVALUE)(MOCTrigerStrategyMgr&,double&);
typedef double(*PFUNTIME)(double,double);

class MOCTrigerStrategy  
{
public:
	MOCTrigerStrategy();
	virtual ~MOCTrigerStrategy();
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime)=0;

protected:
	BOOL Triger(PFUNVALUE pFun,MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime);
	BOOL TimeTriger(PFUNTIME pFun,MOCTrigerStrategyMgr &mgr, double dCurTime, double dStartTime);
};

#endif // !defined(AFX_MOCTRIGERSTRATEGY_H__7BB3A7CD_74CA_4608_A761_6B12BCDD4F30__INCLUDED_)
