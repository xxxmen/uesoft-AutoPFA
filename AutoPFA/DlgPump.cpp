// DlgPump.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgPump.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgPump dialog


DlgPump::DlgPump(UnitSubSystem &UnitSys,ComponentManager &manager,Pump *pPump,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pPump, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page2(UnitSys)
	,m_page3(UnitSys,manager)
	,m_page4(UnitSys)
{
	//{{AFX_DATA_INIT(DlgPump)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgPump::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgPump)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgPump, DlgJun)
	//{{AFX_MSG_MAP(DlgPump)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgPump message handlers
void DlgPump::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init();
	int nType = m_page1.PumpType();
	CString strUnit = m_page1.FlowUnit();
	if(nType==0 && m_page2.Type()!=0)
	{
		nType =3;//变速泵
		strUnit = m_page2.ControlUnit();
	}
	m_page3.Init(Pump::ms_Transient,nType,strUnit);
	m_page4.Init();
}

void DlgPump::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData();
	m_page3.UpData(Pump::ms_Transient);
	m_page4.UpData();
}
BOOL DlgPump::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRPUMP);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("泵模型",&m_page1,IDD_PUMPMODEL);
	m_tab.AddPage("变速泵",&m_page2,IDD_VARIABLESPEED);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page3,IDD_PAGEPUMPTRANS);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page4,IDD_PUMPOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgPump::ChangeType(int nType,CString strUnit)
{
	m_page3.InitTransModel(nType,strUnit);
}

void DlgPump::VariableSpeed(BOOL bVariable)
{
	m_page2.ControlStatus(bVariable);
}

void DlgPump::ChangeControl(int nType,CString strUnit)
{
	if(0 == m_page1.PumpType())
	{//变速泵
		m_page3.InitTransModel(nType,strUnit);
	}
}

void DlgPump::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
