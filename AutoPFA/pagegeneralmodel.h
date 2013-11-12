#if !defined(AFX_PAGEGENERALMODEL_H__817ECFDE_2B69_412E_BFDE_338FE7697020__INCLUDED_)
#define AFX_PAGEGENERALMODEL_H__817ECFDE_2B69_412E_BFDE_338FE7697020__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagegeneralmodel.h : header file
//
#include "DlgBasisArea.h"
#include "TabSheet.h"
#include "pagechart.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageGeneralModel dialog

class PageGeneralModel : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageGeneralModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGeneralModel)
	enum { IDD = IDD_GENERALMODEL };
	CTabSheet	m_tab;
	CNumEdit	m_EditCvOrK;
	CButton	m_Box;
	CString	m_strCvOrK;
	int		m_nLossType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGeneralModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	DlgBasisArea m_dlgBasisArea;
	PageChart m_page1;
	// Generated message map functions
	//{{AFX_MSG(PageGeneralModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioConstK();
	afx_msg void OnRadioRCurve();
	afx_msg void OnRadioVariableK();
	afx_msg void OnCurveData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void LossStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGENERALMODEL_H__817ECFDE_2B69_412E_BFDE_338FE7697020__INCLUDED_)
