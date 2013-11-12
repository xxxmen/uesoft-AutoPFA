#if !defined(AFX_PAGERESERVOIRDATA_H__517BF165_70EB_47B6_AAE5_24F53FE98F04__INCLUDED_)
#define AFX_PAGERESERVOIRDATA_H__517BF165_70EB_47B6_AAE5_24F53FE98F04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageReservoirData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageReservoirData dialog
#include "PageJunData.h"
class PageReservoirData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageReservoirData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageReservoirData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageReservoirData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageReservoirData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGERESERVOIRDATA_H__517BF165_70EB_47B6_AAE5_24F53FE98F04__INCLUDED_)
