#if !defined(AFX_PAGECHART_H__4490F37E_7F13_40B6_BDE1_FD8A15A3AA7A__INCLUDED_)
#define AFX_PAGECHART_H__4490F37E_7F13_40B6_BDE1_FD8A15A3AA7A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagechart.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageChart dialog
#include "UeSoftChart.h"
#include "BaseDlg.h"

class PageChart : public BaseDlg
{
// Construction
public:
	UeSoftChart& GetChart();
	PageChart(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageChart)
	enum { IDD = IDD_PAGECHART };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageChart)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CMSChart m_MsChart;
	UeSoftChart m_UEChart;
	
	// Generated message map functions
	//{{AFX_MSG(PageChart)
	virtual BOOL OnInitDialog();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
inline UeSoftChart& PageChart::GetChart()
{
	return m_UEChart;
}
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECHART_H__4490F37E_7F13_40B6_BDE1_FD8A15A3AA7A__INCLUDED_)
