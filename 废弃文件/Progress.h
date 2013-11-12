#if !defined(AFX_PROGRESS_H__9E1DDE90_2F04_44D5_AC92_5E74A84E3CAA__INCLUDED_)
#define AFX_PROGRESS_H__9E1DDE90_2F04_44D5_AC92_5E74A84E3CAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Progress.h : header file
//
#include "AutoPFA.h"
/////////////////////////////////////////////////////////////////////////////
// CProgress dialog

class CProgress : public CDialog
{
// Construction
public:
	CProgress(CWnd* pParent = NULL);   // standard constructor
	bool ProssMove( int iKeyOfProgress, int iStep = 1, int iPos = -1 );

// Dialog Data
	//{{AFX_DATA(CProgress)
	enum { IDD = IDD_DLGPROGRESS };
	CProgressCtrl	m_proParentStep;
	CProgressCtrl	m_proChildStep;
	CString	m_strChildStep;
	CString	m_strParentStep;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgress)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CProgress)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CProgress)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESS_H__9E1DDE90_2F04_44D5_AC92_5E74A84E3CAA__INCLUDED_)
