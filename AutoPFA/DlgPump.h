#if !defined(AFX_DLGPUMP_H__4E275B3B_25E9_4AEC_8451_4DD9F7903C71__INCLUDED_)
#define AFX_DLGPUMP_H__4E275B3B_25E9_4AEC_8451_4DD9F7903C71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPump.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "PagePumpModel.h"
#include "PageVariableSpeed.h"
#include "PagePumpTrans.h"
#include "PagePumpOption.h"
/////////////////////////////////////////////////////////////////////////////
// DlgPump dialog

class DlgPump : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeControl(int nType,CString strUnit);
	void VariableSpeed(BOOL bVariable);
	void ChangeType(int nType,CString strUnit);
	DlgPump(UnitSubSystem &UnitSys,ComponentManager &manager,Pump *pPump,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgPump)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgPump)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd         m_DlgEle;
	PagePumpModel     m_page1;
	PageVariableSpeed m_page2;
	PagePumpTrans     m_page3;
	PagePumpOption    m_page4;
	// Generated message map functions
	//{{AFX_MSG(DlgPump)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPUMP_H__4E275B3B_25E9_4AEC_8451_4DD9F7903C71__INCLUDED_)
