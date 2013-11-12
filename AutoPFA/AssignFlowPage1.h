#if !defined(AFX_ASSIGNFLOWPAGE1_H__96F5D656_4A80_41F1_9F41_0EE8DF6D793F__INCLUDED_)
#define AFX_ASSIGNFLOWPAGE1_H__96F5D656_4A80_41F1_9F41_0EE8DF6D793F__INCLUDED_

#include "GlobalUse.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AssignFlowPage1.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// AssignFlowPage1 dialog

class AssignFlowPage1 : public BaseDlg
{
// Construction
public:
	CString FlowString();
	CString FlowUnit();
	UnitTypeID FlowType();
	BOOL UpData();
	void Init();
	AssignFlowPage1(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AssignFlowPage1)
	enum { IDD = IDD_PAGEFLOW1 };
	CNumEdit	m_EditFlowRate;
	CUnitComboBox	m_cmbFlowUnit;
	CString	m_strFlowUnit;
	CString	m_strFlowRate;
	int		m_nDirType;
	int		m_nFlowType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AssignFlowPage1)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	UnitSubSystem &m_UnitSys;
// Implementation
protected:
	UnitTypeID m_FlowType;

	// Generated message map functions
	//{{AFX_MSG(AssignFlowPage1)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioVolumeFlow();
	afx_msg void OnRadioMassFlow();
	afx_msg void OnSelchangeFlowunit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ChangeUnit();
	void InitFlowUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ASSIGNFLOWPAGE1_H__96F5D656_4A80_41F1_9F41_0EE8DF6D793F__INCLUDED_)
