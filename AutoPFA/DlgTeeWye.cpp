// DlgTeeWye.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgTeeWye.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgTeeWye dialog


DlgTeeWye::DlgTeeWye(UnitSubSystem &UnitSys,ComponentManager &manager,TeeWye *pTeeWye,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pTeeWye, pParent)
	,m_page1(pTeeWye)
	,m_DlgEle(UnitSys)
	,m_page2(UnitSys)
{
	//{{AFX_DATA_INIT(DlgTeeWye)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgTeeWye::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgTeeWye)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgTeeWye, DlgJun)
	//{{AFX_MSG_MAP(DlgTeeWye)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgTeeWye message handlers
void DlgTeeWye::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init();

}

void DlgTeeWye::UpData()
{
	// TODO: Add extra UpData here

	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData();
}

BOOL DlgTeeWye::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRTEEWYE);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGONEElE,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("三通模型",&m_page1,IDD_TEEWYEMODEL);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page2,IDD_TEEWYEOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgTeeWye::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
