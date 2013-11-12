// DlgAreaChange.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgAreaChange.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgAreaChange dialog


DlgAreaChange::DlgAreaChange(UnitSubSystem &UnitSys,ComponentManager &manager,AreaChange *pAreaChange,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pAreaChange,pParent)
	,m_page1(UnitSys,manager)
	,m_DlgEle(UnitSys)
	,m_page2(UnitSys)
{
	//{{AFX_DATA_INIT(DlgAreaChange)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgAreaChange::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgAreaChange)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgAreaChange, DlgJun)
	//{{AFX_MSG_MAP(DlgAreaChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgAreaChange message handlers
void DlgAreaChange::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init(m_DlgEle.InPipeID(),m_DlgEle.OutPipeID());
	m_page2.Init();
}

void DlgAreaChange::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData();
}

BOOL DlgAreaChange::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRAREACHANGE);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGTWOEND,this);
	InitBox(m_DlgEle);
	m_tab.AddPage(_T("Òì¾¶¹ÜÄ£ÐÍ"),&m_page1,IDD_AREACHANGEMODEL);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page2,IDD_DLGAREACHANGEOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}



void DlgAreaChange::ReadOnly( BOOL bReadOnly )
{
	DlgJun::ReadOnly(bReadOnly);
}
