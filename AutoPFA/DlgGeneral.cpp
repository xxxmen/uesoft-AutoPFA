// DlgGeneral.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgGeneral.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgGeneral dialog


DlgGeneral::DlgGeneral(UnitSubSystem &UnitSys,ComponentManager &manager,General *pGeneral,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pGeneral, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page2(UnitSys)
{
	//{{AFX_DATA_INIT(DlgGeneral)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgGeneral::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgGeneral)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgGeneral, DlgJun)
	//{{AFX_MSG_MAP(DlgGeneral)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgGeneral message handlers
void DlgGeneral::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init();
}

void DlgGeneral::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData();
}
BOOL DlgGeneral::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRGENERAL);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("ËðÊ§Ä£ÐÍ",&m_page1,IDD_GENERALMODEL);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page2,IDD_GENERALOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgGeneral::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
