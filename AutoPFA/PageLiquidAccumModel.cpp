// PageLiquidAccumModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pageliquidaccummodel.h"
#include "LiquidAccumulator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageLiquidAccumModel dialog


PageLiquidAccumModel::PageLiquidAccumModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageLiquidAccumModel::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbVolumeUnit(&m_EditVolume)
	,m_cmbElasticUnit(&m_EditElastic)
{
	//{{AFX_DATA_INIT(PageLiquidAccumModel)
	m_strElasticUnit = _T("");
	m_strVolumeUnit = _T("");
	m_strElastic = _T("");
	m_strVolume = _T("");
	//}}AFX_DATA_INIT
}


void PageLiquidAccumModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageLiquidAccumModel)
	DDX_Control(pDX, IDC_EINITVOLUME, m_EditVolume);
	DDX_Control(pDX, IDC_EELASTIC, m_EditElastic);
	DDX_Control(pDX, IDC_CMBVOLUMEUNIT, m_cmbVolumeUnit);
	DDX_Control(pDX, IDC_CMBELASTICUNIT, m_cmbElasticUnit);
	DDX_CBString(pDX, IDC_CMBELASTICUNIT, m_strElasticUnit);
	DDX_CBString(pDX, IDC_CMBVOLUMEUNIT, m_strVolumeUnit);
	DDX_Text(pDX, IDC_EELASTIC, m_strElastic);
	DDX_Text(pDX, IDC_EINITVOLUME, m_strVolume);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageLiquidAccumModel, BaseDlg)
	//{{AFX_MSG_MAP(PageLiquidAccumModel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageLiquidAccumModel message handlers

void PageLiquidAccumModel::Init()
{
	InitNum(m_strElastic,m_strElasticUnit,LiquidAccumulator::ms_Elastic);
	InitNum(m_strVolume,m_strVolumeUnit,LiquidAccumulator::ms_InitVolume);
	UpdateData(FALSE);
}

BOOL PageLiquidAccumModel::UpData()
{
	UpdateData(TRUE);
	SetNum(m_strElastic,m_strElasticUnit,LiquidAccumulator::ms_Elastic);
	SetNum(m_strVolume,m_strVolumeUnit,LiquidAccumulator::ms_InitVolume);
	return TRUE;
}

BOOL PageLiquidAccumModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Volume,m_cmbVolumeUnit,m_strVolumeUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cmbElasticUnit,m_strElasticUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
