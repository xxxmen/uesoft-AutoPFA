#if !defined(AFX_DLGLIQUIDACCUM_H__BA767F67_65B6_4E7D_A3D8_5702556BC2CA__INCLUDED_)
#define AFX_DLGLIQUIDACCUM_H__BA767F67_65B6_4E7D_A3D8_5702556BC2CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgLiquidAccum.h : header file
//
#include "DlgJun.h"
#include "DlgOneEle.h"
#include "PipeDirPage.h"
#include "pageliquidaccummodel.h"
#include "PageLiquidAccumOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgLiquidAccum dialog

class DlgLiquidAccum : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgLiquidAccum(UnitSubSystem &UnitSys,ComponentManager &manager,LiquidAccumulator *pLiquidAccum,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgLiquidAccum)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgLiquidAccum)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
protected:
	DlgOneEle m_DlgEle;
	PageLiquidAccumModel m_page1;
	PipeDirPage m_page2;
	PageLiquidAccumOption m_page3;
	// Generated message map functions
	//{{AFX_MSG(DlgLiquidAccum)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGLIQUIDACCUM_H__BA767F67_65B6_4E7D_A3D8_5702556BC2CA__INCLUDED_)
