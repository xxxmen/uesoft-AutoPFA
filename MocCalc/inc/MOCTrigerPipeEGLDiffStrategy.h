// MOCTrigerPipeEGLDiffStrategy.h: interface for the MOCTrigerPipeEGLDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPEEGLDIFFSTRATEGY_H__35B6C299_903E_45A8_AA00_EAC575EA2288__INCLUDED_)
#define AFX_MOCTRIGERPIPEEGLDIFFSTRATEGY_H__35B6C299_903E_45A8_AA00_EAC575EA2288__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeEGLDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeEGLDiffStrategy();
	virtual ~MOCTrigerPipeEGLDiffStrategy();

private:
	static BOOL EGLDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPEEGLDIFFSTRATEGY_H__35B6C299_903E_45A8_AA00_EAC575EA2288__INCLUDED_)
