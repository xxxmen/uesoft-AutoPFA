// dlgpumpconfig.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgpumpconfig.h"
#include "Pump.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgPumpConfig dialog


DlgPumpConfig::DlgPumpConfig(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: CDialog(DlgPumpConfig::IDD, pParent)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(DlgPumpConfig)
	m_strFlowUnit = _T("");
	m_strPowerUnit = _T("");
	m_strPressUnit = _T("");
	m_nPower = -1;
	m_nPress = -1;
	m_nFlow = -1;
	//}}AFX_DATA_INIT
}


void DlgPumpConfig::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgPumpConfig)
	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_Control(pDX, IDC_CMBPRESS, m_cmbPressUnit);
	DDX_Control(pDX, IDC_CMBPOWER, m_cbmPowerUnit);
	DDX_Control(pDX, IDC_CMBFLOW, m_cmbFlowUnit);
	DDX_CBString(pDX, IDC_CMBFLOW, m_strFlowUnit);
	DDX_CBString(pDX, IDC_CMBPOWER, m_strPowerUnit);
	DDX_CBString(pDX, IDC_CMBPRESS, m_strPressUnit);
	DDX_Radio(pDX, IDC_RADIOEFFIC, m_nPower);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPress);
	DDX_Radio(pDX, IDC_RADIOVOLFLOW, m_nFlow);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgPumpConfig, CDialog)
	//{{AFX_MSG_MAP(DlgPumpConfig)
	ON_BN_CLICKED(IDC_RADIOEFFIC, OnRadioEffic)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOMASSFLOW, OnRadioMassFlow)
	ON_BN_CLICKED(IDC_RADIOPOWER, OnRadioPower)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_RADIOVOLFLOW, OnRadioVolFlow)
	ON_CBN_SELCHANGE(IDC_CMBFLOW, OnSelchangeFlow)
	ON_CBN_SELCHANGE(IDC_CMBPOWER, OnSelchangePower)
	ON_CBN_SELCHANGE(IDC_CMBPRESS, OnSelchangePress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgPumpConfig message handlers

BOOL DlgPumpConfig::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRPUMPDATA,&m_page1,IDD_PAGEPUMPDATA);
	m_tab.AddPage(IDS_STRCONFIGDATA,&m_page2,IDD_PAGECONFIG);
	m_tab.Show();

	Init();
	InitPage1();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgPumpConfig::Init()
{
	m_nFlow = Pump::ms_Configuration.m_FlowType.GetnValue();
	m_strFlowUnit = Pump::ms_Configuration.m_FlowUnit.GetValue();
	m_nPress = Pump::ms_Configuration.m_PressType.GetnValue();
	m_strPressUnit = Pump::ms_Configuration.m_PressUnit.GetValue();
	m_nPower = Pump::ms_Configuration.m_PowerType.GetnValue();
	m_strPowerUnit = Pump::ms_Configuration.m_PowerUnit.GetValue();
	InitFlowUnit();
	InitPressUnit();
	InitPowerUnit();

}

void DlgPumpConfig::OnRadioEffic() 
{
	// TODO: Add your control notification handler code here
	m_nPower = 0;
	InitPowerUnit();
	m_page1.m_RawData.SetHeader(PowerName(m_nPower),PowerUnit(),4);
	m_page2.SetBEPUnit(PowerUnit());
}

void DlgPumpConfig::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPress = 0;
	InitPressUnit();
	m_page1.m_RawData.SetHeader(PressName(m_nPress),PressUnit(),2);
	m_page1.m_RawData.SetUnit(PressUnit(),3);
}

void DlgPumpConfig::OnRadioMassFlow() 
{
	// TODO: Add your control notification handler code here
	m_nFlow = 1;
	InitFlowUnit();
	m_page1.m_RawData.SetHeader(FlowName(m_nFlow),FlowUnit(),1);
	m_page2.SetFlowUnit(m_nFlow,FlowUnit());
}

void DlgPumpConfig::OnRadioPower() 
{
	// TODO: Add your control notification handler code here
	m_nPower = 1;
	InitPowerUnit();
	m_page1.m_RawData.SetHeader(PowerName(m_nPower),PowerUnit(),4);
	m_page2.SetBEPUnit(PowerUnit());
}

