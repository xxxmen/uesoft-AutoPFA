#if !defined(AFX_PAGESPRAYMODEL_H__8945897D_0C2C_4369_B751_6B2C28E919C6__INCLUDED_)
#define AFX_PAGESPRAYMODEL_H__8945897D_0C2C_4369_B751_6B2C28E919C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageSprayModel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageSprayModel dialog
#include "BaseDlg.h"

class PageSprayModel : public BaseDlg
{
// Construction
public:
	CString SprayString();
	CString SprayUnit();
	BOOL UpData();
	void Init();
	PageSprayModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSprayModel)
	enum { IDD = IDD_SPRAYMODEL };
	CNumEdit	m_EditHoleNum;
	CNumEdit	m_EditHoleArea;
	CNumEdit	m_EditExitPress;
	CNumEdit	m_EditCvOrK;
	CUnitComboBox	m_cmbHoleAreaUnit;
	CComboBox	m_cmbFireKUnit2;
	CComboBox	m_cmbFireKUnit1;
	CUnitComboBox	m_cmbExitPress;
	CString	m_strFireKUnit1;
	CString	m_strFireKUnit2;
	CString	m_strHoleAreaUnit;
	CString	m_strCvOrK;
	CString	m_strExitPressUnit;
	CString	m_strExitPress;
	CString	m_strHoleArea;
	CString	m_strHoleNum;
	int		m_nPressType;
	int		m_nGeometry;
	int		m_nLossType;
	//}}AFX_DATA
	int m_nFireKType;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSprayModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(PageSprayModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	afx_msg void OnRadioSparger();
	afx_msg void OnRadioSpray();
	afx_msg void OnRadioFireK();
	afx_msg void OnRadioConstCv();
	afx_msg void OnSelchangeHoleAreaUnit();
	afx_msg void OnSelchangeFirekUnit1();
	afx_msg void OnSelchangeFirekUnit2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ChangeType();
	void ChangeUnit();
	void SetLossStatus();
	void SetGeometryStatus();
	void InitExitPressUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESPRAYMODEL_H__8945897D_0C2C_4369_B751_6B2C28E919C6__INCLUDED_)
