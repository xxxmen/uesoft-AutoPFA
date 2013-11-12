#if !defined(AFX_PAGEFAILTRANS_H__0EBFDD90_4F4F_4AAA_B251_1717F94E86A3__INCLUDED_)
#define AFX_PAGEFAILTRANS_H__0EBFDD90_4F4F_4AAA_B251_1717F94E86A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageFailTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageFailTrans dialog
#include "PageTrans.h"

class PageFailTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strType);
	PageFailTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageFailTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageFailTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageFailTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEFAILTRANS_H__0EBFDD90_4F4F_4AAA_B251_1717F94E86A3__INCLUDED_)
