#if !defined(AFX_FILEPREVIEWDLG_H__6F8E1C81_900C_11D6_94FC_5254AB3B95BA__INCLUDED_)
#define AFX_FILEPREVIEWDLG_H__6F8E1C81_900C_11D6_94FC_5254AB3B95BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FilePreviewDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFilePreviewDlg dialog
#include "resource.h"
#include "FilePreviewDlgArea.h"
#include "FileDialogEx.h"

#include "ScenariManage.h"
#include "WorkSpaceRef.h"
#include "PersistentMgr.h"
#include "ScenariManage.h"
class CFilePreviewDlg : public CFileDialogEx
{
	DECLARE_DYNAMIC(CFilePreviewDlg)
public:
	CFilePreviewDlgArea m_Area;
	CFilePreviewDlg(BOOL bOpenFileDialog, // TRUE for FileOpen, FALSE for FileSaveAs
		LPCTSTR lpszDefExt = NULL,
		LPCTSTR lpszFileName = NULL,
		DWORD dwFlags = OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
		LPCTSTR lpszFilter = NULL,
		CWnd* pParentWnd = NULL);
public:
	void Draw(CDC* pDC);
	BOOL CheckFileName( const CString& strFileName );
// Dialog Data
	//{{AFX_DATA(CFilePreviewDlg)
	enum { IDD = IDD_PREVIEW };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFilePreviewDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
public:
	//{{AFX_MSG(CFilePreviewDlg)
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEPREVIEWDLG_H__6F8E1C81_900C_11D6_94FC_5254AB3B95BA__INCLUDED_)
