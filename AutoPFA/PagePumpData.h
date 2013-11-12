#if !defined(AFX_PAGEPUMPDATA_H__DC5B096F_0C98_4EB6_A18E_D9F7D907DD8C__INCLUDED_)
#define AFX_PAGEPUMPDATA_H__DC5B096F_0C98_4EB6_A18E_D9F7D907DD8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PagePumpData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PagePumpData dialog
#include "PageJunData.h"
class PagePumpData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PagePumpData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PagePumpData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PagePumpData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PagePumpData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEPUMPDATA_H__DC5B096F_0C98_4EB6_A18E_D9F7D907DD8C__INCLUDED_)
