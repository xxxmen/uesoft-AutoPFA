#if !defined(AFX_DLGINERAILTRANS_H__F79505E2_26A1_4B3E_8D9E_7E1530E8CB42__INCLUDED_)
#define AFX_DLGINERAILTRANS_H__F79505E2_26A1_4B3E_8D9E_7E1530E8CB42__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInerailTrans.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgInerailTrans dialog
#include "DlgInitPumpIneria.h"
#include "DlgPumpTranData.h"
#include "dlgtwotransspecial.h"
#include "PumpTransient.h"
#include "BaseDlg.h"

class DlgInerailTrans : public BaseDlg
{
// Construction
public:
	void ShowFB(BOOL bShow);
	void SetInitCurSel(int nCur);
	void SetDataCurSel(int nCur);
	void ShowDataPage(int nIndex,BOOL bShow = TRUE);
	void ShowInitPage(int nIndex,BOOL bShow = TRUE);
	void EnableEvent(BOOL bEnable = TRUE);
	void TimeEvent(BOOL bEnable = TRUE);
	void EnableSpecial(BOOL bEnable = TRUE);
	void EnableUnit(BOOL bEnable = TRUE);
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	DlgInerailTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgInerailTrans)
	enum { IDD = IDD_PAGETRANS5 };
	CButton	m_Box3;
	CButton	m_Box4;
	CButton	m_Box1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgInerailTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgTwoTransSpecial m_dlgTransSpecial;
	DlgInitPumpIneria  m_dlgInitPumpIneria;
	DlgPumpTranData    m_dlgPumpTranData;
	// Generated message map functions
	//{{AFX_MSG(DlgInerailTrans)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINERAILTRANS_H__F79505E2_26A1_4B3E_8D9E_7E1530E8CB42__INCLUDED_)
