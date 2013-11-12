// MOCTrigerPipeStagStrategy.h: interface for the MOCTrigerPipeStagStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPESTAGSTRATEGY_H__C689A296_3DBD_4473_BBA1_79A4ADE3E77A__INCLUDED_)
#define AFX_MOCTRIGERPIPESTAGSTRATEGY_H__C689A296_3DBD_4473_BBA1_79A4ADE3E77A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeStagStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeStagStrategy();
	virtual ~MOCTrigerPipeStagStrategy();
private:
	static BOOL StagPress(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPESTAGSTRATEGY_H__C689A296_3DBD_4473_BBA1_79A4ADE3E77A__INCLUDED_)
