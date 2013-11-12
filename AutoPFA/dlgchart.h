#if !defined(AFX_DLGCHART_H__F1883EA0_DFD8_4854_BD44_6276BC383B28__INCLUDED_)
#define AFX_DLGCHART_H__F1883EA0_DFD8_4854_BD44_6276BC383B28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgchart.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgChart dialog
#include "UeSoftChart.h"
class DlgChart : public CDialog
{
// Construction
public:
	DlgChart(double dX[],double dY[],int nDat,CWnd* pParent = NULL);   // standard constructor
	DlgChart(double dX[],double dY1[],double dY2[],int nDat,CWnd* pParent = NULL); 

// Dialog Data
	//{{AFX_DATA(DlgChart)
	enum { IDD = IDD_DLGCHART };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgChart)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CMSChart m_MsChart;
	UeSoftChart m_UEChart;
	double *m_dX;
	double *m_dY1;
	double *m_dY2;
	int m_nDat;
	int m_nNum;

	// Generated message map functions
	//{{AFX_MSG(DlgChart)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGCHART_H__F1883EA0_DFD8_4854_BD44_6276BC383B28__INCLUDED_)
