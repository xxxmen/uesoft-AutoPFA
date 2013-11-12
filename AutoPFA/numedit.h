#if !defined(AFX_NUMEDIT_H__29D7BDC0_1FB9_4D8F_A722_69E586BE0637__INCLUDED_)
#define AFX_NUMEDIT_H__29D7BDC0_1FB9_4D8F_A722_69E586BE0637__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// numedit.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CNumEdit window

class CNumEdit : public CEdit
{
// Construction
public:
	CNumEdit();

// Attributes
private:
	COLORREF m_clrFor;  // foreground color
	COLORREF m_clrBack; //background color
	CBrush   m_brush ;   //background brush
	BOOL     m_bReadOnly;
	BOOL     m_bEnable;
public:
	BOOL SetReadOnly(BOOL bReadOnly = TRUE);
	BOOL EnableWindow(BOOL bEnable = TRUE);
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNumEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CNumEdit)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg HBRUSH CtlColor(CDC* pDC, UINT nCtlColor);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMEDIT_H__29D7BDC0_1FB9_4D8F_A722_69E586BE0637__INCLUDED_)
