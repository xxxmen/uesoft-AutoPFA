#if !defined(AFX_PAGEGENERALOPTION_H__1EDF65DC_DDFD_4C0C_94A5_3455DDC26BFE__INCLUDED_)
#define AFX_PAGEGENERALOPTION_H__1EDF65DC_DDFD_4C0C_94A5_3455DDC26BFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGeneralOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageGeneralOption dialog

class PageGeneralOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageGeneralOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGeneralOption)
	enum { IDD = IDD_GENERALOPTION };
	CButton	m_Box;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGeneralOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageGeneralOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGENERALOPTION_H__1EDF65DC_DDFD_4C0C_94A5_3455DDC26BFE__INCLUDED_)
