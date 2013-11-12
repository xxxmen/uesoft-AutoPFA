#if !defined(AFX_DLGGASACCUM_H__9807E379_C11C_4045_992E_944FD7E45538__INCLUDED_)
#define AFX_DLGGASACCUM_H__9807E379_C11C_4045_992E_944FD7E45538__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGasAccum.h : header file
//
#include "DlgJun.h"
#include "DlgOneEle.h"
#include "PageGasAccumModel.h"
#include "PipeDirPage.h"
#include "PageGasAccumOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgGasAccum dialog

class DlgGasAccum : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgGasAccum(UnitSubSystem &UnitSys,ComponentManager &manager,GasAccumulator *pGasAccum,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgGasAccum)
	
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgGasAccum)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEle m_DlgEle;
	PageGasAccumModel m_page1;
	PipeDirPage m_page2;
	PageGasAccumOption m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgGasAccum)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGASACCUM_H__9807E379_C11C_4045_992E_944FD7E45538__INCLUDED_)
