#if !defined(AFX_PAGEASSIGNEDFLOWOPTION_H__7AD85641_0022_4BBD_AAB2_BC38F1D46092__INCLUDED_)
#define AFX_PAGEASSIGNEDFLOWOPTION_H__7AD85641_0022_4BBD_AAB2_BC38F1D46092__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pageassignedflowoption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageAssignedFlowOption dialog

class PageAssignedFlowOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageAssignedFlowOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAssignedFlowOption)
	enum { IDD = IDD_ASSIGNFLOWOPTION };
	CNumEdit	m_EditPress;
	CUnitComboBox	m_cmbPressUnit;
	CButton	m_Box;
	BOOL	m_bInitPress;
	CString	m_strPressUnit;
	CString	m_strInitPress;
	CString	m_strK;
	int		m_nPressType;
	int		m_nSpecial;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAssignedFlowOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageAssignedFlowOption)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	afx_msg void OnCheckInitpress();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetInitPressStatus();
	void InitPressUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEASSIGNEDFLOWOPTION_H__7AD85641_0022_4BBD_AAB2_BC38F1D46092__INCLUDED_)
