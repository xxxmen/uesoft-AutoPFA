// MOCTrigerJunStagDiffStrategy.h: interface for the MOCTrigerJunStagDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERJUNSTAGDIFFSTRATEGY_H__D7EAF393_9D8A_4E1B_B061_F0B4BEA437B5__INCLUDED_)
#define AFX_MOCTRIGERJUNSTAGDIFFSTRATEGY_H__D7EAF393_9D8A_4E1B_B061_F0B4BEA437B5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerJunStagDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerJunStagDiffStrategy();
	virtual ~MOCTrigerJunStagDiffStrategy();
private:
	static BOOL StagDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERJUNSTAGDIFFSTRATEGY_H__D7EAF393_9D8A_4E1B_B061_F0B4BEA437B5__INCLUDED_)
