#if !defined(AFX_PAGEDATATABLE_H__E4BBC8E8_F60C_455F_B306_5C15BF7520CE__INCLUDED_)
#define AFX_PAGEDATATABLE_H__E4BBC8E8_F60C_455F_B306_5C15BF7520CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageDataTable.h : header file
//
#include "GridCtrl.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageDataTable dialog

class PageDataTable : public BaseDlg
{
// Construction
public:
	PageDataTable(CWnd* pParent = NULL);   // standard constructor
	void AutoSize();
	BOOL HasData();
	void HasData(BOOL bHasData);

// Dialog Data
	//{{AFX_DATA(PageDataTable)
	enum { IDD = IDD_DATATABLE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
	CGridCtrl m_table;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageDataTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bHasData;

	// Generated message map functions
	//{{AFX_MSG(PageDataTable)
		// NOTE: the ClassWizard will add member functions here
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
inline BOOL PageDataTable::HasData()
{
	return m_bHasData;
}

inline void PageDataTable::HasData(BOOL bHasData)
{
	m_bHasData = bHasData;
}
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEDATATABLE_H__E4BBC8E8_F60C_455F_B306_5C15BF7520CE__INCLUDED_)
