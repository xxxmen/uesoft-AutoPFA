#if !defined(AFX_PAGEOUTTABLE_H__BE6BD17F_59E2_4923_9B7D_92E9B1B3996E__INCLUDED_)
#define AFX_PAGEOUTTABLE_H__BE6BD17F_59E2_4923_9B7D_92E9B1B3996E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageOutTable.h : header file
//
#include "PageDataTable.h"

//include "OutDataAttr.h"
#include "ComponentStmOut.h"
#include "QuantityManager.h"
#include "OutMgr.h"
#include "OutDataAttr.h"
/////////////////////////////////////////////////////////////////////////////
// PageOutTable dialog



class PageOutTable : public PageDataTable
{
// Construction
public:
	PageOutTable(CWnd* pParent = NULL);   // standard constructor

	void LoadData(OutMgr &mgr,OutAttrArray &Array,int nType = 0);
	BOOL SavePipeUnitOrder(CString strTemp);
	BOOL SaveJunUnitOrder(CString strTemp);
	void LoadComponentMgr(ComponentManager* pComMgr, UnitSubSystem* pUnitSys);
	BOOL ComponentType(CString strType);

// Dialog Data
	//{{AFX_DATA(PageOutTable)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageOutTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	//}}AFX_VIRTUAL

// Implementation
protected:
	OutAttrArray *m_pArray;
	OutMgr *m_pOutMgr;

protected:
	void InitTableHeader(OutAttrArray &array);
	void UpDataTableData(OutDataAttr &attr,int nCol);
	void InitTableData(OutAttrArray &array,ComponentStmOut *pStmOut);

	void ShowDlg(int iDlgType);
	void ShowComponentDlg();
	void ShowUnitDlg();
	virtual void ShowTranStepDlg();

protected:
	virtual CString LookUp(int nAtrrKey,int nRow)=0;
	virtual void Loading(OutMgr &mgr,OutAttrArray &Array,int nType ) =0;

	
	// Generated message map functions
	//{{AFX_MSG(PageOutTable)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	ComponentManager* m_pComponentMgr;
	UnitSubSystem*    m_pUnitSubSys;
	CString m_strComponentType;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEOUTTABLE_H__BE6BD17F_59E2_4923_9B7D_92E9B1B3996E__INCLUDED_)
