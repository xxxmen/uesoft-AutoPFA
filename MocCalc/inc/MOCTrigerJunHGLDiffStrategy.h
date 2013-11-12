// MOCTrigerJunHGLDiffStrategy.h: interface for the MOCTrigerJunHGLDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERJUNHGLDIFFSTRATEGY_H__997DCE28_D92F_46F3_9DB3_BDD5BA1B7167__INCLUDED_)
#define AFX_MOCTRIGERJUNHGLDIFFSTRATEGY_H__997DCE28_D92F_46F3_9DB3_BDD5BA1B7167__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerJunHGLDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerJunHGLDiffStrategy();
	virtual ~MOCTrigerJunHGLDiffStrategy();
private:
	static BOOL HGLDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERJUNHGLDIFFSTRATEGY_H__997DCE28_D92F_46F3_9DB3_BDD5BA1B7167__INCLUDED_)
