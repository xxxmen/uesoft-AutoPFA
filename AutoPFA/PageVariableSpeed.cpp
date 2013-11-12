// PageVariableSpeed.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageVariableSpeed.h"
#include "Pump.h"
#include "OptionTypeNumWrapper.h"
#include "DlgPump.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageVariableSpeed dialog


PageVariableSpeed::PageVariableSpeed(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageVariableSpeed::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbSetUnit(&m_EditSetPoint)
{
	//{{AFX_DATA_INIT(PageVariableSpeed)
	m_strSetPointUnit = _T("");
	m_strSetPointValue = _T("");
	m_strSpeedRatio = _T("");
	m_nApplyType = -1;
	m_nControlType = -1;
	m_nPressType = -1;
	m_strNote = _T("");
	//}}AFX_DATA_INIT
	m_nType = 0;
	m_nSetType = 0;
}


void PageVariableSpeed::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageVariableSpeed)
	DDX_Control(pDX, IDC_ESETVALUE, m_EditSetPoint);
	DDX_Control(pDX, IDC_CMBSETUNIT, m_cmbSetUnit);
	DDX_CBString(pDX, IDC_CMBSETUNIT, m_strSetPointUnit);
	DDX_Text(pDX, IDC_ESETVALUE, m_strSetPointValue);
	DDX_Text(pDX, IDC_ESPEEDRATIO, m_strSpeedRatio);
	DDX_Radio(pDX, IDC_RADIOALWAYS, m_nApplyType);
	DDX_Radio(pDX, IDC_RADIONO, m_nControlType);
	DDX_Radio(pDX, IDC_RADIOSTAG, m_nPressType);
	DDX_Text(pDX, IDC_STATICNOTE, m_strNote);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageVariableSpeed, BaseDlg)
	//{{AFX_MSG_MAP(PageVariableSpeed)
	ON_BN_CLICKED(IDC_RADIOVOLUME, OnRadioVolume)
	ON_BN_CLICKED(IDC_RADIOSUCTIONPRESS, OnRadioSuctionPress)
	ON_BN_CLICKED(IDC_RADIOSUCTIONHEAD, OnRadioSuctionHead)
	ON_BN_CLICKED(IDC_RADIONO, OnRadioNo)
	ON_BN_CLICKED(IDC_RADIOMASS, OnRadioMass)
	ON_BN_CLICKED(IDC_RADIODISPRESS, OnRadioDisPress)
	ON_BN_CLICKED(IDC_RADIODISHEAD, OnRadioDisHead)
	ON_CBN_SELCHANGE(IDC_CMBSETUNIT, OnSelchangeSetunit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageVariableSpeed message handlers

BOOL PageVariableSpeed::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_strNote.LoadString(IDS_STRSPEEDNOTE);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageVariableSpeed::OnRadioVolume() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	m_nSetType = 0;
	SetTypeStatus();
	ChangControl(3);
}

void PageVariableSpeed::OnRadioSuctionPress() 
{
	// TODO: Add your control notification handler code here
	m_nType = 3;
	m_nSetType = 1;
	SetTypeStatus();
	ChangControl(3);
}

void PageVariableSpeed::OnRadioSuctionHead() 
{
	// TODO: Add your control notification handler code here
	m_nType = 3;
	m_nSetType = 0;
	SetTypeStatus();
	ChangControl(3);
}

void PageVariableSpeed::OnRadioNo() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	m_nSetType = 0;
	SetTypeStatus();
	ChangControl(0);
}

void PageVariableSpeed::OnRadioMass() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	m_nSetType = 1;
	SetTypeStatus();
	ChangControl(3);
}

void PageVariableSpeed::OnRadioDisPress() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	m_nSetType = 1;
	SetTypeStatus();
	ChangControl(3);
}

void PageVariableSpeed::OnRadioDisHead() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	m_nSetType = 0;
	SetTypeStatus();
	ChangControl(3);
}

void PageVariableSpeed::InitSetUnit()
{
	if(2 == m_nType)//选择流量控制
	{
		InitFlowUnitCbo(m_UnitSys,m_nSetType,m_cmbSetUnit,m_strSetPointUnit);
	}
	else
	{
		InitPressUnitCbo(m_UnitSys,m_nSetType,m_cmbSetUnit,m_strSetPointUnit);
	}
}

