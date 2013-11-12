// ILossCalcStrategy.h: interface for the ILossCalcStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ILOSSCALCSTRATEGY_H__94022883_CD9B_424F_88CD_2D6F5790FE5A__INCLUDED_)
#define AFX_ILOSSCALCSTRATEGY_H__94022883_CD9B_424F_88CD_2D6F5790FE5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "AreaChangeLossCalc.h"
class ILossCalcStrategy  
{
public:
	virtual double CalcK(const AreaChangeLossCalc &ref)=0;
	ILossCalcStrategy();
	virtual ~ILossCalcStrategy();

};

#endif // !defined(AFX_ILOSSCALCSTRATEGY_H__94022883_CD9B_424F_88CD_2D6F5790FE5A__INCLUDED_)
