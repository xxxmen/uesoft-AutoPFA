// ConicalContraction45Strategy.h: interface for the ConicalContraction45Strategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONICALCONTRACTION45STRATEGY_H__A10EB6EC_385B_4684_BE62_35E5EC2EAF74__INCLUDED_)
#define AFX_CONICALCONTRACTION45STRATEGY_H__A10EB6EC_385B_4684_BE62_35E5EC2EAF74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ILossCalcStrategy.h"

class ConicalContraction45Strategy : public ILossCalcStrategy  
{
public:
	double CalcK(const AreaChangeLossCalc &ref);
	static ILossCalcStrategy* Creator();
	ConicalContraction45Strategy();
	virtual ~ConicalContraction45Strategy();

};

#endif // !defined(AFX_CONICALCONTRACTION45STRATEGY_H__A10EB6EC_385B_4684_BE62_35E5EC2EAF74__INCLUDED_)
