#if !defined(AFX_PAGELIQUIDACCUMOPTION_H__A5D9E42D_2C5C_4C39_A85A_B97731236F09__INCLUDED_)
#define AFX_PAGELIQUIDACCUMOPTION_H__A5D9E42D_2C5C_4C39_A85A_B97731236F09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageLiquidAccumOption.h : header file
//
#include "dlginitpressguess.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageLiquidAccumOption dialog

class PageLiquidAccumOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageLiquidAccumOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageLiquidAccumOption)
	enum { IDD = IDD_LIQUIDACCUMOPTION };
	CButton	m_Box;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageLiquidAccumOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgInitPressGuess m_DlgInitGuess;

	// Generated message map functions
	//{{AFX_MSG(PageLiquidAccumOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGELIQUIDACCUMOPTION_H__A5D9E42D_2C5C_4C39_A85A_B97731236F09__INCLUDED_)
