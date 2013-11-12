#if !defined(AFX_DLGAREACHANGE_H__9E8334EA_9246_43F5_ACD8_C865CE5A0A50__INCLUDED_)
#define AFX_DLGAREACHANGE_H__9E8334EA_9246_43F5_ACD8_C865CE5A0A50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAreaChange.h : header file
//
#include "DlgJun.h"
#include "DlgTwoEnd.h"
#include "AreaChangeModel.h"
#include "pageareachangeoption.h"

/////////////////////////////////////////////////////////////////////////////
// DlgAreaChange dialog

class DlgAreaChange : public DlgJun
{
// Construction
public:
	void ReadOnly(BOOL bReadOnly);
	DlgAreaChange(UnitSubSystem &UnitSys,ComponentManager &manager,AreaChange *pAreaChange,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgAreaChange)
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgAreaChange)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation

protected:
	void UpData();
	void Init();
private:
	DlgTwoEnd m_DlgEle;
	AreaChangeModel m_page1;
	PageAreaChangeOption m_page2;
	// Generated message map functions
	//{{AFX_MSG(DlgAreaChange)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGAREACHANGE_H__9E8334EA_9246_43F5_ACD8_C865CE5A0A50__INCLUDED_)
