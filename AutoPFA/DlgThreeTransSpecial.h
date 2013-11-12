#if !defined(AFX_DLGTHREETRANSSPECIAL_H__F3B3A15F_963B_4467_A128_F96D8CAC837F__INCLUDED_)
#define AFX_DLGTHREETRANSSPECIAL_H__F3B3A15F_963B_4467_A128_F96D8CAC837F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgThreeTransSpecial.h : header file
//
#include "dlgtransspecial.h"
/////////////////////////////////////////////////////////////////////////////
// DlgThreeTransSpecial dialog

class DlgThreeTransSpecial : public DlgTransSpecial
{
// Construction
public:
	BOOL UpData(StrFlyWeight &ref);
	void Init(const StrFlyWeight &ref);
	DlgThreeTransSpecial(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgThreeTransSpecial)
	enum { IDD = IDD_THREESPECIAL };
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgThreeTransSpecial)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgThreeTransSpecial)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTHREETRANSSPECIAL_H__F3B3A15F_963B_4467_A128_F96D8CAC837F__INCLUDED_)
