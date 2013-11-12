#if !defined(AFX_PAGEPUMPTRANS_H__B02A70DC_5F74_498C_B875_F787F6FEEED0__INCLUDED_)
#define AFX_PAGEPUMPTRANS_H__B02A70DC_5F74_498C_B875_F787F6FEEED0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PagePumpTrans.h : header file
//
#include "DlgInerailTrans.h"
#include "DlgNoInerialTrans.h"
#include "NoInerialModel.h"
#include "NoTranFourquadInerialModel.h"
#include "StratUpFourquadInerialModel.h"
#include "StratUpInerialModel.h"
#include "StartUpSpeedModel.h"
#include "TripFourquadInerialModel.h"
#include "TripInerialModel.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PagePumpTrans dialog
class PumpTransient;
class PagePumpTrans : public BaseDlg
{
// Construction
public:
	void InitTransModel(int nType,CString strUnit,int nCurModel = 0);
	BOOL UpData(PumpTransient &ref);
	void Init(PumpTransient &ref,int nType,CString strUnit);
	PagePumpTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PagePumpTrans)
	enum { IDD = IDD_PAGEPUMPTRANS };
	CComboBox	m_cmbTransModel;
	CButton	m_Box;
	//}}AFX_DATA
	int m_nTransModel;
	int m_nType;
	CString m_strUnit;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PagePumpTrans)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgInerailTrans m_dlgInerailTrans;
	DlgNoInerialTrans m_dlgNoInerialTrans;
	
	NoInerialModel               m_Model1;			//1:Whitout Inertia
    TripInerialModel             m_Model2;			//2:Trip With Inertia and No Back Flow or Reverse Speed
	TripFourquadInerialModel     m_Model3;			//3:Trip With Inertia ?Four Quadrant
	StartUpSpeedModel            m_Model4;			//4:Startup Four Quadrant  KnownSpeed
	StratUpInerialModel          m_Model5;			//5:Startup With Inertia and No Back Flow or Reverse Speed
	StratUpFourquadInerialModel  m_Model6;			//6:Startup With Inertia ?Four Quadrant, Known Motor Torque/Speed
	NoTranFourquadInerialModel   m_Model7;			// 7:No Transient ?Four Quadrant
	
	PumpTranModel* m_ModelArray[7];

	// Generated message map functions
	//{{AFX_MSG(PagePumpTrans)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeModel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void VariableSpeed();
	void CombineDlg(int nCurModel);
	CString FlowString();
	void SetUnit(CString strUnit);
	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEPUMPTRANS_H__B02A70DC_5F74_498C_B875_F787F6FEEED0__INCLUDED_)
