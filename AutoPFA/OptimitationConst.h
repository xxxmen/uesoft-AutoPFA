#if !defined(AFX_OPTIMITATIONCONST_H__82CA125C_0C22_4BF3_AC55_789207F1923D__INCLUDED_)
#define AFX_OPTIMITATIONCONST_H__82CA125C_0C22_4BF3_AC55_789207F1923D__INCLUDED_


#pragma once
#include "PFAOptimitationData.h"
#include "AutoPFA.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OptimitationConst.h : header file
//
#include "BaseDlg.h"

/////////////////////////////////////////////////////////////////////////////
// COptimitationConst dialog

class COptimitationConst : public BaseDlg
{
// Construction
public:
	bool OpenData( PFAOptimitationData& OptData );
    bool SaveData( PFAOptimitationData& OptData );
	COptimitationConst(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COptimitationConst)
	enum { IDD = IDD_DLGOPTCONST };
	double	m_dA;
	double	m_dB;
	double	m_dAlfa;
	double	m_dPipeCost;
	double	m_dK;
	double	m_dM;
	double	m_dN;
	double	m_dP;
	double	m_dT;
	double	m_dEconomyK;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptimitationConst)
	public:
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptimitationConst)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(COptimitationConst)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIMITATIONCONST_H__82CA125C_0C22_4BF3_AC55_789207F1923D__INCLUDED_)
