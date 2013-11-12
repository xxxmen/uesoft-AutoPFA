#if !defined(AFX_DLGGENRALCURVE_H__AB4664F2_5B05_463A_A8B4_705FED015FDD__INCLUDED_)
#define AFX_DLGGENRALCURVE_H__AB4664F2_5B05_463A_A8B4_705FED015FDD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGenralCurve.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgGenralCurve dialog
#include "TabSheet.h"
#include "PageCurveData.h"

class DlgGenralCurve : public CDialog
{
// Construction
public:
	void UpData();
	DlgGenralCurve(ArrayFlyWeight<13> &ref,UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgGenralCurve)
	enum { IDD = IDD_GENRALCURVE };
	CTabSheet	m_tab;
	CComboBox	m_cmbPressUnit;
	CComboBox	m_cmbFlowUnit;
	CString	m_strFlowUnit;
	CString	m_strPressUnit;
	int		m_nPress;
	int		m_nFlow;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgGenralCurve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	ArrayFlyWeight<13> &m_Curve;
	PageCurveData m_page1;
	// Generated message map functions
	//{{AFX_MSG(DlgGenralCurve)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioMassFlow();
	afx_msg void OnRadioPress();
	afx_msg void OnRadioVolFlow();
	afx_msg void OnSelchangeFlow();
	afx_msg void OnSelchangePress();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitPage1();
	CString PressUnit();
	CString FlowUnit();
	void InitPressUnit();
	void InitFlowUnit();
	void Init();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGENRALCURVE_H__AB4664F2_5B05_463A_A8B4_705FED015FDD__INCLUDED_)
