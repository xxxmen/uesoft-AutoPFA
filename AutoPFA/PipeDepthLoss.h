#if !defined(AFX_PIPEDEPTHLOSS_H__FCBD6DB0_CF91_4C93_93A8_577B110BB4EC__INCLUDED_)
#define AFX_PIPEDEPTHLOSS_H__FCBD6DB0_CF91_4C93_93A8_577B110BB4EC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PipeDepthLoss.h : header file
//
#include "GridCtrl.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PipeDepthLoss dialog

class PipeDepthLoss : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PipeDepthLoss(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PipeDepthLoss)
	enum { IDD = IDD_PAGEDEPTHLOSS };
	CComboBox	m_cmbDepthEleUnit;
	int		m_nDepthOrEle;
	int		m_nType;
	CString	m_strDepthEleUnit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PipeDepthLoss)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
    CGridCtrl	m_list;
	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(PipeDepthLoss)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioDepth();
	afx_msg void OnRadioEle();
	afx_msg void OnRadioSharp();
	afx_msg void OnRadioRound();
	afx_msg void OnRadioReentrart();
	afx_msg void OnRadioCustom();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL UpDataListData();
	void InitListData();
	void InitListHeader();

private:
	void SetDepthStatus();
	static	const CString ms_frictionModel[4];
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PIPEDEPTHLOSS_H__FCBD6DB0_CF91_4C93_93A8_577B110BB4EC__INCLUDED_)
