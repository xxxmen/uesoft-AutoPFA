#if !defined(AFX_DLGCSCENARIOMANAGER_H__A7A8A85B_D840_48AD_82C6_02A549E5EF63__INCLUDED_)
#define AFX_DLGCSCENARIOMANAGER_H__A7A8A85B_D840_48AD_82C6_02A549E5EF63__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCScenarioManager.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgCScenarioManager.h
  author  : LSP          
*/
#include "TabSheet.h"
#include "TreeScenario.h"
#include "ScenariManage.h"
#include "PageDetail.h"
#include "PageSummary.h"

/////////////////////////////////////////////////////////////////////////////
// DlgCScenarioManager dialog

class DlgCScenarioManager : public CDialog
{
// Construction
public:
	DlgCScenarioManager(ScenariManage &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgCScenarioManager)
	enum { IDD = IDD_DLGSCENARIOMANAGE };
	CTabSheet	 m_tab;
	TreeScenario m_tree;
	CString	m_strCurScenario;
	//}}AFX_DATA
    ScenariManage &m_manager;
	PageSummary m_page1;
	PageDetail m_page2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgCScenarioManager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void InitTree(Scenario* pScenario,HTREEITEM htreeitem = TVI_ROOT);
    HTREEITEM InsertTree(Scenario* pScenario,HTREEITEM htreeitem = TVI_ROOT);
	// Generated message map functions
	//{{AFX_MSG(DlgCScenarioManager)
	virtual BOOL OnInitDialog();
	afx_msg void OnSetCur();
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	afx_msg void OnCloneWithChild();
	afx_msg void OnCloneWithOutChild();
	afx_msg void OnCreatChild();
	afx_msg void OnPromote();
	afx_msg void OnDelete();
	afx_msg void OnReName();
	afx_msg void OnSave();
	
	DECLARE_MESSAGE_MAP()
private:
	Scenario* GetCurScenario();
	CString DefaultName(Scenario *pScenario);
	void InitPage();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCSCENARIOMANAGER_H__A7A8A85B_D840_48AD_82C6_02A549E5EF63__INCLUDED_)
