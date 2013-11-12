#if !defined(AFX_DLGCHANGEUNIT_H__8CB79291_8256_4640_85A5_F185F068874E__INCLUDED_)
#define AFX_DLGCHANGEUNIT_H__8CB79291_8256_4640_85A5_F185F068874E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgChangeUnit.h : header file
//
#include "autopfa.h"
/////////////////////////////////////////////////////////////////////////////
// DlgChangeUnit dialog
class OutDataAttr;

class DlgChangeUnit : public CDialog
{
// Construction
public:
	DlgChangeUnit(OutDataAttr &attr,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgChangeUnit)
	enum { IDD = IDD_DLGCHANGEUNIT };
	CListBox	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgChangeUnit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	OutDataAttr &m_outAttr;
	// Generated message map functions
	//{{AFX_MSG(DlgChangeUnit)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnListBoxDBClick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHANGEUNIT_H__8CB79291_8256_4640_85A5_F185F068874E__INCLUDED_)
