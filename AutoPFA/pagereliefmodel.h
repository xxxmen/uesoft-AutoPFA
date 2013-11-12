#if !defined(AFX_PAGERELIEFMODEL_H__1BDC2D2F_B964_4E37_AD48_7D95863291A3__INCLUDED_)
#define AFX_PAGERELIEFMODEL_H__1BDC2D2F_B964_4E37_AD48_7D95863291A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagereliefmodel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageReliefModel dialog
#include "DlgBasisArea.h"
#include "TabSheet.h"
#include "pagechart.h"
#include "BaseDlg.h"
class PageReliefModel : public BaseDlg
{
// Construction
public:
	CString LossString();
	BOOL IsShowTrans();
	BOOL UpData();
	void Init();
	PageReliefModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageReliefModel)
	enum { IDD = IDD_RELIEFMODEL };
	CTabSheet	m_tab1;
	CNumEdit	m_EditExitPress;
	CNumEdit	m_EditCvOrK;
	CNumEdit	m_EditCrackPress;
	CUnitComboBox	m_cmbExitPress;
	CUnitComboBox	m_cmbCrackPress;
	CButton	m_Box;
	CString	m_strCrackPressUnit;
	CString	m_strExitPressUnit;
	CString	m_strCrackPress;
	CString	m_strCvOrK;
	CString	m_strExitPress;
	int		m_nPressType;
	int		m_nLossType;
	int		m_nType;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageReliefModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    DlgBasisArea m_dlgBasisArea;
	UnitSubSystem &m_UnitSys;
	PageChart m_page1;
	// Generated message map functions
	//{{AFX_MSG(PageReliefModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioExit();
	afx_msg void OnRadioInline();
	afx_msg void OnRadioInter();
	afx_msg void OnRadioVariableCv();
	afx_msg void OnRadioAbsHead();
	afx_msg void OnRadioAbsPress();
	afx_msg void OnRadioConstCv();
	afx_msg void OnRadioConstK();
	afx_msg void OnRadioDiffHead();
	afx_msg void OnRadioDiffPress();
	afx_msg void OnCurveData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetLossStatus();
	void SetExitStatus();
	void InitPressUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGERELIEFMODEL_H__1BDC2D2F_B964_4E37_AD48_7D95863291A3__INCLUDED_)
