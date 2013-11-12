#if !defined(AFX_PAGEBENDMODEL_H__97A1D841_B8A2_43EF_8049_49B97FB9AA7F__INCLUDED_)
#define AFX_PAGEBENDMODEL_H__97A1D841_B8A2_43EF_8049_49B97FB9AA7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// pagebendmodel.h : header file
//
#include "DlgBasisArea.h"
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// PageBendModel dialog
class ComponentManager;

class PageBendModel : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init(CStringArray &PipeArea);
	PageBendModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(PageBendModel)
	enum { IDD = IDD_PAGEBENDMODEL };
	CNumEdit	m_EditRD;
	CNumEdit	m_EditK;
	CNumEdit	m_EditAngel;
	CButton	m_Box;
	CStatic	m_Bitmap;
	CString	m_strAngle;
	CString	m_strK;
	CString	m_strRD;
	int		m_nType;
	int		m_nAngelType;
	double  m_India;
	double  m_Outdia;
	//}}AFX_DATA
	UINT BitMapID[3];
	CBitmap m_bitmap;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(PageBendModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
    UnitSubSystem &m_UnitSys;
	DlgBasisArea m_dlgBasisArea;
	// Generated message map functions
	//{{AFX_MSG(PageBendModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioBend();
	afx_msg void OnRadioElbow();
	afx_msg void OnRadioMitre();
	afx_msg void OnRadioCustom();
	afx_msg void OnRadio90();
	afx_msg void OnRadioNo90();
	afx_msg void OnChangeErd();
	afx_msg void OnSetfocusEk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetAngleStatus();
	void SetTypeStatus();
	void SetTypeModel();
	void CalcK(double K);
	int VerticalNum ;   //直角弯头个数
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PAGEBENDMODEL_H__97A1D841_B8A2_43EF_8049_49B97FB9AA7F__INCLUDED_)
