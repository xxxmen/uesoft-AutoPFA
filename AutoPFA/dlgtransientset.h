#if !defined(AFX_DLGTRANSIENTSET_H__04AB1B7A_CF3D_49D8_B9D3_2FCC790A4891__INCLUDED_)
#define AFX_DLGTRANSIENTSET_H__04AB1B7A_CF3D_49D8_B9D3_2FCC790A4891__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgtransientset.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// DlgTransientSet dialog
class NetModel;
class DlgTransientSet : public CDialog
{
// Construction
public:
	BOOL UpData();
	BOOL Init();
	DlgTransientSet(UnitSubSystem &UnitSys,NetModel* pNetModel,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgTransientSet)
	enum { IDD = IDD_DLGTRANSIENTSET };
	CEdit	m_EditMinFlow;
	CEdit	m_EditStopTime;
	CEdit	m_EditStartTime;
	CUnitComboBox	m_cmbTimeUnit;
	CComboBox	m_cmbModel;
	CUnitComboBox	m_cmbMinFlowUnit;
	CComboBox	m_cmbFrequency;
	BOOL	m_bArtificialTransient;
	BOOL	m_bCavitation;
	BOOL	m_bVariableR;
	CString	m_strFrequency;
	CString	m_strMinFlowUnit;
	CString	m_strTimeUnit;
	float	m_fStartTime;
	float	m_fStopTime;
	int	m_nTotalStep;
	float	m_fStepTime;
	float	m_fMinFlow;
	float	m_fCriteria;
	//}}AFX_DATA
	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgTransientSet)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;
	NetModel *m_pNetModel;
	// Generated message map functions
	//{{AFX_MSG(DlgTransientSet)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnSelchangeTime();
	afx_msg void OnChangeStartTime();
	afx_msg void OnChangeTtopTime();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void TotalStep();
	void LoadData();
	double TotalTime();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTRANSIENTSET_H__04AB1B7A_CF3D_49D8_B9D3_2FCC790A4891__INCLUDED_)
