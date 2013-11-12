#if !defined(AFX_DLGINITPUMPINERIA_H__901866D0_1457_493A_853E_67FA78AE2E7E__INCLUDED_)
#define AFX_DLGINITPUMPINERIA_H__901866D0_1457_493A_853E_67FA78AE2E7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgInitPumpIneria.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgInitPumpIneria dialog
#include "TabSheet.h"
#include "pagetrantriger.h"
#include "PageInertialData.h"
#include "PumpTransient.h"
#include "DlgPumpTranData.h"

class DlgInitPumpIneria : public CDialog
{
// Construction
public:
	void SetCurSel(int nCur);
	void ShowPage(int nIndex,BOOL bShow);
	void EnableEvent(BOOL bEnable);
	void TimeEvent(BOOL bEnable);
	void Init(PumpTransient &ref);
	BOOL UpData(PumpTransient &ref);
	DlgInitPumpIneria(UnitSubSystem &UnitSys,ComponentManager &manager,DlgPumpTranData &TransData,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgInitPumpIneria)
	enum { IDD = IDD_INITTRANS };
	CTabSheet	m_tab;
	int		m_nEventType;
	//}}AFX_DATA
	int m_transModel;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgInitPumpIneria)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgPumpTranData &m_dlgTransData;
	PageTranTriger m_page1;
	PageTranTriger m_page2;
	PageInertialData m_page3;
	

	// Generated message map functions
	//{{AFX_MSG(DlgInitPumpIneria)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioTime();
	afx_msg void OnRadioSingle();
	afx_msg void OnRadioDualSeguen();
	afx_msg void OnRadioDualCyclic();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ChangeName();
	void SetEventStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGINITPUMPINERIA_H__901866D0_1457_493A_853E_67FA78AE2E7E__INCLUDED_)
