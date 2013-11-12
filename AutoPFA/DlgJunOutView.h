#if !defined(AFX_DLGJUNOUTVIEW_H__483BFF59_8D5D_47EE_9103_2731975DDFD9__INCLUDED_)
#define AFX_DLGJUNOUTVIEW_H__483BFF59_8D5D_47EE_9103_2731975DDFD9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgJunOutView.h : header file
//
#include "dlgtabview.h"
#include "PageStmOutTable.h"
#include "Scenario.h"
/////////////////////////////////////////////////////////////////////////////
// DlgJunOutView dialog
class NetModel;
class PFAOutModel;

class DlgJunOutView : public DlgTabView
{
// Construction
public:
	void LoadData(Scenario* pScenario, PFAOutModel &outModel, UnitSubSystem* pUnitSys);
	DlgJunOutView(CWnd* pParent = NULL);   // standard constructor
	~DlgJunOutView();
	static OutAttrArray m_staticJunArray;
	void static InitData(CString InData,CString str[50],TCHAR chSeparator = _T(','));
	void SetOutPutArray(OutMgr &mgr,CStringArray* Array);


// Dialog Data
	//{{AFX_DATA(DlgJunOutView)
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgJunOutView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageStmOutTable m_pageList[20];
	int m_TypeList[20];

	// Generated message map functions
	//{{AFX_MSG(DlgJunOutView)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ShowPageHasData();
	void HideAllPage();

	ComponentManager* m_pComponetMgr;
	UnitSubSystem*    m_pUnitSys;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGJUNOUTVIEW_H__483BFF59_8D5D_47EE_9103_2731975DDFD9__INCLUDED_)
