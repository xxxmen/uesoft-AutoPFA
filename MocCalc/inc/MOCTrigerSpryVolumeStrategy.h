// MOCTrigerSpryVolumeStrategy.h: interface for the MOCTrigerSpryVolumeStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERSPRYVOLUMESTRATEGY_H__CA5D03F9_1212_47B5_86C7_02916FD9BDAA__INCLUDED_)
#define AFX_MOCTRIGERSPRYVOLUMESTRATEGY_H__CA5D03F9_1212_47B5_86C7_02916FD9BDAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerSpryVolumeStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerSpryVolumeStrategy();
	virtual ~MOCTrigerSpryVolumeStrategy();

private:
	static BOOL SpryOutFlow(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERSPRYVOLUMESTRATEGY_H__CA5D03F9_1212_47B5_86C7_02916FD9BDAA__INCLUDED_)
