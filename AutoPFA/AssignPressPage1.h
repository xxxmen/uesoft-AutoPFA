#if !defined(AFX_ASSIGNPRESSPAGE1_H__54DF9EFD_41F9_410B_9F9F_517B22AB544E__INCLUDED_)
#define AFX_ASSIGNPRESSPAGE1_H__54DF9EFD_41F9_410B_9F9F_517B22AB544E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssignPressPage1.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// AssignPressPage1 dialog
#include "BaseDlg.h"

class AssignPressPage1 : public BaseDlg
{
// Construction
public:
	CString PressString();
	CString PressUnit();
	UnitTypeID PressType();
	BOOL UpData();
	void Init();
	AssignPressPage1(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AssignPressPage1)
	enum { IDD = IDD_PAGEPRESS1 };
	CNumEdit	m_EditPress;
	CUnitComboBox	m_cmbPressUnit;
	CString	m_strPressUnit;
	CString	m_strPress;
	int		m_nPressType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AssignPressPage1)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	UnitSubSystem &m_UnitSys;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(AssignPressPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioStag();
	afx_msg void OnRadioStatic();
	afx_msg void OnSelchangePressunit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSIGNPRESSPAGE1_H__54DF9EFD_41F9_410B_9F9F_517B22AB544E__INCLUDED_)
