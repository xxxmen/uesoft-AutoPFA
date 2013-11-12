// AbruptExpansionStrategy.h: interface for the AbruptExpansionStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ABRUPTEXPANSIONSTRATEGY_H__549738F7_5F69_4DA6_AD7F_0026B13EAB96__INCLUDED_)
#define AFX_ABRUPTEXPANSIONSTRATEGY_H__549738F7_5F69_4DA6_AD7F_0026B13EAB96__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ILossCalcStrategy.h"

class AbruptExpansionStrategy : public ILossCalcStrategy  
{
public:
	double CalcK(const AreaChangeLossCalc &ref);
	static ILossCalcStrategy* Creator();
	AbruptExpansionStrategy();
	virtual ~AbruptExpansionStrategy();

};

#endif // !defined(AFX_ABRUPTEXPANSIONSTRATEGY_H__549738F7_5F69_4DA6_AD7F_0026B13EAB96__INCLUDED_)
