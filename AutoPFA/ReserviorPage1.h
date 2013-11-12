#if !defined(AFX_RESERVIORPAGE1_H__91C2B8F8_FFA3_45D3_94DD_7FDDF0B1A53F__INCLUDED_)
#define AFX_RESERVIORPAGE1_H__91C2B8F8_FFA3_45D3_94DD_7FDDF0B1A53F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ReserviorPage1.h : header file
//
/////////////////////////////////////////////////////////////////////////////
// ReserviorPage1 dialog
#include "BaseDlg.h"

class ReserviorPage1 : public BaseDlg
{
// Construction
public:
	CString EleUnit();
	BOOL UpData();
	void Init();
	ReserviorPage1(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(ReserviorPage1)
	enum { IDD = IDD_PAGERESERVIOR1 };
	CEdit	m_EditDen;
	CEdit	m_EditTemp;
	CUnitComboBox	m_cmbTempUnit;
	CUnitComboBox	m_cmbDenUnit;
	CNumEdit	m_EditSurfacePress;
	CUnitComboBox	m_cmbPressUnit;
	CNumEdit	m_EditSurFaceEle;
	CUnitComboBox	m_cmbEleUnit;
	CString	m_strEle;
	CString	m_strEleUnit;
	CString	m_strDenUnit;
	CString	m_strTempUnit;
	CString	m_strDen;
	CString	m_strTemp;
	CString	m_strSurfacePress;
	CString	m_strPressUnit;
	//}}AFX_DATA


	UnitSubSystem &m_UnitSys;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(ReserviorPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL


// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(ReserviorPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeEleUnit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESERVIORPAGE1_H__91C2B8F8_FFA3_45D3_94DD_7FDDF0B1A53F__INCLUDED_)
