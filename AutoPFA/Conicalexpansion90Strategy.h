// Conicalexpansion90Strategy.h: interface for the Conicalexpansion90Strategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONICALEXPANSION90STRATEGY_H__4D9D8D33_8449_40A3_9058_01653BF3AFB0__INCLUDED_)
#define AFX_CONICALEXPANSION90STRATEGY_H__4D9D8D33_8449_40A3_9058_01653BF3AFB0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ILossCalcStrategy.h"

class Conicalexpansion90Strategy : public ILossCalcStrategy  
{
public:
	double CalcK(const AreaChangeLossCalc &ref);
	static ILossCalcStrategy* Creator();
	Conicalexpansion90Strategy();
	virtual ~Conicalexpansion90Strategy();

};

#endif // !defined(AFX_CONICALEXPANSION90STRATEGY_H__4D9D8D33_8449_40A3_9058_01653BF3AFB0__INCLUDED_)
