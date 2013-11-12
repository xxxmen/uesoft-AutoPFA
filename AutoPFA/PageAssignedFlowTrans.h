#if !defined(AFX_PAGEASSIGNEDFLOWTRANS_H__00BA9B58_3837_4E9D_A614_F590C6AA1550__INCLUDED_)
#define AFX_PAGEASSIGNEDFLOWTRANS_H__00BA9B58_3837_4E9D_A614_F590C6AA1550__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageAssignedFlowTrans.h : header file
//
#include "PageTrans.h"
#include "DlgThreeTransSpecial.h"
#include "dlgperiodic.h"
/////////////////////////////////////////////////////////////////////////////
// PageAssignedFlowTrans dialog

class PageAssignedFlowTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,UnitTypeID id,CString strType,CString strUnit);
	PageAssignedFlowTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAssignedFlowTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAssignedFlowTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgThreeTransSpecial m_dlgSpecial;
	DlgPeriodic     m_dlgPeriodit;
	// Generated message map functions
	//{{AFX_MSG(PageAssignedFlowTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEASSIGNEDFLOWTRANS_H__00BA9B58_3837_4E9D_A614_F590C6AA1550__INCLUDED_)
