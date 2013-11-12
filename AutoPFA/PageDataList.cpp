// PageDataList.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageDataList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageDataList dialog


PageDataList::PageDataList(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageDataList::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageDataList)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageDataList::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageDataList)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageDataList, BaseDlg)
	//{{AFX_MSG_MAP(PageDataList)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageDataList message handlers

void PageDataList::OnSize(UINT nType, int cx, int cy) 
{
	BaseDlg::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(1,1);
	if(m_list.GetSafeHwnd())
	{
		m_list.MoveWindow(rc);
	}
}
