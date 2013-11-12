// DlgReliefValve.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgReliefValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgReliefValve dialog


DlgReliefValve::DlgReliefValve(UnitSubSystem &UnitSys,ComponentManager &manager,ReliefValve *pReliefValve,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pReliefValve,pParent)
	,m_page1(UnitSys)
	,m_DlgEle(UnitSys)
	,m_page2(UnitSys,manager)
	,m_page3(UnitSys)
{
	//{{AFX_DATA_INIT(DlgReliefValve)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgReliefValve::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgReliefValve)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgReliefValve, DlgJun)
	//{{AFX_MSG_MAP(DlgReliefValve)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgReliefValve message handlers
void DlgReliefValve::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init(ReliefValve::ms_Transient,m_page1.LossString());
	m_page3.Init();
	m_tab.ShowPage(1,m_page1.IsShowTrans());
}

void DlgReliefValve::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData(ReliefValve::ms_Transient);
	m_page3.UpData();
}
BOOL DlgReliefValve::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRRELIEF);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("·§ÃÅÄ£ÐÍ",&m_page1,IDD_RELIEFMODEL);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page2,IDD_PAGETRANS1);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_RELIEFOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgReliefValve::ChangeType(CString strType,BOOL bShow)
{
	m_page2.SetType(None,strType);
	m_tab.ShowPage(1,bShow);
}

void DlgReliefValve::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
