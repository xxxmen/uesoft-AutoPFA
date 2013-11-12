#if !defined(AFX_DLGTABVIEW_H__F1631274_08A8_4448_A545_3AF21C812DC2__INCLUDED_)
#define AFX_DLGTABVIEW_H__F1631274_08A8_4448_A545_3AF21C812DC2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgtabview.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgTabView dialog
#include "TabSheet.h"
#include "BaseDlg.h"


class DlgTabView : public BaseDlg
{
// Construction
public:
	DlgTabView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgTabView)
	enum { IDD = IDD_DLGTABVIEW };
	CTabSheet	m_tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTabView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgTabView)
		// NOTE: the ClassWizard will add member functions here
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTABVIEW_H__F1631274_08A8_4448_A545_3AF21C812DC2__INCLUDED_)
