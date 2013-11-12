// DlgGeneralOutView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgGeneralOutView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgGeneralOutView dialog


DlgGeneralOutView::DlgGeneralOutView(CWnd* pParent /*=NULL*/)
	: DlgTabView(pParent)
{
	//{{AFX_DATA_INIT(DlgGeneralOutView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgGeneralOutView::DoDataExchange(CDataExchange* pDX)
{
	DlgTabView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgGeneralOutView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgGeneralOutView, DlgTabView)
	//{{AFX_MSG_MAP(DlgGeneralOutView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgGeneralOutView message handlers

BOOL DlgGeneralOutView::OnInitDialog() 
{
	DlgTabView::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRSUMMARY,&m_page1,IDD_DATALIST);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgGeneralOutView::LoadData( Scenario* pScenario, PFAOutModel &outModel )
{
	NetModel* pNetModel = pScenario->GetNetModel();

	m_page1.LoadData(pNetModel);
	m_page1.LoadData(outModel);
}