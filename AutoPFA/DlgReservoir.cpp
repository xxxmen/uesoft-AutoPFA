// DlgReservoir.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgReservoir.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgReservoir dialog


DlgReservoir::DlgReservoir(UnitSubSystem &UnitSys,ComponentManager &manager,Reservoir *pReservoir,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pReservoir,pParent)
	,m_page1(UnitSys)
	,m_page2(UnitSys)
	,m_page3(UnitSys,manager)
{
	//{{AFX_DATA_INIT(DlgReservoir)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgReservoir::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgReservoir)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgReservoir, DlgJun)
	//{{AFX_MSG_MAP(DlgReservoir)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgReservoir message handlers
void DlgReservoir::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_page1.Init();
	m_page2.Init();
	m_page3.Init(Reservoir::ms_Transient,m_page1.EleUnit());
	m_page4.Init();
}

void DlgReservoir::UpData()
{
	// TODO: Add extra UpData here

	m_page1.UpData();
	m_page2.UpData();
	m_page3.UpData(Reservoir::ms_Transient);
	m_page4.UpData();
}

BOOL DlgReservoir::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRRESERVIOR);
	SetWindowText(strTitle);
	m_tab.AddPage("Ë®¿âÄ£ÐÍ",&m_page1,IDD_PAGERESERVIOR1);
	m_tab.AddPage(IDS_STRPIPE,&m_page2,IDD_PAGEDEPTHLOSS);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page3,IDD_PAGETRANS2);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page4,IDD_RESERVIOROPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgReservoir::ChangeUnit(CString strUnit)
{
	m_page3.SetUnit(strUnit);
}

void DlgReservoir::ReadOnly( BOOL bReadOnly )
{
	DlgJun::ReadOnly(bReadOnly);
}
