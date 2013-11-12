#if !defined(AFX_DLGINITIATION_H__1EAEF35C_D1BF_4151_9AA9_0205F56455F9__INCLUDED_)
#define AFX_DLGINITIATION_H__1EAEF35C_D1BF_4151_9AA9_0205F56455F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInitiation.h : header file
//
#include "TabSheet.h"
#include "pagetrantriger.h"
#include "DlgTarnsData.h"
#include "BaseDlg.h"


/////////////////////////////////////////////////////////////////////////////
// DlgInitiation dialog
class Transient;

class DlgInitiation : public BaseDlg
{
// Construction
public:
	void HideDualEvent();
	void SetEventStatus();
	BOOL UpData(Transient &ref);
	void Init(Transient &ref);
	DlgInitiation(UnitSubSystem &UnitSys,ComponentManager &manager,DlgTarnsData &transData,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgInitiation)
	enum { IDD = IDD_INITTRANS };
	CTabSheet	m_tab;
	int		m_nEventType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgInitiation)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageTranTriger m_page1;
	PageTranTriger m_page2;
	DlgTarnsData &m_dlgTanrsData;
	
	// Generated message map functions
	//{{AFX_MSG(DlgInitiation)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioTime();
	afx_msg void OnRadioSingle();
	afx_msg void OnRadioDualCyclic();
	afx_msg void OnRadioDualDeguen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINITIATION_H__1EAEF35C_D1BF_4151_9AA9_0205F56455F9__INCLUDED_)
