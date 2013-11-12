#if !defined(AFX_PAGEJUNDATA_H__546E75F4_4AA3_41E6_AA73_9F86540B86EF__INCLUDED_)
#define AFX_PAGEJUNDATA_H__546E75F4_4AA3_41E6_AA73_9F86540B86EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageJunData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageJunData dialog
#include "PageComponentTable.h"

class PageJunData : public PageComponentTable
{
// Construction
public:
	virtual void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageJunData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageJunData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageJunData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	BOOL m_bHasData;

	// Generated message map functions
	//{{AFX_MSG(PageJunData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	Component* GetComponent(int nKey);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEJUNDATA_H__546E75F4_4AA3_41E6_AA73_9F86540B86EF__INCLUDED_)
