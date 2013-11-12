// MOCTrigerPipeEGLStrategy.h: interface for the MOCTrigerPipeEGLStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPEEGLSTRATEGY_H__F6BD5AA4_71F3_451E_B02C_B723087ED422__INCLUDED_)
#define AFX_MOCTRIGERPIPEEGLSTRATEGY_H__F6BD5AA4_71F3_451E_B02C_B723087ED422__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeEGLStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeEGLStrategy();
	virtual ~MOCTrigerPipeEGLStrategy();

private:
	static BOOL EGL(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPEEGLSTRATEGY_H__F6BD5AA4_71F3_451E_B02C_B723087ED422__INCLUDED_)
