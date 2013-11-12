#if !defined(AFX_PAGEOTHER_H__3D2EDA51_39A5_4430_A895_A8B006AF410E__INCLUDED_)
#define AFX_PAGEOTHER_H__3D2EDA51_39A5_4430_A895_A8B006AF410E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageOther.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageOther dialog

class PageOther : public BaseDlg
{
// Construction
public:
	BOOL Updata();
	void Init();
	PageOther(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageOther)
	enum { IDD = IDD_PAGEOTHER };
	CComboBox	m_cmbMatrix;
	BOOL	m_bKeep;
	CString	m_strFlowRelax;
	CString	m_strMaxIter;
	CString	m_strPressRelax;
	CString	m_strIterSpan;
	//}}AFX_DATA
	int m_nKeep;
	int m_nMatrixMethod;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageOther)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageOther)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEOTHER_H__3D2EDA51_39A5_4430_A895_A8B006AF410E__INCLUDED_)
