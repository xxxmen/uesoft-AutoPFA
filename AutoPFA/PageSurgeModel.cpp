// PageSurgeModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagesurgemodel.h"
#include "Surge.h"
#include "OneWayWrapper.h"
#include "DlgSurge.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageSurgeModel dialog


PageSurgeModel::PageSurgeModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageSurgeModel::IDD, pParent)
	,m_dlgRestrictor(UnitSys)
	,m_dlgShortPipe(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbAreaUnit(&m_EditConstArea)
	,m_cmbOpenPress(&m_EditOpenPress)
	,m_cmbSurfacePress(&m_EditSurfacePress)
	,m_cmbEleUnit(&m_EditSurFaceEle)
{
	//{{AFX_DATA_INIT(PageSurgeModel)
	m_nPressType = 0;
	m_nAreaType = 0;
	m_strSurfacePress = _T("");
	m_strEle = _T("");
	m_strOpenPress = _T("");
	m_strCv = _T("");
	m_strConstArea = _T("");
	m_strSurfacePressUnit = _T("");
	m_strOpenPressUnit = _T("");
	m_strEleUnit = _T("");
	m_strAreaUnit = _T("");
	m_bModel = FALSE;
	m_bCv = FALSE;
	m_nPosition = 0;
	//}}AFX_DATA_INIT
}


void PageSurgeModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageSurgeModel)
	DDX_Control(pDX, IDC_ESURFACEELE, m_EditSurFaceEle);
	DDX_Control(pDX, IDC_BOX3, m_Box3);
	DDX_Control(pDX, IDC_CHECKCV, m_CheckCv);
	DDX_Control(pDX, IDC_CMBARAEUNIT, m_cmbAreaUnit);
	DDX_Control(pDX, IDC_CMBElEUNIT, m_cmbEleUnit);
	DDX_Control(pDX, IDC_CMBOPENPRESSUNIT, m_cmbOpenPress);
	DDX_Control(pDX, IDC_CMBSURFACEPRESSUNIT, m_cmbSurfacePress);
	DDX_Control(pDX, IDC_ECONDTAREA, m_EditConstArea);
	DDX_Control(pDX, IDC_ECV, m_EditCv);
	DDX_Control(pDX, IDC_EOPENPRESS, m_EditOpenPress);
	DDX_Control(pDX, IDC_ESURFACEPRESS, m_EditSurfacePress);
	DDX_Control(pDX, IDC_BOX2, m_Box2);
	DDX_Control(pDX, IDC_BOX1, m_Box1);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPressType);
	DDX_Radio(pDX, IDC_RADIOCONST, m_nAreaType);
	DDX_Text(pDX, IDC_ESURFACEPRESS, m_strSurfacePress);
	DDX_Text(pDX, IDC_ESURFACEELE, m_strEle);
	DDX_Text(pDX, IDC_EOPENPRESS, m_strOpenPress);
	DDX_Text(pDX, IDC_ECV, m_strCv);
	DDX_Text(pDX, IDC_ECONDTAREA, m_strConstArea);
	DDX_CBString(pDX, IDC_CMBSURFACEPRESSUNIT, m_strSurfacePressUnit);
	DDX_CBString(pDX, IDC_CMBOPENPRESSUNIT, m_strOpenPressUnit);
	DDX_CBString(pDX, IDC_CMBElEUNIT, m_strEleUnit);
	DDX_CBString(pDX, IDC_CMBARAEUNIT, m_strAreaUnit);
	DDX_Check(pDX, IDC_CHECKMODEL, m_bModel);
	DDX_Check(pDX, IDC_CHECKCV, m_bCv);
	DDX_Radio(pDX, IDC_RADIOCLOSE, m_nPosition);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageSurgeModel, BaseDlg)
	//{{AFX_MSG_MAP(PageSurgeModel)
	ON_BN_CLICKED(IDC_RADIOCONST, OnRadioConst)
	ON_BN_CLICKED(IDC_RADIOVARIABLE, OnRadioVariable)
	ON_BN_CLICKED(IDC_CHECKMODEL, OnCheckModel)
	ON_BN_CLICKED(IDC_CHECKCV, OnCheckCv)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_CBN_SELCHANGE(IDC_CMBSURFACEPRESSUNIT, OnSelchangePressUnit)
	ON_CBN_SELCHANGE(IDC_CMBElEUNIT, OnSelchangeEleUnit)
	ON_CBN_SELCHANGE(IDC_CMBARAEUNIT, OnSelchangeAraeUnit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageSurgeModel message handlers

BOOL PageSurgeModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgRestrictor.Create(IDD_RESTRICTORMODEL,this);
	Combine(this,m_Box1,m_dlgRestrictor);
	m_dlgShortPipe.Create(IDD_SHORTPIPEMODEL,this);
	Combine(this,m_Box2,m_dlgShortPipe);
	m_dlgTable.Create(IDD_TRANSTABLE,this);
	Combine(this,m_Box3,m_dlgTable);
	m_dlgTable.ShowCheck(SW_HIDE);
	

	InitUnitCbo(m_UnitSys,Pressure,m_cmbSurfacePress,m_strSurfacePressUnit);
	InitUnitCbo(m_UnitSys,Length,m_cmbEleUnit,m_strEleUnit);
	InitUnitCbo(m_UnitSys,Area,m_cmbAreaUnit,m_strAreaUnit);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageSurgeModel::Init()
{
	InitNum(m_strSurfacePress,m_strSurfacePressUnit,Surge::ms_SurfacePress);
	InitNum(m_strEle,m_strEleUnit,Surge::ms_SurgeHeight);
	InitNum(m_strConstArea,m_strAreaUnit,Surge::ms_ConstArea);
	m_dlgRestrictor.Init(Surge::ms_Orifice);
	m_dlgShortPipe.Init(Surge::ms_ShortPipe);
	m_nAreaType = Surge::ms_Variable.GetnValue();
	m_bModel    = abs(Surge::ms_OneWay.GetnValue());
	OneWayWrapper wrapper(Surge::ms_CheckValve);
	m_bCv = wrapper.GetCvModel();
	m_nPosition = wrapper.GetPostion();
	m_strCv = wrapper.GetCv();
	wrapper.GetPress(m_nPressType,m_strOpenPress,m_strOpenPressUnit);
	m_dlgTable.Init(Surge::ms_AreaTable);
	SetModelStatus();
	InitPressUnit();
	SetAreaStatus();
	SetTableHeader();
	UpdateData(FALSE);
}

BOOL PageSurgeModel::UpData()
{
	UpdateData(TRUE);
	SetNum(m_strSurfacePress,m_strSurfacePressUnit,Surge::ms_SurfacePress);
	SetNum(m_strEle,m_strEleUnit,Surge::ms_SurgeHeight);
	SetNum(m_strConstArea,m_strAreaUnit,Surge::ms_ConstArea);
	m_dlgShortPipe.UpData(Surge::ms_ShortPipe);
	m_dlgRestrictor.UpData(Surge::ms_Orifice);
	Surge::ms_Variable.SetValue(m_nAreaType);
	Surge::ms_OneWay.SetValue(m_bModel);
	OneWayWrapper wrapper(Surge::ms_CheckValve);
	wrapper.SetPostion(m_nPosition);
	wrapper.SetCv(m_strCv);
	wrapper.SetPress(m_nPressType,m_strOpenPress,m_strOpenPressUnit);
	Surge::ms_AreaTable.m_Unit.SetValue(m_strEleUnit);
	Surge::ms_AreaTable.m_Unit.SetValue(m_strAreaUnit,1);
	m_dlgTable.UpData(Surge::ms_AreaTable);
	return TRUE;
}

void PageSurgeModel::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbOpenPress,m_strOpenPressUnit);
}

