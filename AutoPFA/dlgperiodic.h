#if !defined(AFX_DLGPERIODIC_H__4B5F1E74_F125_485C_BF9B_650700CEBE11__INCLUDED_)
#define AFX_DLGPERIODIC_H__4B5F1E74_F125_485C_BF9B_650700CEBE11__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgperiodic.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgPeriodic dialog
#include "ArrayFlyWeight.h"
#include "BaseDlg.h"
class DlgPeriodic : public BaseDlg
{
// Construction
public:
	void SetUnit(UnitSubSystem &system,UnitTypeID id);
	BOOL UpData(ArrayFlyWeight<5> &ref);
	void Init(const ArrayFlyWeight<5> &ref,UnitSubSystem &system,UnitTypeID id);
	DlgPeriodic(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgPeriodic)
	enum { IDD = IDD_PERIODIC };
	CEdit	m_EditAmplitude;
	CUnitComboBox	m_cmbAmplitude;
	BOOL	m_bChop;
	BOOL	m_bPeriodic;
	CString	m_strAmplitudeUnit;
	CString	m_strAmplitude;
	CString	m_strFrequency;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgPeriodic)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgPeriodic)
	afx_msg void OnCheckPeriodic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetPeriodicStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPERIODIC_H__4B5F1E74_F125_485C_BF9B_650700CEBE11__INCLUDED_)
