// MOCTrigerJunStaticDiffStrategy.h: interface for the MOCTrigerJunStaticDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERJUNSTATICDIFFSTRATEGY_H__795C2467_6984_4B16_8189_8A1810596C91__INCLUDED_)
#define AFX_MOCTRIGERJUNSTATICDIFFSTRATEGY_H__795C2467_6984_4B16_8189_8A1810596C91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerJunStaticDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerJunStaticDiffStrategy();
	virtual ~MOCTrigerJunStaticDiffStrategy();

private:
	static BOOL StaticDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERJUNSTATICDIFFSTRATEGY_H__795C2467_6984_4B16_8189_8A1810596C91__INCLUDED_)
