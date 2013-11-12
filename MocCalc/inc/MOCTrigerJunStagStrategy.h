// MOCTrigerJunStagStrategy.h: interface for the MOCTrigerJunStagStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERJUNSTAGSTRATEGY_H__F3FDD9C7_D4E1_4E59_AE8B_EC91251E6198__INCLUDED_)
#define AFX_MOCTRIGERJUNSTAGSTRATEGY_H__F3FDD9C7_D4E1_4E59_AE8B_EC91251E6198__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerJunStagStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerJunStagStrategy();
	virtual ~MOCTrigerJunStagStrategy();
private:
	static BOOL StagPress(MOCTrigerStrategyMgr &mgr,double &dValue);

};

#endif // !defined(AFX_MOCTRIGERJUNSTAGSTRATEGY_H__F3FDD9C7_D4E1_4E59_AE8B_EC91251E6198__INCLUDED_)
