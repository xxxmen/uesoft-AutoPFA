// MOCTrigerPipeStagDiffStrategy.h: interface for the MOCTrigerPipeStagDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPESTAGDIFFSTRATEGY_H__B8620E62_3D66_4A30_9710_F0290C163EB2__INCLUDED_)
#define AFX_MOCTRIGERPIPESTAGDIFFSTRATEGY_H__B8620E62_3D66_4A30_9710_F0290C163EB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeStagDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeStagDiffStrategy();
	virtual ~MOCTrigerPipeStagDiffStrategy();
private:
	static BOOL StagDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPESTAGDIFFSTRATEGY_H__B8620E62_3D66_4A30_9710_F0290C163EB2__INCLUDED_)
