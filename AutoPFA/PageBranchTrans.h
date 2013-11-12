#if !defined(AFX_PAGEBRANCHTRANS_H__59D06CB9_784D_4382_81C8_5FBB37E40BCB__INCLUDED_)
#define AFX_PAGEBRANCHTRANS_H__59D06CB9_784D_4382_81C8_5FBB37E40BCB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageBranchTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageBranchTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageBranchTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref);
	PageBranchTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageBranchTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageBranchTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;
	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(PageBranchTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEBRANCHTRANS_H__59D06CB9_784D_4382_81C8_5FBB37E40BCB__INCLUDED_)
