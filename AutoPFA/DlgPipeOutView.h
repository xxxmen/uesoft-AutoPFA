#if !defined(AFX_DLGPIPEOUTVIEW_H__A924343D_BA67_410C_A2C6_D78B2C74C259__INCLUDED_)
#define AFX_DLGPIPEOUTVIEW_H__A924343D_BA67_410C_A2C6_D78B2C74C259__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPipeOutView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgPipeOutView dialog
#pragma once
#include "dlgtabview.h"
#include "PageStmOutTable.h"
#include "PageTranOutTable.h"
#include "OutMgr.h"

#include "OutDataAttr.h"
#include "Iterator.h"
#include "ComponentStmOut.h"
#include "Scenario.h"

class NetModel;
class PFAOutModel;

class DlgPipeOutView : public DlgTabView
{
// Construction
public:
	void LoadData(Scenario* pScenario, PFAOutModel &outModel, UnitSubSystem* pUnitSys);
	DlgPipeOutView(CWnd* pParent = NULL);   // standard constructor
	~DlgPipeOutView();
	static OutAttrArray m_staticPipeArray;
    static OutAttrArray m_staticTranArray;
	static OutAttrArray m_staticMaxMinArray;
	void static InitData(CString InData,CString str[50],TCHAR chSeparator = _T(','));
	void SetOutPutArray(OutMgr &mgr,CStringArray* Array);
	void SetTranPutArray(OutMgr &mgr,CStringArray* Array);


	

// Dialog Data
	//{{AFX_DATA(DlgPipeOutView)
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgPipeOutView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageStmOutTable m_page1;
	PageTranOutTable m_page2;
	PageTranOutTable m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgPipeOutView)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void LoadStmData(OutMgr &Mgr,OutAttrArray &Array,PageOutTable &page,int nIndex);
	
	static CArray<OutDataAttr,OutDataAttr> m_staticArray;//用来保留单位制的改变。使得在在输出窗口关闭后再打开仍能显示上次的单位制
	static CArray<OutDataAttr,OutDataAttr> m_staticArrayPage2;//用来保留单位制的改变。使得在在输出窗口关闭后再打开仍能显示上次的单位制
	static CArray<OutDataAttr,OutDataAttr> m_staticArrayPage3;//用来保留单位制的改变。使得在在输出窗口关闭后再打开仍能显示上次的单位制


	ComponentManager* m_pComMgr;
	UnitSubSystem* m_pUnitSys;
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPIPEOUTVIEW_H__A924343D_BA67_410C_A2C6_D78B2C74C259__INCLUDED_)
