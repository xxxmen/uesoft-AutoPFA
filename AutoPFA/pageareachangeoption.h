#if !defined(AFX_PAGEAREACHANGEOPTION_H__CB49EC29_B0C0_466D_8C8B_A7BB96E90017__INCLUDED_)
#define AFX_PAGEAREACHANGEOPTION_H__CB49EC29_B0C0_466D_8C8B_A7BB96E90017__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pageareachangeoption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageAreaChangeOption dialog

class PageAreaChangeOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageAreaChangeOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAreaChangeOption)
	enum { IDD = IDD_DLGAREACHANGEOPTION };
	CButton	m_Box;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAreaChangeOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageAreaChangeOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEAREACHANGEOPTION_H__CB49EC29_B0C0_466D_8C8B_A7BB96E90017__INCLUDED_)
