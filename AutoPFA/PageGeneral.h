#if !defined(AFX_PAGEGENERAL_H__F2E7FD2B_C63E_45C5_8B00_F06F34B8D2B2__INCLUDED_)
#define AFX_PAGEGENERAL_H__F2E7FD2B_C63E_45C5_8B00_F06F34B8D2B2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGeneral.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageGeneral dialog
#include "PageJunData.h"
class PageGeneralData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageGeneralData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGeneral)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGeneral)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageGeneral)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGENERAL_H__F2E7FD2B_C63E_45C5_8B00_F06F34B8D2B2__INCLUDED_)
