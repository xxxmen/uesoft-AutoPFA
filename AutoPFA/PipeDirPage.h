#if !defined(AFX_PIPEDIRPAGE_H__3FEED504_11DF_4E3C_9DB9_6DCC0E33BBFC__INCLUDED_)
#define AFX_PIPEDIRPAGE_H__3FEED504_11DF_4E3C_9DB9_6DCC0E33BBFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PipeDirPage.h : header file
//
#include "GridCtrl.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PipeDirPage dialog

class PipeDirPage : public BaseDlg
{
// Construction
public:
	PipeDirPage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PipeDirPage)
	enum { IDD = IDD_PAGEPIPEDIR };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

public:
	void Init();
	CGridCtrl	m_list;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PipeDirPage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PipeDirPage)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitList();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIPEDIRPAGE_H__3FEED504_11DF_4E3C_9DB9_6DCC0E33BBFC__INCLUDED_)
