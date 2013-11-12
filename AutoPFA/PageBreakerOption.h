#if !defined(AFX_PAGEBREAKEROPTION_H__7247BBF1_70EA_45C0_B128_BF4B2E044226__INCLUDED_)
#define AFX_PAGEBREAKEROPTION_H__7247BBF1_70EA_45C0_B128_BF4B2E044226__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageBreakerOption.h : header file
//
#include "dlginitpressguess.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageBreakerOption dialog

class PageBreakerOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageBreakerOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageBreakerOption)
	enum { IDD = IDD_BREAKEROPTION };
	CButton	m_Box;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageBreakerOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgInitPressGuess m_DlgInitGuess;

	// Generated message map functions
	//{{AFX_MSG(PageBreakerOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEBREAKEROPTION_H__7247BBF1_70EA_45C0_B128_BF4B2E044226__INCLUDED_)
