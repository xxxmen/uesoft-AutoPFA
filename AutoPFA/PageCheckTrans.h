#if !defined(AFX_PAGECHECKTRANS_H__2B6DD69C_97D9_48C7_9697_FDD6F4B8330F__INCLUDED_)
#define AFX_PAGECHECKTRANS_H__2B6DD69C_97D9_48C7_9697_FDD6F4B8330F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageCheckTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageCheckTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageCheckTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strType);
	PageCheckTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageCheckTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageCheckTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;
	// Generated message map functions
	//{{AFX_MSG(PageCheckTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECHECKTRANS_H__2B6DD69C_97D9_48C7_9697_FDD6F4B8330F__INCLUDED_)
