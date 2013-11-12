#if !defined(AFX_PAGEVALVETRANS_H__2B2707FD_3B3C_4628_9D7B_3EA3188545E3__INCLUDED_)
#define AFX_PAGEVALVETRANS_H__2B2707FD_3B3C_4628_9D7B_3EA3188545E3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageValveTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageValveTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageValveTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strType);
	PageValveTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageValveTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageValveTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;

	// Generated message map functions
	//{{AFX_MSG(PageValveTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVALVETRANS_H__2B2707FD_3B3C_4628_9D7B_3EA3188545E3__INCLUDED_)
