#if !defined(AFX_PAGESURGEOPTION_H__088BC240_972A_40A8_A084_0FC1D5FD18A3__INCLUDED_)
#define AFX_PAGESURGEOPTION_H__088BC240_972A_40A8_A084_0FC1D5FD18A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSurgeOption.h : header file
//
#include "dlginitpressguess.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageSurgeOption dialog

class PageSurgeOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageSurgeOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSurgeOption)
	enum { IDD = IDD_SURGEOPTION };
	CNumEdit	m_EditHeight;
	CUnitComboBox	m_cmbHeight;
	CButton	m_Box;
	BOOL	m_bInitHeight;
	CString	m_strHeightUnit;
	CString	m_strHeight;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSurgeOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgInitPressGuess m_DlgInitGuess;
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(PageSurgeOption)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckInitHeight();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetInitHeightStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESURGEOPTION_H__088BC240_972A_40A8_A084_0FC1D5FD18A3__INCLUDED_)
