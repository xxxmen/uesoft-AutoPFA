#if !defined(AFX_PAGERELIEFOPTION_H__7A4FB6A4_7848_4D7A_9D36_B8AEB0C67B4D__INCLUDED_)
#define AFX_PAGERELIEFOPTION_H__7A4FB6A4_7848_4D7A_9D36_B8AEB0C67B4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageReliefOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageReliefOption dialog

class PageReliefOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageReliefOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageReliefOption)
	enum { IDD = IDD_RELIEFOPTION };
	CButton	m_Box;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageReliefOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageReliefOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGERELIEFOPTION_H__7A4FB6A4_7848_4D7A_9D36_B8AEB0C67B4D__INCLUDED_)
