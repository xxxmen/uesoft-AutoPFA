// MOCTrigerJunEGLDiffStrategy.h: interface for the MOCTrigerJunEGLDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERJUNEGLDIFFSTRATEGY_H__46B3DE03_E7E8_4B5E_AB14_B9EA1277EFA1__INCLUDED_)
#define AFX_MOCTRIGERJUNEGLDIFFSTRATEGY_H__46B3DE03_E7E8_4B5E_AB14_B9EA1277EFA1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerJunEGLDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerJunEGLDiffStrategy();
	virtual ~MOCTrigerJunEGLDiffStrategy();
private:
	static BOOL EGLDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERJUNEGLDIFFSTRATEGY_H__46B3DE03_E7E8_4B5E_AB14_B9EA1277EFA1__INCLUDED_)