void PageSurgeModel::SetAreaStatus()
{
	BOOL m_bEnable = TRUE;
	if(m_nAreaType == 0)
	{
		m_bEnable = FALSE;
	}
	m_EditConstArea.EnableWindow(!m_bEnable);
	m_dlgTable.EnableTable(m_bEnable);
}

void PageSurgeModel::OnRadioConst() 
{
	// TODO: Add your control notification handler code here
	m_nAreaType = 0;
	SetAreaStatus();
}

void PageSurgeModel::OnRadioVariable() 
{
	// TODO: Add your control notification handler code here
	m_nAreaType =1;
	SetAreaStatus();
}

void PageSurgeModel::OnCheckModel() 
{
	// TODO: Add your control notification handler code here
	m_bModel = !m_bModel;
	m_bCv = m_bModel;
	m_CheckCv.SetCheck(m_bCv);
	SetModelStatus();
}

void PageSurgeModel::OnCheckCv() 
{
	// TODO: Add your control notification handler code here
	m_bCv =! m_bCv;
	SetCvStatus();
	
}

void PageSurgeModel::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	InitPressUnit();
}

void PageSurgeModel::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}
void PageSurgeModel::SetCvStatus()
{
	m_EditCv.EnableWindow(m_bCv&&m_bModel);
	if(!m_bCv||!m_bModel)
	{
		m_strCv.Empty();
	}
}


void PageSurgeModel::SetModelStatus()
{
	GetDlgItem(IDC_CHECKCV)->EnableWindow(m_bModel);
	SetCvStatus();
	GetDlgItem(IDC_RADIOCLOSE)->EnableWindow(m_bModel);
	GetDlgItem(IDC_RADIOOPEN)->EnableWindow(m_bModel);
	GetDlgItem(IDC_RADIOPRESS)->EnableWindow(m_bModel);
	GetDlgItem(IDC_RADIOHEAD)->EnableWindow(m_bModel);
	m_cmbOpenPress.EnableWindow(m_bModel);
	m_EditOpenPress.EnableWindow(m_bModel);
}

void PageSurgeModel::OnSelchangePressUnit() 
{
	// TODO: Add your control notification handler code here
	DlgSurge *pSurge = dynamic_cast<DlgSurge*>(GetParent()->GetParent());
	pSurge->ChangeUnit(PressUnit());
}

CString PageSurgeModel::PressUnit()
{
	return GetCmbText(m_cmbSurfacePress);
}

CString PageSurgeModel::HeightUnit()
{
	return GetCmbText(m_cmbEleUnit);
}

CString PageSurgeModel::AreaUnit()
{
	return GetCmbText(m_cmbAreaUnit);
}
void PageSurgeModel::SetTableHeader()
{
	m_dlgTable.SetTableHeader(_T("塔高度"),HeightUnit(),1);
	m_dlgTable.SetTableHeader(_T("底面积"),AreaUnit(),2);
}

void PageSurgeModel::OnSelchangeEleUnit() 
{
	// TODO: Add your control notification handler code here
	SetTableHeader();
}

void PageSurgeModel::OnSelchangeAraeUnit() 
{
	// TODO: Add your control notification handler code here
	SetTableHeader();
}
