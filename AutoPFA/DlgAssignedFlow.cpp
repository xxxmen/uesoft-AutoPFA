// DlgAssignedFlow.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgAssignedFlow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgAssignedFlow dialog


DlgAssignedFlow::DlgAssignedFlow(UnitSubSystem &UnitSys,ComponentManager &manager,AssignedFlow *pAssignFlow,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pAssignFlow,pParent)
	,m_page1(UnitSys)
	,m_page2(UnitSys,manager)
	,m_DlgEnd(UnitSys)
	,m_page3(UnitSys)
{
	//{{AFX_DATA_INIT(DlgAssignedFlow)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgAssignedFlow::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgAssignedFlow)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgAssignedFlow, DlgJun)
	//{{AFX_MSG_MAP(DlgAssignedFlow)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgAssignedFlow message handlers
void DlgAssignedFlow::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEnd.Init();
	m_page1.Init();
	m_page2.Init(AssignedFlow::ms_Transient,m_page1.FlowType(),m_page1.FlowString(),m_page1.FlowUnit());
	m_page3.Init();
}

void DlgAssignedFlow::UpData()
{
	// TODO: Add extra UpData here

	m_DlgEnd.UpData();
	m_page1.UpData();
	m_page2.UpData(AssignedFlow::ms_Transient);
	m_page3.UpData();
}

BOOL DlgAssignedFlow::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRASSIGNFLOW);
	SetWindowText(strTitle);
	m_DlgEnd.Create(IDD_DLGONEEND,this);
	InitBox(m_DlgEnd);
	m_tab.AddPage("流量模型",&m_page1,IDD_PAGEFLOW1);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page2,IDD_PAGETRANS3);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_ASSIGNFLOWOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();
	
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgAssignedFlow::ChangeFlowType(UnitTypeID id,CString strType)
{
	m_page2.SetType(id,strType);
}

void DlgAssignedFlow::ChangeUnit(CString strUnit)
{
	m_page2.SetUnit(strUnit);
}

void DlgAssignedFlow::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
