// ConicalContraction90Strategy.h: interface for the ConicalContraction90Strategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONICALCONTRACTION90STRATEGY_H__41D74D4B_1750_4F8A_828E_8F51D5AE76EF__INCLUDED_)
#define AFX_CONICALCONTRACTION90STRATEGY_H__41D74D4B_1750_4F8A_828E_8F51D5AE76EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ILossCalcStrategy.h"

class ConicalContraction90Strategy : public ILossCalcStrategy  
{
public:
	double CalcK(const AreaChangeLossCalc &ref);
	static ILossCalcStrategy* Creator();
	ConicalContraction90Strategy();
	virtual ~ConicalContraction90Strategy();

};

#endif // !defined(AFX_CONICALCONTRACTION90STRATEGY_H__41D74D4B_1750_4F8A_828E_8F51D5AE76EF__INCLUDED_)
