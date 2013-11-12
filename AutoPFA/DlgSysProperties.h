#if !defined(AFX_DLGSYSPROPERTIES_H__BF64B8ED_205B_4C25_9846_8A3F610BC3A1__INCLUDED_)
#define AFX_DLGSYSPROPERTIES_H__BF64B8ED_205B_4C25_9846_8A3F610BC3A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSysProperties.h : header file
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DlgSysProperties.h
  摘要：    
  author  : LSP          
*/
#include "SysProperties.h"
#include "TabSheet.h"
#include "PageFuild.h"
#include "PageCondition.h"
#include "PageViscosModel.h"

class ImpulseDataMgr;

/////////////////////////////////////////////////////////////////////////////
// DlgSysProperties dialog

class DlgSysProperties : public CDialog
{
// Construction
public:
	DlgSysProperties(ImpulseDataMgr &ImpulseData,UnitSubSystem &UnitSys,SysProperties &sysProper,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgSysProperties)
	enum { IDD = IDD_SYSPROPER };
	CTabSheet	m_tab;
	//}}AFX_DATA
    SysProperties &m_sysProper;
	PageCondition m_page1;
    PageFuild m_page2;
    PageViscosModel m_page3;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgSysProperties)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgSysProperties)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSYSPROPERTIES_H__BF64B8ED_205B_4C25_9846_8A3F610BC3A1__INCLUDED_)
