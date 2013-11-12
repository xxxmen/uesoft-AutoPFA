// MyStaBar.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "MyStaBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyStaBar

CMyStaBar::CMyStaBar()
{
}

CMyStaBar::~CMyStaBar()
{
}


BEGIN_MESSAGE_MAP(CMyStaBar, CStatusBar)
	//{{AFX_MSG_MAP(CMyStaBar)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyStaBar message handlers

void CMyStaBar::OnPaint() 
{
	CStatusBar::OnPaint();
	
	//CPaintDC dc(this); // device context for painting
	CDC *pDC = GetDC();
	
	// TODO: Add your message handler code here
	CBitmap cBmp;
	cBmp.LoadBitmap(IDB_TICKSLTCTR);
	
	//CDC* pDC = m_wndStatusBar.GetDC();
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(&cBmp);
	
	CRect rect;
	GetItemRect(1,&rect);
	
	BITMAP bmp;
	cBmp.GetBitmap(&bmp);
	
	pDC->BitBlt(rect.left +  (rect.right - rect.left-bmp.bmWidth)/2, 
		rect.top + 1 , rect.right - rect.left, 
		rect.bottom - rect.top - 2,
		&dcCompatible, 0, 0,  SRCCOPY);

	ReleaseDC( pDC );
	
	// Do not call CButton::OnPaint() for painting messages
}
