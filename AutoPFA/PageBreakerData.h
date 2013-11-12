#if !defined(AFX_PAGEBREAKERDATA_H__A5B03645_FF30_46F6_BDFA_282162D45E15__INCLUDED_)
#define AFX_PAGEBREAKERDATA_H__A5B03645_FF30_46F6_BDFA_282162D45E15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageBreakerData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageBreakerData dialog
#include "PageJunData.h"
class PageBreakerData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageBreakerData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageBreakerData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageBreakerData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageBreakerData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEBREAKERDATA_H__A5B03645_FF30_46F6_BDFA_282162D45E15__INCLUDED_)
