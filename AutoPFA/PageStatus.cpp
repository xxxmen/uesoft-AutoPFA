// PageStatus.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageStatus.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageStatus dialog


PageStatus::PageStatus(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageStatus::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageStatus)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageStatus::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageStatus)
	DDX_Control(pDX, IDC_LIST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageStatus, BaseDlg)
	//{{AFX_MSG_MAP(PageStatus)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageStatus message handlers

void PageStatus::Init(ComponentStatus &ref)
{
	int nRow = 0;
	m_list.DeleteAllItems();
	CString strText(_T("属性定义完成"));
	if(ref.IsDefine())
	{
		m_list.InsertItem(nRow,strText);
	}
	else
	{
		IteratorPtr<CString> ItPtr(ref.CreatIterator());
		for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
		{
			strText = ItPtr->CurrentItem();
			m_list.InsertItem(nRow,strText);
			nRow++;
		}
	}
}

BOOL PageStatus::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	CRect rc;
	m_list.GetWindowRect(rc);
	m_list.InsertColumn(0,_T("Item"),LVCFMT_LEFT,rc.Width());
	DWORD styles = m_list.GetExtendedStyle();
	m_list.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageStatus::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	CRect rc;
	GetClientRect(rc);
	rc.DeflateRect(25,25);
	if(m_list.GetSafeHwnd())
	{
		m_list.MoveWindow(rc);
	}
}
