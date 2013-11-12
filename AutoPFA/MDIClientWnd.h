#if !defined(AFX_MDICLIENTWND_H__3B7C8731_53AE_4AF3_B5A2_C4376ADBDE82__INCLUDED_)
#define AFX_MDICLIENTWND_H__3B7C8731_53AE_4AF3_B5A2_C4376ADBDE82__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MDIClientWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMDIClientWnd window
#include "resource.h"
class CMDIClientWnd : public CWnd
{
// Construction
public:
	CMDIClientWnd();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDIClientWnd)
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMDIClientWnd();

	// Generated message map functions
protected:
#ifdef _TEST
	afx_msg LRESULT OnMDISetMenu(WPARAM wParam,LPARAM lParam);
#endif
	//{{AFX_MSG(CMDIClientWnd)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDICLIENTWND_H__3B7C8731_53AE_4AF3_B5A2_C4376ADBDE82__INCLUDED_)
