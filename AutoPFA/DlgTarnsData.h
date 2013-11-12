#if !defined(AFX_DLGTARNSDATA_H__BC761E29_9B3E_4912_9D49_2C1D0B7B5E47__INCLUDED_)
#define AFX_DLGTARNSDATA_H__BC761E29_9B3E_4912_9D49_2C1D0B7B5E47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTarnsData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgTarnsData dialog
#include "PageTable.h"
#include "TabSheet.h"
#include "BaseDlg.h"

class DlgTarnsData : public BaseDlg
{
// Construction
public:
	void ChangeName(UINT nID1= IDS_STROPENTRANS,UINT nID2 = IDS_STRCLOSETRANS);
	void SetUnit(CString strUnit);
	void SetType(CString strType);
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strType,CString strUnit);
	DlgTarnsData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgTarnsData)
	enum { IDD = IDD_TARASDATASHEEP };
	CTabSheet	m_tab;
	int		m_nValueType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTarnsData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageTable m_page1;
	PageTable m_page2;
	CString m_strType;
	CString m_strUnit;
	// Generated message map functions
	//{{AFX_MSG(DlgTarnsData)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioAbs();
	afx_msg void OnRadioRel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString GetHeader();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTARNSDATA_H__BC761E29_9B3E_4912_9D49_2C1D0B7B5E47__INCLUDED_)
