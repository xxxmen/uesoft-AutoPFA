#if !defined(AFX_PAGEGASACCUMDATA_H__362BE689_0F12_4A36_9593_18579933ACD4__INCLUDED_)
#define AFX_PAGEGASACCUMDATA_H__362BE689_0F12_4A36_9593_18579933ACD4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGasAccumData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageGasAccumData dialog
#include "PageJunData.h"
class PageGasAccumData : public PageJunData
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageGasAccumData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGasAccumData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGasAccumData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageGasAccumData)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGASACCUMDATA_H__362BE689_0F12_4A36_9593_18579933ACD4__INCLUDED_)
