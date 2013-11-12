// pagetrantriger.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagetrantriger.h"
#include "Jun.h"
#include "ComponentManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTranTriger dialog


PageTranTriger::PageTranTriger(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageTranTriger::IDD, pParent)
	,m_manager(manager)
	,m_UnitSys(UnitSys)
	,m_cmbValue(&m_EditValue)
{
	//{{AFX_DATA_INIT(PageTranTriger)
	m_strValue = _T("");
	m_strValueUnit = _T("");
	//}}AFX_DATA_INIT
	m_nPort1 = 1;
	m_nPort2 = 1;
	m_nCondition = 0;
	m_nEventType = 1;
	m_nComponentID1 = -1;
	m_nComponentID2 = -1;
}


void PageTranTriger::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTranTriger)
	DDX_Control(pDX, IDC_CMBLOCATION2, m_cmbLocation2);
	DDX_Control(pDX, IDC_EDITVALUE, m_EditValue);
	DDX_Control(pDX, IDC_CMBLOCATION1, m_cmbLocation1);
	DDX_Control(pDX, IDC_CMBEVENTTYPE, m_cmbEventType);
	DDX_Control(pDX, IDC_CMBCONDITION, m_cmbCondition);
	DDX_Control(pDX, IDC_CMBCOMPONENT2, m_cmbComponent2);
	DDX_Control(pDX, IDC_CMBCOMPONENT1, m_cmbComponent1);
	DDX_Control(pDX, IDC_CMBVALUE, m_cmbValue);
	DDX_Text(pDX, IDC_EDITVALUE, m_strValue);
	DDX_CBString(pDX, IDC_CMBVALUE, m_strValueUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTranTriger, BaseDlg)
	//{{AFX_MSG_MAP(PageTranTriger)
	ON_CBN_SELCHANGE(IDC_CMBEVENTTYPE, OnSelchangeEvent)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTranTriger message handlers

BOOL PageTranTriger::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageTranTriger::Init(const ArrayFlyWeight<8> &ref)
{
	m_nEventType = ref.GetnValue();
	m_nCondition = ref.GetnValue(1);
	m_strValue = ref.GetValue(2);
	m_strValueUnit = ref.GetValue(3);
	m_nPort1 = ref.GetnValue(4);
	m_nComponentID1 = ref.GetnValue(5);
	m_nPort2 = ref.GetnValue(6);
	m_nComponentID2 = ref.GetnValue(7);

	InitDataCmb(Jun::ms_EventType,24,m_cmbEventType,m_nEventType);
	InitDataCmb(Jun::ms_PipePort,2,m_cmbLocation1,m_nPort1);
	InitDataCmb(Jun::ms_PipePort,2,m_cmbLocation2,m_nPort2);
	SetEventType();
	SetSelKey(m_cmbComponent1,m_nComponentID1);
	SetSelKey(m_cmbComponent2,m_nComponentID2);
	UpdateData(FALSE);
}

BOOL PageTranTriger::UpData(ArrayFlyWeight<8> &ref)
{
	UpdateData(TRUE);
	GetCurKey(m_cmbComponent1,m_nComponentID1);
	GetCurKey(m_cmbComponent2,m_nComponentID2);
	GetCurKey(m_cmbLocation1,m_nPort1);
	GetCurKey(m_cmbLocation2,m_nPort2);
	GetCurKey(m_cmbCondition,m_nCondition);

	ref.SetValue(m_nEventType);
	ref.SetValue(m_nCondition,1);
	ref.SetValue(m_strValue,2);
	ref.SetValue(m_strValueUnit,3);
	ref.SetValue(m_nPort1,4);
	ref.SetValue(m_nComponentID1,5);
	ref.SetValue(m_nPort2,6);
	ref.SetValue(m_nComponentID2,7);
	return TRUE;
}

void PageTranTriger::OnSelchangeEvent() 
{
	// TODO: Add your control notification handler code here
	GetCurKey(m_cmbEventType,m_nEventType);
	SetEventType();
}

void PageTranTriger::SetEventType()
{
	switch(m_nEventType) {
	case 8:
	case 9:
	case 10:
		ValveEvent();
		break;
	case 1:
	case 3:
	case 4:
	case 5:
	case 6:
	case 22:
		SinglePipeEvent();
	    break;
	case 2:
	case 7:
	case 11:
	case 12:
	case 13:
	case 14:
	case 19:
	case 20:
	case 21:
		JunEvent();
	    break;
	case 15:
	case 16:
	case 17:
	case 18:
		DualPipeEvent();
		break;
	default:
		TimeEvent();
		break;
	}
	SetValueUnit();
}

