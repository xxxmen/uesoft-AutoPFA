// DlgSurge.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgSurge.h"
#include "Surge.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSurge dialog


DlgSurge::DlgSurge(UnitSubSystem &UnitSys,ComponentManager &manager,Surge *pSurge,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pSurge, pParent)
	,m_page1(UnitSys)
	,m_page2(UnitSys)
	,m_DlgEle(UnitSys)
	,m_page3(UnitSys,manager)
	,m_page4(UnitSys)
{
	//{{AFX_DATA_INIT(DlgSurge)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgSurge::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSurge)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSurge, DlgJun)
	//{{AFX_MSG_MAP(DlgSurge)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSurge message handlers
void DlgSurge::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init(Surge::ms_PipeInfo,Surge::ms_DistanceUnit);
	m_page3.Init(Surge::ms_Transient,m_page1.PressUnit());
	m_page4.Init();

}

void DlgSurge::UpData()
{
	// TODO: Add extra UpData here

	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData(Surge::ms_PipeInfo,Surge::ms_DistanceUnit);
	m_page3.UpData(Surge::ms_Transient);
	m_page4.UpData();
}

BOOL DlgSurge::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRSURGE);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGONEElE,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("调压塔模型",&m_page1,IDD_SURGEMODEL);
	m_tab.AddPage("损失系数",&m_page2,IDD_PAGEBRANCH1);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page3,IDD_PAGETRANS2);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page4,IDD_SURGEOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgSurge::ChangeUnit(CString strUnit)
{
	m_page3.SetUnit(strUnit);
}

void DlgSurge::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
