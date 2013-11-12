#if !defined(AFX_DLGSCENARIONAME_H__D9DEDF63_DB54_4FD0_A0A2_7872F8075FF0__INCLUDED_)
#define AFX_DLGSCENARIONAME_H__D9DEDF63_DB54_4FD0_A0A2_7872F8075FF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgScenarioName.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgScenarioName.h
  摘要：    
  author  : LSP          
*/

/////////////////////////////////////////////////////////////////////////////
// DlgScenarioName dialog

class DlgScenarioName : public CDialog
{
// Construction
public:
	CString GetName();
	DlgScenarioName(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgScenarioName)
	enum { IDD = IDD_SCENARIONAME };
	CString	m_strName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgScenarioName)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgScenarioName)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSCENARIONAME_H__D9DEDF63_DB54_4FD0_A0A2_7872F8075FF0__INCLUDED_)
