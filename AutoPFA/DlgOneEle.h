#if !defined(AFX_DLGONEELE_H__BCB17431_7154_47B8_8C77_986924F3DAC1__INCLUDED_)
#define AFX_DLGONEELE_H__BCB17431_7154_47B8_8C77_986924F3DAC1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgOneEle.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// DlgOneEle dialog

class DlgOneEle : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	DlgOneEle(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgOneEle)
	enum { IDD = IDD_DLGONEElE };
	CNumEdit	m_EditEle;
	CUnitComboBox	m_cmbEle;
	CString	m_strEle;
	CString	m_strEleUnit;
	//}}AFX_DATA

	UnitSubSystem &m_UnitSys;
 // Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgOneEle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgOneEle)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGONEELE_H__BCB17431_7154_47B8_8C77_986924F3DAC1__INCLUDED_)
