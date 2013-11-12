#if !defined(AFX_PAGERELIEFDATA_H__69F2732B_D0B9_404D_9F9B_58D8B003FC15__INCLUDED_)
#define AFX_PAGERELIEFDATA_H__69F2732B_D0B9_404D_9F9B_58D8B003FC15__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageReliefData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageReliefData dialog
#include "PageJunData.h"
class PageReliefData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageReliefData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageReliefData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageReliefData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageReliefData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGERELIEFDATA_H__69F2732B_D0B9_404D_9F9B_58D8B003FC15__INCLUDED_)
