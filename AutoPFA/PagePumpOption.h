#if !defined(AFX_PAGEPUMPOPTION_H__00692D96_5D58_454C_B447_9511629C16E1__INCLUDED_)
#define AFX_PAGEPUMPOPTION_H__00692D96_5D58_454C_B447_9511629C16E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PagePumpOption.h : header file
//
#include "dlgoption.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PagePumpOption dialog

class PagePumpOption : public BaseDlg
{
// Construction
public:
	int GetPumpSet();
	void InitPumpSet(int nSet);
	BOOL UpData();
	void Init();
	PagePumpOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PagePumpOption)
	enum { IDD = IDD_PUMPOPTION };
	CComboBox	m_cmbNumber;
	CButton	m_Box;
	CString	m_strNumber;
	int		m_nSpecial;
	int		m_nType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PagePumpOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgOption m_dlgOption;

	// Generated message map functions
	//{{AFX_MSG(PagePumpOption)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioOne();
	afx_msg void OnRadioiParallel();
	afx_msg void OnRadioSeries();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitNumber();
	void SetPumpSetStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEPUMPOPTION_H__00692D96_5D58_454C_B447_9511629C16E1__INCLUDED_)
