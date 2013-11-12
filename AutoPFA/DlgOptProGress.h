#if !defined(AFX_DLGOPTPROGRESS_H__6FEDFE5B_5A3A_4332_AAA1_7585CFDDD8A2__INCLUDED_)
#define AFX_DLGOPTPROGRESS_H__6FEDFE5B_5A3A_4332_AAA1_7585CFDDD8A2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOptProGress.h : header file
//
#include "autopfa.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgOptProGress dialog
/************************************************************************

版本: 8.0  开发时间: 2008/06  作者: COM 

功能: 迭代时的进度条,但不知道什么原因导致显示不完整,只能显示2个进度条
                                                                                                                                            
************************************************************************/


class CDlgOptProGress : public CDialog
{
// Construction
public:
	CDlgOptProGress(CWnd* pParent = NULL);   // standard constructor

    bool ProssMove( int iKeyOfProgress, int iStep = 1, int iPos = -1 );

// Dialog Data
	//{{AFX_DATA(CDlgOptProGress)
	enum { IDD = IDD_DLGOPTPROGRESS };
	CProgressCtrl	m_proParentStep;
	CProgressCtrl	m_proChildStep;
	CString	m_strChildStep;
	CString	m_strParentStep;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOptProGress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgOptProGress)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOPTPROGRESS_H__6FEDFE5B_5A3A_4332_AAA1_7585CFDDD8A2__INCLUDED_)
