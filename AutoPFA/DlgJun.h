#if !defined(AFX_DLGJUN_H__0F1896F2_2DE1_4C62_892B_1512257F8426__INCLUDED_)
#define AFX_DLGJUN_H__0F1896F2_2DE1_4C62_892B_1512257F8426__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgJun.h : header file
//
#include "ComponentManager.h"
#include "TabSheet.h"
#include "PageStatus.h"
/////////////////////////////////////////////////////////////////////////////
// DlgJun dialog

class DlgJun : public CDialog
{
// Construction
public:
	DlgJun(UnitSubSystem &UnitSys,ComponentManager &manager,Jun *pJun,CWnd* pParent = NULL,UINT nIDTemplate = DlgJun::IDD);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgJun)
	enum { IDD = IDD_DLGJUN };
	CButton	m_Box;
	CTabSheet	m_tab;
	CComboBox	m_cmbName;
	int		m_nID;
	CString	m_strName;
	//}}AFX_DATA
	//
protected:
	void InitBox(CDialog &dlg);
	void ReadOnly( BOOL bReadOnly );
	Jun  *m_pJun;
	Jun  *m_pJunTemp;//备份节点，用于拷贝
	PageStatus m_pageStatus;
private:
	void InitCmb();
	ComponentManager &m_manager;
	UnitSubSystem    &m_UnitSys;
	int m_nOldSel;
	BOOL m_bReadOnly;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgJun)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void SetReadOnly();
	virtual void UpData()=0;
	virtual void Init();
	void SaveData();

	// Generated message map functions
	//{{AFX_MSG(DlgJun)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
    afx_msg void OnCancel();
	afx_msg void OnJump();
	afx_msg void OnChangeCmbNameList();
	//}}AFX_MSG
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	DECLARE_MESSAGE_MAP()	
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGJUN_H__0F1896F2_2DE1_4C62_892B_1512257F8426__INCLUDED_)
