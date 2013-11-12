#if !defined(AFX_DLGTWOEND_H__64D87E4E_1673_4023_BA94_E6E14187B58E__INCLUDED_)
#define AFX_DLGTWOEND_H__64D87E4E_1673_4023_BA94_E6E14187B58E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTwoEnd.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// DlgTwoEnd dialog

class DlgTwoEnd : public BaseDlg
{
// Construction
public:
	int OutPipeID();
	int InPipeID();
	BOOL UpData();
	void Init();
	DlgTwoEnd(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgTwoEnd)
	enum { IDD = IDD_DLGTWOEND };
	CNumEdit	m_EditOutPipe;
	CNumEdit	m_EditInPipe;
	CNumEdit	m_EditOutEle;
	CNumEdit	m_EditInEle;
	CButton	m_CheckSameEle;
	CUnitComboBox	m_cmbUnit;
	CString	m_strInPipeID;
	CString	m_strOutPipeID;
	CString	m_strOutEle;
	CString	m_strInEle;
	CString	m_strUnit;
	BOOL	m_bSameEle;
	//}}AFX_DATA


	UnitSubSystem &m_UnitSys;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTwoEnd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgTwoEnd)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckSame();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CheckSame();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTWOEND_H__64D87E4E_1673_4023_BA94_E6E14187B58E__INCLUDED_)
