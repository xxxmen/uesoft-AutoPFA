#if !defined(AFX_MODELDATAFRAME_H__0981C7DC_6869_455F_A97F_7D734FF92D03__INCLUDED_)
#define AFX_MODELDATAFRAME_H__0981C7DC_6869_455F_A97F_7D734FF92D03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModelDataFrame.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModelDataFrame frame

class CModelDataFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CModelDataFrame)
protected:
	CModelDataFrame();           // protected constructor used by dynamic creation

// Attributes
public:
	CDialogBar  m_wndDlgBar;
// Operations
public:
	int GetCurSelShow();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModelDataFrame)
	public:
	virtual BOOL DestroyWindow();
	protected:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CModelDataFrame();

	// Generated message map functions
	//{{AFX_MSG(CModelDataFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELDATAFRAME_H__0981C7DC_6869_455F_A97F_7D734FF92D03__INCLUDED_)
