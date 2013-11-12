#if !defined(AFX_PAGESPRAYDATA_H__B4928FB7_73EA_4535_A820_B9D64397D46A__INCLUDED_)
#define AFX_PAGESPRAYDATA_H__B4928FB7_73EA_4535_A820_B9D64397D46A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSprayData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageSprayData dialog
#include "PageJunData.h"
class PageSprayData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageSprayData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSprayData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSprayData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageSprayData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESPRAYDATA_H__B4928FB7_73EA_4535_A820_B9D64397D46A__INCLUDED_)
