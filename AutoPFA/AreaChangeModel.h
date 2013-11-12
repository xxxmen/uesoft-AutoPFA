#if !defined(AFX_AREACHANGEMODEL_H__C03E1118_09A1_4B09_8A2C_53DC0EB080D9__INCLUDED_)
#define AFX_AREACHANGEMODEL_H__C03E1118_09A1_4B09_8A2C_53DC0EB080D9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AreaChangeModel.h : header file
//
#include "DlgBasisArea.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// AreaChangeModel dialog
class ComponentManager;

class AreaChangeModel : public BaseDlg
{
// Construction
public:
	BOOL UpData();
	void Init(int nId1,int nId2);
	AreaChangeModel(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(AreaChangeModel)
	enum { IDD = IDD_AREACHANGEMODEL };
	CStatic	m_BitMap;
	CNumEdit	m_EditK;
	CNumEdit	m_EditAngle;
	CButton	m_Box;
	CString	m_strAngle;
	CString	m_strK;
	int		m_nType;
	//}}AFX_DATA
	int m_InPipeID;
	int m_OutPipeID;
	UINT BitMapID[6];
	CBitmap m_bitmap;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(AreaChangeModel)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	ComponentManager &m_manager;
	DlgBasisArea m_dlgBasisArea;
	void CalcK();
	// Generated message map functions
	//{{AFX_MSG(AreaChangeModel)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadioConical();
	afx_msg void OnRadioAbrupt();
	afx_msg void OnRadioCustom();
	afx_msg void OnChangeAngel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void SetTypeModel();
	void GetArea(double &dUp,double &dDown);
	void SetControlStatus();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AREACHANGEMODEL_H__C03E1118_09A1_4B09_8A2C_53DC0EB080D9__INCLUDED_)
