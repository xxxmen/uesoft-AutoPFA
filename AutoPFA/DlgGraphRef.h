#if !defined(AFX_DLGGRAPHREF_H__3BA2BC07_5CB5_4B08_B6E0_6D80D20ED815__INCLUDED_)
#define AFX_DLGGRAPHREF_H__3BA2BC07_5CB5_4B08_B6E0_6D80D20ED815__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGraphRef.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgGraphRef.h
  摘要：    
  author  : LSP          
*/
#include "WorkSpaceRef.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// DlgGraphRef dialog

class DlgGraphRef : public BaseDlg
{
// Construction
public:
	DlgGraphRef(CWnd* pParent = NULL);   // standard constructor
    BOOL Updata();
	void Init(WorkSpaceRef &ref);
// Dialog Data
	//{{AFX_DATA(DlgGraphRef)
	enum { IDD = IDD_GRAPHICSREF };
	CButton	m_Radio75;
	CButton	m_Radio50;
	CButton	m_Radio25;
	CComboBox	m_pipeThick;
	CButton	m_Radio100;
	CStatic	m_Bitmap;
	//}}AFX_DATA
private:
	void UnCheck();
	int m_nJunSize;
    CBitmap m_bitmap;
	WorkSpaceRef *m_pWorkSpaceRef;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgGraphRef)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgGraphRef)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio25();
	afx_msg void OnRadio50();
	afx_msg void OnRadio75();
	afx_msg void OnRadio100();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGRAPHREF_H__3BA2BC07_5CB5_4B08_B6E0_6D80D20ED815__INCLUDED_)
