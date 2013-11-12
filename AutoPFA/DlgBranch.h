#if !defined(AFX_DLGBRANCH_H__8BBCEC9B_1FA7_4104_B732_78B70CC49D3B__INCLUDED_)
#define AFX_DLGBRANCH_H__8BBCEC9B_1FA7_4104_B732_78B70CC49D3B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBranch.h : header file
//
#include "DlgJun.h"
#include "DlgOneEle.h"
#include "BranchPage1.h"
#include "PageBranchOption.h"
#include "PageBranchTrans.h"
/////////////////////////////////////////////////////////////////////////////
// DlgBranch dialog

class DlgBranch : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeUnit(CString strUnit);
	void ChangeFlowType(UnitTypeID id,CString strType);
	DlgBranch(UnitSubSystem &UnitSys,ComponentManager &manager,Branch *pBrach,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgBranch)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgBranch)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEle m_DlgEle;
	BranchPage1 m_page1;
	PageBranchTrans  m_page2;
	PageBranchOption m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgBranch)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBRANCH_H__8BBCEC9B_1FA7_4104_B732_78B70CC49D3B__INCLUDED_)
