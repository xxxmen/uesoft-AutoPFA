// DlgPipeView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgPipeView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgPipeView dialog


DlgPipeView::DlgPipeView(CWnd* pParent /*=NULL*/)
	: DlgTabView(pParent)
{
	//{{AFX_DATA_INIT(DlgPipeView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgPipeView::DoDataExchange(CDataExchange* pDX)
{
	DlgTabView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgPipeView)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgPipeView, DlgTabView)
	//{{AFX_MSG_MAP(DlgPipeView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgPipeView message handlers


BOOL DlgPipeView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRPIPE,&m_page1,IDD_DATATABLE);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgPipeView::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager)
{
	m_tab.ShowPage(0,FALSE);
	m_page1.HasData(FALSE);
	
	Component *pComponent = NULL;
	IteratorPtr<Component> iteratorPtr(pManager->CreatPipeIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pComponent = &iteratorPtr->CurrentItem();
		m_page1.LoadData(pUnitSys,pManager,pComponent);
	}
	if(m_page1.HasData())
	{
		m_tab.ShowPage(0,TRUE);
		m_tab.SetCurSel(0);
		m_page1.AutoSize();
	}
}
