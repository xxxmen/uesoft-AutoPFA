// PagePumpModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PagePumpModel.h"
#include "Pump.h"
#include "OptionTypeNumWrapper.h"
#include "DlgPump.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PagePumpModel dialog


PagePumpModel::PagePumpModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PagePumpModel::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbOpenPress(&m_EditOpenPress)
	,m_cmbSuctionPress(&m_EditSuctionPress)
	,m_cmbVelocity(&m_EditVelocity)
	,m_cmbFlowRateUnit(&m_EditFlowRate)
{
	//{{AFX_DATA_INIT(PagePumpModel)
	m_bAntiReserse = FALSE;
	m_bCheckValve = FALSE;
	m_bSubmerge = FALSE;
	m_strFlowRateUnit = _T("");
	m_strOpenPressUnit = _T("");
	m_strSuctionPressUnit = _T("");
	m_strVelocityUnit = _T("");
	m_strFlowRate = _T("");
	m_strOpenPress = _T("");
	m_strSuctionPress = _T("");
	m_strVelocity = _T("");
	m_nType = -1;
	m_nSuctionPressType = -1;
	m_nOpenPressType = -1;
	//}}AFX_DATA_INIT
	m_nFlowType = -1;
}


void PagePumpModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PagePumpModel)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_EVELOCITY, m_EditVelocity);
	DDX_Control(pDX, IDC_ESUCTIONPRESS, m_EditSuctionPress);
	DDX_Control(pDX, IDC_EOPENPRESS, m_EditOpenPress);
	DDX_Control(pDX, IDC_EFLOWRATE, m_EditFlowRate);
	DDX_Control(pDX, IDC_CMBVELOCITYUNIT, m_cmbVelocity);
	DDX_Control(pDX, IDC_CMBSUCTIONPRESSUNIT, m_cmbSuctionPress);
	DDX_Control(pDX, IDC_CMBOPENPRESSUNIT, m_cmbOpenPress);
	DDX_Control(pDX, IDC_CMBFLOWRATEUNIT, m_cmbFlowRateUnit);
	DDX_Check(pDX, IDC_CHECKANTIREVERSE, m_bAntiReserse);
	DDX_Check(pDX, IDC_CHECKCHECKVALVE, m_bCheckValve);
	DDX_Check(pDX, IDC_CHECKSUBMERGE, m_bSubmerge);
	DDX_CBString(pDX, IDC_CMBFLOWRATEUNIT, m_strFlowRateUnit);
	DDX_CBString(pDX, IDC_CMBOPENPRESSUNIT, m_strOpenPressUnit);
	DDX_CBString(pDX, IDC_CMBSUCTIONPRESSUNIT, m_strSuctionPressUnit);
	DDX_CBString(pDX, IDC_CMBVELOCITYUNIT, m_strVelocityUnit);
	DDX_Text(pDX, IDC_EFLOWRATE, m_strFlowRate);
	DDX_Text(pDX, IDC_EOPENPRESS, m_strOpenPress);
	DDX_Text(pDX, IDC_ESUCTIONPRESS, m_strSuctionPress);
	DDX_Text(pDX, IDC_EVELOCITY, m_strVelocity);
	DDX_Radio(pDX, IDC_RADIOCURVE, m_nType);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nSuctionPressType);
	DDX_Radio(pDX, IDC_RADIOOPENHEAD, m_nOpenPressType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PagePumpModel, BaseDlg)
	//{{AFX_MSG_MAP(PagePumpModel)
	ON_BN_CLICKED(IDC_RADIOCURVE, OnRadioCurve)
	ON_BN_CLICKED(IDC_RADIOMASSFLOW, OnRadioMassFlow)
	ON_BN_CLICKED(IDC_RADIOVOLUMEFLOE, OnRadioVolumeFlow)
	ON_BN_CLICKED(IDC_CHECKCHECKVALVE, OnCheckCheckValve)
	ON_BN_CLICKED(IDC_CHECKSUBMERGE, OnCheckSubmerge)
	ON_CBN_SELCHANGE(IDC_CMBFLOWRATEUNIT, OnSelchangeFlowUnit)
	ON_BN_CLICKED(IDC_BCONFIG, OnConfig)
	ON_BN_CLICKED(IDC_RADIOOPENHEAD, OnRadioOpenHead)
	ON_BN_CLICKED(IDC_RADIOOPENPRESS, OnRadioOpenPress)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PagePumpModel message handlers

