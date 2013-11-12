#if !defined(AFX_MYSTABAR_H__C9A9249B_0831_4517_8E3E_860FBB4E49CC__INCLUDED_)
#define AFX_MYSTABAR_H__C9A9249B_0831_4517_8E3E_860FBB4E49CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyStaBar.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyStaBar window

class CMyStaBar : public CStatusBar
{
// Construction
public:
	CMyStaBar();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyStaBar)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyStaBar();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyStaBar)
	afx_msg void OnPaint();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSTABAR_H__C9A9249B_0831_4517_8E3E_860FBB4E49CC__INCLUDED_)
