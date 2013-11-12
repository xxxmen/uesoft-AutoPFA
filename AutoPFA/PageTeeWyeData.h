#if !defined(AFX_PAGETEEWYEDATA_H__22FE3533_D395_447A_90C3_C82BD53DFCFA__INCLUDED_)
#define AFX_PAGETEEWYEDATA_H__22FE3533_D395_447A_90C3_C82BD53DFCFA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTeeWyeData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeData dialog
#include "PageJunData.h"
class PageTeeWyeData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageTeeWyeData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTeeWyeData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTeeWyeData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageTeeWyeData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETEEWYEDATA_H__22FE3533_D395_447A_90C3_C82BD53DFCFA__INCLUDED_)
