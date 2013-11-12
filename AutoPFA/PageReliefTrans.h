#if !defined(AFX_PAGERELIEFTRANS_H__B360CE64_AF17_49D7_B2AB_5259CDC08E10__INCLUDED_)
#define AFX_PAGERELIEFTRANS_H__B360CE64_AF17_49D7_B2AB_5259CDC08E10__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageReliefTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageReliefTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageReliefTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strType);
	PageReliefTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageReliefTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageReliefTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;

	// Generated message map functions
	//{{AFX_MSG(PageReliefTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGERELIEFTRANS_H__B360CE64_AF17_49D7_B2AB_5259CDC08E10__INCLUDED_)
