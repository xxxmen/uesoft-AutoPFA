// PageDataTable.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageDataTable.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageDataTable dialog


PageDataTable::PageDataTable(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageDataTable::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageDataTable)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageDataTable::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageDataTable)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_TABLE, m_table);
}


BEGIN_MESSAGE_MAP(PageDataTable, BaseDlg)
	//{{AFX_MSG_MAP(PageDataTable)
		// NOTE: the ClassWizard will add message map macros here
		ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageDataTable message handlers
void PageDataTable::OnSize(UINT nType, int cx, int cy) 
{
	BaseDlg::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(1,1);
	if(m_table.GetSafeHwnd())
	{
		m_table.MoveWindow(rc);
	}
}

void PageDataTable::AutoSize()
{
	m_table.AutoSizeColumns();
	m_table.SetEditable(FALSE);
	m_table.SortItems(CGridCtrl::pfnCellNumericCompare,0,TRUE);
}
