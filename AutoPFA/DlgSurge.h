#if !defined(AFX_DLGSURGE_H__D6CC609B_D6F7_4AC1_89C1_6FEB3FB7AC91__INCLUDED_)
#define AFX_DLGSURGE_H__D6CC609B_D6F7_4AC1_89C1_6FEB3FB7AC91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSurge.h : header file
//
#include "DlgJun.h"
#include "DlgOneEle.h"
#include "pagesurgemodel.h"
#include "BranchPage1.h"//ËðÊ§ÏµÊý
#include "PageSurgeTrans.h"
#include "PageSurgeOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgSurge dialog

class DlgSurge : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeUnit(CString strUnit);
	DlgSurge(UnitSubSystem &UnitSys,ComponentManager &manager,Surge *pSurge,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSurge)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSurge)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEle m_DlgEle;
	PageSurgeModel m_page1;
	BranchPage1 m_page2;
	PageSurgeTrans  m_page3;
	PageSurgeOption m_page4;
	// Generated message map functions
	//{{AFX_MSG(DlgSurge)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSURGE_H__D6CC609B_D6F7_4AC1_89C1_6FEB3FB7AC91__INCLUDED_)
