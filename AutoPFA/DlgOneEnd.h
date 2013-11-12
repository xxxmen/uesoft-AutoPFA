#if !defined(AFX_DLGONEEND_H__7D74C0C4_7957_444C_B91F_67BFE1A9E421__INCLUDED_)
#define AFX_DLGONEEND_H__7D74C0C4_7957_444C_B91F_67BFE1A9E421__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOneEnd.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// DlgOneEnd dialog

class DlgOneEnd : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	DlgOneEnd(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgOneEnd)
	enum { IDD = IDD_DLGONEEND };
	CNumEdit	m_EditOutPipe;
	CNumEdit	m_EditInPipe;
	CNumEdit	m_EditEle;
	CUnitComboBox	m_cmbEleUnit;
	CString	m_strEleUnit;
	CString	m_strEle;
	CString	m_strInPipeID;
	CString	m_strOutPipeID;
	//}}AFX_DATA


	UnitSubSystem &m_UnitSys;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgOneEnd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgOneEnd)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGONEEND_H__7D74C0C4_7957_444C_B91F_67BFE1A9E421__INCLUDED_)
