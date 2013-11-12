#if !defined(AFX_PAGERESERVOIRTRANS_H__76967007_E9EE_4C27_8C27_6C30B44A7F45__INCLUDED_)
#define AFX_PAGERESERVOIRTRANS_H__76967007_E9EE_4C27_8C27_6C30B44A7F45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageReservoirTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageReservoirTrans dialog
#include "PageTrans.h"
#include "dlgtwotransspecial.h"

class PageReservoirTrans : public PageTrans
{
// Construction
public:
	BOOL UpData(Transient &ref);
	void Init(Transient &ref,CString strUnit);
	PageReservoirTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageReservoirTrans)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageReservoirTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgSpecial;
	// Generated message map functions
	//{{AFX_MSG(PageReservoirTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGERESERVOIRTRANS_H__76967007_E9EE_4C27_8C27_6C30B44A7F45__INCLUDED_)
