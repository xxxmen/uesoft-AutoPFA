#if !defined(AFX_DLGCHECKVALVE_H__0249D1F4_26D3_4CA2_920E_D85D8EFA134C__INCLUDED_)
#define AFX_DLGCHECKVALVE_H__0249D1F4_26D3_4CA2_920E_D85D8EFA134C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgCheckValve.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "pagecheckmodel.h"
#include "PageCheckTrans.h"
#include "PageCheckOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgCheckValve dialog

class DlgCheckValve : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeType(CString strType);
	DlgCheckValve(UnitSubSystem &UnitSys,ComponentManager &manager,CheckValve *pCheckValve,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgCheckValve)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgCheckValve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd m_DlgEle;
	PageCheckModel m_page1;
	PageCheckTrans m_page2;
	PageCheckOption m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgCheckValve)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHECKVALVE_H__0249D1F4_26D3_4CA2_920E_D85D8EFA134C__INCLUDED_)
