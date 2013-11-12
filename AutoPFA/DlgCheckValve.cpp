// DlgCheckValve.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgCheckValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgCheckValve dialog


DlgCheckValve::DlgCheckValve(UnitSubSystem &UnitSys,ComponentManager &manager,CheckValve *pCheckValve,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pCheckValve, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page2(UnitSys,manager)
	,m_page3(UnitSys)
{
	//{{AFX_DATA_INIT(DlgCheckValve)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgCheckValve::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgCheckValve)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgCheckValve, DlgJun)
	//{{AFX_MSG_MAP(DlgCheckValve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgCheckValve message handlers
void DlgCheckValve::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init(CheckValve::ms_Transient,m_page1.LossString());
	m_page3.Init();

}

void DlgCheckValve::UpData()
{
	// TODO: Add extra UpData here
    m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData(CheckValve::ms_Transient);
	m_page3.UpData();
}
BOOL DlgCheckValve::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRCHECK);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("·§ÃÅÄ£ÐÍ",&m_page1,IDD_CHECKMODEL);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page2,IDD_PAGETRANS1);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_CHECKOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgCheckValve::ChangeType(CString strType)
{
	m_page2.SetType(None,strType);
}

void DlgCheckValve::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
