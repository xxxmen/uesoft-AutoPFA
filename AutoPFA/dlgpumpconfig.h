#if !defined(AFX_DLGPUMPCONFIG_H__15F3A27A_8156_4EB0_A367_6CDBC5B48CC0__INCLUDED_)
#define AFX_DLGPUMPCONFIG_H__15F3A27A_8156_4EB0_A367_6CDBC5B48CC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgpumpconfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgPumpConfig dialog
#include "TabSheet.h"
#include "pageconfigdata.h"
#include "PageConfiguration.h"

class DlgPumpConfig : public CDialog
{
// Construction
public:
	void UpData();
	DlgPumpConfig(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgPumpConfig)
	enum { IDD = IDD_DLGPUMPCONFIG };
	CTabSheet	m_tab;
	CComboBox	m_cmbPressUnit;
	CComboBox	m_cbmPowerUnit;
	CComboBox	m_cmbFlowUnit;
	CString	m_strFlowUnit;
	CString	m_strPowerUnit;
	CString	m_strPressUnit;
	int		m_nPower;
	int		m_nPress;
	int		m_nFlow;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgPumpConfig)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageConfigData m_page1;
	PageConfiguration m_page2;
	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(DlgPumpConfig)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioEffic();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioMassFlow();
	afx_msg void OnRadioPower();
	afx_msg void OnRadioPress();
	afx_msg void OnRadioVolFlow();
	afx_msg void OnSelchangeFlow();
	afx_msg void OnSelchangePower();
	afx_msg void OnSelchangePress();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitPage1();
	CString PowerUnit();
	CString PressUnit();
	CString FlowUnit();
	void InitPowerUnit();
	void InitPressUnit();
	void InitFlowUnit();
	void Init();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPUMPCONFIG_H__15F3A27A_8156_4EB0_A367_6CDBC5B48CC0__INCLUDED_)
