// DlgGeneralView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgGeneralView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgGeneralView dialog


DlgGeneralView::DlgGeneralView(CWnd* pParent /*=NULL*/)
	: DlgTabView(pParent)
{
	//{{AFX_DATA_INIT(DlgGeneralView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgGeneralView::DoDataExchange(CDataExchange* pDX)
{
	DlgTabView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgGeneralView)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgGeneralView, DlgTabView)
	//{{AFX_MSG_MAP(DlgGeneralView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgGeneralView message handlers

BOOL DlgGeneralView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRSUMMARY,&m_page1,IDD_DATALIST);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgGeneralView::LoadData(NetModel *pNetModel)
{
	m_page1.LoadData(pNetModel);
}
