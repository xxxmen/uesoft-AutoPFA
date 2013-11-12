#if !defined(AFX_MODELDATAVIEW_H__3279DB95_97D8_4555_B962_90509C77CF1F__INCLUDED_)
#define AFX_MODELDATAVIEW_H__3279DB95_97D8_4555_B962_90509C77CF1F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ModelDataView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CModelDataView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif


class CModelDataView : public CFormView
{
protected:
	CModelDataView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CModelDataView)

// Form Data
public:
	//{{AFX_DATA(CModelDataView)
	enum { IDD = IDD_MODELDATAVIEW };
	//}}AFX_DATA
	CDialog	*m_pPipeView;
	CDialog	*m_pJunView;
	CDialog	*m_pGeneralView;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModelDataView)
	public:
	virtual void OnInitialUpdate();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CModelDataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CModelDataView)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSelChangeShow();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void TabStatus();
	int m_nCurShow; //0:概要 管道 连接元件 1:管道 连接元件2:管道
	                //3:连接元件4:概要
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MODELDATAVIEW_H__3279DB95_97D8_4555_B962_90509C77CF1F__INCLUDED_)
