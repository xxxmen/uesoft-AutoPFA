// MOCTrigerPipeMassStrategy.h: interface for the MOCTrigerPipeMassStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOCTRIGERPIPEMASSSTRATEGY_H__C9847D18_E7F3_4D26_B8E8_64CDF17E5107__INCLUDED_)
#define AFX_MOCTRIGERPIPEMASSSTRATEGY_H__C9847D18_E7F3_4D26_B8E8_64CDF17E5107__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "MOCTrigerStrategy.h"

class MOCTrigerPipeMassStrategy : public MOCTrigerStrategy  
{
public:
	virtual BOOL IsTriger(MOCTrigerStrategyMgr &mgr,double dCurTime,double dStartTime);
	static MOCTrigerStrategy* Creator();
	MOCTrigerPipeMassStrategy();
	virtual ~MOCTrigerPipeMassStrategy();
private:
	static BOOL EndMass(MOCTrigerStrategyMgr &mgr,double &dValue);
};

#endif // !defined(AFX_MOCTRIGERPIPEMASSSTRATEGY_H__C9847D18_E7F3_4D26_B8E8_64CDF17E5107__INCLUDED_)
