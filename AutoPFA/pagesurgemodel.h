#if !defined(AFX_PAGESURGEMODEL_H__869ED5A1_3CA0_4D1C_B0BB_4A73EA8E8244__INCLUDED_)
#define AFX_PAGESURGEMODEL_H__869ED5A1_3CA0_4D1C_B0BB_4A73EA8E8244__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagesurgemodel.h : header file
//
#include "GridCtrl.h"
#include "DlgShortPipe.h"
#include "DlgRestrictorModel.h"
#include "PageTable.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// PageSurgeModel dialog

class PageSurgeModel : public BaseDlg
{
// Construction
public:
	CString PressUnit();
	BOOL UpData();
	void Init();
	PageSurgeModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageSurgeModel)
	enum { IDD = IDD_SURGEMODEL };
	CEdit	m_EditSurFaceEle;
	CButton	m_Box3;
	CButton	m_CheckCv;
	CUnitComboBox	m_cmbAreaUnit;
	CUnitComboBox	m_cmbEleUnit;
	CUnitComboBox	m_cmbOpenPress;
	CUnitComboBox	m_cmbSurfacePress;
	CNumEdit	m_EditConstArea;
	CNumEdit	m_EditCv;
	CNumEdit	m_EditOpenPress;
	CNumEdit	m_EditSurfacePress;
	CButton	m_Box2;
	CButton	m_Box1;
	int		m_nPressType;
	int		m_nAreaType;
	CString	m_strSurfacePress;
	CString	m_strEle;
	CString	m_strOpenPress;
	CString	m_strCv;
	CString	m_strConstArea;
	CString	m_strSurfacePressUnit;
	CString	m_strOpenPressUnit;
	CString	m_strEleUnit;
	CString	m_strAreaUnit;
	BOOL	m_bModel;
	BOOL	m_bCv;
	int		m_nPosition;
	//}}AFX_DATA

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageSurgeModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	PageTable m_dlgTable;
	DlgRestrictorModel m_dlgRestrictor;
	DlgShortPipe m_dlgShortPipe;
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(PageSurgeModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioConst();
	afx_msg void OnRadioVariable();
	afx_msg void OnCheckModel();
	afx_msg void OnCheckCv();
	afx_msg void OnRadioHead();
	afx_msg void OnRadioPress();
	afx_msg void OnSelchangePressUnit();
	afx_msg void OnSelchangeEleUnit();
	afx_msg void OnSelchangeAraeUnit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CString HeightUnit();
	CString AreaUnit();
	void SetTableHeader();
	void SetAreaStatus();
	void SetModelStatus();
	void SetCvStatus();
	void InitPressUnit();
	void InitList();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGESURGEMODEL_H__869ED5A1_3CA0_4D1C_B0BB_4A73EA8E8244__INCLUDED_)
