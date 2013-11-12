#if !defined(AFX_PAGEBREAKERMODEL_H__19A1B3B1_D0DB_414E_80B8_A81BBD7EB071__INCLUDED_)
#define AFX_PAGEBREAKERMODEL_H__19A1B3B1_D0DB_414E_80B8_A81BBD7EB071__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagebreakermodel.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageBreakerModel dialog

class PageBreakerModel : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageBreakerModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageBreakerModel)
	enum { IDD = IDD_BREAKERMODEL };
	CNumEdit	m_EditWeight;
	CNumEdit	m_EditOutFlow;
	CNumEdit	m_EditMediateVlaue;
	CNumEdit	m_EditMediateOut;
	CNumEdit	m_EditLiquidTemp;
	CNumEdit	m_EditInFlow;
	CNumEdit	m_EditGasTemp;
	CNumEdit	m_EditGasPress;
	CNumEdit	m_EditGasMass;
	CNumEdit	m_EditCrackPress;
	CNumEdit	m_EditCpCv;
	CUnitComboBox	m_cmbOutFlow;
	CUnitComboBox	m_cmbMediate;
	CUnitComboBox	m_cmbMediateOut;
	CUnitComboBox	m_cmbLiquidTemp;
	CUnitComboBox	m_cmbInFlow;
	CUnitComboBox	m_cmbGasTemp;
	CUnitComboBox	m_cmbGasPress;
	CUnitComboBox	m_cmbGasMass;
	CUnitComboBox	m_cmbCrackPress;
	CString	m_strCrackPressUnit;
	CString	m_strGasMassUnit;
	CString	m_strGasPressUnit;
	CString	m_strGasTempUnit;
	CString	m_strInFlowUnit;
	CString	m_strLiquidTempUnit;
	CString	m_strMediateOutUnit;
	CString	m_strMediteUnit;
	CString	m_strOutFlowUnit;
	CString	m_strCpCv;
	CString	m_strCrackPress;
	CString	m_strGasMass;
	CString	m_strGasPress;
	CString	m_strGasTemp;
	CString	m_strInFlow;
	CString	m_strLiquidTemp;
	CString	m_strMediateOut;
	CString	m_strMediateValue;
	CString	m_strOurFlow;
	CString	m_strWeight;
	int		m_nAirType;
	int		m_nMediateType;
	int		m_nType;
	int		m_nConnectPipe;
	int		m_nLiquidTempType;
	int		m_nCrackPressType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageBreakerModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(PageBreakerModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioSystem();
	afx_msg void OnRadioCustom();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	afx_msg void OnRadioOther();
	afx_msg void OnRadioAir();
	afx_msg void OnRadioMediatePress();
	afx_msg void OnRadioVolumeFlow();
	afx_msg void OnRadioRelease();
	afx_msg void OnRadioDual();
	afx_msg void OnRadioBreaker();
	afx_msg void OnRadio3Stage();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetTypeStatus();
	void SetAirStatus();
	void InitCrackPressUnit();
	void SetLiquidTempStatus();
	void InitMediateUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEBREAKERMODEL_H__19A1B3B1_D0DB_414E_80B8_A81BBD7EB071__INCLUDED_)
