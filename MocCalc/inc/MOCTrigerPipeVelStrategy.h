// MOCTrigerPipeVelStrategy.h: interface for the MOCTrigerPipeVelStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPEVELSTRATEGY_H__D0D8DC2B_0E93_4920_9CAB_10D2DA2C50ED__INCLUDED_)
#define AFX_MOCTRIGERPIPEVELSTRATEGY_H__D0D8DC2B_0E93_4920_9CAB_10D2DA2C50ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeVelStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeVelStrategy();
	virtual ~MOCTrigerPipeVelStrategy();
private:
	static BOOL EndVelocity(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPEVELSTRATEGY_H__D0D8DC2B_0E93_4920_9CAB_10D2DA2C50ED__INCLUDED_)
