#if !defined(AFX_DLGOPTCHECKIN_H__D0EC403E_12AC_4A37_8C00_2C5FB90E2329__INCLUDED_)
#define AFX_DLGOPTCHECKIN_H__D0EC403E_12AC_4A37_8C00_2C5FB90E2329__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOptCheckIn.h : header file
//
#include "PageOptCheckInPipeNet.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgOptCheckIn dialog
/************************************************************************
版本: 8.0  开发时间: 2008/06  作者: COM

功能: 打算把优化出来的一些数据（主要是管径）导入到管网中                                                                                                                                          
************************************************************************/


class CDlgOptCheckIn : public CDialog
{
// Construction
public:
	CDlgOptCheckIn(CWnd* pParent = NULL);   // standard constructor
    CDlgOptCheckIn( int& iSelect );


// Dialog Data
	//{{AFX_DATA(CDlgOptCheckIn)
	enum { IDD = IDD_DLGOPTCHECKIN };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgOptCheckIn)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgOptCheckIn)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	CPageOptCheckInPipeNet m_PagePipeNet;
	int* m_piSelect;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOPTCHECKIN_H__D0EC403E_12AC_4A37_8C00_2C5FB90E2329__INCLUDED_)
