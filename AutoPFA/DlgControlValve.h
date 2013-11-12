#if !defined(AFX_DLGCONTROLVALVE_H__1EFEE162_19AF_48AE_A168_EB7B96446E8C__INCLUDED_)
#define AFX_DLGCONTROLVALVE_H__1EFEE162_19AF_48AE_A168_EB7B96446E8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgControlValve.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "PageControlModel.h"
#include "PageFailTrans.h"
#include "PageControlTrans.h"
#include "PageControlOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgControlValve dialog

class DlgControlValve : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeUnit(CString strUnit);
	void ChangeType(CString strLossType,CString strCtrlType);
	DlgControlValve(UnitSubSystem &UnitSys,ComponentManager &manager,ControlValve *pControlValve,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgControlValve)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgControlValve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd m_DlgEle;
	PageControlModel  m_page1;
	PageFailTrans     m_page2;
	PageControlTrans  m_page3;
	PageControlOption m_page4;
	// Generated message map functions
	//{{AFX_MSG(DlgControlValve)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCONTROLVALVE_H__1EFEE162_19AF_48AE_A168_EB7B96446E8C__INCLUDED_)
