// MOCTrigerSpeedStrategy.h: interface for the MOCTrigerSpeedStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERSPEEDSTRATEGY_H__04267B92_E542_46C8_8ECD_B5B4CD0D6178__INCLUDED_)
#define AFX_MOCTRIGERSPEEDSTRATEGY_H__04267B92_E542_46C8_8ECD_B5B4CD0D6178__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerSpeedStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerSpeedStrategy();
	virtual ~MOCTrigerSpeedStrategy();

private:
	static BOOL PumpSpeed(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERSPEEDSTRATEGY_H__04267B92_E542_46C8_8ECD_B5B4CD0D6178__INCLUDED_)
