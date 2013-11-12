// MOCTrigerPipeHGLStrategy.h: interface for the MOCTrigerPipeHGLStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPEHGLSTRATEGY_H__4C0EDEF1_C0C3_4C45_A42C_E88004D8992B__INCLUDED_)
#define AFX_MOCTRIGERPIPEHGLSTRATEGY_H__4C0EDEF1_C0C3_4C45_A42C_E88004D8992B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeHGLStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeHGLStrategy();
	virtual ~MOCTrigerPipeHGLStrategy();
private:
	static BOOL HGL(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPEHGLSTRATEGY_H__4C0EDEF1_C0C3_4C45_A42C_E88004D8992B__INCLUDED_)
