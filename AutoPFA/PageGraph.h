#if !defined(AFX_PAGEGRAPH_H__CCCBC77D_FC9C_4106_8DCF_0957F2756112__INCLUDED_)
#define AFX_PAGEGRAPH_H__CCCBC77D_FC9C_4106_8DCF_0957F2756112__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGraph.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageGraph dialog
#include "TranOutMgr.h"
#include "OutDataAttr.h"
#include "ComponentStmOut.h"
#include "BaseDlg.h"

class GraphView;

class PageGraph : public BaseDlg
{
// Construction
public:
	virtual void ShowData(TranOutMgr &mgr,GraphView &view)=0;
	PageGraph(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGraph)
	enum { IDD = IDD_PAGEGRAPH };
	CButton	m_butMove;
	CButton	m_butAdd;
	CTreeCtrl	m_tree;
	CListBox	m_box;
	CListCtrl	m_list;
	CComboBox	m_cbmYUnit;
	CComboBox	m_cbmXUnit;
	CString	m_strXUnit;
	CString	m_strYUnit;
	CString	m_strYUnitText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGraph)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	OutAttrArray *m_pArray;
	HTREEITEM InsertItem(CString strText,int nKey,HTREEITEM hitem=TVI_ROOT);
	void InitAttr(OutAttrArray &array,int nStart = 2);
	// Generated message map functions
	//{{AFX_MSG(PageGraph)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelChangeBox();
	afx_msg void OnAdd();
	afx_msg void OnMove();
	afx_msg void OnClear();
	afx_msg void OnSelChangedTree(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemChangedList(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	BOOL Exist();
	void InitUnit(CComboBox &cbo,CString &strUnit,OutDataAttr &attr);
	int m_nCurSelRow;
	int m_nPipeKey;
	int m_nStationKey;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGRAPH_H__CCCBC77D_FC9C_4106_8DCF_0957F2756112__INCLUDED_)
