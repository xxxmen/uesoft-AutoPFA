#if !defined(AFX_DLGPIPEMODEL_H__B5A28B77_F8F8_48D9_BE9D_A8243F08ED03__INCLUDED_)
#define AFX_DLGPIPEMODEL_H__B5A28B77_F8F8_48D9_BE9D_A8243F08ED03__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgpipemodel.h : header file
//
#include "Pipe.h"
#include "BaseDlg.h"
#include "atlstr.h"
#include "afxwin.h"
/////////////////////////////////////////////////////////////////////////////
// DlgPipeModel dialog
class ComponentManager;

class DlgPipeModel : public BaseDlg
{
// Construction
public:
	void SetLossStatus();
	void UpData();
	void Init();
	DlgPipeModel(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgPipeModel)
	enum { IDD = IDD_PAGEPIPEMODEL };
	CNumEdit	m_EditFriction;
	CNumEdit	m_EditElastic;
	CNumEdit	m_EditInDia;
	CNumEdit	m_EditLen;
	CNumEdit	m_EditPossion;
	CNumEdit	m_EditThick;
	CNumEdit	m_EditWave;
	CNumEdit	m_EditC1;
	CComboBox	m_cmbLossType;
	CComboBox	m_cmbType;
	CUnitComboBox	m_cmbThick;
	CComboBox	m_cmbSupport;
	CComboBox	m_cmbSize;
	CComboBox	m_cmbMaterail;
	CUnitComboBox	m_cmbFriction;
	CUnitComboBox	m_cmbElaticity;
	CUnitComboBox	m_cmbWaveUnit;
	CUnitComboBox	m_cmbLenUnit;
	CUnitComboBox	m_cmbInDiaUnit;
	CString	m_strInDiaUnit;
	CString	m_strLenUnit;
	CString	m_strWaveUnit;
	CString	m_strInDia;
	CString	m_strLen;
	CString	m_strWave;
	CString	m_strElasticityUnit;
	CString	m_strThickUnit;
	CString	m_strType;
	CString	m_strC1;
	CString	m_strElasticity;
	CString	m_strFrictionUnit;
	CString	m_strFriction;
	CString	m_strInDiaReduce;
	CString	m_strPossionRatio;
	CString	m_strThick;
	int		m_bCalcWave;
	CString	m_strMaterial;
	CString	m_strSize;
	//}}AFX_DATA

	UnitSubSystem &m_UnitSys;
	ComponentManager &m_manager;
	int m_support;
	int m_frictionModel;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgPipeModel)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgPipeModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioAssign();
	afx_msg void OnRadioCalc();
	afx_msg void OnSelchangeSupport();
	afx_msg void OnSelchangeLoss();
	afx_msg void OnSelchangeMatirail();
	afx_msg void OnChangeC1();
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
	
private:
	void CalcWaveSpeed();
	void SetControlStatus();
	CStatic m_ThickControl;
	CStatic m_ElasticityControl;
	CStatic m_PossinControl;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPIPEMODEL_H__B5A28B77_F8F8_48D9_BE9D_A8243F08ED03__INCLUDED_)
