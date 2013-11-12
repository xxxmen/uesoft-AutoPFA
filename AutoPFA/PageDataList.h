#if !defined(AFX_PAGEDATALIST_H__91CA0AC8_8777_42BE_B17E_1AE4C665F6BF__INCLUDED_)
#define AFX_PAGEDATALIST_H__91CA0AC8_8777_42BE_B17E_1AE4C665F6BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageDataList.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageDataList dialog

class PageDataList : public BaseDlg
{
// Construction
public:
	PageDataList(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageDataList)
	enum { IDD = IDD_DATALIST };
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageDataList)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageDataList)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEDATALIST_H__91CA0AC8_8777_42BE_B17E_1AE4C665F6BF__INCLUDED_)
