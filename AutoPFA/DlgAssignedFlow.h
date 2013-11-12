#if !defined(AFX_DLGASSIGNEDFLOW_H__424E04CB_D4D5_4502_9765_C1CC0F46B0D5__INCLUDED_)
#define AFX_DLGASSIGNEDFLOW_H__424E04CB_D4D5_4502_9765_C1CC0F46B0D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAssignedFlow.h : header file
//
#include "DlgJun.h"
#include "DlgOneEnd.h"
#include "AssignFlowPage1.h"
#include "pageassignedflowoption.h"
#include "PageAssignedFlowTrans.h"
/////////////////////////////////////////////////////////////////////////////
// DlgAssignedFlow dialog

class DlgAssignedFlow : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeUnit(CString strUnit);
	void ChangeFlowType(UnitTypeID id,CString strType);
	DlgAssignedFlow(UnitSubSystem &UnitSys,ComponentManager &manager,AssignedFlow *pAssignFlow,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgAssignedFlow)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgAssignedFlow)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEnd m_DlgEnd;
	AssignFlowPage1 m_page1;
	PageAssignedFlowTrans m_page2;
	PageAssignedFlowOption m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgAssignedFlow)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGASSIGNEDFLOW_H__424E04CB_D4D5_4502_9765_C1CC0F46B0D5__INCLUDED_)
