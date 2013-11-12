#if !defined(AFX_PAGEPUMPMODEL_H__E6D85FF5_64C6_45E6_BBA6_6EF5DD3D458C__INCLUDED_)
#define AFX_PAGEPUMPMODEL_H__E6D85FF5_64C6_45E6_BBA6_6EF5DD3D458C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PagePumpModel.h : header file
//
#include "TabSheet.h"
/////////////////////////////////////////////////////////////////////////////
// PagePumpModel dialog
#include "dlgpumpconfig.h"
#include "pagechart.h"
#include "BaseDlg.h"
class PagePumpModel : public BaseDlg
{
// Construction
public:
	int PumpType();
	CString FlowUnit();
	BOOL UpData();
	void Init();
	PagePumpModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PagePumpModel)
	enum { IDD = IDD_PUMPMODEL };
	CTabSheet	m_tab;
	CNumEdit	m_EditVelocity;
	CNumEdit	m_EditSuctionPress;
	CNumEdit	m_EditOpenPress;
	CNumEdit	m_EditFlowRate;
	CUnitComboBox	m_cmbVelocity;
	CUnitComboBox	m_cmbSuctionPress;
	CUnitComboBox	m_cmbOpenPress;
	CUnitComboBox	m_cmbFlowRateUnit;
	BOOL	m_bAntiReserse;
	BOOL	m_bCheckValve;
	BOOL	m_bSubmerge;
	CString	m_strFlowRateUnit;
	CString	m_strOpenPressUnit;
	CString	m_strSuctionPressUnit;
	CString	m_strVelocityUnit;
	CString	m_strFlowRate;
	CString	m_strOpenPress;
	CString	m_strSuctionPress;
	CString	m_strVelocity;
	int		m_nType;
	int		m_nSuctionPressType;
	int		m_nOpenPressType;
	//}}AFX_DATA
	int m_nFlowType;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PagePumpModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	PageChart m_Page1;
	PageChart m_Page2;
	PageChart m_Page3;
	// Generated message map functions
	//{{AFX_MSG(PagePumpModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioCurve();
	afx_msg void OnRadioMassFlow();
	afx_msg void OnRadioVolumeFlow();
	afx_msg void OnCheckCheckValve();
	afx_msg void OnCheckSubmerge();
	afx_msg void OnSelchangeFlowUnit();
	afx_msg void OnConfig();
	afx_msg void OnRadioOpenHead();
	afx_msg void OnRadioOpenPress();
	afx_msg void OnRadioPress();
	afx_msg void OnRadioHead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitChart(PageChart &Page,CString strYTitle,ArrayFlyWeight<7> &ref,int nIndex);
	void InitHQChart();
	void ChangeType();
	void SetSubmergeStatus();
	void SetTypeStatus();
	void SetCheckStatus();
	void InitSuctionPressUnit();
	void InitOpenPressUnit();
	void InitFlowUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEPUMPMODEL_H__E6D85FF5_64C6_45E6_BBA6_6EF5DD3D458C__INCLUDED_)
