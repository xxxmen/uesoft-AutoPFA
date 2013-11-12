#if !defined(AFX_DLGRAWDATATABLE_H__82810270_2935_4F29_84B7_1A7A28E43842__INCLUDED_)
#define AFX_DLGRAWDATATABLE_H__82810270_2935_4F29_84B7_1A7A28E43842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRawDataTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgRawDataTable dialog
#include "GridCtrl.h"
#include "TransDataTable.h"
class DlgRawDataTable : public CDialog
{
// Construction
public:

	void SetDataNum(int nNum);
	void TableStatus(int nColWidth = 65,int nColHeight = 40);
	void SetHeader(CString strName,CString strUnit,int nCol);
	void SetUnit(CString strUnit,int nCol);
	void InsertColumn(CString strName,CString strUnit);
	DlgRawDataTable(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgRawDataTable)
	enum { IDD = IDD_RAWDATATABLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgRawDataTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CGridCtrl m_table;
	// Generated message map functions
	//{{AFX_MSG(DlgRawDataTable)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString GetHeader(CString strName, CString strUnit);

public:
	template<UINT size> BOOL UpData(TransDataTable<size> &table)
	{
		return SaveTable(table,m_table);
	}
	template<UINT size> void Init(TransDataTable<size> &table)
	{
		LoadTable(table,m_table);
	}
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRAWDATATABLE_H__82810270_2935_4F29_84B7_1A7A28E43842__INCLUDED_)
