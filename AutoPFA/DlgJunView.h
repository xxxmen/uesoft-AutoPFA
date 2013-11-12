#if !defined(AFX_DLGJUNVIEW_H__5F2EEA9C_E2B6_4289_9C6F_A8F791B302ED__INCLUDED_)
#define AFX_DLGJUNVIEW_H__5F2EEA9C_E2B6_4289_9C6F_A8F791B302ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgJunView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgJunView dialog
#include "dlgtabview.h"
#include "PageAreaChangeData.h"
#include "PageAssignedFlowData.h"
#include "PageAssignedPressureData.h"
#include "PageBranchData.h"
#include "PageCheck.h"
#include "PageControlData.h"
#include "PageDeadEndData.h"
#include "PageGasAccumData.h"
#include "PageGeneral.h"
#include "PageLiquidAccumData.h"
#include "PagePumpData.h"
#include "PageReliefData.h"
#include "PageReservoirData.h"
#include "PageBreakerData.h"
#include "PageSprayData.h"
#include "PageSurgeData.h"
#include "PageTeeWyeData.h"
#include "PageValveData.h"
#include "PageTransientData.h"
#include "PageBendData.h"
#include "ComponentManager.h"

class DlgJunView : public DlgTabView
{
// Construction
public:
	void LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager);
	DlgJunView(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgJunView)
	//}}AFX_DATA
	PageAreaChangeData m_page1;
	PageAssignedFlowData m_page2;
	PageAssignedPressureData m_page3;
	PageBranchData m_page4;
	PageCheckData m_page5;
	PageControlData m_page6;
	PageDeadEndData m_page7;
	PageGasAccumData m_page8;
	PageGeneralData m_page9;
	PageLiquidAccumData m_page10;
	PagePumpData m_page11;
	PageReliefData m_page12;
	PageReservoirData m_page13;
	PageSprayData m_page14;
	PageSurgeData m_page15;
	PageTeeWyeData m_page16;
	PageBreakerData m_page17;
	PageValveData m_page18;
	PageBendData m_page19;
	PageJunData *m_pageList[19];

	PageTransientData m_page0;

	


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgJunView)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(DlgJunView)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void LoadPageData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent);
	void ShowPageHasData();
	void HideAllPage();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGJUNVIEW_H__5F2EEA9C_E2B6_4289_9C6F_A8F791B302ED__INCLUDED_)
