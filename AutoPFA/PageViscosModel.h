#if !defined(AFX_PAGEVISCOSMODEL_H__06BD996A_FE39_4781_9BD5_90D1A0A8B40D__INCLUDED_)
#define AFX_PAGEVISCOSMODEL_H__06BD996A_FE39_4781_9BD5_90D1A0A8B40D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageViscosModel.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PageViscosModel.h
  摘要：    
  author  : LSP          
*/

/////////////////////////////////////////////////////////////////////////////
// PageViscosModel dialog

#include "BaseDlg.h"
class PageViscosModel : public BaseDlg
{
// Construction
public:
	PageViscosModel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageViscosModel)
	enum { IDD = IDD_VISCOSMODEL };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageViscosModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageViscosModel)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVISCOSMODEL_H__06BD996A_FE39_4781_9BD5_90D1A0A8B40D__INCLUDED_)
