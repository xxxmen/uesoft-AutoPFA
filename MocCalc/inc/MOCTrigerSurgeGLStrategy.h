// MOCTrigerSurgeGLStrategy.h: interface for the MOCTrigerSurgeGLStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERSURGEGLSTRATEGY_H__7EB63D24_AEDE_4647_9834_8CDC82F41570__INCLUDED_)
#define AFX_MOCTRIGERSURGEGLSTRATEGY_H__7EB63D24_AEDE_4647_9834_8CDC82F41570__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerSurgeGLStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerSurgeGLStrategy();
	virtual ~MOCTrigerSurgeGLStrategy();
private:
	static BOOL SurgeGL(MOCTrigerStrategyMgr &mgr,double &dValue);

};

#endif // !defined(AFX_MOCTRIGERSURGEGLSTRATEGY_H__7EB63D24_AEDE_4647_9834_8CDC82F41570__INCLUDED_)
