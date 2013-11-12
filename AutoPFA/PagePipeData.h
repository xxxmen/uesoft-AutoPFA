#if !defined(AFX_PAGEPIPEDATA_H__F27278CA_DBEB_4E50_88DF_DD497D31AABD__INCLUDED_)
#define AFX_PAGEPIPEDATA_H__F27278CA_DBEB_4E50_88DF_DD497D31AABD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PagePipeData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PagePipeData dialog
#include "PageComponentTable.h"

class PagePipeData : public PageComponentTable
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PagePipeData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PagePipeData)
	
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PagePipeData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(PagePipeData)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	Component* GetComponent(int nKey);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEPIPEDATA_H__F27278CA_DBEB_4E50_88DF_DD497D31AABD__INCLUDED_)
