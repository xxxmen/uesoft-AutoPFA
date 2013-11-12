#if !defined(AFX_PAGESTMOUTTABLE_H__BE85AC61_8ECB_4E48_8F99_B69A451739EF__INCLUDED_)
#define AFX_PAGESTMOUTTABLE_H__BE85AC61_8ECB_4E48_8F99_B69A451739EF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageStmOutTable.h : header file
//

#include "PageOutTable.h"
/////////////////////////////////////////////////////////////////////////////
// PageStmOutTable dialog

class PageStmOutTable : public PageOutTable
{
// Construction
public:
	PageStmOutTable(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageStmOutTable)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageStmOutTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void Loading(OutMgr &mgr,OutAttrArray &Array,int nType );
	CString LookUp(int nAtrrKey,int nRow);
	// Generated message map functions
	//{{AFX_MSG(PageStmOutTable)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:	
	
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESTMOUTTABLE_H__BE85AC61_8ECB_4E48_8F99_B69A451739EF__INCLUDED_)
