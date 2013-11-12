#if !defined(AFX_OPTCONTROL_H__ACC7F6A8_8B13_43C5_BA92_6CDDAEADF2D5__INCLUDED_)
#define AFX_OPTCONTROL_H__ACC7F6A8_8B13_43C5_BA92_6CDDAEADF2D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptControl.h : header file
//

/************************************************************************

版本: 8.0  开发时间: 2008/06  作者: COM 

功能: 优化控制, 只做了个界面, 具体的算法没做，算法多,比较难   
                                                                                                                                        
************************************************************************/

#include "OptContralTwo.h"
/////////////////////////////////////////////////////////////////////////////
// COptControl dialog

class COptControl : public CDialog
{
// Construction
public:
	COptControl(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptControl)
	enum { IDD = IDD_DLGOPTCONTROL };
	CButton	m_btnCheckFour;
	CButton	m_btnCheckThree;
	CButton	m_btnCheckTwo;
	CButton	m_btnCheckOne;
	CComboBox	m_cmbMethod;
	CEdit	m_MaxIniCost;
	CComboBox	m_cmbITimeUnit;
	CComboBox	m_cmbSTimeUnit;
	CComboBox	m_cmbObj;
	CComboBox	m_cmbEneCostUnit;
	CEdit	m_edtEneCostValue;
	CEdit	m_StaticText5;
	CEdit	m_StaticText4;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptControl)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptControl)
	afx_msg void OnRadio5();
	afx_msg void OnRadio6();
	afx_msg void OnRadio7();
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio8();
	afx_msg void OnRadio1();
	afx_msg void OnRadio9();
	afx_msg void OnRadio10();
	afx_msg void OnSelchangeCombo3();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnRadio4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COptControl)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	int m_iGroupBoxState;
	bool SetEnableGroupBox( int iGroupBox );
	COptContralTwo m_PageOptContralTwo;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTCONTROL_H__ACC7F6A8_8B13_43C5_BA92_6CDDAEADF2D5__INCLUDED_)
