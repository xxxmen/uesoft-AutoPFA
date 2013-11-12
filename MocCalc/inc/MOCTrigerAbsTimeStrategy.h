// MOCTrigerAbsTimeStrategy.h: interface for the MOCTrigerAbsTimeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERABSTIMESTRATEGY_H__5CEAFC7D_0B9B_424A_80D4_A0981BD38A63__INCLUDED_)
#define AFX_MOCTRIGERABSTIMESTRATEGY_H__5CEAFC7D_0B9B_424A_80D4_A0981BD38A63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "MOCTrigerStrategy.h"

class MOCTrigerAbsTimeStrategy : public  MOCTrigerStrategy  
{
public:
	static MOCTrigerStrategy* Creator();
	MOCTrigerAbsTimeStrategy();
	virtual ~MOCTrigerAbsTimeStrategy();

public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	
private:
	static double AbsTime(double dCurTime,double dStartTime);
};

#endif // !defined(AFX_MOCTRIGERABSTIMESTRATEGY_H__5CEAFC7D_0B9B_424A_80D4_A0981BD38A63__INCLUDED_)
