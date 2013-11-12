#if !defined(AFX_DLGCOMMON_H__EFDF43EA_FCCF_4661_B8A1_357CF9769414__INCLUDED_)
#define AFX_DLGCOMMON_H__EFDF43EA_FCCF_4661_B8A1_357CF9769414__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCommon.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgCommon.h
  摘要：    
  author  : LSP          
*/

/////////////////////////////////////////////////////////////////////////////
// DlgPipe dialog
#include "ComponentManager.h"
#include "dlgpipemodel.h"
#include "TabSheet.h"
#include "PageFitLoss.h"
#include "PagePipeOption.h"
#include "PageStatus.h"
class DlgPipe : public CDialog
{
// Construction
public:
	DlgPipe(UnitSubSystem &UnitSys,ComponentManager &manager,Pipe *pPipe,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgCommon)
	enum { IDD = IDD_PIPE };
	CButton	m_btnext;
	CButton	m_btPre;
	CNumEdit	m_EditOutJun;
	CNumEdit	m_EditInJun;
	CTabSheet	m_tab;
	CComboBox	m_cboName;
	int		m_nID;
	CString	m_strName;
	CString	m_strInJunID;
	CString	m_strOutJunID;
	//}}AFX_DATA

public:
	void ReadOnly(BOOL bReadOnly = FALSE);
	DlgPipeModel m_page1;
	PageFitLoss  m_page2;
	PagePipeOption m_page3;
	PageStatus m_page4;

private:
	void Init(Pipe *pPipe);
	void Init();
	void UpData();
	void SaveData();
	void InitCmb();
	ComponentManager &m_manager;
	Pipe             *m_pPipe;
	Pipe             *m_pPipeTemp;//备份节点，用于拷贝
	UnitSubSystem    &m_UnitSys;
	int m_nOldSel;
	BOOL m_bReadOnly;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgCommon)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgCommon)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnCancel();
	afx_msg void OnSelchangePipe();
	afx_msg void OnJump();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCOMMON_H__EFDF43EA_FCCF_4661_B8A1_357CF9769414__INCLUDED_)
