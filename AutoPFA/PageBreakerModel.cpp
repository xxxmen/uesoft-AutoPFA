// PageBreakerModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagebreakermodel.h"
#include "VacuumBreaker.h"
#include "GasPropertyWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageBreakerModel dialog


PageBreakerModel::PageBreakerModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageBreakerModel::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbCrackPress(&m_EditCrackPress)
	,m_cmbInFlow(&m_EditInFlow)
	,m_cmbOutFlow(&m_EditOutFlow)
	,m_cmbMediateOut(&m_EditMediateOut)
	,m_cmbMediate(&m_EditMediateVlaue)
	,m_cmbLiquidTemp(&m_EditLiquidTemp)
	,m_cmbGasMass(&m_EditGasMass)
	,m_cmbGasPress(&m_EditGasPress)
	,m_cmbGasTemp(&m_EditGasTemp)
{
	//{{AFX_DATA_INIT(PageBreakerModel)
	m_strCrackPressUnit = _T("");
	m_strGasMassUnit = _T("");
	m_strGasPressUnit = _T("");
	m_strGasTempUnit = _T("");
	m_strInFlowUnit = _T("");
	m_strLiquidTempUnit = _T("");
	m_strMediateOutUnit = _T("");
	m_strMediteUnit = _T("");
	m_strOutFlowUnit = _T("");
	m_strCpCv = _T("");
	m_strCrackPress = _T("");
	m_strGasMass = _T("");
	m_strGasPress = _T("");
	m_strGasTemp = _T("");
	m_strInFlow = _T("");
	m_strLiquidTemp = _T("");
	m_strMediateOut = _T("");
	m_strMediateValue = _T("");
	m_strOurFlow = _T("");
	m_strWeight = _T("");
	m_nAirType = -1;
	m_nMediateType = -1;
	m_nType = -1;
	m_nConnectPipe = -1;
	m_nLiquidTempType = -1;
	m_nCrackPressType = -1;
	//}}AFX_DATA_INIT
}


void PageBreakerModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageBreakerModel)
	DDX_Control(pDX, IDC_EWEIGHT, m_EditWeight);
	DDX_Control(pDX, IDC_EOUTFLOW, m_EditOutFlow);
	DDX_Control(pDX, IDC_EMEDIATEVALUE, m_EditMediateVlaue);
	DDX_Control(pDX, IDC_EMEDIATEOUT, m_EditMediateOut);
	DDX_Control(pDX, IDC_ELIQUIDTEMP, m_EditLiquidTemp);
	DDX_Control(pDX, IDC_EINFLOW, m_EditInFlow);
	DDX_Control(pDX, IDC_EGASTEMPERATURE, m_EditGasTemp);
	DDX_Control(pDX, IDC_EGASPRESS, m_EditGasPress);
	DDX_Control(pDX, IDC_EGASMASS, m_EditGasMass);
	DDX_Control(pDX, IDC_ECRACKPRESS, m_EditCrackPress);
	DDX_Control(pDX, IDC_ECPCV, m_EditCpCv);
	DDX_Control(pDX, IDC_CMBOUTFLOWUNIT, m_cmbOutFlow);
	DDX_Control(pDX, IDC_CMBMEDIATEUNIT, m_cmbMediate);
	DDX_Control(pDX, IDC_CMBMEDIATEOUTUNIT, m_cmbMediateOut);
	DDX_Control(pDX, IDC_CMBLIQUIDTEMPUNIT, m_cmbLiquidTemp);
	DDX_Control(pDX, IDC_CMBINFLOWUNIT, m_cmbInFlow);
	DDX_Control(pDX, IDC_CMBGASTEMPERATUREUNIT, m_cmbGasTemp);
	DDX_Control(pDX, IDC_CMBGASPRESSUNIT, m_cmbGasPress);
	DDX_Control(pDX, IDC_CMBGASMASSUNIT, m_cmbGasMass);
	DDX_Control(pDX, IDC_CMBCRACKPRESSUNIT, m_cmbCrackPress);
	DDX_CBString(pDX, IDC_CMBCRACKPRESSUNIT, m_strCrackPressUnit);
	DDX_CBString(pDX, IDC_CMBGASMASSUNIT, m_strGasMassUnit);
	DDX_CBString(pDX, IDC_CMBGASPRESSUNIT, m_strGasPressUnit);
	DDX_CBString(pDX, IDC_CMBGASTEMPERATUREUNIT, m_strGasTempUnit);
	DDX_CBString(pDX, IDC_CMBINFLOWUNIT, m_strInFlowUnit);
	DDX_CBString(pDX, IDC_CMBLIQUIDTEMPUNIT, m_strLiquidTempUnit);
	DDX_CBString(pDX, IDC_CMBMEDIATEOUTUNIT, m_strMediateOutUnit);
	DDX_CBString(pDX, IDC_CMBMEDIATEUNIT, m_strMediteUnit);
	DDX_CBString(pDX, IDC_CMBOUTFLOWUNIT, m_strOutFlowUnit);
	DDX_Text(pDX, IDC_ECPCV, m_strCpCv);
	DDX_Text(pDX, IDC_ECRACKPRESS, m_strCrackPress);
	DDX_Text(pDX, IDC_EGASMASS, m_strGasMass);
	DDX_Text(pDX, IDC_EGASPRESS, m_strGasPress);
	DDX_Text(pDX, IDC_EGASTEMPERATURE, m_strGasTemp);
	DDX_Text(pDX, IDC_EINFLOW, m_strInFlow);
	DDX_Text(pDX, IDC_ELIQUIDTEMP, m_strLiquidTemp);
	DDX_Text(pDX, IDC_EMEDIATEOUT, m_strMediateOut);
	DDX_Text(pDX, IDC_EMEDIATEVALUE, m_strMediateValue);
	DDX_Text(pDX, IDC_EOUTFLOW, m_strOurFlow);
	DDX_Text(pDX, IDC_EWEIGHT, m_strWeight);
	DDX_Radio(pDX, IDC_RADIOAIR, m_nAirType);
	DDX_Radio(pDX, IDC_RADIODEFFPRESS, m_nMediateType);
	DDX_Radio(pDX, IDC_RADIODUAL, m_nType);
	DDX_Radio(pDX, IDC_RADIOTWO, m_nConnectPipe);
	DDX_Radio(pDX, IDC_RADIOSYSTEM, m_nLiquidTempType);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nCrackPressType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageBreakerModel, BaseDlg)
	//{{AFX_MSG_MAP(PageBreakerModel)
	ON_BN_CLICKED(IDC_RADIOSYSTEM, OnRadioSystem)
	ON_BN_CLICKED(IDC_RADIOCUSTOM, OnRadioCustom)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_RADIOOTHER, OnRadioOther)
	ON_BN_CLICKED(IDC_RADIOAIR, OnRadioAir)
	ON_BN_CLICKED(IDC_RADIODEFFPRESS, OnRadioMediatePress)
	ON_BN_CLICKED(IDC_RADIOVOLUMEFLOW, OnRadioVolumeFlow)
	ON_BN_CLICKED(IDC_RADIORELEASE, OnRadioRelease)
	ON_BN_CLICKED(IDC_RADIODUAL, OnRadioDual)
	ON_BN_CLICKED(IDC_RADIOBREAKER, OnRadioBreaker)
	ON_BN_CLICKED(IDC_RADIO3STAGE, OnRadio3Stage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageBreakerModel message handlers

BOOL PageBreakerModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Area,m_cmbInFlow,m_strInFlowUnit);
	InitUnitCbo(m_UnitSys,Area,m_cmbOutFlow,m_strOutFlowUnit);
	InitUnitCbo(m_UnitSys,Area,m_cmbMediateOut,m_strMediateOutUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cmbGasPress,m_strGasPressUnit);
	InitUnitCbo(m_UnitSys,Temperature,m_cmbGasTemp,m_strGasTempUnit);
	InitUnitCbo(m_UnitSys,Mass,m_cmbGasMass,m_strGasMassUnit);
	InitUnitCbo(m_UnitSys,Temperature,m_cmbLiquidTemp,m_strLiquidTempUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageBreakerModel::Init()
{
	InitTypeNum(m_nCrackPressType,m_strCrackPress,m_strCrackPressUnit,VacuumBreaker::ms_CrackPress);
	InitNum(m_strInFlow,m_strInFlowUnit,VacuumBreaker::ms_OrificeInCdA);
	InitNum(m_strOurFlow,m_strOutFlowUnit,VacuumBreaker::ms_OrificeOutCdA);
	InitNum(m_strMediateOut,m_strMediateOutUnit,VacuumBreaker::ms_InterMediateCdA);
	InitTypeNum(m_nLiquidTempType,m_strLiquidTemp,m_strLiquidTempUnit,VacuumBreaker::ms_LiquidTemp);

	GasPropertyWrapper wrapper(VacuumBreaker::ms_GasProperty);
	m_nAirType = wrapper.GetType();
	m_strCpCv = wrapper.GetCpCv();
	m_strWeight = wrapper.GetWeight();
	wrapper.GetPress(m_strGasPress,m_strGasPressUnit);
	wrapper.GetTemp(m_strGasTemp,m_strGasTempUnit);
	wrapper.GetMass(m_strGasMass,m_strGasMassUnit);

	m_nConnectPipe = VacuumBreaker::ms_ConnectPipe.GetnValue();
	m_nType = VacuumBreaker::ms_ValveType.GetnValue();
	InitTypeNum(m_nMediateType,m_strMediateValue,m_strMediteUnit,VacuumBreaker::ms_MediateActivation);

	SetTypeStatus();
	InitMediateUnit();
	SetAirStatus();
	InitCrackPressUnit();
	SetLiquidTempStatus();
	UpdateData(FALSE);
}

BOOL PageBreakerModel::UpData()
{
	UpdateData(TRUE);
	SetTypeNum(m_nCrackPressType,m_strCrackPress,m_strCrackPressUnit,VacuumBreaker::ms_CrackPress);
	SetNum(m_strInFlow,m_strInFlowUnit,VacuumBreaker::ms_OrificeInCdA);
	SetNum(m_strOurFlow,m_strOutFlowUnit,VacuumBreaker::ms_OrificeOutCdA);
	SetNum(m_strMediateOut,m_strMediateOutUnit,VacuumBreaker::ms_InterMediateCdA);
	SetTypeNum(m_nLiquidTempType,m_strLiquidTemp,m_strLiquidTempUnit,VacuumBreaker::ms_LiquidTemp);

	GasPropertyWrapper wrapper(VacuumBreaker::ms_GasProperty);
	wrapper.SetType(m_nAirType);
	wrapper.SetCpCv(m_strCpCv);
	wrapper.SetWeight(m_strWeight);
	wrapper.SetPress(m_strGasPress,m_strGasPressUnit);
	wrapper.SetTemp(m_strGasTemp,m_strGasTempUnit);
	wrapper.SetMass(m_strGasMass,m_strGasMassUnit);
	
	VacuumBreaker::ms_ConnectPipe.SetValue(m_nConnectPipe);
	VacuumBreaker::ms_ValveType.SetValue(m_nType);
	SetTypeNum(m_nMediateType,m_strMediateValue,m_strMediteUnit,VacuumBreaker::ms_MediateActivation);
	return TRUE;
}

void PageBreakerModel::SetLiquidTempStatus()
{
	BOOL bEnable = TRUE;
	if(m_nLiquidTempType == 0)
	{
		bEnable = FALSE;
	}
	m_cmbLiquidTemp.EnableWindow(bEnable);
	m_EditLiquidTemp.EnableWindow(bEnable);
}

void PageBreakerModel::OnRadioSystem() 
{
	// TODO: Add your control notification handler code here
	m_nLiquidTempType = 0;
	SetLiquidTempStatus();
}

void PageBreakerModel::OnRadioCustom() 
{
	// TODO: Add your control notification handler code here
	m_nLiquidTempType = 1;
	SetLiquidTempStatus();
}

void PageBreakerModel::InitCrackPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nCrackPressType,m_cmbCrackPress,m_strCrackPressUnit);
}

