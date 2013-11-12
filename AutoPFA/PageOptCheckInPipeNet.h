#if !defined(AFX_PAGEOPTCHECKINPIPENET_H__F7A93E46_4EAC_4C3B_A7B6_CB0B0ED3EA2E__INCLUDED_)
#define AFX_PAGEOPTCHECKINPIPENET_H__F7A93E46_4EAC_4C3B_A7B6_CB0B0ED3EA2E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageOptCheckInPipeNet.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CPageOptCheckInPipeNet dialog

class CPageOptCheckInPipeNet : public BaseDlg
{
// Construction
public:
	CPageOptCheckInPipeNet(CWnd* pParent = NULL);   // standard constructor
	CPageOptCheckInPipeNet( int& iSelect );

// Dialog Data
	//{{AFX_DATA(CPageOptCheckInPipeNet)
	enum { IDD = IDD_PAGEOPTCHECKIN_PIPENET };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageOptCheckInPipeNet)
	public:
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageOptCheckInPipeNet)
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int* m_piSelect;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEOPTCHECKINPIPENET_H__F7A93E46_4EAC_4C3B_A7B6_CB0B0ED3EA2E__INCLUDED_)
