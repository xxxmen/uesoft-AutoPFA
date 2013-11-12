#if !defined(AFX_PAGECONTROLOPTION_H__57A2C3E3_59B1_4754_BE81_06B7F91A9516__INCLUDED_)
#define AFX_PAGECONTROLOPTION_H__57A2C3E3_59B1_4754_BE81_06B7F91A9516__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageControlOption.h : header file
//
#include "dlgoption.h"
/////////////////////////////////////////////////////////////////////////////
// PageControlOption dialog
#include "DlgRawDataTable.h"
#include "BaseDlg.h"

class PageControlOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageControlOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageControlOption)
	enum { IDD = IDD_CONTROLOPTION };
	CComboBox	m_cmbAreaUnit;
	CButton	m_CvBox;
	CButton	m_Box;
	int		m_nSpecial;
	CString	m_strAreaUnit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageControlOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;
	DlgRawDataTable m_CvData;
	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(PageControlOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONTROLOPTION_H__57A2C3E3_59B1_4754_BE81_06B7F91A9516__INCLUDED_)
