#if !defined(AFX_PAGEPIPEGRAPH_H__28F3ACA3_E658_4946_AD5C_359D4A18E0DE__INCLUDED_)
#define AFX_PAGEPIPEGRAPH_H__28F3ACA3_E658_4946_AD5C_359D4A18E0DE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PagePipeGraph.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PagePipeGraph dialog
#include "PageGraph.h"

class PagePipeGraph : public PageGraph
{
// Construction
public:
	void ShowData(TranOutMgr &mgr,GraphView &view);
	void InitData(OutMgr &mgr, OutAttrArray &Array);
	PagePipeGraph(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PagePipeGraph)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PagePipeGraph)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(PagePipeGraph)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEPIPEGRAPH_H__28F3ACA3_E658_4946_AD5C_359D4A18E0DE__INCLUDED_)
