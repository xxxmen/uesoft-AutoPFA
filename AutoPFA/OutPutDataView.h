#if !defined(AFX_OUTPUTDATAVIEW_H__3AEA5BB1_35FC_4B8A_BB96_2E9A9DCB3617__INCLUDED_)
#define AFX_OUTPUTDATAVIEW_H__3AEA5BB1_35FC_4B8A_BB96_2E9A9DCB3617__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutPutDataView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// OutPutDataView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "DlgPipeOutView.h"
#include "DlgJunOutView.h"
#include "DlgGeneralOutView.h"
#include "ModelDataView.h"

class OutPutDataView : public CModelDataView
{
protected:
	OutPutDataView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(OutPutDataView)

// Form Data
public:
	//{{AFX_DATA(OutPutDataView)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	DlgPipeOutView	m_PipeView;
	DlgJunOutView	m_JunView;
	DlgGeneralOutView	m_GeneralView;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(OutPutDataView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~OutPutDataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(OutPutDataView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTDATAVIEW_H__3AEA5BB1_35FC_4B8A_BB96_2E9A9DCB3617__INCLUDED_)