void PageBreakerModel::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nCrackPressType = 0;
	InitCrackPressUnit();
}

void PageBreakerModel::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nCrackPressType = 1;
	InitCrackPressUnit();
}

void PageBreakerModel::SetAirStatus()
{
	BOOL bEnable = FALSE;
	if(m_nAirType == 0)
	{
		bEnable = TRUE;
		m_strWeight = _T("28.97");
		m_strCpCv   = _T("1.4");
		m_EditCpCv.SetWindowText(m_strCpCv);
	    m_EditWeight.SetWindowText(m_strWeight);

	}
	m_EditCpCv.SetReadOnly(bEnable);
	m_EditWeight.SetReadOnly(bEnable);
}

void PageBreakerModel::OnRadioOther() 
{
	// TODO: Add your control notification handler code here
	m_nAirType = 1;
	SetAirStatus();
}

void PageBreakerModel::OnRadioAir() 
{
	// TODO: Add your control notification handler code here
	m_nAirType = 0;
	SetAirStatus();
}

void PageBreakerModel::InitMediateUnit()
{
	if(m_nMediateType ==0)
	{
		InitUnitCbo(m_UnitSys,Pressure,m_cmbMediate,m_strMediteUnit);
	}
	else
	{
		InitUnitCbo(m_UnitSys,VolumetricFlow,m_cmbMediate,m_strMediteUnit);
	}
}

