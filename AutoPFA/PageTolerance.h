#if !defined(AFX_PAGETOLERANCE_H__01213EA2_1414_47CD_AEFF_2AB9D039A2D8__INCLUDED_)
#define AFX_PAGETOLERANCE_H__01213EA2_1414_47CD_AEFF_2AB9D039A2D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTolerance.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageTolerance dialog
#include "dlgtolerance.h"
#include "BaseDlg.h"

class PageTolerance : public BaseDlg
{
// Construction
public:
	BOOL Updata();
	void Init();
	PageTolerance(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTolerance)
	enum { IDD = IDD_PAGETOLERANCE };
	CButton	m_Box2;
	CButton	m_Box1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTolerance)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTolerance m_PressTol;
	DlgTolerance m_FlowTol;

	// Generated message map functions
	//{{AFX_MSG(PageTolerance)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETOLERANCE_H__01213EA2_1414_47CD_AEFF_2AB9D039A2D8__INCLUDED_)