void PageVariableSpeed::Init()
{
	float fSpeedRatio = fabs(Pump::ms_SpeedRatio.GetfValue());
	m_strSpeedRatio.Format(_T("%d"),int(fSpeedRatio*100.1));
	m_nPressType    = Pump::ms_PressType.GetnValue();
	m_nApplyType    = Pump::ms_ControlApply.GetnValue();

	OptionTypeNumWrapper wrapper(Pump::ms_PumpControl);
	m_nType = wrapper.GetModel();
	wrapper.GetPress(m_nSetType,m_strSetPointValue,m_strSetPointUnit);

	SetTypeStatus();
	InitControlType();
	UpdateData(FALSE);
}

BOOL PageVariableSpeed::UpData()
{
	UpdateData(TRUE);

	float fSpeedRatio = _tcstod(m_strSpeedRatio, NULL )/100.0;
	Pump::ms_SpeedRatio.SetValue(fSpeedRatio);
	Pump::ms_PressType.SetValue(m_nPressType);
	Pump::ms_ControlApply.SetValue(m_nApplyType);
	
	OptionTypeNumWrapper wrapper(Pump::ms_PumpControl);
	wrapper.SetModel(m_nType);
	wrapper.SetPress(m_nSetType,m_strSetPointValue,m_strSetPointUnit);
	return TRUE;
}

void PageVariableSpeed::InitControlType()
{
	if(m_nType ==2)
	{
		m_nControlType = 5 + m_nSetType;
	}
	else
	{
		m_nControlType = m_nType + m_nSetType;
	}
}

void PageVariableSpeed::SetTypeStatus()
{
	BOOL bSppedEnable = FALSE;
	BOOL bSetPointEnable = FALSE;
	BOOL nPressEnable = FALSE;
	switch(m_nType) {
	case 0:
		bSppedEnable = TRUE;
		bSetPointEnable = FALSE;
		nPressEnable = FALSE;
		break;
	case 1:
	case 3:
		bSppedEnable = FALSE;
		bSetPointEnable = TRUE;
		nPressEnable = TRUE;
		break;
	case 2:
		bSppedEnable = FALSE;
		bSetPointEnable = TRUE;
		nPressEnable = FALSE;
		break;
	default:
		break;
	}
	GetDlgItem(IDC_ESPEEDRATIO)->EnableWindow(bSppedEnable);
	GetDlgItem(IDC_STATICNOTE)->EnableWindow(bSppedEnable);
	m_EditSetPoint.EnableWindow(bSetPointEnable);
	m_cmbSetUnit.EnableWindow(bSetPointEnable);
	GetDlgItem(IDC_RADIOSTAG)->EnableWindow(nPressEnable);
	GetDlgItem(IDC_RADIOSTATIC)->EnableWindow(nPressEnable);
	GetDlgItem(IDC_RADIOALWAYS)->EnableWindow(nPressEnable);
	GetDlgItem(IDC_RADIOEXCEED)->EnableWindow(nPressEnable);
	GetDlgItem(IDC_RADIOBELOW)->EnableWindow(nPressEnable);
	InitSetUnit();
}

void PageVariableSpeed::ControlStatus(BOOL bVariableSpeed)
{
	if(!bVariableSpeed)
	{
		if(m_nType!=0)
		{
			ASSERT(FALSE);
		}
	}
	GetDlgItem(IDC_RADIONO)->EnableWindow(bVariableSpeed);
	GetDlgItem(IDC_RADIODISPRESS)->EnableWindow(bVariableSpeed);
	GetDlgItem(IDC_RADIODISHEAD)->EnableWindow(bVariableSpeed);
	GetDlgItem(IDC_RADIOSUCTIONPRESS)->EnableWindow(bVariableSpeed);
	GetDlgItem(IDC_RADIOSUCTIONHEAD)->EnableWindow(bVariableSpeed);
	GetDlgItem(IDC_RADIOVOLUME)->EnableWindow(bVariableSpeed);
	GetDlgItem(IDC_RADIOMASS)->EnableWindow(bVariableSpeed);
}

CString PageVariableSpeed::ControlUnit()
{
	return GetCmbText(m_cmbSetUnit);
}

void PageVariableSpeed::ChangControl(int nType)
{
	DlgPump *pDlgPump = dynamic_cast<DlgPump*>(GetParent()->GetParent());
	pDlgPump->ChangeControl(nType,ControlUnit());
}

void PageVariableSpeed::OnSelchangeSetunit() 
{
	// TODO: Add your control notification handler code here
	if(m_nType==0)
	{
		ChangControl(0);
	}
	else
	{
		ChangControl(3);
	}
}