BOOL PagePumpModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Velocity,m_cmbVelocity,m_strVelocityUnit);
	m_tab.AddPage(IDS_STRCURVERCONFIG,&m_Page1,IDD_PAGECHART);
	m_tab.AddPage(IDS_STRCURVERNPRS,&m_Page2,IDD_PAGECHART);
	m_tab.AddPage(IDS_STRCURVERPOWER,&m_Page3,IDD_PAGECHART);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PagePumpModel::Init()
{
	m_nType = Pump::ms_PumpType.GetnValue();
	InitTypeNum(m_nFlowType,m_strFlowRate,m_strFlowRateUnit,Pump::ms_PumpFlow);

	OptionTypeNumWrapper wrapper(Pump::ms_SubmergePump);
	m_bSubmerge = wrapper.GetModel();
	wrapper.GetPress(m_nSuctionPressType,m_strSuctionPress,m_strSuctionPressUnit);

	m_bAntiReserse = abs(Pump::ms_antiReverse.GetnValue());
	m_bAntiReserse = !m_bAntiReserse;//-1：没有选择限制泵反转，0选择限制泵反转
	m_bCheckValve  = abs(Pump::ms_ExitCheck.GetnValue());
	InitNum(m_strVelocity,m_strVelocityUnit,Pump::ms_CloseVel);
	InitTypeNum(m_nOpenPressType,m_strOpenPress,m_strOpenPressUnit,Pump::ms_ReOpenPress);

	SetSubmergeStatus();
	SetTypeStatus();
	SetCheckStatus();
	InitSuctionPressUnit();
	InitOpenPressUnit();
	InitHQChart();

	UpdateData(FALSE);
}

BOOL PagePumpModel::UpData()
{
	UpdateData(TRUE);
	Pump::ms_PumpType.SetValue(m_nType);
	SetTypeNum(m_nFlowType,m_strFlowRate,m_strFlowRateUnit,Pump::ms_PumpFlow);

	OptionTypeNumWrapper wrapper(Pump::ms_SubmergePump);
	wrapper.SetModel(m_bSubmerge);
	wrapper.SetPress(m_nSuctionPressType,m_strSuctionPress,m_strSuctionPressUnit);

	Pump::ms_antiReverse.SetValue(-int(!m_bAntiReserse));
	Pump::ms_ExitCheck.SetValue(m_bCheckValve);
	SetNum(m_strVelocity,m_strVelocityUnit,Pump::ms_CloseVel);
	SetTypeNum(m_nOpenPressType,m_strOpenPress,m_strOpenPressUnit,Pump::ms_ReOpenPress);
	return TRUE;
}

void PagePumpModel::InitFlowUnit()
{
	InitFlowUnitCbo(m_UnitSys,m_nFlowType,m_cmbFlowRateUnit,m_strFlowRateUnit);
}

void PagePumpModel::InitOpenPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nOpenPressType,m_cmbOpenPress,m_strOpenPressUnit);
}

void PagePumpModel::InitSuctionPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nSuctionPressType,m_cmbSuctionPress,m_strSuctionPressUnit);
}

void PagePumpModel::OnRadioCurve() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	SetTypeStatus();
}

void PagePumpModel::OnRadioMassFlow() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	m_nFlowType = 1;
	SetTypeStatus();
}

void PagePumpModel::OnRadioVolumeFlow() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	m_nFlowType = 0;
	SetTypeStatus();
}

void PagePumpModel::SetTypeStatus()
{
	int nCmdTab = SW_HIDE;
	int nCmdFlow = SW_SHOW;
	if(m_nType ==0)
	{
		nCmdTab = SW_SHOW;
		nCmdFlow = SW_HIDE;
	}
	m_tab.ShowWindow(nCmdTab);
	GetDlgItem(IDC_BCONFIG)->ShowWindow(nCmdTab);
	GetDlgItem(IDC_STATICFLOW)->ShowWindow(nCmdFlow);
	m_EditFlowRate.ShowWindow(nCmdFlow);
	m_cmbFlowRateUnit.ShowWindow(nCmdFlow);
	InitFlowUnit();
	ChangeType();
}

