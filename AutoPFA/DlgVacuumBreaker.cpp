// DlgVacuumBreaker.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgVacuumBreaker.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgVacuumBreaker dialog


DlgVacuumBreaker::DlgVacuumBreaker(UnitSubSystem &UnitSys,ComponentManager &manager,VacuumBreaker *pVacuumBreaker,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pVacuumBreaker, pParent)
	,m_DlgEnd(UnitSys)
	,m_page1(UnitSys)
	,m_page2(UnitSys)
{
	//{{AFX_DATA_INIT(DlgVacuumBreaker)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgVacuumBreaker::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgVacuumBreaker)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgVacuumBreaker, DlgJun)
	//{{AFX_MSG_MAP(DlgVacuumBreaker)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgVacuumBreaker message handlers
void DlgVacuumBreaker::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEnd.Init();
	m_page1.Init();
	m_page2.Init();
}

void DlgVacuumBreaker::UpData()
{
	// TODO: Add extra UpData here

	m_DlgEnd.UpData();
	m_page1.UpData();
	m_page2.UpData();
}
BOOL DlgVacuumBreaker::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRBREAKER);
	SetWindowText(strTitle);
	m_DlgEnd.Create(IDD_DLGONEEND,this);
	InitBox(m_DlgEnd);
	m_tab.AddPage("·§ÃÅÄ£ÐÍ",&m_page1,IDD_BREAKERMODEL);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page2,IDD_BREAKEROPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgVacuumBreaker::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
