#if !defined(AFX_DLGVACUUMBREAKER_H__F2D9C34D_3803_437C_A93A_CC2927AA042A__INCLUDED_)
#define AFX_DLGVACUUMBREAKER_H__F2D9C34D_3803_437C_A93A_CC2927AA042A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgVacuumBreaker.h : header file
//
#include "DlgJun.h"
#include "DlgOneEnd.h"
#include "pagebreakermodel.h"
#include "PageBreakerOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgVacuumBreaker dialog

class DlgVacuumBreaker : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgVacuumBreaker(UnitSubSystem &UnitSys,ComponentManager &manager,VacuumBreaker *pVacuumBreaker,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgVacuumBreaker)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgVacuumBreaker)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEnd m_DlgEnd;
	PageBreakerModel m_page1;
	PageBreakerOption m_page2;
	// Generated message map functions
	//{{AFX_MSG(DlgVacuumBreaker)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVACUUMBREAKER_H__F2D9C34D_3803_437C_A93A_CC2927AA042A__INCLUDED_)
