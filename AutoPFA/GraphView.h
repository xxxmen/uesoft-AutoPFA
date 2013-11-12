#if !defined(AFX_GRAPHVIEW_H__EE0E24AE_8EB3_44FA_8686_98EF6EEAC988__INCLUDED_)
#define AFX_GRAPHVIEW_H__EE0E24AE_8EB3_44FA_8686_98EF6EEAC988__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GraphView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// GraphView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "UeSoftChart.h"

class CAutoPFADoc;

class GraphView : public CFormView
{
protected:
	GraphView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(GraphView)

// Form Data
public:
	//{{AFX_DATA(GraphView)
	enum { IDD = IDD_VIEWCHART};
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CMSChart m_MsChart;
	UeSoftChart m_UEChart;
// Operations
public:
	UeSoftChart& GetChart();
	CAutoPFADoc* GetDocument();
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(GraphView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~GraphView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(GraphView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelGraph();
	afx_msg void OnUpdateSelGraph(CCmdUI* pCmdUI);
	afx_msg void OnCopyData();
	afx_msg void OnUpdateCopyData(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
inline UeSoftChart& GraphView::GetChart()
{
	return m_UEChart;
}
inline CAutoPFADoc* GraphView::GetDocument()
{ return (CAutoPFADoc*)m_pDocument; }
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRAPHVIEW_H__EE0E24AE_8EB3_44FA_8686_98EF6EEAC988__INCLUDED_)
