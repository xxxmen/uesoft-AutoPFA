#if !defined(AFX_DLGTRANSSPECIAL_H__BFCC4C95_BCFC_4D36_ADD7_3E1C4A5A6C22__INCLUDED_)
#define AFX_DLGTRANSSPECIAL_H__BFCC4C95_BCFC_4D36_ADD7_3E1C4A5A6C22__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgtransspecial.h : header file
//
#include "StrFlyWeight.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// DlgTransSpecial dialog

class DlgTransSpecial : public BaseDlg
{
// Construction
public:
	DlgTransSpecial(UINT nIDTemplate,CWnd* pParent = NULL);   // standard constructor
	virtual BOOL UpData(StrFlyWeight &ref) = 0;
	virtual void Init(const StrFlyWeight &ref) = 0;

// Dialog Data
	//{{AFX_DATA(DlgTransSpecial)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTransSpecial)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgTransSpecial)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTRANSSPECIAL_H__BFCC4C95_BCFC_4D36_ADD7_3E1C4A5A6C22__INCLUDED_)
