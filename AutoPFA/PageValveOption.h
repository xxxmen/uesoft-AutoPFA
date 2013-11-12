#if !defined(AFX_PAGEVALVEOPTION_H__1E99724A_41EC_4AE2_8AEE_3DF6AC0D031D__INCLUDED_)
#define AFX_PAGEVALVEOPTION_H__1E99724A_41EC_4AE2_8AEE_3DF6AC0D031D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageValveOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageValveOption dialog

class PageValveOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageValveOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageValveOption)
	enum { IDD = IDD_VALVEOPTION };
	CButton	m_Box;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageValveOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageValveOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVALVEOPTION_H__1E99724A_41EC_4AE2_8AEE_3DF6AC0D031D__INCLUDED_)
