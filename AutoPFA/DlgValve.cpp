// DlgValve.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgValve dialog


DlgValve::DlgValve(UnitSubSystem &UnitSys,ComponentManager &manager,Valve *pValve,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pValve, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page2(UnitSys,manager)
	,m_page3(UnitSys)
{
	//{{AFX_DATA_INIT(DlgValve)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgValve::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgValve)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgValve, DlgJun)
	//{{AFX_MSG_MAP(DlgValve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgValve message handlers
void DlgValve::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init(Valve::ms_Transient,m_page1.LossString());
	m_page3.Init();
}

void DlgValve::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData(Valve::ms_Transient);
	m_page3.UpData();
}

BOOL DlgValve::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRVALVE);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);

	m_tab.AddPage("·§ÃÅÄ£ÐÍ",&m_page1,IDD_VALVEMODEL);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page2,IDD_PAGETRANS2);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_VALVEOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgValve::ChangeType(CString strType)
{
	m_page2.SetType(None,strType);
}

void DlgValve::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
