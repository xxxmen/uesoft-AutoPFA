// PageSprayModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageSprayModel.h"
#include "SprayDischarge.h"
#include "CurveWrapper.h"
#include "DlgSprayDischarge.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageSprayModel dialog


PageSprayModel::PageSprayModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageSprayModel::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbHoleAreaUnit(&m_EditHoleArea)
	,m_cmbExitPress(&m_EditExitPress)
{
	//{{AFX_DATA_INIT(PageSprayModel)
	m_strFireKUnit1 = _T("");
	m_strFireKUnit2 = _T("");
	m_strHoleAreaUnit = _T("");
	m_strCvOrK = _T("");
	m_strExitPressUnit = _T("");
	m_strExitPress = _T("");
	m_strHoleArea = _T("");
	m_strHoleNum = _T("");
	m_nPressType = -1;
	m_nGeometry = -1;
	m_nLossType = -1;
	//}}AFX_DATA_INIT
	m_nFireKType = -1;
}


void PageSprayModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageSprayModel)
	DDX_Control(pDX, IDC_EHOLENUM, m_EditHoleNum);
	DDX_Control(pDX, IDC_EHOLEAREA, m_EditHoleArea);
	DDX_Control(pDX, IDC_EEXITPRESS, m_EditExitPress);
	DDX_Control(pDX, IDC_ECVORK, m_EditCvOrK);
	DDX_Control(pDX, IDC_CMBHOLEAREAUNIT, m_cmbHoleAreaUnit);
	DDX_Control(pDX, IDC_CMBFIREKUNIT2, m_cmbFireKUnit2);
	DDX_Control(pDX, IDC_CMBFIREKUNIT1, m_cmbFireKUnit1);
	DDX_Control(pDX, IDC_CMBEXITPRESSUNIT, m_cmbExitPress);
	DDX_CBString(pDX, IDC_CMBFIREKUNIT1, m_strFireKUnit1);
	DDX_CBString(pDX, IDC_CMBFIREKUNIT2, m_strFireKUnit2);
	DDX_CBString(pDX, IDC_CMBHOLEAREAUNIT, m_strHoleAreaUnit);
	DDX_Text(pDX, IDC_ECVORK, m_strCvOrK);
	DDX_CBString(pDX, IDC_CMBEXITPRESSUNIT, m_strExitPressUnit);
	DDX_Text(pDX, IDC_EEXITPRESS, m_strExitPress);
	DDX_Text(pDX, IDC_EHOLEAREA, m_strHoleArea);
	DDX_Text(pDX, IDC_EHOLENUM, m_strHoleNum);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPressType);
	DDX_Radio(pDX, IDC_RADIOSPRAY, m_nGeometry);
	DDX_Radio(pDX, IDC_RADIOCONSTCV, m_nLossType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageSprayModel, BaseDlg)
	//{{AFX_MSG_MAP(PageSprayModel)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_RADIOSPARGER, OnRadioSparger)
	ON_BN_CLICKED(IDC_RADIOSPRAY, OnRadioSpray)
	ON_BN_CLICKED(IDC_RADIOFIREK, OnRadioFireK)
	ON_BN_CLICKED(IDC_RADIOCONSTCV, OnRadioConstCv)
	ON_CBN_SELCHANGE(IDC_CMBHOLEAREAUNIT, OnSelchangeHoleAreaUnit)
	ON_CBN_SELCHANGE(IDC_CMBFIREKUNIT1, OnSelchangeFirekUnit1)
	ON_CBN_SELCHANGE(IDC_CMBFIREKUNIT2, OnSelchangeFirekUnit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageSprayModel message handlers

BOOL PageSprayModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Pressure,m_cmbFireKUnit2,m_strFireKUnit2);
	InitUnitCbo(m_UnitSys,VolumetricFlow,m_cmbFireKUnit1,m_strFireKUnit1);
	InitUnitCbo(m_UnitSys,Area,m_cmbHoleAreaUnit,m_strHoleAreaUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageSprayModel::Init()
{
	m_nGeometry = SprayDischarge::ms_Type.GetnValue();
	InitNum(m_strHoleArea,m_strHoleAreaUnit,SprayDischarge::ms_ExitArea);
	m_strHoleNum = SprayDischarge::ms_ExitArea.GetValue(2);
	m_strCvOrK = SprayDischarge::ms_KOrCv.GetValue();
	InitTypeNum(m_nPressType,m_strExitPress,m_strExitPressUnit,SprayDischarge::ms_ExitPress);

	CurveWrapper wrapper(SprayDischarge::ms_Curve);
	m_nLossType = wrapper.GetLossType();
	m_nFireKType = wrapper.GetYAxisType();
	if(!m_strCvOrK.IsEmpty())
	{
		CString strUnit1 = wrapper.GetXAxisUnit();
		CString strUnit2 = wrapper.GetYAxisUnit();
		if(!strUnit1.IsEmpty()&&strUnit1.CollateNoCase(_T("None")) !=0
			&&!strUnit2.IsEmpty()&&strUnit2.CollateNoCase(_T("None")) !=0)
		{
			m_strFireKUnit1 = strUnit1;
			m_strFireKUnit2 = strUnit2;
		}
	}
	
	SetLossStatus();
	InitExitPressUnit();
	UpdateData(FALSE);
}

BOOL PageSprayModel::UpData()
{
	UpdateData(TRUE);
	SprayDischarge::ms_Type.SetValue(m_nGeometry);
	SprayDischarge::ms_ExitArea.SetValue(m_strHoleArea,0);
	SprayDischarge::ms_ExitArea.SetValue(m_strHoleAreaUnit,1);
	SprayDischarge::ms_ExitArea.SetValue(m_strHoleNum,2);
	SprayDischarge::ms_KOrCv.SetValue(m_strCvOrK);
	SetTypeNum(m_nPressType,m_strExitPress,m_strExitPressUnit,SprayDischarge::ms_ExitPress);
	
	CurveWrapper wrapper(SprayDischarge::ms_Curve);
	wrapper.SetLossType(m_nLossType);
	wrapper.SetXAxisUnit(m_strFireKUnit1);
	wrapper.SetYAxisUnit(m_strFireKUnit2);
	wrapper.SetYAxisType(m_nFireKType);
	
	return TRUE;
}

void PageSprayModel::InitExitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbExitPress,m_strExitPressUnit);
}


