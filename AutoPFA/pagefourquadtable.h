#if !defined(AFX_PAGEFOURQUADTABLE_H__5A563DA3_85CB_4CE7_BBD6_D6FA5C284075__INCLUDED_)
#define AFX_PAGEFOURQUADTABLE_H__5A563DA3_85CB_4CE7_BBD6_D6FA5C284075__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagefourquadtable.h : header file
//
#include "GridCtrl.h"
/////////////////////////////////////////////////////////////////////////////
// PageFourQuadTable dialog
#include "PumpTransient.h"
#include "BaseDlg.h"

class PageFourQuadTable : public BaseDlg
{
// Construction
public:
	void ShowFB(BOOL bShow = TRUE);
	void InitRow(int Num);
	BOOL UpData(TransDataTable<3> &table);
	void Init(TransDataTable<3> &table,int num);
	PageFourQuadTable(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageFourQuadTable)
	enum { IDD = IDD_FOURQUADTABLE };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageFourQuadTable)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CGridCtrl	m_list;
	// Generated message map functions
	//{{AFX_MSG(PageFourQuadTable)
	virtual BOOL OnInitDialog();
	afx_msg void OnBChart();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void InitListHeader();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEFOURQUADTABLE_H__5A563DA3_85CB_4CE7_BBD6_D6FA5C284075__INCLUDED_)
