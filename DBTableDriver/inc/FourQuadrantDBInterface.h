// FourQuadrantDBInterface.h: interface for the CFourQuadrantDBInterface class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FOURQUADRANTDBINTERFACE_H__072379BB_BD24_4921_8365_ECE28F1F66D4__INCLUDED_)
#define AFX_FOURQUADRANTDBINTERFACE_H__072379BB_BD24_4921_8365_ECE28F1F66D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "CalcTable.h"

class AFX_EXT_CLASS CFourQuadrantDBInterface  
{
public:
	int GetAngelExpression(CString strID);
	BOOL GetSpeedOfSqecID(CString &strSpeed, CString strID);
	BOOL GetSqecSpeedTable(CalcTable<2> &speedTable);
	BOOL GetFourQuadrantTable(CalcTable<2> &DBTable, CString ID);
	CFourQuadrantDBInterface();
	virtual ~CFourQuadrantDBInterface();
};

#endif // !defined(AFX_FOURQUADRANTDBINTERFACE_H__072379BB_BD24_4921_8365_ECE28F1F66D4__INCLUDED_)
