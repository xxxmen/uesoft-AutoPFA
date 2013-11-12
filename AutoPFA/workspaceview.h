#if !defined(AFX_WORKSPACEVIEW_H__F401052F_5D61_429E_93CA_88FC5D6ECF8C__INCLUDED_)
#define AFX_WORKSPACEVIEW_H__F401052F_5D61_429E_93CA_88FC5D6ECF8C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// workspaceview.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// WorkSpaceView form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

#include "DlgPipeView.h"
#include "DlgGeneralView.h"
#include "DlgJunView.h"
#include "ModelDataView.h"

class WorkSpaceDataView : public CModelDataView
{
protected:
	WorkSpaceDataView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(WorkSpaceDataView)

// Form Data
public:
	//{{AFX_DATA(WorkSpaceView)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	DlgPipeView	m_PipeView;
	DlgJunView	m_JunView;
	DlgGeneralView	m_GeneralView;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(WorkSpaceView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnActivateView(BOOL bActivate, CView* pActivateView, CView* pDeactiveView);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~WorkSpaceDataView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(WorkSpaceView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WORKSPACEVIEW_H__F401052F_5D61_429E_93CA_88FC5D6ECF8C__INCLUDED_)
