#if !defined(AFX_PAGECHECK_H__9A895DA6_5CEA_402F_A141_B1585391F2C7__INCLUDED_)
#define AFX_PAGECHECK_H__9A895DA6_5CEA_402F_A141_B1585391F2C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageCheck.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageCheck dialog
#include "PageJunData.h"
class PageCheckData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageCheckData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageCheck)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageCheck)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageCheck)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECHECK_H__9A895DA6_5CEA_402F_A141_B1585391F2C7__INCLUDED_)
