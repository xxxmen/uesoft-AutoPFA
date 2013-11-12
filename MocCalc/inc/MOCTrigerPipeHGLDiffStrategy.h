// MOCTrigerPipeHGLDiffStrategy.h: interface for the MOCTrigerPipeHGLDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPEHGLDIFFSTRATEGY_H__57BBDB11_8E85_4B0D_8E57_63FDD609A0EF__INCLUDED_)
#define AFX_MOCTRIGERPIPEHGLDIFFSTRATEGY_H__57BBDB11_8E85_4B0D_8E57_63FDD609A0EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeHGLDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeHGLDiffStrategy();
	virtual ~MOCTrigerPipeHGLDiffStrategy();
private:
	static BOOL HGLDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPEHGLDIFFSTRATEGY_H__57BBDB11_8E85_4B0D_8E57_63FDD609A0EF__INCLUDED_)
