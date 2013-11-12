#if !defined(AFX_PAGEDETAIL_H__66ABFF4E_8D6A_45A3_9FFE_EA491F98C138__INCLUDED_)
#define AFX_PAGEDETAIL_H__66ABFF4E_8D6A_45A3_9FFE_EA491F98C138__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageDetail.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PageDetail.h
  摘要：    
  author  : LSP          
*/
#include "Iterator.h"
#include "GridCtrl.h"
#include "BaseDlg.h"

class ComponentManager;
class Scenario;
class Component;
/////////////////////////////////////////////////////////////////////////////
// PageDetail dialog

class PageDetail : public BaseDlg
{
// Construction
public:
	PageDetail(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageDetail)
	enum { IDD = IDD_DETAILS };
	CButton	m_RadioAll;
	CTreeCtrl	m_tree;
	CGridCtrl	m_list;
	//}}AFX_DATA
public:
	void InitList(Component *pComponent);
	void InitList();
	void InitJun(HTREEITEM hitem);
	void InitPipe(HTREEITEM hitem);
	void InitTree();
	void Init(Scenario *pScenario);
	ComponentManager *m_pCompManager;
    Scenario *m_pScenario;
	int m_nFilter;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageDetail)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageDetail)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRadioAll();
	afx_msg void OnRadioAncest();
	afx_msg void OnRadioSelect();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEDETAIL_H__66ABFF4E_8D6A_45A3_9FFE_EA491F98C138__INCLUDED_)
