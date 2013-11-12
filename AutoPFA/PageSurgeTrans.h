#if !defined(AFX_PAGESURGETRANS_H__FC611774_909F_4B6E_A3F9_ED22ADEA8782__INCLUDED_)
#define AFX_PAGESURGETRANS_H__FC611774_909F_4B6E_A3F9_ED22ADEA8782__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSurgeTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageSurgeTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageSurgeTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strUnit);
	PageSurgeTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSurgeTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSurgeTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;

	// Generated message map functions
	//{{AFX_MSG(PageSurgeTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESURGETRANS_H__FC611774_909F_4B6E_A3F9_ED22ADEA8782__INCLUDED_)
