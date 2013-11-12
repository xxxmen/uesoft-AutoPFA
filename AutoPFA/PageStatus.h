#if !defined(AFX_PAGESTATUS_H__FF7DAEB2_7B87_4263_A830_EF908DC6F190__INCLUDED_)
#define AFX_PAGESTATUS_H__FF7DAEB2_7B87_4263_A830_EF908DC6F190__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageStatus.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageStatus dialog
#include "ComponentStatus.h"
#include "BaseDlg.h"
class PageStatus : public BaseDlg
{
// Construction
public:
	void Init(ComponentStatus &ref);
	PageStatus(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageStatus)
	enum { IDD = IDD_PAGESTATUS };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageStatus)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageStatus)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESTATUS_H__FF7DAEB2_7B87_4263_A830_EF908DC6F190__INCLUDED_)
