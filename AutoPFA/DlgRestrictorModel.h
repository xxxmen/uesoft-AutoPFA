#if !defined(AFX_DLGRESTRICTORMODEL_H__6FBB9B81_412D_4F89_B384_955FDE8B41DF__INCLUDED_)
#define AFX_DLGRESTRICTORMODEL_H__6FBB9B81_412D_4F89_B384_955FDE8B41DF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRestrictorModel.h : header file
//
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// DlgRestrictorModel dialog

class DlgRestrictorModel : public BaseDlg
{
// Construction
public:
	BOOL UpData(ArrayFlyWeight<5> &ref);
	void Init(ArrayFlyWeight<5> &ref);
	DlgRestrictorModel(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgRestrictorModel)
	enum { IDD = IDD_RESTRICTORMODEL };
	CNumEdit	m_EditOutFlowCD;
	CNumEdit	m_EditInFlowCD;
	CNumEdit	m_EditArea;
	CUnitComboBox	m_cmbAreaUnit;
	BOOL	m_bModel;
	CString	m_strAreaUnit;
	CString	m_strArea;
	CString	m_strInFlowCD;
	CString	m_strOutlowCD;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgRestrictorModel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(DlgRestrictorModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckModel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ModelStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRESTRICTORMODEL_H__6FBB9B81_412D_4F89_B384_955FDE8B41DF__INCLUDED_)
