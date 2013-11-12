#if !defined(AFX_DLGTOLERANCE_H__AC22C25E_01E0_411F_B51C_DD1D49EDEA7E__INCLUDED_)
#define AFX_DLGTOLERANCE_H__AC22C25E_01E0_411F_B51C_DD1D49EDEA7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgtolerance.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgTolerance dialog
#include "SteadySet.h"
#include "BaseDlg.h"

class DlgTolerance : public BaseDlg
{
// Construction
public:
	BOOL Updata(StrFlyWeight &type,NumFlyWeight &absTol,StrFlyWeight &RelTol);
	void Init(StrFlyWeight &type,NumFlyWeight &absTol,StrFlyWeight &RelTol);
	DlgTolerance(UnitSubSystem &UnitSys,UnitTypeID ID,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgTolerance)
	enum { IDD = IDD_DlGTOLERANCE };
	CEdit	m_EditAbsTol;
	CUnitComboBox	m_cbmAbsTol;
	int		m_nTolType;
	CString	m_strRelTol;
	CString	m_strAbsTol;
	CString	m_strAbsTolUnit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTolerance)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	UnitTypeID m_ID;
	// Generated message map functions
	//{{AFX_MSG(DlgTolerance)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioAbsTol();
	afx_msg void OnRadioAbsOrRel();
	afx_msg void OnRadioAbsAndRel();
	afx_msg void OnRadioRelTol();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void AbsTolStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTOLERANCE_H__AC22C25E_01E0_411F_B51C_DD1D49EDEA7E__INCLUDED_)
