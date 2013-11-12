// MOCTrigerRelTimeStrategy.h: interface for the MOCTrigerRelTimeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERRELTIMESTRATEGY_H__88672155_E181_4880_9F70_E08D874F5E57__INCLUDED_)
#define AFX_MOCTRIGERRELTIMESTRATEGY_H__88672155_E181_4880_9F70_E08D874F5E57__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerRelTimeStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerRelTimeStrategy();
	virtual ~MOCTrigerRelTimeStrategy();

private:
	static double RelTime(double dCurTime,double dStartTime);

};

#endif // !defined(AFX_MOCTRIGERRELTIMESTRATEGY_H__88672155_E181_4880_9F70_E08D874F5E57__INCLUDED_)