void PageTranTriger::ValveEvent()
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDITVALUE)->ShowWindow(SW_HIDE);
	m_cmbValue.ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC2)->SetWindowText(_T("连接元件"));
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	m_cmbComponent1.ShowWindow(SW_SHOW);
	m_cmbLocation1.ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	m_cmbComponent2.ShowWindow(SW_HIDE);
	m_cmbLocation2.ShowWindow(SW_HIDE);
	InitDataCmb(Jun::ms_ValveStatus,4,m_cmbCondition,m_nCondition);
	switch(m_nEventType) {
	case 8:
		InitJunCmb(m_cmbComponent1,m_manager,CheckValve::m_nTypeID);
		break;
	case 9:
		InitJunCmb(m_cmbComponent1,m_manager,ReliefValve::m_nTypeID);
		break;
	case 10:
		InitJunCmb(m_cmbComponent1,m_manager,ControlValve::m_nTypeID);
		break;
	default:
		ASSERT(FALSE);
	}
}

void PageTranTriger::SinglePipeEvent()
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDITVALUE)->ShowWindow(SW_SHOW);
	m_cmbValue.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC2)->SetWindowText(_T("管道"));
	m_cmbComponent1.ShowWindow(SW_SHOW);
	m_cmbLocation1.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	m_cmbComponent2.ShowWindow(SW_HIDE);
	m_cmbLocation2.ShowWindow(SW_HIDE);
	InitDataCmb(Jun::ms_Condition,5,m_cmbCondition,m_nCondition);
	InitPipeCmb(m_cmbComponent1,m_manager);
}

void PageTranTriger::JunEvent()
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDITVALUE)->ShowWindow(SW_SHOW);
	m_cmbValue.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC2)->SetWindowText(_T("连接元件"));
	m_cmbComponent1.ShowWindow(SW_SHOW);
	m_cmbLocation1.ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	m_cmbComponent2.ShowWindow(SW_HIDE);
	m_cmbLocation2.ShowWindow(SW_HIDE);
	InitDataCmb(Jun::ms_Condition,5,m_cmbCondition,m_nCondition);
	switch(m_nEventType) {
	case 7:
		InitJunCmb(m_cmbComponent1,m_manager,Pump::m_nTypeID);
		break;
	case 99:
		InitJunCmb(m_cmbComponent1,m_manager,SprayDischarge::m_nTypeID);
		break;
	case 20:
    case 21:
		InitJunCmb(m_cmbComponent1,m_manager,Surge::m_nTypeID);
		break;
	default:
		InitJunCmb(m_cmbComponent1,m_manager);
	}
}

void PageTranTriger::DualPipeEvent()
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDITVALUE)->ShowWindow(SW_SHOW);
	m_cmbValue.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC2)->SetWindowText(_T("第一根管道"));
	m_cmbComponent1.ShowWindow(SW_SHOW);
	m_cmbLocation1.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_SHOW);
	m_cmbComponent2.ShowWindow(SW_SHOW);
	m_cmbLocation2.ShowWindow(SW_SHOW);
	InitDataCmb(Jun::ms_Condition,5,m_cmbCondition,m_nCondition);
	InitPipeCmb(m_cmbComponent1,m_manager);
	InitPipeCmb(m_cmbComponent2,m_manager);
}

void PageTranTriger::TimeEvent()
{
	GetDlgItem(IDC_STATIC1)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDITVALUE)->ShowWindow(SW_SHOW);
	m_cmbValue.ShowWindow(SW_SHOW);
	GetDlgItem(IDC_STATIC2)->ShowWindow(SW_HIDE);
	m_cmbComponent1.ShowWindow(SW_HIDE);
	m_cmbLocation1.ShowWindow(SW_HIDE);
	GetDlgItem(IDC_STATIC3)->ShowWindow(SW_HIDE);
	m_cmbComponent2.ShowWindow(SW_HIDE);
	m_cmbLocation2.ShowWindow(SW_HIDE);
	InitDataCmb(Jun::ms_Condition,5,m_cmbCondition,m_nCondition);
}

void PageTranTriger::SetValueUnit()
{
	UnitTypeID id = Length;
	switch(m_nEventType) {
	case 6:
	case 14:
	case 18:
	case 5:
	case 13:
	case 17:
	case 20:
	case 21:
		//Head
		id = Length;
		break;
	case 16:
	case 12:
	case 2:
	case 1:
	case 11:
	case 15:
		//Pressure
		id = Pressure;
	    break;
	case 3:
		//MassFlow
		id = MassFlow;
		break;
	case 7:
		//PercentFractional
		id = PercentFractional;
		break;
	case 19:
	case 4:
		//VolumetricFlow
		id = VolumetricFlow;
		break;
	case 0:
	case 23:
		//Time
		id = Time;
		break;
	case 22:
		//Velocity
		id = Velocity;
		break;
	default:
		break;
	}
	InitUnitCbo(m_UnitSys,id,m_cmbValue,m_strValueUnit);
}


