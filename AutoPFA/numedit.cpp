// numedit.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "numedit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNumEdit

CNumEdit::CNumEdit()
{
	m_bReadOnly = TRUE;
	m_bEnable   = FALSE;
	m_clrFor =::GetSysColor(COLOR_WINDOWTEXT);
	m_clrBack=RGB(0,255,255); 
	m_brush.CreateSolidBrush (m_clrBack);

}

CNumEdit::~CNumEdit()
{
	m_brush.DeleteObject();
}


BEGIN_MESSAGE_MAP(CNumEdit, CEdit)
	//{{AFX_MSG_MAP(CNumEdit)
	ON_WM_CHAR()
	ON_WM_CTLCOLOR_REFLECT()
	ON_WM_CTLCOLOR()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNumEdit message handlers

void CNumEdit::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(('0'<=nChar&&nChar<='9')||nChar=='.'||nChar == VK_BACK
		||nChar == 'e'||nChar == 'E'||nChar == '+'||nChar == '-')
		CEdit::OnChar(nChar, nRepCnt, nFlags);
}

HBRUSH CNumEdit::CtlColor(CDC* pDC, UINT nCtlColor) 
{
	if(m_bEnable&&!m_bReadOnly)
	{
		pDC->SetTextColor(m_clrFor);
		pDC->SetBkColor(m_clrBack);
		return (HBRUSH)m_brush.GetSafeHandle();
	}
	else 
	{
		return NULL;
	}
}

BOOL CNumEdit::SetReadOnly(BOOL bReadOnly)
{
	m_bReadOnly = bReadOnly;
	return CEdit::SetReadOnly(bReadOnly);
}

BOOL CNumEdit::EnableWindow( BOOL bEnable)
{
	m_bEnable = bEnable;
	return CWnd::EnableWindow(bEnable);
}
