#if !defined(AFX_DLGCOPYDATA_H__3B00098F_6D86_43BA_8D21_04A5D4981141__INCLUDED_)
#define AFX_DLGCOPYDATA_H__3B00098F_6D86_43BA_8D21_04A5D4981141__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCopyData.h : header file
//

#include "Component.h"

/////////////////////////////////////////////////////////////////////////////
// DlgCopyData dialog

class DlgCopyData : public CDialog
{
// Construction
public:
	DlgCopyData( Component* pSrcComponent , Component* pAimComponent , CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgCopyData)
	enum { IDD = IDD_Dlg_CopyData };
	CListCtrl	m_attrList;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgCopyData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
protected:
	Component* m_pSrcComponent;//被拷贝对象
	Component* m_pAimComponent;//拷贝对象
protected:
	BOOL m_bOther;//其它项标志

	// Generated message map functions
	//{{AFX_MSG(DlgCopyData)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelectAll();
	afx_msg void OnSelectNone();
	afx_msg void OnInvert();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCOPYDATA_H__3B00098F_6D86_43BA_8D21_04A5D4981141__INCLUDED_)
