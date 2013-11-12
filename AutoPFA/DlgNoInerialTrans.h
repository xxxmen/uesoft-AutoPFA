#if !defined(AFX_DLGNOINERIALTRANS_H__931E8E02_0665_456B_8D1B_7C66DCD78485__INCLUDED_)
#define AFX_DLGNOINERIALTRANS_H__931E8E02_0665_456B_8D1B_7C66DCD78485__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgNoInerialTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgNoInerialTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"
class DlgNoInerialTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref);
	DlgNoInerialTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgNoInerialTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgNoInerialTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;

	// Generated message map functions
	//{{AFX_MSG(DlgNoInerialTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGNOINERIALTRANS_H__931E8E02_0665_456B_8D1B_7C66DCD78485__INCLUDED_)
