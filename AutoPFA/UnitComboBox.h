#if !defined(AFX_UNITCOMBOBOX_H__1537EEF9_9858_4067_9073_FE5A014D370B__INCLUDED_)
#define AFX_UNITCOMBOBOX_H__1537EEF9_9858_4067_9073_FE5A014D370B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// UnitComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CUnitComboBox window

class CUnitComboBox : public CComboBox
{
// Construction
public:
	CUnitComboBox(CEdit *pWnd1 = NULL,CEdit *pWnd2 = NULL);

// Attributes
public:

// Operations
public:
	CEdit *m_pWnd1;
	CEdit *m_pWnd2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUnitComboBox)
	//}}AFX_VIRTUAL

// Implementation
public:
	void InitUnit(UnitSubSystem &system,UnitTypeID id,CString &m_strCurSymbol);
	virtual ~CUnitComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CUnitComboBox)
	afx_msg void OnSelendOk();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CString GetValue(double dOut);
	void Tran(CWnd *pWnd);
	double m_dRatio;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UNITCOMBOBOX_H__1537EEF9_9858_4067_9073_FE5A014D370B__INCLUDED_)
