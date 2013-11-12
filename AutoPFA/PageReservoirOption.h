#if !defined(AFX_PAGERESERVOIROPTION_H__48DB7D64_8C86_40ED_855E_A5FD0359C13C__INCLUDED_)
#define AFX_PAGERESERVOIROPTION_H__48DB7D64_8C86_40ED_855E_A5FD0359C13C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageReservoirOption.h : header file
//
#include "dlgdesignfactor.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageReservoirOption dialog

class PageReservoirOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageReservoirOption(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageReservoirOption)
	enum { IDD = IDD_RESERVIOROPTION };
	CButton	m_Box;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageReservoirOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgDesignFactor m_dlgDesignFactor;

	// Generated message map functions
	//{{AFX_MSG(PageReservoirOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGERESERVOIROPTION_H__48DB7D64_8C86_40ED_855E_A5FD0359C13C__INCLUDED_)
