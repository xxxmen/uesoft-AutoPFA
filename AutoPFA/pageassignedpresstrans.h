#if !defined(AFX_PAGEASSIGNEDPRESSTRANS_H__4F4B86FA_C6E8_48A8_8B52_897674BD8FF7__INCLUDED_)
#define AFX_PAGEASSIGNEDPRESSTRANS_H__4F4B86FA_C6E8_48A8_8B52_897674BD8FF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pageassignedpresstrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageAssignedPressTrans dialog
#include "PageTrans.h"
#include "DlgThreeTransSpecial.h"
#include "dlgperiodic.h"

class PageAssignedPressTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,UnitTypeID id,CString strType,CString strUnit);
	PageAssignedPressTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAssignedPressTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAssignedPressTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgThreeTransSpecial m_dlgSpecial;
	DlgPeriodic     m_dlgPeriodit;

	// Generated message map functions
	//{{AFX_MSG(PageAssignedPressTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEASSIGNEDPRESSTRANS_H__4F4B86FA_C6E8_48A8_8B52_897674BD8FF7__INCLUDED_)
