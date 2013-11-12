#if !defined(AFX_GRAPHFRAME_H__096483E0_9992_43E5_8551_40AD8F1AFCDE__INCLUDED_)
#define AFX_GRAPHFRAME_H__096483E0_9992_43E5_8551_40AD8F1AFCDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// graphframe.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGraphFrame frame

class CGraphFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CGraphFrame)
protected:
	CGraphFrame();           // protected constructor used by dynamic creation

// Attributes
public:
	CToolBar    m_GraphBar;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGraphFrame)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CGraphFrame();

	// Generated message map functions
	//{{AFX_MSG(CGraphFrame)
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	virtual void OnUpdateFrameTitle(BOOL bAddToTitle);
	
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHFRAME_H__096483E0_9992_43E5_8551_40AD8F1AFCDE__INCLUDED_)
