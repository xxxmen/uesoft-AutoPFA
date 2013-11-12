#if !defined(AFX_DLGOPTION_H__2915C990_C1EE_4BAE_860F_101D09089465__INCLUDED_)
#define AFX_DLGOPTION_H__2915C990_C1EE_4BAE_860F_101D09089465__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dlgoption.h : header file
//
#include "dlginitpressguess.h"
#include "dlgdesignfactor.h"
#include "BaseDlg.h"
/////////////////////////////////////////////////////////////////////////////
// DlgOption dialog

class DlgOption : public BaseDlg
{
// Construction
public:
	void SetDesignCaption(CString strCaption);
	BOOL UpData(ArrayFlyWeight<3> &ref1,StrFlyWeight &ref2);
	void Init(ArrayFlyWeight<3> &ref1,StrFlyWeight &ref2);
	DlgOption(UnitSubSystem &UnitSys,CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(DlgOption)
	enum { IDD = IDD_DIAOPTION };
	CButton	m_Box2;
	CButton	m_Box1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(DlgOption)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	DlgDesignFactor m_dlgDesignFactor;
	DlgInitPressGuess m_DlgInitGuess;

	// Generated message map functions
	//{{AFX_MSG(DlgOption)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOPTION_H__2915C990_C1EE_4BAE_860F_101D09089465__INCLUDED_)
