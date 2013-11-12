#if !defined(AFX_PAGECONDITION_H__3A6D0A08_ABD5_4A1B_B88E_893CF445CAD6__INCLUDED_)
#define AFX_PAGECONDITION_H__3A6D0A08_ABD5_4A1B_B88E_893CF445CAD6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageCondition.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PageCondition.h
  摘要：    
  author  : LSP          
*/
#include "UnitSubSystem.h"
#include "BaseDlg.h"

class Condition;
/////////////////////////////////////////////////////////////////////////////
// PageCondition dialog

class PageCondition : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init(Condition *pCondition);
	PageCondition(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageCondition)
	enum { IDD = IDD_CONDITION };
	CNumEdit	m_AtmospherTemp;
	CNumEdit	m_EditAtmospherPress;
	CUnitComboBox	m_cboTemperature;
	CUnitComboBox	m_cboPress;
	CString	m_strPressUnit;
	CString	m_strTemperatureUnit;
	CString	m_strAtmosphericPress;
	CString	m_strAtmosphericTemp;
	CString	m_strGravity;
	CString	m_strRetransTurb;
	CString	m_strRetransLam;
	//}}AFX_DATA

    Condition *m_pCondition;
    UnitSubSystem &m_UnitSys;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageCondition)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageCondition)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONDITION_H__3A6D0A08_ABD5_4A1B_B88E_893CF445CAD6__INCLUDED_)
