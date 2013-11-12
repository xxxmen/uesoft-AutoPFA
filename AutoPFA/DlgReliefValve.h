#if !defined(AFX_DLGRELIEFVALVE_H__CE946C1D_7773_4E00_A2BC_8B8309EC3155__INCLUDED_)
#define AFX_DLGRELIEFVALVE_H__CE946C1D_7773_4E00_A2BC_8B8309EC3155__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgReliefValve.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "pagereliefmodel.h"
#include "PageReliefTrans.h"
#include "PageReliefOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgReliefValve dialog

class DlgReliefValve : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeType(CString strType,BOOL bShow);
	DlgReliefValve(UnitSubSystem &UnitSys,ComponentManager &manager,ReliefValve *pReliefValve,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgReliefValve)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgReliefValve)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd m_DlgEle;
	PageReliefModel m_page1;
	PageReliefTrans m_page2;
	PageReliefOption m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgReliefValve)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRELIEFVALVE_H__CE946C1D_7773_4E00_A2BC_8B8309EC3155__INCLUDED_)
