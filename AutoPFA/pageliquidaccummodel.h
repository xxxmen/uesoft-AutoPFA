#if !defined(AFX_PAGELIQUIDACCUMMODEL_H__F09BC78C_FEF8_4EC7_BB67_51D3922E3189__INCLUDED_)
#define AFX_PAGELIQUIDACCUMMODEL_H__F09BC78C_FEF8_4EC7_BB67_51D3922E3189__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pageliquidaccummodel.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageLiquidAccumModel dialog

class PageLiquidAccumModel : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init();
	PageLiquidAccumModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageLiquidAccumModel)
	enum { IDD = IDD_LIQUIDACCUMMODEL };
	CNumEdit	m_EditVolume;
	CNumEdit	m_EditElastic;
	CUnitComboBox	m_cmbVolumeUnit;
	CUnitComboBox	m_cmbElasticUnit;
	CString	m_strElasticUnit;
	CString	m_strVolumeUnit;
	CString	m_strElastic;
	CString	m_strVolume;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageLiquidAccumModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	UnitSubSystem &m_UnitSys;
	// Generated message map functions
	//{{AFX_MSG(PageLiquidAccumModel)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGELIQUIDACCUMMODEL_H__F09BC78C_FEF8_4EC7_BB67_51D3922E3189__INCLUDED_)
