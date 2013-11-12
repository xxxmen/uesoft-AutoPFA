#if !defined(AFX_DLGBEND_H__4DE1D835_7973_4582_82DC_7EEFE7950CB6__INCLUDED_)
#define AFX_DLGBEND_H__4DE1D835_7973_4582_82DC_7EEFE7950CB6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgbend.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "pagebendmodel.h"
/////////////////////////////////////////////////////////////////////////////
// DlgBend dialog

class DlgBend : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgBend(UnitSubSystem &UnitSys,ComponentManager &manager,Bend *pBend,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgBend)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgBend)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd m_DlgEle;
	PageBendModel m_page1;
	ComponentManager &m_manager;
// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgBend)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBEND_H__4DE1D835_7973_4582_82DC_7EEFE7950CB6__INCLUDED_)
