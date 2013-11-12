#if !defined(AFX_PAGEDEADENDOPTION_H__232EF5C2_9E8E_45F1_B551_8EF4FFAF336E__INCLUDED_)
#define AFX_PAGEDEADENDOPTION_H__232EF5C2_9E8E_45F1_B551_8EF4FFAF336E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageDeadEndOption.h : header file
//
#include "dlginitpressguess.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageDeadEndOption dialog

class PageDeadEndOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageDeadEndOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageDeadEndOption)
	enum { IDD = IDD_DEADENDOPTION };
	CButton	m_Box;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageDeadEndOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgInitPressGuess m_DlgInitGuess;

	// Generated message map functions
	//{{AFX_MSG(PageDeadEndOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEDEADENDOPTION_H__232EF5C2_9E8E_45F1_B551_8EF4FFAF336E__INCLUDED_)
