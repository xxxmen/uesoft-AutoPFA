#if !defined(AFX_PAGECONFIGURATION_H__8DEA23EA_CD91_4821_9FD4_86CC72AF1FE2__INCLUDED_)
#define AFX_PAGECONFIGURATION_H__8DEA23EA_CD91_4821_9FD4_86CC72AF1FE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageConfiguration.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageConfiguration dialog
class Configuration;

class PageConfiguration : public BaseDlg
{
// Construction
public:
	void SetFlowUnit(int nType,CString strUnit);
	void SetBEPUnit(CString strUnit);
	void Init(Configuration &ref);
	BOOL UpData(Configuration &ref);
	PageConfiguration(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageConfiguration)
	enum { IDD = IDD_PAGECONFIG };
	CString	m_strBEP;
	CString	m_strEndFlow;
	CString	m_strK;
	int		m_nCalc;
	CString	m_strBEPUnit;
	CString	m_strFlowUnit;
	//}}AFX_DATA
	int m_nFlowType;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageConfiguration)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(PageConfiguration)
	afx_msg void OnRadioCalcBEP();
	afx_msg void OnRadioUserBEP();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetCalcStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONFIGURATION_H__8DEA23EA_CD91_4821_9FD4_86CC72AF1FE2__INCLUDED_)
