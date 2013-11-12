// InputToFile.cpp: implementation of the CInputToFile class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "InputToFile.h"
#include <fstream>

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CInputToFile::CInputToFile()
{

}

CInputToFile::~CInputToFile()
{

}
void CInputToFile::GetFilePath()
{
	CFileDialog fileDlg(FALSE);
	fileDlg.m_ofn.lpstrTitle=_T("AutoPFA File");
	fileDlg.m_ofn.lpstrFilter=_T("Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0\0");
	if (IDOK == fileDlg.DoModal())
	{
		m_strFilePath = fileDlg.GetPathName();
	}
}

void CInputToFile::SetDAtaToFile(CalcTable<2> &DBTable)
{
	CString strBuffer;
    ofstream ofFile(m_strFilePath);
	
	GetFilePath();
    StrArray<2> temp;
	IteratorPtr<StrArray<2> > DBPtr(DBTable.CreatIterator());
	for(DBPtr->Fist();!DBPtr->IsDone();DBPtr->Next())
	{
		temp = DBPtr->CurrentItem();
		strBuffer = temp.Data(0);
		ofFile<<strBuffer<<_T(",");
		strBuffer = temp.Data(1);
		ofFile<<strBuffer<<endl;
	}	
}
