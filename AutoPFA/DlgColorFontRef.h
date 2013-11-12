#if !defined(AFX_DLGCOLORFONTREF_H__EF0332E6_30B2_417E_BF33_ACE86F8F26D0__INCLUDED_)
#define AFX_DLGCOLORFONTREF_H__EF0332E6_30B2_417E_BF33_ACE86F8F26D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgColorFontRef.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgColorFontRef.h
  摘要：    
  author  : LSP          
*/
#include "WorkSpaceRef.h"
#include "GridCtrl.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// DlgColorFontRef dialog

class DlgColorFontRef : public BaseDlg
{
// Construction
public:
	BOOL Updata();
	void Init(WorkSpaceRef &ref);
	DlgColorFontRef(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgColorFontRef)
	enum { IDD = IDD_COLORFONTREF };
	CString   m_strFont;
	CGridCtrl	m_list;
	//}}AFX_DATA
private:
    WorkSpaceRef *m_pWorkSpaceRef;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgColorFontRef)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgColorFontRef)
	virtual BOOL OnInitDialog();
	afx_msg void OnSetColor();
	afx_msg void OnSetFont();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	LOGFONT m_lf;
	void SetFontText();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCOLORFONTREF_H__EF0332E6_30B2_417E_BF33_ACE86F8F26D0__INCLUDED_)
