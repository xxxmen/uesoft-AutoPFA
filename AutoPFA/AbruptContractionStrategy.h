// AbruptContractionStrategy.h: interface for the AbruptContractionStrategy class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ABRUPTCONTRACTIONSTRATEGY_H__2B97403C_0F57_48ED_8580_9CD05944DD01__INCLUDED_)
#define AFX_ABRUPTCONTRACTIONSTRATEGY_H__2B97403C_0F57_48ED_8580_9CD05944DD01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ILossCalcStrategy.h"

class AbruptContractionStrategy : public ILossCalcStrategy  
{
public:
	double CalcK(const AreaChangeLossCalc &ref);
	static ILossCalcStrategy* Creator();
	AbruptContractionStrategy();
	virtual ~AbruptContractionStrategy();

};

#endif // !defined(AFX_ABRUPTCONTRACTIONSTRATEGY_H__2B97403C_0F57_48ED_8580_9CD05944DD01__INCLUDED_)
