#if !defined(AFX_OPTCONTRALTWO_H__AF607CD7_06C9_4F8C_BAB9_AE0647BC445E__INCLUDED_)
#define AFX_OPTCONTRALTWO_H__AF607CD7_06C9_4F8C_BAB9_AE0647BC445E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptContralTwo.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// COptContralTwo dialog

class COptContralTwo : public BaseDlg
{
// Construction
public:
	COptContralTwo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptContralTwo)
	enum { IDD = IDD_PAGEOPTCONTRALTWO };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptContralTwo)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptContralTwo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COptContralTwo)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTCONTRALTWO_H__AF607CD7_06C9_4F8C_BAB9_AE0647BC445E__INCLUDED_)
