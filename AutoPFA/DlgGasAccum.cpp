// DlgGasAccum.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgGasAccum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgGasAccum dialog


DlgGasAccum::DlgGasAccum(UnitSubSystem &UnitSys,ComponentManager &manager,GasAccumulator *pGasAccum,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pGasAccum, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page3(UnitSys)
{
	//{{AFX_DATA_INIT(DlgGasAccum)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgGasAccum::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgGasAccum)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgGasAccum, DlgJun)
	//{{AFX_MSG_MAP(DlgGasAccum)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgGasAccum message handlers
void DlgGasAccum::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init();
	m_page3.Init();
}

void DlgGasAccum::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page3.UpData();
}

BOOL DlgGasAccum::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRGASACCUM);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGONEElE,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("空气罐模型",&m_page1,IDD_GASACCUMMODEL);
	m_tab.AddPage("管道流向",&m_page2,IDD_PAGEPIPEDIR);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_GASACCUMOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();
	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgGasAccum::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
