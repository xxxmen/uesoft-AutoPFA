#if !defined(AFX_DLGUNDEFINEDOBJECTS_H__BFBBB021_882B_42E1_B99F_BF8010334EE1__INCLUDED_)
#define AFX_DLGUNDEFINEDOBJECTS_H__BFBBB021_882B_42E1_B99F_BF8010334EE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgUndefinedObjects.h : header file
//
#include "ComponentManager.h"
class Component;
/////////////////////////////////////////////////////////////////////////////
// CDlgUndefinedObjects dialog

typedef CMap<int,int,Component*,Component*> ComponentMap;
class CDlgUndefinedObjects : public CDialog
{
// Construction
public:
	CDlgUndefinedObjects( UnitSubSystem* pUnitSubSystem , ComponentManager* pComponentManager , CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgUndefinedObjects)
	enum { IDD = IDD_DLG_UndefinedObjects };
	CStatic	m_staDisplayMsg;
	CListBox	m_listUndefinedProps;
	CListBox	m_listUndefinedPipes;
	CListBox	m_listUndefinedJuns;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgUndefinedObjects)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
	
	// Implementation
public:
	void InitWindow();
	void ShowPropDlg( Component* pComponent );
public:
	ComponentManager* m_pComponentManager;
	UnitSubSystem* m_pUnitSystem;
protected:
	ComponentMap m_unDefinedPipesMap;
	ComponentMap m_unDefinedJunsMap;
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgUndefinedObjects)
	afx_msg void OnSelChangeListUndefinedPipes();
	afx_msg void OnSelChangeListUndefinedJuns();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelChangeListUndefinedProps();
	afx_msg void OnLDBClickPipeList();
	afx_msg void OnDBClickJunList();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGUNDEFINEDOBJECTS_H__BFBBB021_882B_42E1_B99F_BF8010334EE1__INCLUDED_)
