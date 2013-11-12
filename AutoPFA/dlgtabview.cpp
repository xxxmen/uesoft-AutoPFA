W// dlgtabview.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgtabview.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTabView dialog


DlgTabView::DlgTabView(CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgTabView::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgTabView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgTabView::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTabView)
	DDX_Control(pDX, IDC_TAB, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTabView, BaseDlg)
	//{{AFX_MSG_MAP(DlgTabView)
		// NOTE: the ClassWizard will add message map macros here
		ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTabView message handlers
void DlgTabView::OnSize(UINT nType, int cx, int cy) 
{
	BaseDlg::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(1,1);
	if(m_tab.GetSafeHwnd())
	{
		m_tab.MoveWindow(rc);
		m_tab.SetRect();
	}
}