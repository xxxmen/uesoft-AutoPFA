#if !defined(AFX_PAGEFUILD_H__DA932FAA_826F_40F7_BAD1_F66551E3DCF1__INCLUDED_)
#define AFX_PAGEFUILD_H__DA932FAA_826F_40F7_BAD1_F66551E3DCF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageFuild.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PageFuild.h 
  摘要：    
  author  : LSP          
*/

#include "UnitSubSystem.h"
#include "ImpulseDataMgr.h"
#include "BaseDlg.h"

class Fuild;
/////////////////////////////////////////////////////////////////////////////
// PageFuild dialog

class PageFuild : public BaseDlg
{
// Construction
public:
	BOOL Updata();
	void Init(Fuild *pFuild);
	PageFuild(ImpulseDataMgr &ImpulseData,UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageFuild)
	enum { IDD = IDD_FUILDDATA };
	CListCtrl	m_list;
	CNumEdit	m_EditVapor;
	CNumEdit	m_EditViscos;
	CNumEdit	m_EditTemp;
	CNumEdit	m_EditDen;
	CNumEdit	m_EditBulk;
	CUnitComboBox   m_cmbViscos;
	CUnitComboBox	m_cmbVapor;
	CUnitComboBox	m_cmbTemp;
	CUnitComboBox	m_cmbDen;
	CUnitComboBox	m_cmbBulk;
	CString	m_strName;
	CString	m_strTemperature;
	CString	m_strVapor;
	CString	m_strViscos;
	CString	m_strDensity;
	CString	m_strBulkMudus;
	CString	m_strTempUnit;
	CString	m_strVaporUnit;
	CString	m_strViscosUnit;
	CString	m_strDensityUnit;
	CString	m_strBulkMudusUnit;
	CString	m_strRange;
	int		m_bStandard;
	//}}AFX_DATA
	Fuild *m_pFuild;
	UnitSubSystem &m_UnitSys;
	ImpulseDataMgr &m_ImpulseData;
	int m_nOldKey;
	FuildDatabase *m_pFuildDB;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageFuild)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageFuild)
	virtual BOOL OnInitDialog();
	afx_msg void OnCalc();
	afx_msg void OnAdd();
	afx_msg void OnRadiopfa();
	afx_msg void OnRadioUser();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetStandardStatus();
	BOOL CheckTRange(double &dt);
	void InitList();
	BOOL PreTranslateMessage(MSG* pMsg);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEFUILD_H__DA932FAA_826F_40F7_BAD1_F66551E3DCF1__INCLUDED_)
