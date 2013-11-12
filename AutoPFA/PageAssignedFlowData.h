#if !defined(AFX_PAGEASSIGNEDFLOWDATA_H__7526304E_B645_4B39_857A_CE2BDBD0E9E0__INCLUDED_)
#define AFX_PAGEASSIGNEDFLOWDATA_H__7526304E_B645_4B39_857A_CE2BDBD0E9E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageAssignedFlowData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageAssignedFlowData dialog
#include "PageJunData.h"
class PageAssignedFlowData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageAssignedFlowData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAssignedFlowData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAssignedFlowData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageAssignedFlowData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEASSIGNEDFLOWDATA_H__7526304E_B645_4B39_857A_CE2BDBD0E9E0__INCLUDED_)