void PageSprayModel::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	InitExitPressUnit();
}

void PageSprayModel::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitExitPressUnit();
}

void PageSprayModel::OnRadioSparger() 
{
	// TODO: Add your control notification handler code here
	m_nGeometry = 1;
	SetGeometryStatus();
}

void PageSprayModel::OnRadioSpray() 
{
	// TODO: Add your control notification handler code here
	m_nGeometry = 0;
	SetGeometryStatus();
}

void PageSprayModel::OnRadioFireK() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_nLossType = 1;
	SetLossStatus();
	ChangeType();
	UpdateData(FALSE);
}

void PageSprayModel::OnRadioConstCv() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_nLossType = 0;
	SetLossStatus();
	ChangeType();
	UpdateData(FALSE);
}

void PageSprayModel::SetGeometryStatus()
{
	if(m_nGeometry ==0)
	{
		GetDlgItem(IDC_STATICHOLENUM)->ShowWindow(SW_HIDE);
		m_EditHoleNum.ShowWindow(SW_HIDE);
	}
	else
	{
		GetDlgItem(IDC_STATICHOLENUM)->ShowWindow(SW_SHOW);
		m_EditHoleNum.ShowWindow(SW_SHOW);
	}
}

void PageSprayModel::SetLossStatus()
{
	switch(m_nLossType) {
	case 0:
		GetDlgItem(IDC_STATICGEOMETRY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIOSPRAY)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_RADIOSPARGER)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATICCVORK)->SetWindowText(_T("流量系数"));
		m_cmbFireKUnit1.ShowWindow(SW_HIDE);
		m_cmbFireKUnit2.ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATICSQUR)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATICHOLEAREA)->ShowWindow(SW_SHOW);
		m_EditHoleArea.ShowWindow(SW_SHOW);
		m_cmbHoleAreaUnit.ShowWindow(SW_SHOW);
		m_nFireKType =0;
		break;
	case 1:
		GetDlgItem(IDC_STATICGEOMETRY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIOSPRAY)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_RADIOSPARGER)->ShowWindow(SW_HIDE);
		m_nGeometry = 1; //K系数损失模型几何形状只能为喷雾
		m_nFireKType =1; //
		GetDlgItem(IDC_STATICCVORK)->SetWindowText(_T("K系数"));
		m_cmbFireKUnit1.ShowWindow(SW_SHOW);
		m_cmbFireKUnit2.ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATICSQUR)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_STATICHOLEAREA)->ShowWindow(SW_HIDE);
		m_EditHoleArea.ShowWindow(SW_HIDE);
		m_cmbHoleAreaUnit.ShowWindow(SW_HIDE);
		break;
	default:
		break;
	}
	SetGeometryStatus();
}

CString PageSprayModel::SprayUnit()
{
	CString strRet;
	if(0 == m_nLossType)
	{
		strRet = GetCmbText(m_cmbHoleAreaUnit);
	}
	else
	{
		CString temp;
		strRet = GetCmbText(m_cmbFireKUnit1);
		temp = GetCmbText(m_cmbFireKUnit2);
		strRet = strRet + _T(" sqrt ") + temp;
	}
	return strRet;
}

CString PageSprayModel::SprayString()
{
	CString strRet;
	if(0 == m_nLossType)
	{
		strRet = _T("CdA");
	}
	else
	{
		strRet = _T("K");
	}
	return strRet;
}

void PageSprayModel::OnSelchangeHoleAreaUnit() 
{
	// TODO: Add your control notification handler code here
	ChangeUnit();
}

void PageSprayModel::OnSelchangeFirekUnit1() 
{
	// TODO: Add your control notification handler code here
	ChangeUnit();
}

void PageSprayModel::OnSelchangeFirekUnit2() 
{
	// TODO: Add your control notification handler code here
	ChangeUnit();
}

void PageSprayModel::ChangeUnit()
{
	DlgSprayDischarge *pSprayDischarge = dynamic_cast<DlgSprayDischarge*>(GetParent()->GetParent());
	pSprayDischarge->ChangeUnit(SprayUnit());
}

void PageSprayModel::ChangeType()
{
	DlgSprayDischarge *pSprayDischarge = dynamic_cast<DlgSprayDischarge*>(GetParent()->GetParent());
	pSprayDischarge->ChangeType(SprayString());
	ChangeUnit();
}
