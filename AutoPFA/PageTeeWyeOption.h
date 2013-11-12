#if !defined(AFX_PAGETEEWYEOPTION_H__D3984DE6_A0CE_4388_807D_3A819CDD106C__INCLUDED_)
#define AFX_PAGETEEWYEOPTION_H__D3984DE6_A0CE_4388_807D_3A819CDD106C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTeeWyeOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeOption dialog

class PageTeeWyeOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageTeeWyeOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTeeWyeOption)
	enum { IDD = IDD_TEEWYEOPTION };
	CButton	m_Box;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTeeWyeOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageTeeWyeOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETEEWYEOPTION_H__D3984DE6_A0CE_4388_807D_3A819CDD106C__INCLUDED_)
