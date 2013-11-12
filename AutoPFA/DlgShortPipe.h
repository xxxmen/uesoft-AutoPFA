#if !defined(AFX_DLGSHORTPIPE_H__7B5ED230_8B4E_4BA8_8D51_3F3C76E0CB41__INCLUDED_)
#define AFX_DLGSHORTPIPE_H__7B5ED230_8B4E_4BA8_8D51_3F3C76E0CB41__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgShortPipe.h : header file
//
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// DlgShortPipe dialog

class DlgShortPipe : public BaseDlg
{
// Construction
public:
	BOOL UpData(ArrayFlyWeight<10> &ref);
	void Init(ArrayFlyWeight<10> &ref);
	DlgShortPipe(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgShortPipe)
	enum { IDD = IDD_SHORTPIPEMODEL };
	CNumEdit	m_EditLen;
	CNumEdit	m_EditInDia;
	CNumEdit	m_EditFriction;
	CNumEdit	m_EditEle;
	CNumEdit	m_EditArea;
	CUnitComboBox	m_cmbLenUnit;
	CUnitComboBox	m_cmbInDiaUnit;
	CUnitComboBox	m_cmbEleUnit;
	CUnitComboBox	m_cmbAreaUnit;
	BOOL	m_bModel;
	CString	m_strAreaUnit;
	CString	m_strEleUnit;
	CString	m_strInDiaUnit;
	CString	m_strLenUnit;
	CString	m_strArea;
	CString	m_strEle;
	CString	m_strFriction;
	CString	m_strInDia;
	CString	m_strLen;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgShortPipe)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	UnitSubSystem &m_UnitSys;

	// Generated message map functions
	//{{AFX_MSG(DlgShortPipe)
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckPipe();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void ModelStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSHORTPIPE_H__7B5ED230_8B4E_4BA8_8D51_3F3C76E0CB41__INCLUDED_)
