#if !defined(AFX_PAGEBRANCHOPTION_H__3C7A06C0_8BD0_40DA_9473_1E422DB48992__INCLUDED_)
#define AFX_PAGEBRANCHOPTION_H__3C7A06C0_8BD0_40DA_9473_1E422DB48992__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageBranchOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageBranchOption dialog

class PageBranchOption : public BaseDlg
{
// Construction
public:
	CString FlowString();
	CString FlowUnit();
	BOOL UpData();
	void Init();
	PageBranchOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageBranchOption)
	enum { IDD = IDD_BRACHOPTION };
	CEdit	m_EditFlowRate;
	CUnitComboBox	m_cmbFlowRate;
	CButton	m_Box;
	CString	m_strFlowRateUnit;
	CString	m_strFlowRate;
	int		m_nFlowType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageBranchOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PageBranchOption)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioVolumeflow();
	afx_msg void OnRadioMassflow();
	afx_msg void OnSelchangeFlowUnit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ChangeType();
	void ChangeUnit();
	void InitFlowUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEBRANCHOPTION_H__3C7A06C0_8BD0_40DA_9473_1E422DB48992__INCLUDED_)
