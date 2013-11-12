// DlgSysProperties.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgSysProperties.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSysProperties dialog


DlgSysProperties::DlgSysProperties(ImpulseDataMgr &ImpulseData,UnitSubSystem &UnitSys,SysProperties &sysProper,CWnd* pParent /*=NULL*/)
	: CDialog(DlgSysProperties::IDD, pParent)
	,m_sysProper(sysProper)
	,m_page1(UnitSys)
	,m_page2(ImpulseData,UnitSys)
{
	//{{AFX_DATA_INIT(DlgSysProperties)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgSysProperties::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSysProperties)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSysProperties, CDialog)
	//{{AFX_MSG_MAP(DlgSysProperties)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSysProperties message handlers

BOOL DlgSysProperties::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage("环境数据",&m_page1,IDD_CONDITION);
	m_tab.AddPage("流体数据",&m_page2,IDD_FUILDDATA);
	//m_tab.AddPage("粘度模型",&m_page3,IDD_VISCOSMODEL);
	m_tab.Show(); 
	m_page1.Init(m_sysProper.GetCondition());
	m_page2.Init(m_sysProper.GetFuild());
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgSysProperties::OnOK() 
{
	// TODO: Add extra validation here
	m_page1.UpData();
	m_page2.Updata();
	CDialog::OnOK();
}