void PagePumpModel::SetCheckStatus()
{
	m_EditVelocity.EnableWindow(m_bCheckValve);
	m_cmbVelocity.EnableWindow(m_bCheckValve);
	m_EditOpenPress.EnableWindow(m_bCheckValve);
	m_cmbOpenPress.EnableWindow(m_bCheckValve);
	GetDlgItem(IDC_RADIOOPENHEAD)->EnableWindow(m_bCheckValve);
	GetDlgItem(IDC_RADIOOPENPRESS)->EnableWindow(m_bCheckValve);
}

void PagePumpModel::SetSubmergeStatus()
{
	m_EditSuctionPress.EnableWindow(m_bSubmerge);
	m_cmbSuctionPress.EnableWindow(m_bSubmerge);
	GetDlgItem(IDC_RADIOHEAD)->EnableWindow(m_bSubmerge);
	GetDlgItem(IDC_RADIOPRESS)->EnableWindow(m_bSubmerge);
}

void PagePumpModel::OnCheckCheckValve() 
{
	// TODO: Add your control notification handler code here
	m_bCheckValve = !m_bCheckValve;
	SetCheckStatus();
}

void PagePumpModel::OnCheckSubmerge() 
{
	// TODO: Add your control notification handler code here
	m_bSubmerge = !m_bSubmerge;
	SetSubmergeStatus();
}

int PagePumpModel::PumpType()
{
	return m_nType;
}

void PagePumpModel::ChangeType()
{
	DlgPump *pDlgPump = dynamic_cast<DlgPump*>(GetParent()->GetParent());
	pDlgPump->ChangeType(m_nType,FlowUnit());
}

CString PagePumpModel::FlowUnit()
{
	return GetCmbText(m_cmbFlowRateUnit);
}

void PagePumpModel::OnSelchangeFlowUnit() 
{
	// TODO: Add your control notification handler code here
    ChangeType();
}


void PagePumpModel::OnConfig() 
{
	// TODO: Add your control notification handler code here
	DlgPumpConfig dlgConfig(m_UnitSys);
	if(IDOK == dlgConfig.DoModal())
	{
		InitHQChart();
	}
	
}

void PagePumpModel::InitHQChart()
{
	CString strTitle;
	strTitle = Pump::ms_Configuration.PressTitle();
	InitChart(m_Page1,strTitle,Pump::ms_Configuration.m_Curve1,1);
	strTitle = Pump::ms_Configuration.PressTitle();
	InitChart(m_Page2,strTitle,Pump::ms_Configuration.m_Curve2,2);
	strTitle = Pump::ms_Configuration.PowerTitle();
	InitChart(m_Page3,strTitle,Pump::ms_Configuration.m_Curve3,3);

}

void PagePumpModel::InitChart(PageChart &Page,CString strYTitle,ArrayFlyWeight<7> &ref,int nIndex)
{
	double dMax;
	int nType;
	int nNum;
	CString strXTitle;

	nType = ref.GetnValue();
	nNum = ref.GetnValue(1);
	strXTitle = Pump::ms_Configuration.FlowTitle();

	Page.GetChart().Init();
	//Page.GetChart().SetXAXisTitle(strXTitle);
	//Page.GetChart().SetYAXisTitle(strYTitle);
	if( nType==1)
	{
		double dParme[5];
		dMax = Pump::ms_Configuration.m_MaxFlow.GetfValue();
		Configuration::GetPrame(ref,dParme);
		Page.GetChart().SetData(dParme,nNum,0,dMax);
	}
	else if(nType == 2)
	{
		double dX[100] = {0};
		double dY[100] = {0};
		
		int dat = Pump::ms_Configuration.m_RawData.Data().GetCount();
		Pump::ms_Configuration.m_RawData.m_Data.GetData().ToDuoble(dX,0);
		Pump::ms_Configuration.m_RawData.m_Data.GetData().ToDuoble(dY,nIndex);
		Page.GetChart().SetData(dX,dY,dat);
	}
}

void PagePumpModel::OnRadioOpenHead() 
{
	// TODO: Add your control notification handler code here
	m_nOpenPressType = 0;
	InitOpenPressUnit();
}

void PagePumpModel::OnRadioOpenPress() 
{
	// TODO: Add your control notification handler code here
	m_nOpenPressType = 1;
	InitOpenPressUnit();
}

void PagePumpModel::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nSuctionPressType = 1;
	InitSuctionPressUnit();
}

void PagePumpModel::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nSuctionPressType = 0;
	InitSuctionPressUnit();
}
