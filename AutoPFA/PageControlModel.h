#if !defined(AFX_PAGECONTROLMODEL_H__540D49D4_61B8_4014_BBA6_ADD230ACF628__INCLUDED_)
#define AFX_PAGECONTROLMODEL_H__540D49D4_61B8_4014_BBA6_ADD230ACF628__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageControlModel.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageControlModel dialog

class PageControlModel : public BaseDlg
{
// Construction
public:
	CString LossString();
	CString CtrlString();
	CString CtrlUnit();
	BOOL UpData();
	void Init();
	PageControlModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageControlModel)
	enum { IDD = IDD_CONTROLMODEL };
	CButton	m_RadioOpen2;
	CButton	m_RadioOpen1;
	CNumEdit	m_EditSetValue;
	CNumEdit	m_EditKOrCv;
	CUnitComboBox	m_cmbSetUnit;
	BOOL	m_bAlways;
	BOOL	m_bDefault;
	CString	m_strSetUnit;
	CString	m_strKOrCv;
	CString	m_strSetValue;
	int		m_nLossType;
	int		m_nInSuffic;
	int		m_nExceesive;
	int		m_nType;
	int		m_nPress;
	int		m_nSetType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageControlModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(PageControlModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioType1();
	afx_msg void OnRadioType2();
	afx_msg void OnRadioTableCv();
	afx_msg void OnRadioPSV();
	afx_msg void OnRadioPRV();
	afx_msg void OnRadioPDCV();
	afx_msg void OnRadioK();
	afx_msg void OnRadioFCV();
	afx_msg void OnRadioCv();
	afx_msg void OnCheckDefault();
	afx_msg void OnSelchangeSetUnit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void FailActionStatus();
	void InitSetUnit();
	void SetPointStatus();
	void FullOpenLossStatus();
	void LossModelStatus();
	void SetTypeStatus();

	void ChangeType();
	void ChangeUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONTROLMODEL_H__540D49D4_61B8_4014_BBA6_ADD230ACF628__INCLUDED_)
