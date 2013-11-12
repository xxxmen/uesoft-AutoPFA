// ClipboardManage.cpp: implementation of the CClipboardManage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ClipboardManage.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CClipboardManage::CClipboardManage()
{

}

CClipboardManage::~CClipboardManage()
{

}

void CClipboardManage::CopyFromClipBoard(CalcTable<2> &DBTable)
{
	char * buffer = NULL;
	//´ò¿ª¼ôÌù°å
	CString fromClipboard;
	if ( OpenClipboard(NULL) )
	{
		HANDLE hData = GetClipboardData(CF_TEXT);
		char * buffer = (char*)GlobalLock(hData);
		fromClipboard = buffer;
		GlobalUnlock(hData);
		CloseClipboard();
	}
}

void CClipboardManage::SaveData(CString fromClipboard, CalcTable<2> &DBTable)
{
	int iStart = 0;
	int iFHNUM = 0;
	int iFBNUM = 0;
	int iData = 0;
	CString strFH;
	CString strFB;
	for (int i=0; fromClipboard[i]; i++)
	{
		if (!IsNumOrLetter(fromClipboard[i]))
		{
			iData++;
			if (0 != iData%2)
			{
				strFH = fromClipboard.Mid(iStart, i);
				strFH.SetAt(i, _T('\0'));
				iStart = i+1;
			}
			else
			{
				strFB = fromClipboard.Mid(iStart, i);
				strFB.SetAt(i, _T('\0'));
				iStart = i+1;
				SaveFBAndFH(strFH, strFB, DBTable);
			}
		}
	}
}


BOOL CClipboardManage::IsNumOrLetter(char cchar)
{
	if (_T('0')<=cchar && cchar<=_T('9') || (_T('a')<=cchar && cchar<=_T('z')) || (_T('A')<=cchar && cchar<=_T('Z')))
	{
		return TRUE;
	}
	else
		return FALSE;
}

void CClipboardManage::SaveFBAndFH(CString strFH, CString strFB, CalcTable<2> &DBTable)
{
	StrArray<2> strArray;

	strArray.Data(strFH, 0);
	strArray.Data(strFH, 1);
	DBTable.AddItem(strArray);
}

void CClipboardManage::SaveToClipboard(CalcTable<2> &DBTable)
{
	CString strSource;

	ReadDBTable(strSource, DBTable);
	if(OpenClipboard(NULL))
	{
		HGLOBAL clipbuffer;
		TCHAR * buffer;
		
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, strSource.GetLength()+1);
		buffer = (TCHAR*)GlobalLock(clipbuffer);
		_tcscpy(buffer, strSource);
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT,clipbuffer);
		CloseClipboard();
	}
	
}

void CClipboardManage::ReadDBTable(CString &strDBTable, CalcTable<2> &DBTable)
{
	strDBTable.Empty();

	IteratorPtr<StrArray<2> > DBPtr(DBTable.CreatIterator());		
	for(DBPtr->Fist();!DBPtr->IsDone();DBPtr->Next())
	{
		strDBTable += DBPtr->CurrentItem().Data(0);
		strDBTable += _T(",");
		strDBTable += DBPtr->CurrentItem().Data(1);
		strDBTable +=_T("\n");
	}
}
