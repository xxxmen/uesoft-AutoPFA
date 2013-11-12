// DlgJunView.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgJunView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgJunView dialog


DlgJunView::DlgJunView(CWnd* pParent /*=NULL*/)
	: DlgTabView(pParent)
{
	//{{AFX_DATA_INIT(DlgJunView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgJunView::DoDataExchange(CDataExchange* pDX)
{
	DlgTabView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgJunView)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgJunView, DlgTabView)
	//{{AFX_MSG_MAP(DlgJunView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgJunView message handlers

BOOL DlgJunView::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRAREACHANGE,&m_page1,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRASSIGNFLOW,&m_page2,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRASSIGNPRESS,&m_page3,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRBRANCH,&m_page4,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRCHECK,&m_page5,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRCONTROL,&m_page6,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRDEADEND,&m_page7,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRGASACCUM,&m_page8,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRGENERAL,&m_page9,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRLIQUIDACCUM,&m_page10,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRPUMP,&m_page11,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRRELIEF,&m_page12,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRRESERVIOR,&m_page13,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRSPRAY,&m_page14,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRSURGE,&m_page15,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRTEEWYE,&m_page16,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRBREAKER,&m_page17,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRVALVE,&m_page18,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRBEND,&m_page19,IDD_DATATABLE);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page0,IDD_DATALIST);
	m_tab.Show();

	m_pageList[0]=&m_page1;
	m_pageList[1]=&m_page2;
	m_pageList[2]=&m_page3;
	m_pageList[3]=&m_page4;
	m_pageList[4]=&m_page5;
	m_pageList[5]=&m_page6;
	m_pageList[6]=&m_page7;
	m_pageList[7]=&m_page8;
	m_pageList[8]=&m_page9;
	m_pageList[9]=&m_page10;
	m_pageList[10]=&m_page11;
	m_pageList[11]=&m_page12;
	m_pageList[12]=&m_page13;
	m_pageList[13]=&m_page14;
	m_pageList[14]=&m_page15;
	m_pageList[15]=&m_page16;
	m_pageList[16]=&m_page17;
	m_pageList[17]=&m_page18;
	m_pageList[18]=&m_page19;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgJunView::LoadData(UnitSubSystem *pUnitSys,ComponentManager *pManager)
{
	HideAllPage();//先隐藏所有页面

	Component *pComponent = NULL;
	IteratorPtr<Component> iteratorPtr(pManager->CreatJunIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pComponent = &iteratorPtr->CurrentItem();
		LoadPageData(pUnitSys,pManager,pComponent);
	}

	ShowPageHasData();
	m_page0.LoadData(pManager);
}

void DlgJunView::HideAllPage()
{
	int nCount = sizeof(m_pageList)/sizeof(m_pageList[0]);
	for(int i=0; i<nCount; i++)
	{
		m_tab.ShowPage(i,FALSE);
		m_pageList[i]->HasData(FALSE);
	}
}

void DlgJunView::ShowPageHasData()
{
	int nCount = sizeof(m_pageList)/sizeof(m_pageList[0]);
	int i;
	for( i=0; i<nCount; i++)
	{
		m_tab.ShowPage(i,m_pageList[i]->HasData());
		m_pageList[i]->AutoSize();
	}
	
	for(i=0; i<nCount; i++)
	{
		if(m_pageList[i]->HasData())
		{
			m_tab.SetCurSel(i);
			break;
		}
		m_tab.SetCurSel(i+1);
	}
}

void DlgJunView::LoadPageData(UnitSubSystem *pUnitSys,ComponentManager *pManager,Component *pComponent)
{
	int nCount = sizeof(m_pageList)/sizeof(m_pageList[0]);
	for(int i=0; i<nCount; i++)
	{
		m_pageList[i]->LoadData(pUnitSys,pManager,pComponent);
	}
}
