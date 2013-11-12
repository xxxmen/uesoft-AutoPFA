#if !defined(AFX_FILEPREVIEWDLGAREA_H__6B77989D_2664_4E2D_9980_50D3929D2BFC__INCLUDED_)
#define AFX_FILEPREVIEWDLGAREA_H__6B77989D_2664_4E2D_9980_50D3929D2BFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FilePreviewDlgArea.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFilePreviewDlgArea window
class CFilePreviewDlg;
class CFilePreviewDlgArea : public CWnd
{
// Construction
public:
	CFilePreviewDlgArea();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilePreviewDlgArea)
	//}}AFX_VIRTUAL

// Implementation
public:
	CFilePreviewDlg* m_pParentDlg;
	virtual ~CFilePreviewDlgArea();

	// Generated message map functions
protected:
	BOOL RegisterWindowClass();
	//{{AFX_MSG(CFilePreviewDlgArea)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEPREVIEWDLGAREA_H__6B77989D_2664_4E2D_9980_50D3929D2BFC__INCLUDED_)
