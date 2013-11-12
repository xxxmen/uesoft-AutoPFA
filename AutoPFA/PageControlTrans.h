#if !defined(AFX_PAGECONTROLTRANS_H__4E598320_FEEA_4C15_9F57_1FBF7C88D9BC__INCLUDED_)
#define AFX_PAGECONTROLTRANS_H__4E598320_FEEA_4C15_9F57_1FBF7C88D9BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageControlTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageControlTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageControlTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strType,CString strUnit);
	PageControlTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageControlTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageControlTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;

	// Generated message map functions
	//{{AFX_MSG(PageControlTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONTROLTRANS_H__4E598320_FEEA_4C15_9F57_1FBF7C88D9BC__INCLUDED_)
