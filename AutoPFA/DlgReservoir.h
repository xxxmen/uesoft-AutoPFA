#if !defined(AFX_DLGRESERVOIR_H__033F4894_8CEF_4BCD_A7D3_5DF7749353A6__INCLUDED_)
#define AFX_DLGRESERVOIR_H__033F4894_8CEF_4BCD_A7D3_5DF7749353A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgReservoir.h : header file
//
#include "DlgJun.h"
#include "ReserviorPage1.h"
#include "PipeDepthLoss.h"
#include "PageReservoirTrans.h"
#include "PageReservoirOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgReservoir dialog

class DlgReservoir : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeUnit(CString strUnit);
	DlgReservoir(UnitSubSystem &UnitSys,ComponentManager &manager,Reservoir *pReservoir,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgReservoir)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgReservoir)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();

protected:
	ReserviorPage1 m_page1;
	PipeDepthLoss  m_page2;
	PageReservoirTrans  m_page3;
	PageReservoirOption m_page4;
	// Generated message map functions
	//{{AFX_MSG(DlgReservoir)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRESERVOIR_H__033F4894_8CEF_4BCD_A7D3_5DF7749353A6__INCLUDED_)
