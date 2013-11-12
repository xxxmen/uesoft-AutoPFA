#if !defined(AFX_DLGGENERALVIEW_H__22DAC78B_F4F5_4BBA_A485_A4D7DF6806D4__INCLUDED_)
#define AFX_DLGGENERALVIEW_H__22DAC78B_F4F5_4BBA_A485_A4D7DF6806D4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGeneralView.h : header file
//
//管网模型摘要信息
/////////////////////////////////////////////////////////////////////////////
// DlgGeneralView dialog
#include "dlgtabview.h"
#include "PageGeneralInfo.h"
class NetModel;

class DlgGeneralView : public DlgTabView
{
// Construction
public:
	void LoadData(NetModel *pNetModel);
	DlgGeneralView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgGeneralView)
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgGeneralView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageGeneralInfo m_page1;

	// Generated message map functions
	//{{AFX_MSG(DlgGeneralView)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGENERALVIEW_H__22DAC78B_F4F5_4BBA_A485_A4D7DF6806D4__INCLUDED_)
