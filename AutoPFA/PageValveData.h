#if !defined(AFX_PAGEVALVEDATA_H__8CAB64C6_70FB_43E0_8373_054688DF20B1__INCLUDED_)
#define AFX_PAGEVALVEDATA_H__8CAB64C6_70FB_43E0_8373_054688DF20B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageValveData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageValveData dialog
#include "PageJunData.h"
class PageValveData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageValveData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageValveData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageValveData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageValveData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVALVEDATA_H__8CAB64C6_70FB_43E0_8373_054688DF20B1__INCLUDED_)
