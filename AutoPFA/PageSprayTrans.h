#if !defined(AFX_PAGESPRAYTRANS_H__BA6FDD8E_97E5_4C23_B695_C258910BE473__INCLUDED_)
#define AFX_PAGESPRAYTRANS_H__BA6FDD8E_97E5_4C23_B695_C258910BE473__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSprayTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageSprayTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageSprayTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strType,CString strUnit);
	PageSprayTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSprayTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSprayTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;

	// Generated message map functions
	//{{AFX_MSG(PageSprayTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESPRAYTRANS_H__BA6FDD8E_97E5_4C23_B695_C258910BE473__INCLUDED_)
