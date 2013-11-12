#if !defined(AFX_PAGESPRAYOPTION_H__529A4BFF_BD74_4B32_8C88_BE26C3DFCEDC__INCLUDED_)
#define AFX_PAGESPRAYOPTION_H__529A4BFF_BD74_4B32_8C88_BE26C3DFCEDC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSprayOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageSprayOption dialog

class PageSprayOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageSprayOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSprayOption)
	enum { IDD = IDD_SPRAYOPTION };
	CButton	m_Box;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSprayOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageSprayOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESPRAYOPTION_H__529A4BFF_BD74_4B32_8C88_BE26C3DFCEDC__INCLUDED_)
