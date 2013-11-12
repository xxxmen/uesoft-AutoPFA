// ConicalExpansionStrategy.h: interface for the ConicalExpansion45Strategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONICALEXPANSIONSTRATEGY_H__EE99090F_9D55_4B1D_AA27_C583BBDA9C93__INCLUDED_)
#define AFX_CONICALEXPANSIONSTRATEGY_H__EE99090F_9D55_4B1D_AA27_C583BBDA9C93__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ILossCalcStrategy.h"

class ConicalExpansion45Strategy : public ILossCalcStrategy  
{
public:
	double CalcK(const AreaChangeLossCalc &ref);
	static ILossCalcStrategy* Creator();
	ConicalExpansion45Strategy();
	virtual ~ConicalExpansion45Strategy();

};

#endif // !defined(AFX_CONICALEXPANSIONSTRATEGY_H__EE99090F_9D55_4B1D_AA27_C583BBDA9C93__INCLUDED_)
