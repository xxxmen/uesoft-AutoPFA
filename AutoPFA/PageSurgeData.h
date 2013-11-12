#if !defined(AFX_PAGESURGEDATA_H__B119B4E7_54BA_4F60_BF34_874B92B2DD46__INCLUDED_)
#define AFX_PAGESURGEDATA_H__B119B4E7_54BA_4F60_BF34_874B92B2DD46__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSurgeData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageSurgeData dialog
#include "PageJunData.h"
class PageSurgeData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageSurgeData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSurgeData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSurgeData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageSurgeData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESURGEDATA_H__B119B4E7_54BA_4F60_BF34_874B92B2DD46__INCLUDED_)
