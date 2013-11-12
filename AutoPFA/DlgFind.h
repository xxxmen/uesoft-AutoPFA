#if !defined(AFX_DLGFIND_H__1C8CC81A_8172_4453_AE3B_C95C0A6503A5__INCLUDED_)
#define AFX_DLGFIND_H__1C8CC81A_8172_4453_AE3B_C95C0A6503A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgFind.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgFind.h
  摘要：    
  author  : LSP          
*/

/////////////////////////////////////////////////////////////////////////////
// DlgFind dialog
class ComponentManager;
class DlgFind : public CDialog
{
// Construction
public:
	DlgFind(ComponentManager &compManager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgFind)
	enum { IDD = IDD_DLGFIND };
	CButton	m_RadioJun;
	CButton	m_RadioPipe;
	CListCtrl	m_listPipe;
	CListCtrl	m_listJun;
	CComboBox	m_cboJunType;
	int		m_nObjectKey;
	//}}AFX_DATA

	int m_nObjectType;
public:
	void InitCboJun();
	void ShowJunList(int nType = 0);
	void ShowPipeList(int nType = 0);
	ComponentManager &m_CompManager;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgFind)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgFind)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchange();
	afx_msg void OnRjun();
	afx_msg void OnRpipe();
	afx_msg void OnChangedJun(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangedPipe(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetFocusPipe(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetFocusJun(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGFIND_H__1C8CC81A_8172_4453_AE3B_C95C0A6503A5__INCLUDED_)
