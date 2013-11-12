#if !defined(AFX_PAGEPIPEOPTION_H__01EA8D26_1133_4A91_BE7A_13335020E131__INCLUDED_)
#define AFX_PAGEPIPEOPTION_H__01EA8D26_1133_4A91_BE7A_13335020E131__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PagePipeOption.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PagePipeOption dialog
#include "BaseDlg.h"

class PagePipeOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PagePipeOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PagePipeOption)
	enum { IDD = IDD_PAGEPIPEOPTION };
	CEdit	m_EditFlow;
	CUnitComboBox	m_cmbFlowUnit;
	CComboBox	m_cmbFlowType;
	CString	m_strFlowUnit;
	CString	m_strFitFactor;
	CString	m_strFlowValue;
	CString	m_strParaNum;
	CString	m_strPipeFactor;
	BOOL	m_bPartFull;
	CString	m_strPartFull;
	//}}AFX_DATA
	int m_nCurFlowType;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PagePipeOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(PagePipeOption)
	afx_msg void OnSelchangeType();
	afx_msg void OnCheckPartFull();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void PartFullStatus();
	void SetFlowUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEPIPEOPTION_H__01EA8D26_1133_4A91_BE7A_13335020E131__INCLUDED_)
