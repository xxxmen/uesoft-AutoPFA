// ClipboardManage.h: interface for the CClipboardManage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIPBOARDMANAGE_H__9F8B0C23_BC28_4409_BEA9_19345A9200EC__INCLUDED_)
#define AFX_CLIPBOARDMANAGE_H__9F8B0C23_BC28_4409_BEA9_19345A9200EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CClipboardManage  
{
public:
	void SaveToClipboard(CalcTable<2> &DBTable);
	void CopyFromClipBoard(CalcTable<2> &DBTable);
	CClipboardManage();
	virtual ~CClipboardManage();

private:
	void ReadDBTable(CString &strDBTable, CalcTable<2> &DBTable);
	void SaveFBAndFH(CString strFH, CString strFB, CalcTable<2> &DBTable);
	BOOL IsNumOrLetter(char cchar);
	void SaveData(CString fromClipboard,CalcTable<2> &DBTable);
};

#endif // !defined(AFX_CLIPBOARDMANAGE_H__9F8B0C23_BC28_4409_BEA9_19345A9200EC__INCLUDED_)