void PageBreakerModel::OnRadioMediatePress() 
{
	// TODO: Add your control notification handler code here
	m_nMediateType = 0;
	InitMediateUnit();
}

void PageBreakerModel::OnRadioVolumeFlow() 
{
	// TODO: Add your control notification handler code here
	m_nMediateType = 1;
	InitMediateUnit();
}

void PageBreakerModel::SetTypeStatus()
{
	switch(m_nType) 
	{
	case 0 :
		m_EditInFlow.EnableWindow(TRUE);
		m_EditOutFlow.EnableWindow(TRUE);
		m_EditMediateOut.EnableWindow(FALSE);
		m_cmbInFlow.EnableWindow(TRUE);
		m_cmbOutFlow.EnableWindow(TRUE);
		m_cmbMediateOut.EnableWindow(FALSE);
		m_EditMediateVlaue.EnableWindow(FALSE);
		m_cmbMediate.EnableWindow(FALSE);
		GetDlgItem(IDC_RADIODEFFPRESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOVOLUMEFLOW)->EnableWindow(FALSE);
		break;
	case 1 :
		m_EditInFlow.EnableWindow(TRUE);
		m_EditOutFlow.EnableWindow(FALSE);
		m_EditMediateOut.EnableWindow(FALSE);
		m_cmbInFlow.EnableWindow(TRUE);
		m_cmbOutFlow.EnableWindow(FALSE);
		m_cmbMediateOut.EnableWindow(FALSE);
		m_EditMediateVlaue.EnableWindow(FALSE);
		m_cmbMediate.EnableWindow(FALSE);
		GetDlgItem(IDC_RADIODEFFPRESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOVOLUMEFLOW)->EnableWindow(FALSE);
		break;
	case 2 :
		m_EditInFlow.EnableWindow(FALSE);
		m_EditOutFlow.EnableWindow(TRUE);
		m_EditMediateOut.EnableWindow(FALSE);
		m_cmbInFlow.EnableWindow(FALSE);
		m_cmbOutFlow.EnableWindow(TRUE);
		m_cmbMediateOut.EnableWindow(FALSE);
		m_EditMediateVlaue.EnableWindow(FALSE);
		m_cmbMediate.EnableWindow(FALSE);
		GetDlgItem(IDC_RADIODEFFPRESS)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOVOLUMEFLOW)->EnableWindow(FALSE);
		break;
	case 3 :
		m_EditInFlow.EnableWindow(TRUE);
		m_EditOutFlow.EnableWindow(TRUE);
		m_EditMediateOut.EnableWindow(TRUE);
		m_cmbInFlow.EnableWindow(TRUE);
		m_cmbOutFlow.EnableWindow(TRUE);
		m_cmbMediateOut.EnableWindow(TRUE);
		m_EditMediateVlaue.EnableWindow(TRUE);
		m_cmbMediate.EnableWindow(TRUE);
		GetDlgItem(IDC_RADIODEFFPRESS)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIOVOLUMEFLOW)->EnableWindow(TRUE);
		break;
	default:
		break;
	}
}

void PageBreakerModel::OnRadioRelease() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	SetTypeStatus();
}

void PageBreakerModel::OnRadioDual() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	SetTypeStatus();
}

void PageBreakerModel::OnRadioBreaker() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	SetTypeStatus();
}

void PageBreakerModel::OnRadio3Stage() 
{
	// TODO: Add your control notification handler code here
	m_nType =3;
	SetTypeStatus();
}
