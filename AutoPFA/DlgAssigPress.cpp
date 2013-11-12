// DlgAssigPress.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgAssigPress.h"
#include "AssignedPressure.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgAssigPress dialog


DlgAssigPress::DlgAssigPress(UnitSubSystem &UnitSys,ComponentManager &manager,AssignedPressure *pAssigPress,CWnd* pParent /*=NULL*/)
	: DlgJun(UnitSys,manager,pAssigPress, pParent)
	,m_page1(UnitSys)
	,m_page2(UnitSys)
	,m_page3(UnitSys,manager)
	,m_DlgEle(UnitSys)
{
	//{{AFX_DATA_INIT(DlgAssigPress)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgAssigPress::DoDataExchange(CDataExchange* pDX)
{
	DlgJun::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgAssigPress)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgAssigPress, DlgJun)
	//{{AFX_MSG_MAP(DlgAssigPress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgAssigPress message handlers
void DlgAssigPress::Init()
{
	// TODO: Add extra initialization here
	DlgJun::Init();
	m_DlgEle.Init();
	m_page1.Init();
	m_page2.Init(AssignedPressure::ms_PipeInfo,AssignedPressure::ms_DistanceUnit);
	m_page3.Init(AssignedPressure::ms_Transient,m_page1.PressType(),m_page1.PressString(),m_page1.PressUnit());
	m_page4.Init();
}

void DlgAssigPress::UpData()
{
	// TODO: Add extra UpData here
	m_DlgEle.UpData();
	m_page1.UpData();
	m_page2.UpData(AssignedPressure::ms_PipeInfo,AssignedPressure::ms_DistanceUnit);
	m_page3.UpData(AssignedPressure::ms_Transient);
	m_page4.UpData();
}

BOOL DlgAssigPress::OnInitDialog() 
{
	DlgJun::OnInitDialog();
	
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRASSIGNPRESS);
	SetWindowText(strTitle);
	m_DlgEle.Create(IDD_DLGONEElE,this);
	InitBox(m_DlgEle);
	m_tab.AddPage("压力模型",&m_page1,IDD_PAGEPRESS1);
	m_tab.AddPage("损失系数",&m_page2,IDD_PAGEBRANCH1);
	m_tab.AddPage(IDS_STRPAGETRANS,&m_page3,IDD_PAGETRANS3);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page4,IDD_ASSIGNPRESSOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_pageStatus,IDD_PAGESTATUS);
	m_tab.Show();

	Init();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgAssigPress::ChangePressType(UnitTypeID id,CString strType)
{
	m_page3.SetType(id,strType);
}

void DlgAssigPress::ChangeUnit(CString strUnit)
{
	m_page3.SetUnit(strUnit);
}

void DlgAssigPress::ReadOnly(BOOL bReadOnly)
{
	DlgJun::ReadOnly(bReadOnly);
}
