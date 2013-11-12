#if !defined(AFX_DLGSELGRAPHDATA_H__CFDD19A8_D0F0_49CB_ABE8_E0E41B1662E4__INCLUDED_)
#define AFX_DLGSELGRAPHDATA_H__CFDD19A8_D0F0_49CB_ABE8_E0E41B1662E4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSelGraphData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgSelGraphData dialog
#include "TabSheet.h"
#include "PagePipeGraph.h"
#include "PageJunGraph.h"

class PFAOutModel;
class GraphView;

class DlgSelGraphData : public CDialog
{
// Construction
public:
	DlgSelGraphData(GraphView &view,PFAOutModel &out,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSelGraphData)
	enum { IDD = IDD_DLGSELGRAPHDATA };
	CTabSheet	m_tab;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSelGraphData)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	GraphView &m_view;
	PFAOutModel &m_out;
	PagePipeGraph m_pipeData;
	PageJunGraph m_junData;
	// Generated message map functions
	//{{AFX_MSG(DlgSelGraphData)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void Init();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSELGRAPHDATA_H__CFDD19A8_D0F0_49CB_ABE8_E0E41B1662E4__INCLUDED_)
