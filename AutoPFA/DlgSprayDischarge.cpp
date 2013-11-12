// DlgSprayDischarge.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgSprayDischarge.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSprayDischarge dialog


DlgSprayDischarge::DlgSprayDischarge(UnitSubSystem &UnitSys,ComponentManager &manager,SprayDischarge *pSprayDischarge,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pSprayDischarge, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page2(UnitSys)
	,m_page3(UnitSys,manager)
	,m_page4(UnitSys)
{
	//{{AFX_DATA_INIT(DlgSprayDischarge)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgSprayDischarge::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSprayDischarge)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSprayDischarge, DlgJun)
	//{{AFX_MSG_MAP(DlgSprayDischarge)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSprayDischarge message handlers
void DlgSprayDischarge::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_page1.Init();
//	m_page2.Init();
	m_page2.Init(SprayDischarge::ms_PipeInfo,SprayDischarge::ms_DistanceUnit);
	m_page3.Init(SprayDischarge::ms_Transient,m_page1.SprayString(),m_page1.SprayUnit());
	m_page4.Init();
	m_DlgEle.Init();
}

void DlgSprayDischarge::UpData()
{
	// TODO: Add extra UpData here

	m_page1.UpData();
	m_DlgEle.UpData();
	m_page2.UpData(SprayDischarge::ms_PipeInfo,SprayDischarge::ms_DistanceUnit);

	m_page3.UpData(SprayDischarge::ms_Transient);
	m_page4.UpData();
}

BOOL DlgSprayDischarge::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRSPRAY);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGONEElE,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("损失模型",&m_page1,IDD_SPRAYMODEL);
//	m_tab.AddPage("管道流向",&m_page2,IDD_PAGEPIPEDIR);
	m_tab.AddPage("损失系数",&m_page2,IDD_PAGEBRANCH1);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page3,IDD_PAGETRANS2);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page4,IDD_SPRAYOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgSprayDischarge::ChangeType(CString strType)
{
	m_page3.SetType(None,strType);
}

void DlgSprayDischarge::ChangeUnit(CString strUnit)
{
	m_page3.SetUnit(strUnit);
}

void DlgSprayDischarge::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
