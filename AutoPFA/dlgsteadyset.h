#if !defined(AFX_DLGSTEADYSET_H__5902BB56_447B_451A_8493_E52F43D78D23__INCLUDED_)
#define AFX_DLGSTEADYSET_H__5902BB56_447B_451A_8493_E52F43D78D23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgsteadyset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgSteadySet dialog
#include "TabSheet.h"
#include "PageTolerance.h"
#include "PageOther.h"
class UnitSubSystem;
class SteadySet;

class DlgSteadySet : public CDialog
{
// Construction
public:
	DlgSteadySet(UnitSubSystem &UnitSys,SteadySet *pSteady,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSteadySet)
	enum { IDD = IDD_DLGSTEADYSET };
	CTabSheet	m_tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSteadySet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	SteadySet *m_pSteady;
	PageTolerance m_page1;
	PageOther     m_page2;
	// Generated message map functions
	//{{AFX_MSG(DlgSteadySet)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSTEADYSET_H__5902BB56_447B_451A_8493_E52F43D78D23__INCLUDED_)
