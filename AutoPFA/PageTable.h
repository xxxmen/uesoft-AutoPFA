#if !defined(AFX_PAGETABLE_H__AEC5465F_640B_4850_ABCB_D1B60A544859__INCLUDED_)
#define AFX_PAGETABLE_H__AEC5465F_640B_4850_ABCB_D1B60A544859__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageTable dialog
#include "GridCtrl.h"
#include "Transient.h"
#include "BaseDlg.h"
class PageTable : public BaseDlg
{
// Construction
public:
	void RemoveData();
	BOOL UpData(TransDataTable<2> &table);
	void Init(TransDataTable<2> &table);
	void EnableTable(BOOL bEnable);
	void ShowCheck(int nCmdShow);
	void SetTableHeader(CString strHeader,int nCol = 2);
	void SetTableHeader(CString strName,CString strUnit,int nCol);
	BOOL UpData(StrFlyWeight &Repeat,TransDataTable<2> &table);
	void Init(const StrFlyWeight &Repeat,TransDataTable<2> &table,CString strHeader);
	PageTable(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTable)
	enum { IDD = IDD_TRANSTABLE };
	BOOL	m_bRepeat;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CGridCtrl	m_list;
	BOOL m_bEnable;

	// Generated message map functions
	//{{AFX_MSG(PageTable)
	virtual BOOL OnInitDialog();
	afx_msg void OnBchart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitList(CString strHeader = _T(""));
	void SetTableStatus(BOOL bEnable);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETABLE_H__AEC5465F_640B_4850_ABCB_D1B60A544859__INCLUDED_)
