#if !defined(AFX_DLGCHECKLIST_H__576F5A94_F376_4BDF_88C4_C8F7294D837E__INCLUDED_)
#define AFX_DLGCHECKLIST_H__576F5A94_F376_4BDF_88C4_C8F7294D837E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/////////////////////////////////////////////////////////////////////////////
// DlgCheckList dialog
#include "AutoPFADoc.h"
#include "DlgUndefinedObjects.h"
class DlgCheckList : public CDialog
{
// Construction
public:
	void Init(BOOL bCheck[],BOOL bTran);
	DlgCheckList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgCheckList)
	enum { IDD = IDD_DLGCHECKLIST };
	BOOL	m_b1;
	BOOL	m_b2;
	BOOL	m_b3;
	BOOL	m_b4;
	BOOL	m_b5;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgCheckList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
public:
	void SetCurDoc( CAutoPFADoc * pCurDoc );
	void ShowUndefinedObjects();
	CAutoPFADoc* m_pCurDoc;
//	CDlgUndefinedObjects m_dlgUndefinedObjects( m_pCurDoc->m_scenarioManager.GetCurScenario()->GetCompManager() );
protected:
	BOOL m_bTran;

	// Generated message map functions
	//{{AFX_MSG(DlgCheckList)
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	virtual BOOL OnInitDialog();
	afx_msg void OnShowSteadySet();
	afx_msg void OnShowSystemProper();
	afx_msg void OnShowSectionPipe();
	afx_msg void OnShowTransControl();
	afx_msg void OnShowUndefinedObjects();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHECKLIST_H__576F5A94_F376_4BDF_88C4_C8F7294D837E__INCLUDED_)
