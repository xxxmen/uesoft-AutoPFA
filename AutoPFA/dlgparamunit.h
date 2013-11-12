#if !defined(AFX_DLGPARAMUNIT_H__2AACE4AC_7F7A_465C_B482_C9CF19F1AC68__INCLUDED_)
#define AFX_DLGPARAMUNIT_H__2AACE4AC_7F7A_465C_B482_C9CF19F1AC68__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgparamunit.h : header file
//
#include "TabSheet.h"
#include "PageUnit.h"
#include "UnitSubSystem.h"
/////////////////////////////////////////////////////////////////////////////
// DlgParamUnit dialog

class DlgParamUnit : public CDialog
{
// Construction
public:
	DlgParamUnit(UnitSubSystem &unitSystem,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgParamUnit)
	enum { IDD = IDD_DLGPARAMUNIT};
	CTabSheet	m_Tab;
	//}}AFX_DATA
	PageUnit m_page1;
	UnitSubSystem m_unitSystem;
	UnitSubSystem &m_Ref;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgParamUnit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgParamUnit)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPARAMUNIT_H__2AACE4AC_7F7A_465C_B482_C9CF19F1AC68__INCLUDED_)
