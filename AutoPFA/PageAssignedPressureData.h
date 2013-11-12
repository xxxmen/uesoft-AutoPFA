#if !defined(AFX_PAGEASSIGNEDPRESSUREDATA_H__9D87131D_5737_4A37_901B_0A6B9924846A__INCLUDED_)
#define AFX_PAGEASSIGNEDPRESSUREDATA_H__9D87131D_5737_4A37_901B_0A6B9924846A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageAssignedPressureData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageAssignedPressureData dialog
#include "PageJunData.h"
class PageAssignedPressureData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageAssignedPressureData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAssignedPressureData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAssignedPressureData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageAssignedPressureData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEASSIGNEDPRESSUREDATA_H__9D87131D_5737_4A37_901B_0A6B9924846A__INCLUDED_)
