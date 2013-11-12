#if !defined(AFX_PAGEAREACHANGEDATA_H__7B27CE28_BC37_4854_9018_140D61002402__INCLUDED_)
#define AFX_PAGEAREACHANGEDATA_H__7B27CE28_BC37_4854_9018_140D61002402__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageAreaChangeData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageAreaChangeData dialog
#include "PageJunData.h"
class PageAreaChangeData : public PageJunData
{
// Construction
public:
	virtual void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageAreaChangeData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAreaChangeData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAreaChangeData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageAreaChangeData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEAREACHANGEDATA_H__7B27CE28_BC37_4854_9018_140D61002402__INCLUDED_)
