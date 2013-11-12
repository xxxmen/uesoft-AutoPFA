// AutoPFA.h : main header file for the AUTOPFA application
//

#if !defined(AFX_AUTOPFA_H__E0ED0D2F_50AF_4B10_A00E_E2CBBA525E19__INCLUDED_)
#define AFX_AUTOPFA_H__E0ED0D2F_50AF_4B10_A00E_E2CBBA525E19__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoPFAApp:
// See AutoPFA.cpp for the implementation of this class
//

class CAutoPFAApp : public CWinApp
{
public:
	CAutoPFAApp();
	~CAutoPFAApp();
	CMultiDocTemplate* m_pModelDataTemplate;
	CMultiDocTemplate* m_pOutDataTemplate;
	CMultiDocTemplate* m_pGraphTemplate;
	BOOL FileExists(LPCTSTR lpszPathName);

	void OnFileOpen(); 
	bool ChartActiveXRegister( const bool& bChangeType );
	bool ActiveXRegister( CString& OcxFileName, const bool& bChangeType );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoPFAApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CAutoPFAApp)
	afx_msg void OnAppAbout();
	afx_msg void OnPfahelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOPFA_H__E0ED0D2F_50AF_4B10_A00E_E2CBBA525E19__INCLUDED_)
