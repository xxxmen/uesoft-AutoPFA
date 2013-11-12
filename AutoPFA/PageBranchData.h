#if !defined(AFX_PAGEBRANCHDATA_H__5E81AE4E_1F88_4C25_9F21_564BE5A0876B__INCLUDED_)
#define AFX_PAGEBRANCHDATA_H__5E81AE4E_1F88_4C25_9F21_564BE5A0876B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageBranchData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageBranchData dialog
#include "PageJunData.h"
class PageBranchData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageBranchData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageBranchData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageBranchData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageBranchData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEBRANCHDATA_H__5E81AE4E_1F88_4C25_9F21_564BE5A0876B__INCLUDED_)
