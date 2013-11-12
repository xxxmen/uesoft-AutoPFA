#if !defined(AFX_PAGELIQUIDACCUMDATA_H__A851BE57_7807_4A05_A59A_75684A6EDBDE__INCLUDED_)
#define AFX_PAGELIQUIDACCUMDATA_H__A851BE57_7807_4A05_A59A_75684A6EDBDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageLiquidAccumData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageLiquidAccumData dialog
#include "PageJunData.h"
class PageLiquidAccumData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageLiquidAccumData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageLiquidAccumData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageLiquidAccumData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageLiquidAccumData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGELIQUIDACCUMDATA_H__A851BE57_7807_4A05_A59A_75684A6EDBDE__INCLUDED_)
