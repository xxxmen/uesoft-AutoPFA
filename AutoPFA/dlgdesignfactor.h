#if !defined(AFX_DLGDESIGNFACTOR_H__5770A7CF_006B_4A25_94BE_A951FD1EC67D__INCLUDED_)
#define AFX_DLGDESIGNFACTOR_H__5770A7CF_006B_4A25_94BE_A951FD1EC67D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgdesignfactor.h : header file
//
#include "StrFlyWeight.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// DlgDesignFactor dialog

class DlgDesignFactor : public BaseDlg
{
// Construction
public:
	void SetDesignCaption(CString strCaption);
	BOOL UpData(StrFlyWeight &ref);
	void Init(StrFlyWeight &ref);
	DlgDesignFactor(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgDesignFactor)
	enum { IDD = IDD_DESIGNFACTOR };
	CString	m_strDesignFactor;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgDesignFactor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgDesignFactor)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDESIGNFACTOR_H__5770A7CF_006B_4A25_94BE_A951FD1EC67D__INCLUDED_)
