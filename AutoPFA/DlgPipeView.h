#if !defined(AFX_DLGPIPEVIEW_H__3A244F5C_00A4_47A9_90BB_9564E10DA183__INCLUDED_)
#define AFX_DLGPIPEVIEW_H__3A244F5C_00A4_47A9_90BB_9564E10DA183__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPipeView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgPipeView dialog
#include "dlgtabview.h"
#include "PagePipeData.h"
#include "ComponentManager.h"

class DlgPipeView : public DlgTabView
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager);
	DlgPipeView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgPipeView)
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgPipeView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PagePipeData m_page1;

	// Generated message map functions
	//{{AFX_MSG(DlgPipeView)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPIPEVIEW_H__3A244F5C_00A4_47A9_90BB_9564E10DA183__INCLUDED_)
