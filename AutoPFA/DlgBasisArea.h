#if !defined(AFX_DLGBASISAREA_H__C82E3E37_BAC3_4EFF_B135_4599DBFA13E0__INCLUDED_)
#define AFX_DLGBASISAREA_H__C82E3E37_BAC3_4EFF_B135_4599DBFA13E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBasisArea.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// DlgBasisArea dialog

class DlgBasisArea : public BaseDlg
{
// Construction
public:
	BOOL UpData(ArrayFlyWeight<3> &ref);
	void Init(ArrayFlyWeight<3> &ref);
	DlgBasisArea(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor
	void UpUnit();
	CString GetArea();

// Dialog Data
	//{{AFX_DATA(DlgBasisArea)
	enum { IDD = IDD_DLGBASISAREA };
	CNumEdit	m_EditValue;
	CUnitComboBox	m_cmbUnit;
	CComboBox	m_cmbRefType;
	CString	m_strValue;
	CString	m_strUnit;
	CString m_BaseArea;
	//}}AFX_DATA
	int m_nRefType;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgBasisArea)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	UnitSubSystem &m_UnitSys;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgBasisArea)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeType();
	afx_msg void OnSelchangeCmbdiaorareaunit();
	afx_msg void OnChangeEdiaorarea();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetControlStatus();
	void InitAreaOrEleUnit();
};


inline CString DlgBasisArea::GetArea()
{
	return m_BaseArea;
}
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBASISAREA_H__C82E3E37_BAC3_4EFF_B135_4599DBFA13E0__INCLUDED_)
