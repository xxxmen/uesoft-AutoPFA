#if !defined(AFX_PAGEVARIABLESPEED_H__1FA48868_7A6A_4928_963B_8E2342F77D05__INCLUDED_)
#define AFX_PAGEVARIABLESPEED_H__1FA48868_7A6A_4928_963B_8E2342F77D05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageVariableSpeed.h : header file
//

#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageVariableSpeed dialog

class PageVariableSpeed : public BaseDlg
{
// Construction
public:
	int Type();
	CString ControlUnit();
	void ControlStatus(BOOL bVariableSpeed = TRUE);
	BOOL UpData();
	void Init();
	PageVariableSpeed(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageVariableSpeed)
	enum { IDD = IDD_VARIABLESPEED };
	CNumEdit	m_EditSetPoint;
	CUnitComboBox	m_cmbSetUnit;
	CString	m_strSetPointUnit;
	CString	m_strSetPointValue;
	CString	m_strSpeedRatio;
	int		m_nApplyType;
	int		m_nControlType;
	int		m_nPressType;
	CString	m_strNote;
	//}}AFX_DATA
	int		m_nSetType;//0：水头/体积流量1：压力/质量流量
	int		m_nType;//0：没有控制，1：输出端压力/水头控制，3：输入端压力/水头控制，2：流量控制


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageVariableSpeed)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(PageVariableSpeed)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioVolume();
	afx_msg void OnRadioSuctionPress();
	afx_msg void OnRadioSuctionHead();
	afx_msg void OnRadioNo();
	afx_msg void OnRadioMass();
	afx_msg void OnRadioDisPress();
	afx_msg void OnRadioDisHead();
	afx_msg void OnSelchangeSetunit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ChangControl(int nType);
	void SetTypeStatus();
	void InitControlType();
	void InitSetUnit();
};
inline int PageVariableSpeed::Type()
{
	return m_nType;
}
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEVARIABLESPEED_H__1FA48868_7A6A_4928_963B_8E2342F77D05__INCLUDED_)
