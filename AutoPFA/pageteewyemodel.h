#if !defined(AFX_PAGETEEWYEMODEL_H__1CE24FB8_5F74_45CB_971E_75DDE73B40D5__INCLUDED_)
#define AFX_PAGETEEWYEMODEL_H__1CE24FB8_5F74_45CB_971E_75DDE73B40D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pageteewyemodel.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeModel dialog
class TeeWye;

class PageTeeWyeModel : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageTeeWyeModel(TeeWye *pTeeWye,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTeeWyeModel)
	enum { IDD = IDD_TEEWYEMODEL };
	CComboBox	m_cbmC;
	CComboBox	m_cbmB;
	CComboBox	m_cbmA;
	CStatic	m_BitMap;
	CNumEdit	m_EditAngle;
	CString m_numA;
	CString m_numB;
	CString m_numC;
	CString	m_strAngle;
	int		m_nType;
	int		m_nLossType;
	//}}AFX_DATA
	UINT BitMapID[4];
	CBitmap m_bitmap;
	int m_nPipeId[3];

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTeeWyeModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	TeeWye *m_pTeeWye;

	// Generated message map functions
	//{{AFX_MSG(PageTeeWyeModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioSharp();
	afx_msg void OnRadioRound();
	afx_msg void OnRadioChange();
	afx_msg void OnRadioWye();
	afx_msg void OnSelchangeA();
	afx_msg void OnSelchangeB();
	afx_msg void OnSelchangeC();
	afx_msg void OnTeeDetail();
	afx_msg void OnTeeSimple();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ChangeLink(CComboBox &cmb,CString &m_num);
	CComboBox& Find(CString strText);
	void InitCbm(CComboBox &cbm);
	void SetTypeStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETEEWYEMODEL_H__1CE24FB8_5F74_45CB_971E_75DDE73B40D5__INCLUDED_)
