#if !defined(AFX_PAGECOMPONENTTABLE_H__DA815D56_C3E0_45AA_A2B1_8B6459EE2030__INCLUDED_)
#define AFX_PAGECOMPONENTTABLE_H__DA815D56_C3E0_45AA_A2B1_8B6459EE2030__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageComponentTable.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageComponentTable dialog

#include "Component.h"
#include "ComponentManager.h"
#include "PageDataTable.h"

class PageComponentTable : public PageDataTable
{
// Construction
public:
	virtual void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	PageComponentTable(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageComponentTable)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA
    

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageComponentTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
	ComponentManager *m_pManager;
	UnitSubSystem    *m_pUnitSys;

	// Generated message map functions
	//{{AFX_MSG(PageComponentTable)

		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	void InitTableData(Component *pComponent);
	void InitTableHeader(Component *pComponent);
	void UpDataTableData(Component *pComponent,int nRow);
private:
	void ShowDlg();
	virtual Component* GetComponent(int nKey) = 0;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGECOMPONENTTABLE_H__DA815D56_C3E0_45AA_A2B1_8B6459EE2030__INCLUDED_)
