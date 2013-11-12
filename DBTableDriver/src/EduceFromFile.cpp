// EduceFromFile.cpp: implementation of the CEduceFromFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "EduceFromFile.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CEduceFromFile::CEduceFromFile()
{

}

CEduceFromFile::~CEduceFromFile()
{

}

BOOL CEduceFromFile::ReadFile(CalcTable<2> &DBTable)
{
	char buffer[50] = {0};
	ifstream file((LPCTSTR)m_strFilePath);

	GetFilePath();
	file.getline(buffer, 50);
	while (file.getline(buffer, 50))
	{
		CString strFront;
		CString strBack;
		CString strSource = buffer;
		StrArray<2> strArray;
		
		SlipeString(strFront, strBack, buffer);
		strArray.Data(strFront, 0);
		strArray.Data(strBack, 1);
		DBTable.AddItem(strArray);
	}
	return TRUE;
}

void CEduceFromFile::GetFilePath()
{
	CFileDialog fileDlg(TRUE);

	fileDlg.m_ofn.lpstrTitle=_T("AutoPFA File");
	fileDlg.m_ofn.lpstrFilter=_T("Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0");
	if (IDOK == fileDlg.DoModal())
	{
		m_strFilePath = fileDlg.GetPathName();
	}
}

void CEduceFromFile::SlipeString(CString &strFront, CString &strBack, CString strSource)
{
	int iPos = strSource.Find(_T(","));
	
	if (iPos > 0)
	{
		strFront = strSource.Mid(0, iPos);
		strBack = strSource.Mid(iPos + 1, strSource.GetLength());
	}
}
