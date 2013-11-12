#if !defined(AFX_DLGTEEWYE_H__1B29867D_D3CE_47C4_B10F_B47300BFC696__INCLUDED_)
#define AFX_DLGTEEWYE_H__1B29867D_D3CE_47C4_B10F_B47300BFC696__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTeeWye.h : header file
//
#include "DlgJun.h"
#include "DlgOneEle.h"
#include "pageteewyemodel.h"
#include "PageTeeWyeOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgTeeWye dialog

class DlgTeeWye : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgTeeWye(UnitSubSystem &UnitSys,ComponentManager &manager,TeeWye *pTeeWye,CWnd* pParent = NULL);   // standard constructor
	
// Dialog Data
	//{{AFX_DATA(DlgTeeWye)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTeeWye)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEle m_DlgEle;
	PageTeeWyeModel m_page1;
	PageTeeWyeOption m_page2;
	// Generated message map functions
	//{{AFX_MSG(DlgTeeWye)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTEEWYE_H__1B29867D_D3CE_47C4_B10F_B47300BFC696__INCLUDED_)
