// DlgBranch.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgBranch.h"
#include "Branch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgBranch dialog


DlgBranch::DlgBranch(UnitSubSystem &UnitSys,ComponentManager &manager,Branch *pBrach,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pBrach,pParent)
	,m_page1(UnitSys)
	,m_DlgEle(UnitSys)
	,m_page2(UnitSys,manager)
	,m_page3(UnitSys)
{
	//{{AFX_DATA_INIT(DlgBranch)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgBranch::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgBranch)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgBranch, DlgJun)
	//{{AFX_MSG_MAP(DlgBranch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgBranch message handlers

void DlgBranch::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
    m_DlgEle.Init();
	m_page1.Init(Branch::ms_PipeInfo,Branch::ms_DistanceUnit);
	m_page2.Init(Branch::ms_Transient);
	m_page3.Init();
}

void DlgBranch::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData(Branch::ms_PipeInfo,Branch::ms_DistanceUnit);
	m_page2.UpData(Branch::ms_Transient);
	m_page3.UpData();
}

BOOL DlgBranch::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRBRANCH);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGONEElE,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("ËðÊ§ÏµÊý",&m_page1,IDD_PAGEBRANCH1);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page2,IDD_PAGETRANS2);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_BRACHOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgBranch::ChangeFlowType(UnitTypeID id,CString strType)
{
	m_page2.SetType(id,strType);
}

void DlgBranch::ChangeUnit(CString strUnit)
{
	m_page2.SetUnit(strUnit);
}

void DlgBranch::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
