// MOCTrigerPipeStaticDiffStrategy.h: interface for the MOCTrigerPipeStaticDiffStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPESTATICDIFFSTRATEGY_H__CE7822D7_0871_4833_86C8_FEA640D6FF9E__INCLUDED_)
#define AFX_MOCTRIGERPIPESTATICDIFFSTRATEGY_H__CE7822D7_0871_4833_86C8_FEA640D6FF9E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeStaticDiffStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeStaticDiffStrategy();
	virtual ~MOCTrigerPipeStaticDiffStrategy();
private:
	static BOOL StaticDiff(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPESTATICDIFFSTRATEGY_H__CE7822D7_0871_4833_86C8_FEA640D6FF9E__INCLUDED_)
