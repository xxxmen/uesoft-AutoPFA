// DlgControlValve.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgControlValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgControlValve dialog


DlgControlValve::DlgControlValve(UnitSubSystem &UnitSys,ComponentManager &manager,ControlValve *pControlValve,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pControlValve, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page2(UnitSys,manager)
	,m_page3(UnitSys,manager)
	,m_page4(UnitSys)
{
	//{{AFX_DATA_INIT(DlgControlValve)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgControlValve::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgControlValve)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgControlValve, DlgJun)
	//{{AFX_MSG_MAP(DlgControlValve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgControlValve message handlers
void DlgControlValve::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init(ControlValve::ms_FailTransient,m_page1.LossString());
	m_page3.Init(ControlValve::ms_Transient,m_page1.CtrlString(),m_page1.CtrlUnit());
	m_page4.Init();
}

void DlgControlValve::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData(ControlValve::ms_FailTransient);
	m_page3.UpData(ControlValve::ms_Transient);
	m_page4.UpData();
}
BOOL DlgControlValve::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRCONTROL);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("¿ØÖÆ·§Ä£ÐÍ",&m_page1,IDD_CONTROLMODEL);
	m_tab.AddPage(IDS_STRPAGEFAILTRANS,&m_page2,IDD_PAGETRANS0);
	m_tab.AddPage(IDS_STRPAGECTRLTRANS,&m_page3,IDD_PAGETRANS2);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page4,IDD_CONTROLOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void DlgControlValve::ChangeType(CString strLossType,CString strCtrlType)
{
	m_page2.SetType(None,strLossType);
	m_page3.SetType(None,strCtrlType);
}

void DlgControlValve::ChangeUnit(CString strUnit)
{
	m_page3.SetUnit(strUnit);
}

void DlgControlValve::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
