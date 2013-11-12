#if !defined(AFX_PAGECONTROLDATA_H__1DCC3182_0A05_4B82_8148_DDED9FAA57B7__INCLUDED_)
#define AFX_PAGECONTROLDATA_H__1DCC3182_0A05_4B82_8148_DDED9FAA57B7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageControlData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageControlData dialog
#include "PageJunData.h"
class PageControlData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageControlData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageControlData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageControlData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageControlData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONTROLDATA_H__1DCC3182_0A05_4B82_8148_DDED9FAA57B7__INCLUDED_)
