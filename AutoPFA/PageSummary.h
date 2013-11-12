#if !defined(AFX_PAGESUMMARY_H__9BB1E9A8_823D_421E_A917_80881D43E717__INCLUDED_)
#define AFX_PAGESUMMARY_H__9BB1E9A8_823D_421E_A917_80881D43E717__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSummary.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PageSummary.h
  摘要：    
  author  : LSP          
*/
class ComponentManager;
class Scenario;
class Fuild;
/////////////////////////////////////////////////////////////////////////////
// PageSummary dialog
#include "BaseDlg.h"

class PageSummary : public BaseDlg
{
// Construction
public:
	PageSummary(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSummary)
	enum { IDD = IDD_SUMMARY };
	CString	m_strCurName;
	CString	m_strAnName;
	CString	m_strPipeNum;
	CString	m_strJunNum;
	CString	m_strFuildName;
	CString	m_strTemp;
	CString	m_strDen;
	CString	m_strViscos;
	//}}AFX_DATA

public:
	void Init(Scenario *pScenario);
	ComponentManager *m_pCompManager;
	Fuild *m_pFuild;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSummary)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageSummary)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESUMMARY_H__9BB1E9A8_823D_421E_A917_80881D43E717__INCLUDED_)
