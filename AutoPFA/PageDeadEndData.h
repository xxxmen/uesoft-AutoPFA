#if !defined(AFX_PAGEDEADENDDATA_H__883FA63D_58E9_41A7_B82F_66C92F60AECB__INCLUDED_)
#define AFX_PAGEDEADENDDATA_H__883FA63D_58E9_41A7_B82F_66C92F60AECB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageDeadEndData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageDeadEndData dialog
#include "PageJunData.h"
class PageDeadEndData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageDeadEndData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageDeadEndData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageDeadEndData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageDeadEndData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEDEADENDDATA_H__883FA63D_58E9_41A7_B82F_66C92F60AECB__INCLUDED_)
