#if !defined(AFX_DLGWORKSPACEREF_H__609CBFC0_667F_472C_A735_3BF64FD4BD9C__INCLUDED_)
#define AFX_DLGWORKSPACEREF_H__609CBFC0_667F_472C_A735_3BF64FD4BD9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgWorkspaceRef.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgWorkspaceRef.h
  摘要：    
  author  : LSP          
*/
#include "TabSheet.h"
#include "DlgColorFontRef.h"
#include "DlgGraphRef.h"
#include "WorkSpaceRef.h"
/////////////////////////////////////////////////////////////////////////////
// DlgWorkspaceRef dialog

class DlgWorkspaceRef : public CDialog
{
// Construction
public:
	DlgWorkspaceRef(WorkSpaceRef &workSpace,CWnd* pParent = NULL);   // standard constructor

public:
	DlgGraphRef m_page1;
	DlgColorFontRef m_page2;
	WorkSpaceRef &m_workSpaceRef;
// Dialog Data
	//{{AFX_DATA(DlgWorkspaceRef)
	enum { IDD = IDD_DLGWORKSPACEREF };
	CTabSheet	m_tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgWorkspaceRef)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgWorkspaceRef)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGWORKSPACEREF_H__609CBFC0_667F_472C_A735_3BF64FD4BD9C__INCLUDED_)
