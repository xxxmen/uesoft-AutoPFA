#if !defined(AFX_PAGECONFIGDATA_H__7A255EEE_B852_4608_A0E8_0C1FEC469B66__INCLUDED_)
#define AFX_PAGECONFIGDATA_H__7A255EEE_B852_4608_A0E8_0C1FEC469B66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pageconfigdata.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageConfigData dialog
#include "DlgRawDataTable.h"
#include "DlgParamTable.h"
#include "BaseDlg.h"

class Configuration;
class PageConfigData : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init(Configuration &ref);
	PageConfigData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageConfigData)
	enum { IDD = IDD_PAGEPUMPDATA };
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
	//{{AFX_VIRTUAL(PageConfigData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	

	// Generated message map functions
	//{{AFX_MSG(PageConfigData)
	afx_msg void OnFitcurve();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeType();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void CurverStatus();
	void InitCurver();
	void UpDataMaxFLow(double dx[],int nNum);
	void UpDataCurve(ArrayFlyWeight<7>& ref,double dParam[],int nNum);
	Configuration *pConfig;
	ArrayFlyWeight<7>& GetCurve(int nCol);
	int GetOrder();
	void Fitcurve(double dx[],double dy[],int nNum,int nCol);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECONFIGDATA_H__7A255EEE_B852_4608_A0E8_0C1FEC469B66__INCLUDED_)
