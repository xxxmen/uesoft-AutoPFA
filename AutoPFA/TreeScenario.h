#if !defined(AFX_TREESCENARIO_H__B7EA7CAC_9B26_4A94_946E_765BC24133F8__INCLUDED_)
#define AFX_TREESCENARIO_H__B7EA7CAC_9B26_4A94_946E_765BC24133F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TreeScenario.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：TreeScenario.h 
  摘要：    
  author  : LSP          
*/

/////////////////////////////////////////////////////////////////////////////
// TreeScenario window

class TreeScenario : public CTreeCtrl
{
// Construction
public:
	TreeScenario();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TreeScenario)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~TreeScenario();

	// Generated message map functions
protected:
	//{{AFX_MSG(TreeScenario)
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TREESCENARIO_H__B7EA7CAC_9B26_4A94_946E_765BC24133F8__INCLUDED_)
