#if !defined(AFX_PAGEASSIGNEDPRESSOPTION_H__4A3D0A90_16A8_47A7_B6F4_8CC4C36F6538__INCLUDED_)
#define AFX_PAGEASSIGNEDPRESSOPTION_H__4A3D0A90_16A8_47A7_B6F4_8CC4C36F6538__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageAssignedPressOption.h : header file
//
#include "dlgdesignfactor.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageAssignedPressOption dialog

class PageAssignedPressOption : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageAssignedPressOption(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageAssignedPressOption)
	enum { IDD = IDD_ASSIGNPRESSOPTION };
	CButton	m_Box;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageAssignedPressOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgDesignFactor m_dlgDesignFactor;

	// Generated message map functions
	//{{AFX_MSG(PageAssignedPressOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEASSIGNEDPRESSOPTION_H__4A3D0A90_16A8_47A7_B6F4_8CC4C36F6538__INCLUDED_)
