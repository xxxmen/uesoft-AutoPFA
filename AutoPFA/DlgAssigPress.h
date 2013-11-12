#if !defined(AFX_DLGASSIGPRESS_H__9B116823_F25F_41BD_8A99_DC9B2B9A4013__INCLUDED_)
#define AFX_DLGASSIGPRESS_H__9B116823_F25F_41BD_8A99_DC9B2B9A4013__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAssigPress.h : header file
//
#include "DlgJun.h"
#include "DlgOneEle.h"
#include "BranchPage1.h"//ËðÊ§ÏµÊý
#include "AssignPressPage1.h"
#include "PageAssignedPressOption.h"
#include "pageassignedpresstrans.h"
/////////////////////////////////////////////////////////////////////////////
// DlgAssigPress dialog

class DlgAssigPress : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	void ChangeUnit(CString strUnit);
	void ChangePressType(UnitTypeID id,CString strType);
	DlgAssigPress(UnitSubSystem &UnitSys,ComponentManager &manager,AssignedPressure *pAssigPress,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgAssigPress)

		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgAssigPress)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	void UpData();
	void Init();
private:
	AssignPressPage1 m_page1;
	BranchPage1      m_page2;
	PageAssignedPressTrans  m_page3;
	PageAssignedPressOption m_page4;
	DlgOneEle m_DlgEle;
	// Generated message map functions
	//{{AFX_MSG(DlgAssigPress)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGASSIGPRESS_H__9B116823_F25F_41BD_8A99_DC9B2B9A4013__INCLUDED_)
