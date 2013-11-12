#if !defined(AFX_PAGECHECKMODEL_H__6002326B_FA6B_42AA_BD3C_E73B412F00A8__INCLUDED_)
#define AFX_PAGECHECKMODEL_H__6002326B_FA6B_42AA_BD3C_E73B412F00A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagecheckmodel.h : header file
//
#include "DlgBasisArea.h"
#include "BaseDlg.h"
#include "numedit.h"
/////////////////////////////////////////////////////////////////////////////
// PageCheckModel dialog

class PageCheckModel : public BaseDlg
{
// Construction
public:
	CString LossString();
	BOOL UpData();
	void Init();
	PageCheckModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageCheckModel)
	enum { IDD = IDD_CHECKMODEL };
	CNumEdit	m_EditVelocity;
	CNumEdit	m_EditPress;
	CNumEdit	m_EditCvOrK;
	CUnitComboBox	m_cmbVelocityUnit;
	CUnitComboBox	m_cmbPressUnit;
	CButton	m_Box;
	CString	m_strPressUnit;
	CString	m_strVelocityUnit;
	CString	m_strCvOrK;
	CString	m_strPress;
	CString	m_strVelocity;
	int		m_nPressType;
	int		m_nLossType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageCheckModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
     DlgBasisArea m_dlgBasisArea;
	 UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(PageCheckModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	afx_msg void OnRadioConstCv();
	afx_msg void OnRadioConstK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void LossStatus();
	void InitPressUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECHECKMODEL_H__6002326B_FA6B_42AA_BD3C_E73B412F00A8__INCLUDED_)
