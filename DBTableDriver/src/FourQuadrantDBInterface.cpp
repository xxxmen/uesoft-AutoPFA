// FourQuadrantDBInterface.cpp: implementation of the CFourQuadrantDBInterface class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FourQuadrantDBInterface.h"
#include "FourQuadrantDBManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFourQuadrantDBInterface::CFourQuadrantDBInterface()
{

}

CFourQuadrantDBInterface::~CFourQuadrantDBInterface()
{

}

BOOL CFourQuadrantDBInterface::GetFourQuadrantTable(CalcTable<2> &DBTable, CString ID)
{
	if (CFourQuadrantDBManager::Instance().QueryID(ID))
	{
		CFourQuadrantDBManager::Instance().GetFourQuadrantTable(DBTable, ID);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL CFourQuadrantDBInterface::GetSqecSpeedTable(CalcTable<2> &speedTable)
{
	speedTable.DelList();
	CFourQuadrantDBManager::Instance().GetSqecSpeedTable(speedTable);
	if (speedTable.GetCount() <= 0 )
	{
		return FALSE;
	}
	else
		return TRUE;
}

BOOL CFourQuadrantDBInterface::GetSpeedOfSqecID(CString &strSpeed, CString strID)
{
	return CFourQuadrantDBManager::Instance().GetSpeedOfSqecID(strSpeed, strID);
}

int CFourQuadrantDBInterface::GetAngelExpression(CString strID)
{
	return CFourQuadrantDBManager::Instance().GetAngelExpression(strID);
}
