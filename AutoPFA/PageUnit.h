#if !defined(AFX_PAGEUNIT_H__937D42A7_9D60_485E_8A16_5B68B79EE667__INCLUDED_)
#define AFX_PAGEUNIT_H__937D42A7_9D60_485E_8A16_5B68B79EE667__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageUnit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPageUnit dialog
#include "UnitSubSystem.h"
#include "BaseDlg.h"
class PageUnit : public BaseDlg
{
// Construction
public:
	void Init(UnitSubSystem *pUnitSystem);
	BOOL UpdataSymbol();
	PageUnit(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPageUnit)
	enum { IDD = IDD_PAGEUNIT };
	CCheckListBox	m_symbolList;
	CListCtrl	m_UnitTypeList;
	//}}AFX_DATA


	UnitSubSystem *m_pUnitSystem;
	UnitType *m_pCurUnit;
	int m_CurSel;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPageUnit)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPageUnit)
	virtual BOOL OnInitDialog();
	afx_msg void OnChangedType(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCurUnit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitSymbol(UnitString *pSymbol);
	void InitListHeader();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEUNIT_H__937D42A7_9D60_485E_8A16_5B68B79EE667__INCLUDED_)
