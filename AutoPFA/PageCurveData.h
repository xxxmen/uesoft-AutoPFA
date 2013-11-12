#if !defined(AFX_PAGECURVEDATA_H__A444CA46_CEDD_4BE3_917E_F79623CD594D__INCLUDED_)
#define AFX_PAGECURVEDATA_H__A444CA46_CEDD_4BE3_917E_F79623CD594D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageCurveData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageCurveData dialog
#include "DlgRawDataTable.h"
#include "DlgParamTable.h"

class PageCurveData : public CDialog
{
// Construction
public:
	BOOL UpData();
	void Init(ArrayFlyWeight<13>& ref);
	PageCurveData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageCurveData)
	enum { IDD = IDD_PAGEPUMPDATA};
	CComboBox	m_cmbOrder;
	CCheckListBox m_list;
	CButton	m_BitMap;
	CComboBox	m_cmbCurveype;
	CButton	m_Box1;
	CButton	m_Box2;
	CString	m_strOrder;
	//}}AFX_DATA
	DlgRawDataTable m_RawData;
	DlgParamTable   m_Param;
	int m_nType;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageCurveData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	ArrayFlyWeight<13>* pRef;

	// Generated message map functions
	//{{AFX_MSG(PageCurveData)
	virtual BOOL OnInitDialog();
	afx_msg void OnFitcurve();
	afx_msg void OnSelchangeType();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CurverStatus();
	void InitCurver();
	void UpDataMaxFLow(double dx[],int nNum);
	void UpDataCurve(double dParam[],int nNum);
	int GetOrder();
	void Fitcurve(double dx[],double dy[],int nNum);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECURVEDATA_H__A444CA46_CEDD_4BE3_917E_F79623CD594D__INCLUDED_)
