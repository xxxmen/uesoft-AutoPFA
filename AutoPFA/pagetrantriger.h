#if !defined(AFX_PAGETRANTRIGER_H__52C75953_D3E6_445E_8235_0DD1956ECCC7__INCLUDED_)
#define AFX_PAGETRANTRIGER_H__52C75953_D3E6_445E_8235_0DD1956ECCC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagetrantriger.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// PageTranTriger dialog
class ComponentManager;

#include "BaseDlg.h"

class PageTranTriger : public BaseDlg
{
// Construction
public:
	BOOL UpData(ArrayFlyWeight<8> &ref);
	void Init(const ArrayFlyWeight<8> &ref);
	PageTranTriger(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageTranTriger)
	enum { IDD = IDD_TRANTRIGER };
	CComboBox	m_cmbLocation2;
	CNumEdit	m_EditValue;
	CComboBox	m_cmbLocation1;
	CComboBox	m_cmbEventType;
	CComboBox	m_cmbCondition;
	CComboBox	m_cmbComponent2;
	CComboBox	m_cmbComponent1;
	CUnitComboBox	m_cmbValue;
	CString	m_strValue;
	CString	m_strValueUnit;
	//}}AFX_DATA

	int m_nPort1;
	int m_nPort2;
	int m_nCondition;
	int m_nEventType;
	int m_nComponentID1;
	int m_nComponentID2;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageTranTriger)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	ComponentManager &m_manager;
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(PageTranTriger)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeEvent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetValueUnit();
	void TimeEvent();
	void DualPipeEvent();
	void JunEvent();
	void SinglePipeEvent();
	void SetEventType();
	void ValveEvent();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGETRANTRIGER_H__52C75953_D3E6_445E_8235_0DD1956ECCC7__INCLUDED_)
