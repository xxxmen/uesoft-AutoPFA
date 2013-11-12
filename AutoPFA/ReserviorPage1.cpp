// ReserviorPage1.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "ReserviorPage1.h"
#include "Fuild.h"
#include "Reservoir.h"
#include "DlgReservoir.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// ReserviorPage1 dialog


ReserviorPage1::ReserviorPage1(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(ReserviorPage1::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbEleUnit(&m_EditSurFaceEle)
	,m_cmbTempUnit(&m_EditTemp)
	,m_cmbPressUnit(&m_EditSurfacePress)
	,m_cmbDenUnit(&m_EditDen)
{
	//{{AFX_DATA_INIT(ReserviorPage1)
	m_strEle = _T("");
	m_strEleUnit = _T("");
	m_strDenUnit = _T("");
	m_strTempUnit = _T("");
	m_strDen = _T("");
	m_strTemp = _T("");
	m_strSurfacePress = _T("");
	m_strPressUnit = _T("");
	//}}AFX_DATA_INIT
}


void ReserviorPage1::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(ReserviorPage1)
	DDX_Control(pDX, IDC_EFUILDDEN, m_EditDen);
	DDX_Control(pDX, IDC_EFUILDTEMP, m_EditTemp);
	DDX_Control(pDX, IDC_CMBTEMPUNIT, m_cmbTempUnit);
	DDX_Control(pDX, IDC_CMBDENUNIT, m_cmbDenUnit);
	DDX_Control(pDX, IDC_ESURFACEPRESS, m_EditSurfacePress);
	DDX_Control(pDX, IDC_CMBPRESSUNIT, m_cmbPressUnit);
	DDX_Control(pDX, IDC_ESURFACEELE, m_EditSurFaceEle);
	DDX_Control(pDX, IDC_CMBElEUNIT, m_cmbEleUnit);
	DDX_Text(pDX, IDC_ESURFACEELE, m_strEle);
	DDX_CBString(pDX, IDC_CMBElEUNIT, m_strEleUnit);
	DDX_CBString(pDX, IDC_CMBDENUNIT, m_strDenUnit);
	DDX_CBString(pDX, IDC_CMBTEMPUNIT, m_strTempUnit);
	DDX_Text(pDX, IDC_EFUILDDEN, m_strDen);
	DDX_Text(pDX, IDC_EFUILDTEMP, m_strTemp);
	DDX_Text(pDX, IDC_ESURFACEPRESS, m_strSurfacePress);
	DDX_CBString(pDX, IDC_CMBPRESSUNIT, m_strPressUnit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(ReserviorPage1, BaseDlg)
	//{{AFX_MSG_MAP(ReserviorPage1)
	ON_CBN_SELCHANGE(IDC_CMBElEUNIT, OnSelchangeEleUnit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// ReserviorPage1 message handlers

void ReserviorPage1::Init()
{
	InitNum(m_strEle,m_strEleUnit,Jun::ms_InletEle);
	InitNum(m_strSurfacePress,m_strPressUnit,Reservoir::ms_SurfacePress);
	//水库不保存流体密度和温度
	InitNum(m_strDen,m_strDenUnit,Fuild::ms_Density);
	InitNum(m_strTemp,m_strTempUnit,Fuild::ms_Temperature);
	
	UpdateData(FALSE);
}

BOOL ReserviorPage1::UpData()
{
	UpdateData(TRUE);
	SetNum(m_strEle,m_strEleUnit,Jun::ms_InletEle);
    SetNum(m_strEle,m_strEleUnit,Jun::ms_OutletEle);
	SetNum(m_strSurfacePress,m_strPressUnit,Reservoir::ms_SurfacePress);
	return TRUE;
}

BOOL ReserviorPage1::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Length,m_cmbEleUnit,m_strEleUnit);
	InitUnitCbo(m_UnitSys,Pressure,m_cmbPressUnit,m_strPressUnit);
	InitUnitCbo(m_UnitSys,Temperature,m_cmbTempUnit,m_strTempUnit);
	InitUnitCbo(m_UnitSys,Density,m_cmbDenUnit,m_strDenUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void ReserviorPage1::OnSelchangeEleUnit() 
{
	// TODO: Add your control notification handler code here
	DlgReservoir *pReservoir = dynamic_cast<DlgReservoir*>(GetParent()->GetParent());
	pReservoir->ChangeUnit(EleUnit());
}

CString ReserviorPage1::EleUnit()
{
	return GetCmbText(m_cmbEleUnit);
}
