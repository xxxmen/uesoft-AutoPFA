#if !defined(AFX_DLGVALVE_H__EA23743F_CD05_46DE_B5FE_23CD71EE64CB__INCLUDED_)
#define AFX_DLGVALVE_H__EA23743F_CD05_46DE_B5FE_23CD71EE64CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgValve.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "PageValveModel.h"
#include "PageValveTrans.h"
#include "PageValveOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgValve dialog

class DlgValve : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeType(CString strType);
	DlgValve(UnitSubSystem &UnitSys,ComponentManager &manager,Valve *pValve,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgValve)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgValve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd m_DlgEle;
	PageValveModel m_page1;
	PageValveTrans m_page2;
	PageValveOption m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgValve)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGVALVE_H__EA23743F_CD05_46DE_B5FE_23CD71EE64CB__INCLUDED_)
