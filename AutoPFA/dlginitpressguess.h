#if !defined(AFX_DLGINITPRESSGUESS_H__739C748C_FDFA_42E6_8EEC_9EAF99A38CC3__INCLUDED_)
#define AFX_DLGINITPRESSGUESS_H__739C748C_FDFA_42E6_8EEC_9EAF99A38CC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlginitpressguess.h : header file
//
#include "BaseDlg.h"

class StrFlyWeight;
/////////////////////////////////////////////////////////////////////////////
// DlgInitPressGuess dialog

class DlgInitPressGuess : public BaseDlg
{
// Construction
public:
	BOOL UpData(ArrayFlyWeight<3> &ref);
	void Init(ArrayFlyWeight<3> &ref);
	DlgInitPressGuess(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgInitPressGuess)
	enum { IDD = IDD_DLGINITPRESSGUESS };
	CEdit	m_EditGuess;
	CUnitComboBox	m_cmbInitGuess;
	CString	m_strGuessUnit;
	CString	m_strInitGuess;
	int		m_nPressType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgInitPressGuess)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(DlgInitPressGuess)
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitPressUnit();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINITPRESSGUESS_H__739C748C_FDFA_42E6_8EEC_9EAF99A38CC3__INCLUDED_)
