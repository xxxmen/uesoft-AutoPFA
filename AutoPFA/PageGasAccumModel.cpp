// PageGasAccumModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageGasAccumModel.h"
#include "GasAccumulator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageGasAccumModel dialog


PageGasAccumModel::PageGasAccumModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageGasAccumModel::IDD, pParent)
	,m_dlgRestrictor(UnitSys)
	,m_dlgShortPipe(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbPressUnit(&m_EditPress)
	,m_cmbVolumeUnit(&m_EditVolume)
{
	//{{AFX_DATA_INIT(PageGasAccumModel)
	m_strPressUnit = _T("");
	m_strVolumeUnit = _T("");
	m_strInitPress = _T("");
	m_strInitVolume = _T("");
	m_strMaxVolume = _T("");
	m_strMinVolume = _T("");
	m_strPolyConst = _T("");
	m_nVolumeType = 0;
	//}}AFX_DATA_INIT
}


void PageGasAccumModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageGasAccumModel)
	DDX_Control(pDX, IDC_EPOLYCONST, m_EditPolyConst);
	DDX_Control(pDX, IDC_EINITVOLUME, m_EditVolume);
	DDX_Control(pDX, IDC_EINITPRESS, m_EditPress);
	DDX_Control(pDX, IDC_CMBVOLUMEUNIT, m_cmbVolumeUnit);
	DDX_Control(pDX, IDC_CMBPRESSUNIT, m_cmbPressUnit);
	DDX_Control(pDX, IDC_BOX2, m_Box2);
	DDX_Control(pDX, IDC_BOX1, m_Box1);
	DDX_CBString(pDX, IDC_CMBPRESSUNIT, m_strPressUnit);
	DDX_CBString(pDX, IDC_CMBVOLUMEUNIT, m_strVolumeUnit);
	DDX_Text(pDX, IDC_EINITPRESS, m_strInitPress);
	DDX_Text(pDX, IDC_EINITVOLUME, m_strInitVolume);
	DDX_Text(pDX, IDC_EMAXVOLUME, m_strMaxVolume);
	DDX_Text(pDX, IDC_EMINVOLUME, m_strMinVolume);
	DDX_Text(pDX, IDC_EPOLYCONST, m_strPolyConst);
	DDX_Radio(pDX, IDC_RADIOACTUAL, m_nVolumeType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageGasAccumModel, BaseDlg)
	//{{AFX_MSG_MAP(PageGasAccumModel)
	ON_BN_CLICKED(IDC_RADIOACTUAL, OnRadioActual)
	ON_BN_CLICKED(IDC_RADIOSPECITY, OnRadioSpecity)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageGasAccumModel message handlers

BOOL PageGasAccumModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgRestrictor.Create(IDD_RESTRICTORMODEL,this);
	Combine(this,m_Box1,m_dlgRestrictor);
	m_dlgShortPipe.Create(IDD_SHORTPIPEMODEL,this);
	Combine(this,m_Box2,m_dlgShortPipe);
	
	InitUnitCbo(m_UnitSys,Volume,m_cmbVolumeUnit,m_strVolumeUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cmbPressUnit,m_strPressUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageGasAccumModel::Init()
{
	m_strPolyConst = GasAccumulator::ms_Polytropic.GetValue();
	InitNum(m_strInitVolume,m_strVolumeUnit,GasAccumulator::ms_InitVolume);
	m_strMaxVolume = GasAccumulator::ms_MaxVolume.GetValue();
	m_strMinVolume = GasAccumulator::ms_MinVolume.GetValue();
	InitTypeNum(m_nVolumeType,m_strInitPress,m_strPressUnit,GasAccumulator::ms_GasVolume);
	m_dlgRestrictor.Init(GasAccumulator::ms_Orifice);
	m_dlgShortPipe.Init(GasAccumulator::ms_ShortPipe);

	VolumeStatus();
	UpdateData(FALSE);
}

BOOL PageGasAccumModel::UpData()
{
	UpdateData(TRUE);
	GasAccumulator::ms_Polytropic.SetValue(m_strPolyConst);
	SetNum(m_strInitVolume,m_strVolumeUnit,GasAccumulator::ms_InitVolume);
	GasAccumulator::ms_MaxVolume.SetValue(m_strMaxVolume);
	GasAccumulator::ms_MinVolume.SetValue(m_strMinVolume);
	SetTypeNum(m_nVolumeType,m_strInitPress,m_strPressUnit,GasAccumulator::ms_GasVolume);
	m_dlgShortPipe.UpData(GasAccumulator::ms_ShortPipe);
	m_dlgRestrictor.UpData(GasAccumulator::ms_Orifice);
	return TRUE;
}

void PageGasAccumModel::VolumeStatus()
{
	BOOL bEnable = TRUE;
	CString strText;
	if(m_nVolumeType == 0)
	{
		bEnable = FALSE;
		strText.LoadString(IDS_STRINITGASVOLUME);
	}
	else
	{
		strText.LoadString(IDS_STRREFGASVOLUME);
	}
	GetDlgItem(IDC_STATICGAS)->SetWindowText(strText);
	GetDlgItem(IDC_STATICPRESS)->EnableWindow(bEnable);
	m_EditPress.EnableWindow(bEnable);
	m_cmbPressUnit.EnableWindow(bEnable);
}

void PageGasAccumModel::OnRadioActual() 
{
	// TODO: Add your control notification handler code here
	m_nVolumeType = 0;
	VolumeStatus();
}

void PageGasAccumModel::OnRadioSpecity() 
{
	// TODO: Add your control notification handler code here
	m_nVolumeType = 1;
	VolumeStatus();
}
