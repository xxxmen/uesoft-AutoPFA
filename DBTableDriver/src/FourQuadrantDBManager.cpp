// FourQuadrantDBManager.cpp: implementation of the CFourQuadrantDBManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "FourQuadrantDBManager.h"
#include "ListFlyWeightImp.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const CString CFourQuadrantDBManager::strTableDBBegin = _T( "TABLEDB_BEGIN" );
const CString CFourQuadrantDBManager::strTableDBEnd = _T( "TABLEDB_END" );

CFourQuadrantDBManager::CFourQuadrantDBManager()
{
	Init();	
}

CFourQuadrantDBManager::~CFourQuadrantDBManager()
{
	
}
CFourQuadrantDBManager& CFourQuadrantDBManager::Instance()
{
	static CFourQuadrantDBManager mg;
	return mg;
}

void CFourQuadrantDBManager::Init()
{
	TCHAR exeFullPath[MAX_PATH];
	::GetModuleFileName(NULL,exeFullPath,MAX_PATH);
	CString strPath(exeFullPath);
	int index = strPath.ReverseFind(_T('\\'));
	ASSERT(index != -1);
	strPath = strPath.Left(index+1);
	strPath += _T("FourQuadrantData.txt");
	m_configFilePath = strPath;
}

void CFourQuadrantDBManager::GetSqecSpeedTable(CalcTable<2> &speedTable)
{
	TCHAR buffer[50] = {0};	
	ueifStream file(m_configFilePath);

	while (file.getline(buffer, 50))
	{
		if (strTableDBBegin.Compare(buffer) == 0)
		{
			GetSqecSpeed(speedTable, file, buffer);
		}		
	}
}

void CFourQuadrantDBManager::GetSqecSpeed(CalcTable<2> &speedTable, ueifStream &file, TCHAR *buffer)
{
	StrArray<2> strArray;

	file.getline(buffer, 50);
	strArray.Data(buffer, 0);
	file.getline(buffer, 50);
	file.getline(buffer, 50);
	strArray.Data(buffer, 1);
	speedTable.AddItem(strArray);
}

BOOL CFourQuadrantDBManager::QueryID(CString &ID)
{
	TCHAR buffer[50] = {0};
	ueifStream file((LPCTSTR)m_configFilePath);

	while (file.getline(buffer, 50))
	{
		if (ID.Compare(buffer) == 0)
		{
			return TRUE;
		}
	}

	return FALSE;
}

void CFourQuadrantDBManager::GetFourQuadrantTable(CalcTable<2> &DBTable, CString ID)
{
	TCHAR buffer[50] = {0};
	ueifStream file((LPCTSTR)m_configFilePath);

	while (file.getline(buffer, 50))
	{
		if (ID.Compare(buffer) == 0)
		{
			GetFourQuadrantDB(DBTable, buffer, file);
			break;
		}
	}
}

void CFourQuadrantDBManager::GetFourQuadrantDB(CalcTable<2> &DBTable, TCHAR *buffer, ueifStream &file)
{
	int i = 0;
	file.getline(buffer, 50);
	file.getline(buffer, 50);
	while (file.getline(buffer, 50))
	{
		CString strFront;
		CString strBack;
		CString strSource = buffer;
		StrArray<2> strArray;

		if (strTableDBEnd.Compare(strSource) == 0)
		{
			i;
			break;
		}
		else
		{
			SlipeString(strFront, strBack, buffer);
			strArray.Data(strFront, 0);
			strArray.Data(strBack, 1);
			DBTable.AddItem(strArray);
			i++;
		}
	}	
}

void CFourQuadrantDBManager::SlipeString(CString &strFront, CString &strBack, CString strSource)
{
	int iPos = strSource.Find(_T(","));
	
	if (iPos > 0)
	{
		strFront = strSource.Mid(0, iPos);
		strBack = strSource.Mid(iPos + 1, strSource.GetLength());
	}
}
BOOL CFourQuadrantDBManager::GetSpeedOfSqecID(CString &strSpeed, CString strID)
{
	TCHAR buffer[50] = {0};
	ueifStream file((LPCTSTR)m_configFilePath);

	while (file.getline(buffer, 50))
	{
		if (strID.Compare(buffer) == 0)
		{
			file.getline(buffer, 50);
			strSpeed = buffer;
			return TRUE;
		}
	}
	return FALSE;
}
int CFourQuadrantDBManager::GetAngelExpression(CString strID)
{
	TCHAR buffer[50] = {0};
	ueifStream file((LPCTSTR)m_configFilePath);

	while (file.getline(buffer, 50))
	{
		if (strID.Compare(buffer) == 0)
		{
			file.getline(buffer, 50);
			
			CString strSpeedExpression = buffer;
			if (strSpeedExpression.Compare(_T("SECOND")) == 0)
			{
				return 1;
			}
			break;
		}
	}
	return 0;
}