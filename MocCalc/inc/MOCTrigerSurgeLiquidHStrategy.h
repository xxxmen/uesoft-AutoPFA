// MOCTrigerSurgeLiquidHStrategy.h: interface for the MOCTrigerSurgeLiquidHStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERSURGELIQUIDHSTRATEGY_H__C1E590E0_A81D_456D_92D0_34EEE543EFD3__INCLUDED_)
#define AFX_MOCTRIGERSURGELIQUIDHSTRATEGY_H__C1E590E0_A81D_456D_92D0_34EEE543EFD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerSurgeLiquidHStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerSurgeLiquidHStrategy();
	virtual ~MOCTrigerSurgeLiquidHStrategy();
private:
	static BOOL LiquidH(MOCTrigerStrategyMgr &mgr,double &dValue);

};

#endif // !defined(AFX_MOCTRIGERSURGELIQUIDHSTRATEGY_H__C1E590E0_A81D_456D_92D0_34EEE543EFD3__INCLUDED_)
