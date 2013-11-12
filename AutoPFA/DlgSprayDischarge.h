#if !defined(AFX_DLGSPRAYDISCHARGE_H__89577257_754B_4EC2_904B_BC27A594AEA0__INCLUDED_)
#define AFX_DLGSPRAYDISCHARGE_H__89577257_754B_4EC2_904B_BC27A594AEA0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSprayDischarge.h : header file
//
#include "DlgJun.h"
#include "DlgOneEle.h"
//#include "PipeDirPage.h"
#include "BranchPage1.h"//损失系数
#include "PageSprayModel.h"
#include "PageSprayTrans.h"
#include "PageSprayOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgSprayDischarge dialog

class DlgSprayDischarge : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeUnit(CString strUnit);
	void ChangeType(CString strType);
	DlgSprayDischarge(UnitSubSystem &UnitSys,ComponentManager &manager,SprayDischarge *pSprayDischarge,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSprayDischarge)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSprayDischarge)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEle m_DlgEle;
	PageSprayModel m_page1;
//	PipeDirPage m_page2;
	BranchPage1  m_page2;//6.0下改成了有K系数的
	PageSprayTrans m_page3;
	PageSprayOption m_page4;
	// Generated message map functions
	//{{AFX_MSG(DlgSprayDischarge)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSPRAYDISCHARGE_H__89577257_754B_4EC2_904B_BC27A594AEA0__INCLUDED_)
