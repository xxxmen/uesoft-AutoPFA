#if !defined(AFX_DLGGENERALOUTVIEW_H__3A8B0AE1_2935_43C9_82FA_A638BA68D2B1__INCLUDED_)
#define AFX_DLGGENERALOUTVIEW_H__3A8B0AE1_2935_43C9_82FA_A638BA68D2B1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGeneralOutView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgGeneralOutView dialog
#include "dlgtabview.h"
#include "PageGeneralInfo.h"
#include "Scenario.h"
class NetModel;
class PFAOutModel;

class DlgGeneralOutView : public DlgTabView
{
// Construction
public:
	void LoadData(Scenario* pScenario, PFAOutModel &outModel);
	DlgGeneralOutView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgGeneralOutView)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgGeneralOutView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageGeneralInfo m_page1;

	// Generated message map functions
	//{{AFX_MSG(DlgGeneralOutView)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGENERALOUTVIEW_H__3A8B0AE1_2935_43C9_82FA_A638BA68D2B1__INCLUDED_)
