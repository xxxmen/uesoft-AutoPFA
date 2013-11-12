// DlgDeadEnd.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgDeadEnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgDeadEnd dialog


DlgDeadEnd::DlgDeadEnd(UnitSubSystem &UnitSys,ComponentManager &manager,DeadEnd *pDeadEnd,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pDeadEnd, pParent)
	,m_DlgEnd(UnitSys)
	,m_page1(UnitSys)
{
	//{{AFX_DATA_INIT(DlgDeadEnd)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgDeadEnd::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgDeadEnd)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgDeadEnd, DlgJun)
	//{{AFX_MSG_MAP(DlgDeadEnd)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgDeadEnd message handlers
void DlgDeadEnd::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEnd.Init();
	m_page1.Init();
}

void DlgDeadEnd::UpData()
{
	// TODO: Add extra UpData here

	m_DlgEnd.UpData();
	m_page1.UpData();
}
BOOL DlgDeadEnd::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRDEADEND);
	SetWindowText(strTitle);
	m_DlgEnd.Create(IDD_DLGONEEND,this);
	InitBox(m_DlgEnd);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page1,IDD_DEADENDOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();
	
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgDeadEnd::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
