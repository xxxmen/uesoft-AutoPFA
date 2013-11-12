#if !defined(AFX_PAGECHECKOPTION_H__ECEAD538_6E8F_4569_8E8B_D13383FBE2DE__INCLUDED_)
#define AFX_PAGECHECKOPTION_H__ECEAD538_6E8F_4569_8E8B_D13383FBE2DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageCheckOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageCheckOption dialog

class PageCheckOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageCheckOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageCheckOption)
	enum { IDD = IDD_CHECKOPTION };
	CButton	m_Box;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageCheckOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageCheckOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECHECKOPTION_H__ECEAD538_6E8F_4569_8E8B_D13383FBE2DE__INCLUDED_)