void DlgPumpConfig::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPress = 1;
	InitPressUnit();
	m_page1.m_RawData.SetHeader(PressName(m_nPress),PressUnit(),2);
	m_page1.m_RawData.SetUnit(PressUnit(),3);
}

void DlgPumpConfig::OnRadioVolFlow() 
{
	// TODO: Add your control notification handler code here
	m_nFlow = 0;
	InitFlowUnit();
	m_page1.m_RawData.SetHeader(FlowName(m_nFlow),FlowUnit(),1);
	m_page2.SetFlowUnit(m_nFlow,FlowUnit());
}

void DlgPumpConfig::OnSelchangeFlow() 
{
	// TODO: Add your control notification handler code here
	m_page1.m_RawData.SetUnit(FlowUnit(),1);
	m_page2.SetFlowUnit(m_nFlow,FlowUnit());
}

void DlgPumpConfig::OnSelchangePower() 
{
	// TODO: Add your control notification handler code here
	m_page1.m_RawData.SetUnit(PowerUnit(),4);
	m_page2.SetBEPUnit(PowerUnit());
}

void DlgPumpConfig::OnSelchangePress() 
{
	// TODO: Add your control notification handler code here
	m_page1.m_RawData.SetUnit(PressUnit(),2);
	m_page1.m_RawData.SetUnit(PressUnit(),3);
}

void DlgPumpConfig::InitFlowUnit()
{
	InitFlowUnitCbo(m_UnitSys,m_nFlow,m_cmbFlowUnit,m_strFlowUnit);
}

void DlgPumpConfig::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPress,m_cmbPressUnit,m_strPressUnit);
}

void DlgPumpConfig::InitPowerUnit()
{
	InitPowerUnitCbo(m_UnitSys,m_nPower,m_cbmPowerUnit,m_strPowerUnit);
}

CString DlgPumpConfig::FlowUnit()
{
	return GetCmbText(m_cmbFlowUnit);
}

CString DlgPumpConfig::PressUnit()
{
	return GetCmbText(m_cmbPressUnit);
}

CString DlgPumpConfig::PowerUnit()
{
	return GetCmbText(m_cbmPowerUnit);
}


void DlgPumpConfig::InitPage1()
{
	m_page1.m_RawData.InsertColumn(_T("  "),_T(""));
	m_page1.m_RawData.InsertColumn(FlowName(m_nFlow),FlowUnit());
	m_page1.m_RawData.InsertColumn(PressName(m_nPress),PressUnit());
	m_page1.m_RawData.InsertColumn(_T("NPSHR"),PressUnit());
	m_page1.m_RawData.InsertColumn(PowerName(m_nPower),PowerUnit());
	m_page1.m_RawData.TableStatus();
	m_page1.m_RawData.SetDataNum(100);
	m_page1.Init(Pump::ms_Configuration);
	m_page2.Init(Pump::ms_Configuration);
	m_page2.SetBEPUnit(PowerUnit());
	m_page2.SetFlowUnit(m_nFlow,FlowUnit());
}

void DlgPumpConfig::OnOK() 
{
	// TODO: Add extra validation here
	UpData();
	CDialog::OnOK();
}

void DlgPumpConfig::UpData()
{
	UpdateData(TRUE);
	Pump::ms_Configuration.m_FlowType.SetValue(m_nFlow);
	Pump::ms_Configuration.m_FlowUnit.SetValue(m_strFlowUnit);
	Pump::ms_Configuration.m_PressType.SetValue(m_nPress);
	Pump::ms_Configuration.m_PressUnit.SetValue(m_strPressUnit);
	Pump::ms_Configuration.m_PowerType.SetValue(m_nPower);
	Pump::ms_Configuration.m_PowerUnit.SetValue(m_strPowerUnit);
	StrArray<4> UnitArray;
	UnitArray.Data(m_strFlowUnit,0);
	UnitArray.Data(m_strPressUnit,1);
	UnitArray.Data(m_strPressUnit,2);
	UnitArray.Data(m_strPowerUnit,3);
	Pump::ms_Configuration.m_RawData.m_Unit.SetData(UnitArray);
	m_page1.UpData();
	m_page2.UpData(Pump::ms_Configuration);
}

