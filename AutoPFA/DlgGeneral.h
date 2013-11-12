#if !defined(AFX_DLGGENERAL_H__7FC0881E_A73C_495C_920C_3663E5824A90__INCLUDED_)
#define AFX_DLGGENERAL_H__7FC0881E_A73C_495C_920C_3663E5824A90__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgGeneral.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "pagegeneralmodel.h"
#include "PageGeneralOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgGeneral dialog

class DlgGeneral : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgGeneral(UnitSubSystem &UnitSys,ComponentManager &manager,General *pGeneral,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgGeneral)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgGeneral)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd m_DlgEle;
	PageGeneralModel m_page1;
	PageGeneralOption m_page2;
	// Generated message map functions
	//{{AFX_MSG(DlgGeneral)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGGENERAL_H__7FC0881E_A73C_495C_920C_3663E5824A90__INCLUDED_)
