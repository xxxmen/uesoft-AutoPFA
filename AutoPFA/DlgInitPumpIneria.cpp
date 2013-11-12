// DlgInitPumpIneria.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgInitPumpIneria.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgInitPumpIneria dialog


DlgInitPumpIneria::DlgInitPumpIneria(UnitSubSystem &UnitSys,ComponentManager &manager,DlgPumpTranData &TransData,CWnd* pParent /*=NULL*/)
	: CDialog(DlgInitPumpIneria::IDD, pParent)
	,m_dlgTransData(TransData)
	,m_page1(UnitSys,manager)
	,m_page2(UnitSys,manager)
	,m_page3(UnitSys,m_dlgTransData.FourQuadTable())
	
{
	//{{AFX_DATA_INIT(DlgInitPumpIneria)
	m_nEventType = -1;
	//}}AFX_DATA_INIT
	m_transModel = 0;
}


void DlgInitPumpIneria::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgInitPumpIneria)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Radio(pDX, IDC_RADIOTIME, m_nEventType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgInitPumpIneria, CDialog)
	//{{AFX_MSG_MAP(DlgInitPumpIneria)
	ON_BN_CLICKED(IDC_RADIOTIME, OnRadioTime)
	ON_BN_CLICKED(IDC_RADIOSINGLE, OnRadioSingle)
	ON_BN_CLICKED(IDC_RADIODUALSEGUEN, OnRadioDualSeguen)
	ON_BN_CLICKED(IDC_RADIODUALCYCLIC, OnRadioDualCyclic)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgInitPumpIneria message handlers

BOOL DlgInitPumpIneria::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRSTARTTRANS,&m_page1,IDD_TRANTRIGER);
	m_tab.AddPage(IDS_STRTRIPTRANS,&m_page2,IDD_TRANTRIGER);
	m_tab.AddPage(IDS_STRINERIALDATA,&m_page3,IDD_INERTIALDATA);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgInitPumpIneria::Init(PumpTransient &ref)
{
	m_transModel = ref.TranModel().GetnValue();
	m_nEventType = ref.TranType().GetnValue();
	m_page1.Init(ref.TranTriger1());
	m_page2.Init(ref.TranTriger2());
	m_page3.Init(ref);

	SetEventStatus();
	ChangeName();
	UpdateData(FALSE);
}

BOOL DlgInitPumpIneria::UpData(PumpTransient &ref)
{
	UpdateData(TRUE);
	ref.m_TranType.SetValue(m_nEventType);
	m_page1.UpData(ref.m_TranTriger1);
	m_page2.UpData(ref.m_TranTriger2);
	m_page3.UpData(ref);
	return TRUE;
}

void DlgInitPumpIneria::EnableEvent(BOOL bEnable)
{
	GetDlgItem(IDC_RADIOTIME)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIOSINGLE)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIODUALCYCLIC)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIODUALSEGUEN)->EnableWindow(bEnable);
}

void DlgInitPumpIneria::ShowPage(int nIndex,BOOL bShow)
{
	m_tab.ShowPage(nIndex,bShow);
}

void DlgInitPumpIneria::SetCurSel(int nCur)
{
	m_tab.SetCurSel(nCur);
}

void DlgInitPumpIneria::TimeEvent(BOOL bEnable)
{//call after init();
	if(bEnable)
	{
		m_nEventType = 0;
	}
	else
	{
		if(m_nEventType == 0)
		{
			m_nEventType = 1;
			SetEventStatus();
		}
		
	}
	GetDlgItem(IDC_RADIOTIME)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIOSINGLE)->EnableWindow(!bEnable);
	GetDlgItem(IDC_RADIODUALCYCLIC)->EnableWindow(!bEnable);
	GetDlgItem(IDC_RADIODUALSEGUEN)->EnableWindow(!bEnable);
	UpdateData(FALSE);
}

void DlgInitPumpIneria::SetEventStatus()
{
	switch(m_nEventType) {
	case 0:
		break;
	case 1:
		m_tab.ShowPage(1,FALSE);
		m_tab.SetCurSel(0);
		if(m_transModel==2 ||m_transModel==3)
		{
			m_dlgTransData.m_tab.ShowPage(1,FALSE);
		}
		if(m_transModel==3)
		{
			m_dlgTransData.m_tab.SetCurSel(0);
		}
		break;
	default:
		m_tab.ShowPage(1,TRUE);
		m_tab.SetCurSel(0);
		if(m_transModel==2 ||m_transModel==3)
		{
			m_dlgTransData.m_tab.ShowPage(1,TRUE);
			m_dlgTransData.m_tab.SetCurSel(1);
		}
		break;
	}
}

void DlgInitPumpIneria::OnRadioTime() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 0;
	SetEventStatus();
}

void DlgInitPumpIneria::OnRadioSingle() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 1;
	SetEventStatus();
}

void DlgInitPumpIneria::OnRadioDualSeguen() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 2;
	SetEventStatus();
}

void DlgInitPumpIneria::OnRadioDualCyclic() 
{
	// TODO: Add your control notification handler code here
	m_nEventType = 3;
	SetEventStatus();
}

void DlgInitPumpIneria::ChangeName()
{
	UINT nID1 = IDS_STRSTARTTRANS;
	UINT nID2 = IDS_STRTRIPTRANS;
	if(m_transModel==2 ||m_transModel==3)
	{
		m_tab.SetItemTitle(nID2,0);
		m_tab.SetItemTitle(nID1,1);
		
	}
	if(m_transModel==5||m_transModel==6)
	{
		m_tab.SetItemTitle(nID1,0);
		m_tab.SetItemTitle(nID2,1);
	}
}
