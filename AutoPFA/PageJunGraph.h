#if !defined(AFX_PAGEJUNGRAPH_H__DF506F31_1237_49C9_B14C_D3D10B92E1A4__INCLUDED_)
#define AFX_PAGEJUNGRAPH_H__DF506F31_1237_49C9_B14C_D3D10B92E1A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageJunGraph.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageJunGraph dialog
#include "PageGraph.h"

class PageJunGraph : public PageGraph
{
// Construction
public:
	void ShowData(TranOutMgr &mgr,GraphView &view);
	void InitData(OutMgr &mgr, OutAttrArray &Array);
	PageJunGraph(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageJunGraph)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageJunGraph)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageJunGraph)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEJUNGRAPH_H__DF506F31_1237_49C9_B14C_D3D10B92E1A4__INCLUDED_)
