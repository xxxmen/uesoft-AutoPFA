#if !defined(AFX_DLGTWOTRANSSPECIAL_H__E885F7A6_7791_4E26_AF6C_D84530024FBF__INCLUDED_)
#define AFX_DLGTWOTRANSSPECIAL_H__E885F7A6_7791_4E26_AF6C_D84530024FBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgtwotransspecial.h : header file
//
#include "dlgtransspecial.h"
/////////////////////////////////////////////////////////////////////////////
// DlgTwoTransSpecial dialog

class DlgTwoTransSpecial : public DlgTransSpecial
{
// Construction
public:
	void Enable(BOOL bEnable);
	BOOL UpData(StrFlyWeight &ref);
	void Init(const StrFlyWeight &ref);
	DlgTwoTransSpecial(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgTwoTransSpecial)
	enum { IDD = IDD_TWOSPECIAL };
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTwoTransSpecial)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgTwoTransSpecial)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTWOTRANSSPECIAL_H__E885F7A6_7791_4E26_AF6C_D84530024FBF__INCLUDED_)
