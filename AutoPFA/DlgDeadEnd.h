#if !defined(AFX_DLGDEADEND_H__1CD318C0_7A70_4601_8D72_FA8EEA59EE5A__INCLUDED_)
#define AFX_DLGDEADEND_H__1CD318C0_7A70_4601_8D72_FA8EEA59EE5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDeadEnd.h : header file
//
#include "DlgJun.h"
#include "DlgOneEnd.h"
#include "PageDeadEndOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgDeadEnd dialog

class DlgDeadEnd : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgDeadEnd(UnitSubSystem &UnitSys,ComponentManager &manager,DeadEnd *pDeadEnd,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgDeadEnd)
	
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgDeadEnd)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEnd m_DlgEnd;
	PageDeadEndOption m_page1;
	// Generated message map functions
	//{{AFX_MSG(DlgDeadEnd)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDEADEND_H__1CD318C0_7A70_4601_8D72_FA8EEA59EE5A__INCLUDED_)
