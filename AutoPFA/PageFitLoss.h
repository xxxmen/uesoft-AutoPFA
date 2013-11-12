#if !defined(AFX_PAGEFITLOSS_H__2137491D_2906_4EE1_BC28_7E8943BE04A7__INCLUDED_)
#define AFX_PAGEFITLOSS_H__2137491D_2906_4EE1_BC28_7E8943BE04A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageFitLoss.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageFitLoss dialog

class PageFitLoss : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageFitLoss(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageFitLoss)
	enum { IDD = IDD_PAGEFITLOSS };
	CString	m_strLocalK;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageFitLoss)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageFitLoss)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEFITLOSS_H__2137491D_2906_4EE1_BC28_7E8943BE04A7__INCLUDED_)
