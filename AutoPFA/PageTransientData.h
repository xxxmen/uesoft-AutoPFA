#if !defined(AFX_PAGETRANSIENTDATA_H__D2D859DC_B757_4252_95D2_BDD91A5C2319__INCLUDED_)
#define AFX_PAGETRANSIENTDATA_H__D2D859DC_B757_4252_95D2_BDD91A5C2319__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageTransientData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageTransientData dialog
#include "PageDataList.h"
#include "ComponentManager.h"
class PageTransientData : public PageDataList
{
// Construction
public:
	void LoadData(ComponentManager *pManager);
	PageTransientData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTransientData)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTransientData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void InitListData(TransDataTable<2> &ref);

	// Generated message map functions
	//{{AFX_MSG(PageTransientData)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETRANSIENTDATA_H__D2D859DC_B757_4252_95D2_BDD91A5C2319__INCLUDED_)
