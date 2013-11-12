// DlgInitiation.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgInitiation.h"
#include "Transient.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgInitiation dialog


DlgInitiation::DlgInitiation(UnitSubSystem &UnitSys,ComponentManager &manager,DlgTarnsData &transData,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgInitiation::IDD, pParent)
	,m_page1(UnitSys,manager)
	,m_page2(UnitSys,manager)
	,m_dlgTanrsData(transData)
{
	//{{AFX_DATA_INIT(DlgInitiation)
	m_nEventType = -1;
	//}}AFX_DATA_INIT
}


void DlgInitiation::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgInitiation)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Radio(pDX, IDC_RADIOTIME, m_nEventType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgInitiation, BaseDlg)
	//{{AFX_MSG_MAP(DlgInitiation)
	ON_BN_CLICKED(IDC_RADIOTIME, OnRadioTime)
	ON_BN_CLICKED(IDC_RADIOSINGLE, OnRadioSingle)
	ON_BN_CLICKED(IDC_RADIODUALCYCLIC, OnRadioDualCyclic)
	ON_BN_CLICKED(IDC_RADIODUALSEGUEN, OnRadioDualDeguen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgInitiation message handlers

BOOL DlgInitiation::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRFRISTEVENT,&m_page1,IDD_TRANTRIGER);
	m_tab.AddPage(IDS_STRSECONDEVENT,&m_page2,IDD_TRANTRIGER);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgInitiation::OnRadioTime() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 0;
	SetEventStatus();
}

void DlgInitiation::OnRadioSingle() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 1;
	SetEventStatus();
}

void DlgInitiation::OnRadioDualCyclic() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 2;
	SetEventStatus();
}

void DlgInitiation::OnRadioDualDeguen() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 3;
	SetEventStatus();
}

void DlgInitiation::Init(Transient &ref)
{
	m_nEventType = ref.TranType().GetnValue();
	m_page1.Init(ref.TranTriger1());
	m_page2.Init(ref.TranTriger2());

	SetEventStatus();
	UpdateData(FALSE);
}

BOOL DlgInitiation::UpData(Transient &ref)
{
	UpdateData(TRUE);
	ref.m_TranType.SetValue(m_nEventType);
	m_page1.UpData(ref.m_TranTriger1);
	m_page2.UpData(ref.m_TranTriger2);
	return TRUE;
}

void DlgInitiation::SetEventStatus()
{
	switch(m_nEventType) {
	case 0:
		m_tab.ShowWindow(SW_HIDE);
		m_dlgTanrsData.m_tab.ShowWindow(SW_SHOW);
		m_dlgTanrsData.m_tab.ShowPage(1,FALSE);
		m_dlgTanrsData.m_tab.SetCurSel(0);
		break;
	case 1:
		m_tab.ShowWindow(SW_SHOW);
		m_tab.ShowPage(1,FALSE);
		m_tab.SetCurSel(0);
		m_dlgTanrsData.m_tab.ShowWindow(SW_SHOW);
		m_dlgTanrsData.m_tab.ShowPage(1,FALSE);
		m_dlgTanrsData.m_tab.SetCurSel(0);
		break;
	default:
		m_tab.ShowWindow(SW_SHOW);
		m_tab.ShowPage(1,TRUE);
		m_tab.SetCurSel(0);
		m_dlgTanrsData.m_tab.ShowWindow(SW_SHOW);
		m_dlgTanrsData.m_tab.ShowPage(1,TRUE);
		m_dlgTanrsData.m_tab.SetCurSel(0);
		break;
	}
	
}

void DlgInitiation::HideDualEvent()
{
	GetDlgItem(IDC_RADIODUALSEGUEN)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_RADIODUALCYCLIC)->ShowWindow(SW_HIDE);
}
