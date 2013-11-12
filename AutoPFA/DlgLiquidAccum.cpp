// DlgLiquidAccum.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgLiquidAccum.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgLiquidAccum dialog


DlgLiquidAccum::DlgLiquidAccum(UnitSubSystem &UnitSys,ComponentManager &manager,LiquidAccumulator *pLiquidAccum,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pLiquidAccum, pParent)
	,m_DlgEle(UnitSys)
	,m_page1(UnitSys)
	,m_page3(UnitSys)
{
	//{{AFX_DATA_INIT(DlgLiquidAccum)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgLiquidAccum::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgLiquidAccum)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgLiquidAccum, DlgJun)
	//{{AFX_MSG_MAP(DlgLiquidAccum)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgLiquidAccum message handlers
void DlgLiquidAccum::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_page1.Init();
	m_page2.Init();
	m_DlgEle.Init();
	m_page3.Init();

}

void DlgLiquidAccum::UpData()
{
	// TODO: Add extra UpData here
	
	m_page1.UpData();
	m_DlgEle.UpData();
	m_page3.UpData();
}

BOOL DlgLiquidAccum::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRLIQUIDACCUM);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGONEElE,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("流体罐模型",&m_page1,IDD_LIQUIDACCUMMODEL);
	m_tab.AddPage("管道流向",&m_page2,IDD_PAGEPIPEDIR);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_LIQUIDACCUMOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgLiquidAccum::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
