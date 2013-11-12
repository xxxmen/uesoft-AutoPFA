#if !defined(AFX_PAGEGASACCUMOPTION_H__2DD05E95_332D_45C1_B5B6_E9F10694424C__INCLUDED_)
#define AFX_PAGEGASACCUMOPTION_H__2DD05E95_332D_45C1_B5B6_E9F10694424C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGasAccumOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageGasAccumOption dialog

class PageGasAccumOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageGasAccumOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGasAccumOption)
	enum { IDD = IDD_GASACCUMOPTION };
	CNumEdit	m_EditInitPress;
	CUnitComboBox	m_cmbInitPress;
	CButton	m_Box;
	BOOL	m_bInitPress;
	CString	m_strPressUnit;
	CString	m_strInitPress;
	int		m_nPressType;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGasAccumOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    UnitSubSystem &m_UnitSys;
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageGasAccumOption)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	afx_msg void OnCheckInitpress();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetInitPressStatus();
	void InitPressUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGASACCUMOPTION_H__2DD05E95_332D_45C1_B5B6_E9F10694424C__INCLUDED_)
