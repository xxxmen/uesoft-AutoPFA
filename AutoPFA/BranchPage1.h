#if !defined(AFX_BRANCHPAGE1_H__F8F71208_96EC_4B9D_94CF_27DDDA23DD0E__INCLUDED_)
#define AFX_BRANCHPAGE1_H__F8F71208_96EC_4B9D_94CF_27DDDA23DD0E__INCLUDED_
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称： BranchPage1.h
  摘要：损失系数分支元件、指定压力、调压罐公用    
  author  : LSP          
*/
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BranchPage1.h : header file
//
#include "GridCtrl.h"
#include "TableFlyWeigh.h"
#include "BaseDlg.h"

class StrFlyWeight;
class Jun;

/////////////////////////////////////////////////////////////////////////////
// BranchPage1 dialog

class BranchPage1 : public BaseDlg
{
// Construction
public:
	BranchPage1(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(BranchPage1)
	enum { IDD = IDD_PAGEBRANCH1 };
	CComboBox	m_cmbEleUnit;
	CString	m_strEleUnit;
	//}}AFX_DATA
public:
	BOOL UpData(TableFlyWeight<4>&ref,StrFlyWeight &ref1);
	void Init(TableFlyWeight<4>&ref,StrFlyWeight &ref1);
	CGridCtrl	m_list;
	UnitSubSystem &m_UnitSys;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(BranchPage1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(BranchPage1)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL UpDataEleK(TableFlyWeight<4>&ref);
	void InitListHeader();
	void InitEleK(TableFlyWeight<4>&ref);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRANCHPAGE1_H__F8F71208_96EC_4B9D_94CF_27DDDA23DD0E__INCLUDED_)
