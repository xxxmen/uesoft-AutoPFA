#if !defined(AFX_PAGEGASACCUMMODEL_H__DC0595F5_F1B6_4562_89CD_3630FADFCC58__INCLUDED_)
#define AFX_PAGEGASACCUMMODEL_H__DC0595F5_F1B6_4562_89CD_3630FADFCC58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PageGasAccumModel.h : header file
//
#include "DlgShortPipe.h"
#include "DlgRestrictorModel.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageGasAccumModel dialog

class PageGasAccumModel : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageGasAccumModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageGasAccumModel)
	enum { IDD = IDD_GASACCUMMODEL };
	CNumEdit	m_EditPolyConst;
	CNumEdit	m_EditVolume;
	CNumEdit	m_EditPress;
	CUnitComboBox	m_cmbVolumeUnit;
	CUnitComboBox	m_cmbPressUnit;
	CButton	m_Box2;
	CButton	m_Box1;
	CString	m_strPressUnit;
	CString	m_strVolumeUnit;
	CString	m_strInitPress;
	CString	m_strInitVolume;
	CString	m_strMaxVolume;
	CString	m_strMinVolume;
	CString	m_strPolyConst;
	int		m_nVolumeType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageGasAccumModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgRestrictorModel m_dlgRestrictor;
	DlgShortPipe m_dlgShortPipe;
	UnitSubSystem &m_UnitSys;
	
	// Generated message map functions
	//{{AFX_MSG(PageGasAccumModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioActual();
	afx_msg void OnRadioSpecity();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void VolumeStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEGASACCUMMODEL_H__DC0595F5_F1B6_4562_89CD_3630FADFCC58__INCLUDED_)
