#if !defined(AFX_PAGEVALVEMODEL_H__18F92210_4A53_40C2_9348_229FCB3AC091__INCLUDED_)
#define AFX_PAGEVALVEMODEL_H__18F92210_4A53_40C2_9348_229FCB3AC091__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageValveModel.h : header file
//
#include "DlgBasisArea.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageValveModel dialog

class PageValveModel : public BaseDlg
{
// Construction
public:
	CString LossString();
	BOOL UpData();
	void Init();
	PageValveModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageValveModel)
	enum { IDD = IDD_VALVEMODEL };
	CNumEdit	m_EditExitPress;
	CNumEdit	m_EditCvOrK;
	CComboBox	m_cmbHandBook;
	CUnitComboBox	m_cmbExitPress;
	CButton	m_Box;
	BOOL	m_bCheckExit;
	CString	m_strCvOrK;
	CString	m_strExitPress;
	int		m_nHandBook;
	int		m_nLossType;
	int		m_nPressType;
	CString	m_strExitPressUnit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageValveModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	DlgBasisArea m_dlgBasisArea;

	// Generated message map functions
	//{{AFX_MSG(PageValveModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	afx_msg void OnRadioConstCv();
	afx_msg void OnRadioConstK();
	afx_msg void OnCheckExit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ExitPressSatus();
	void SetLossStatus();
	void InitPressUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVALVEMODEL_H__18F92210_4A53_40C2_9348_229FCB3AC091__INCLUDED_)
