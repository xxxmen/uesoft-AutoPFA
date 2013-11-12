// PageControlModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageControlModel.h"
#include "ControlValve.h"
#include "ControlWrapper.h"
#include "DlgControlValve.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageControlModel dialog


PageControlModel::PageControlModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageControlModel::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbSetUnit(&m_EditSetValue)
{
	//{{AFX_DATA_INIT(PageControlModel)
	m_bAlways = FALSE;
	m_bDefault = TRUE;
	m_strSetUnit = _T("");
	m_strKOrCv = _T("");
	m_strSetValue = _T("");
	m_nLossType = 1;
	m_nInSuffic = 0;
	m_nExceesive = 1;
	m_nType = 0;
	m_nPress = 1;
	m_nSetType = 0;
	//}}AFX_DATA_INIT
}


void PageControlModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageControlModel)
	DDX_Control(pDX, IDC_RADIOFULLOPEN2, m_RadioOpen2);
	DDX_Control(pDX, IDC_RADIOFULLOPEN1, m_RadioOpen1);
	DDX_Control(pDX, IDC_EDITSETVALVE, m_EditSetValue);
	DDX_Control(pDX, IDC_EDITKORCV, m_EditKOrCv);
	DDX_Control(pDX, IDC_CMBSETUNIT, m_cmbSetUnit);
	DDX_Check(pDX, IDC_CHECKALWAYS, m_bAlways);
	DDX_Check(pDX, IDC_CHECKDEFAULT, m_bDefault);
	DDX_CBString(pDX, IDC_CMBSETUNIT, m_strSetUnit);
	DDX_Text(pDX, IDC_EDITKORCV, m_strKOrCv);
	DDX_Text(pDX, IDC_EDITSETVALVE, m_strSetValue);
	DDX_Radio(pDX, IDC_RADIOCV, m_nLossType);
	DDX_Radio(pDX, IDC_RADIOFULLOPEN1, m_nInSuffic);
	DDX_Radio(pDX, IDC_RADIOFULLOPEN2, m_nExceesive);
	DDX_Radio(pDX, IDC_RADIOPRV, m_nType);
	DDX_Radio(pDX, IDC_RADIOSTAGN, m_nPress);
	DDX_Radio(pDX, IDC_RADIOTYPE1, m_nSetType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageControlModel, BaseDlg)
	//{{AFX_MSG_MAP(PageControlModel)
	ON_BN_CLICKED(IDC_RADIOTYPE1, OnRadioType1)
	ON_BN_CLICKED(IDC_RADIOTYPE2, OnRadioType2)
	ON_BN_CLICKED(IDC_RADIOTABLECV, OnRadioTableCv)
	ON_BN_CLICKED(IDC_RADIOPSV, OnRadioPSV)
	ON_BN_CLICKED(IDC_RADIOPRV, OnRadioPRV)
	ON_BN_CLICKED(IDC_RADIOPDCV, OnRadioPDCV)
	ON_BN_CLICKED(IDC_RADIOK, OnRadioK)
	ON_BN_CLICKED(IDC_RADIOFCV, OnRadioFCV)
	ON_BN_CLICKED(IDC_RADIOCV, OnRadioCv)
	ON_BN_CLICKED(IDC_CHECKDEFAULT, OnCheckDefault)
	ON_CBN_SELCHANGE(IDC_CMBSETUNIT, OnSelchangeSetUnit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageControlModel message handlers

BOOL PageControlModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageControlModel::Init()
{
	ControlWrapper wrapper(ControlValve::ms_ControlSet);
	m_nType = wrapper.GetType();
	m_nPress = wrapper.GetPressType();
	m_nSetType = wrapper.GetSetType();
	wrapper.GetSetNum(m_strSetValue,m_strSetUnit);
	m_strKOrCv = ControlValve::ms_KOrCv.GetValue();
	m_nLossType = abs(ControlValve::ms_ModelType.GetnValue());//-2使用系数表的值
	m_bAlways = abs(ControlValve::ms_failAction.GetnValue());
	m_bDefault = abs(ControlValve::ms_failAction.GetnValue(1));
	m_nInSuffic = ControlValve::ms_failAction.GetnValue(2);
	m_nExceesive = ControlValve::ms_failAction.GetnValue(3);

	SetTypeStatus();
	UpdateData(FALSE);
}

BOOL PageControlModel::UpData()
{
	UpdateData(TRUE);
	ControlWrapper wrapper(ControlValve::ms_ControlSet);
	wrapper.SetType(m_nType);
	wrapper.SetPressType(m_nPress);
	wrapper.SetSetType(m_nSetType);
	wrapper.SetSetNum(m_strSetValue,m_strSetUnit);
	ControlValve::ms_KOrCv.SetValue(m_strKOrCv);
	if(m_nLossType==2)
		m_nLossType = -2;
	ControlValve::ms_ModelType.SetValue(m_nLossType);
	ControlValve::ms_failAction.SetValue(m_bAlways);
	ControlValve::ms_failAction.SetValue(m_bDefault,1);
	ControlValve::ms_failAction.SetValue(m_nInSuffic,2);
	ControlValve::ms_failAction.SetValue(m_nExceesive,3);

	return TRUE;
}

void PageControlModel::OnRadioType1() 
{
	// TODO: Add your control notification handler code here
	m_nSetType = 0;
	InitSetUnit();
	ChangeType();
}

void PageControlModel::OnRadioType2() 
{
	// TODO: Add your control notification handler code here
	m_nSetType = 1;
	InitSetUnit();
	ChangeType();
}

void PageControlModel::OnRadioTableCv() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 2;
	LossModelStatus();
}

void PageControlModel::OnRadioPSV() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetTypeStatus();
	UpdateData(FALSE);
}

void PageControlModel::OnRadioPRV() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetTypeStatus();
	UpdateData(FALSE);
}

void PageControlModel::OnRadioPDCV() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetTypeStatus();
	UpdateData(FALSE);
}

void PageControlModel::OnRadioK() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 1;
	LossModelStatus();
}

void PageControlModel::OnRadioFCV() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	SetTypeStatus();
	UpdateData(FALSE);
}

void PageControlModel::OnRadioCv() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 0;
	LossModelStatus();
}

void PageControlModel::OnCheckDefault() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	FailActionStatus();
	UpdateData(FALSE);
}

void PageControlModel::SetTypeStatus()
{
	FailActionStatus();
	SetPointStatus();
	FullOpenLossStatus();
}

void PageControlModel::FullOpenLossStatus()
{
	int bEnable = TRUE;
	if(3== m_nType)//选择PDCV阀门
		bEnable = FALSE;

	GetDlgItem(IDC_RADIOCV)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIOK)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIOTABLECV)->EnableWindow(bEnable);
	m_EditKOrCv.EnableWindow(bEnable);
	if(m_nLossType == 2)
	{//使用系数表的值
		m_EditKOrCv.EnableWindow(FALSE);
	}
}

void PageControlModel::SetPointStatus()
{
	int bEnable = TRUE;
	CString strText1,strText2;
	if(2 == m_nType)//选择FCV阀门
	{
		bEnable = FALSE;
		strText1.LoadString(IDS_STRVOLUMEFLOW);
		strText2.LoadString(IDS_STRMASSFLOW);
	}
	else if(3==m_nType)
	{
		strText1.LoadString(IDS_STRHEADLOSS);
		strText2.LoadString(IDS_STRPRESSLOSS);
	}
	else
	{
		strText1.LoadString(IDS_STRHEAD);
		strText2.LoadString(IDS_STRPRESSURE);
	}
	GetDlgItem(IDC_RADIOTYPE1)->SetWindowText(strText1);
	GetDlgItem(IDC_RADIOTYPE2)->SetWindowText(strText2);
	GetDlgItem(IDC_RADIOSTAGN)->EnableWindow(bEnable);
	GetDlgItem(IDC_RADIOSTATIC)->EnableWindow(bEnable);
	InitSetUnit();
	ChangeType();
}

void PageControlModel::LossModelStatus()
{
	if(m_nLossType == 2)
	{//使用系数表的值
		m_EditKOrCv.EnableWindow(FALSE);
	}
	else
	{
		m_EditKOrCv.EnableWindow(TRUE);
	}
	ChangeType();
}

void PageControlModel::InitSetUnit()
{
	if(2 == m_nType)//选择FCV阀门
	{
		InitFlowUnitCbo(m_UnitSys,m_nSetType,m_cmbSetUnit,m_strSetUnit);
	}
	else
	{
		InitPressUnitCbo(m_UnitSys,m_nSetType,m_cmbSetUnit,m_strSetUnit);
	}
}

void PageControlModel::FailActionStatus()
{
	switch(m_nType) {
	case 0:
		GetDlgItem(IDC_CHECKALWAYS)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECKDEFAULT)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIOFULLOPEN1)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIOCLOSE2)->EnableWindow(TRUE);
		if(m_bDefault)
		{
			m_nInSuffic = 0;
			m_nExceesive = 1;
			GetDlgItem(IDC_RADIOFULLOPEN2)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIOCLOSS1)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_RADIOFULLOPEN2)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIOCLOSS1)->EnableWindow(TRUE);
		}
		break;
	case 1:
		GetDlgItem(IDC_CHECKALWAYS)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECKDEFAULT)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIOFULLOPEN2)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIOCLOSS1)->EnableWindow(TRUE);
		if(m_bDefault)
		{
			m_nInSuffic = 1;
			m_nExceesive = 0;
			GetDlgItem(IDC_RADIOFULLOPEN1)->EnableWindow(FALSE);
			GetDlgItem(IDC_RADIOCLOSE2)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_RADIOFULLOPEN1)->EnableWindow(TRUE);
			GetDlgItem(IDC_RADIOCLOSE2)->EnableWindow(TRUE);
		}
		break;
	case 2:
		GetDlgItem(IDC_CHECKALWAYS)->EnableWindow(TRUE);
		GetDlgItem(IDC_CHECKDEFAULT)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIOFULLOPEN1)->EnableWindow(TRUE);
		GetDlgItem(IDC_RADIOFULLOPEN2)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOCLOSE2)->EnableWindow(FALSE);
		if(m_bDefault)
		{
			m_nInSuffic = 0;
			GetDlgItem(IDC_RADIOCLOSS1)->EnableWindow(FALSE);
		}
		else
		{
			GetDlgItem(IDC_RADIOCLOSS1)->EnableWindow(TRUE);
		}
		break;
	case 3:
		GetDlgItem(IDC_CHECKALWAYS)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECKDEFAULT)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOFULLOPEN1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOCLOSS1)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOFULLOPEN2)->EnableWindow(FALSE);
		GetDlgItem(IDC_RADIOCLOSE2)->EnableWindow(FALSE);
		break;
	default:
		break;
	}
}


CString PageControlModel::CtrlUnit()
{
	return GetCmbText(m_cmbSetUnit);;
}

CString PageControlModel::CtrlString()
{
	CString strRet;
	if(0 == m_nSetType)
	{
		GetDlgItem(IDC_RADIOTYPE1)->GetWindowText(strRet);
	}
	else
	{
		GetDlgItem(IDC_RADIOTYPE2)->GetWindowText(strRet);
	}
	return strRet;
}

void PageControlModel::ChangeUnit()
{
	DlgControlValve *pControlValve = dynamic_cast<DlgControlValve*>(GetParent()->GetParent());
	pControlValve->ChangeUnit(CtrlUnit());
}

void PageControlModel::ChangeType()
{
	DlgControlValve *pControlValve = dynamic_cast<DlgControlValve*>(GetParent()->GetParent());
	pControlValve->ChangeType(LossString(),CtrlString());
	ChangeUnit();
}

void PageControlModel::OnSelchangeSetUnit() 
{
	// TODO: Add your control notification handler code here
	ChangeUnit();
}

CString PageControlModel::LossString()
{
	CString strRet;
	if (1 == m_nLossType)
	{
		GetDlgItem(IDC_RADIOK)->GetWindowText(strRet);
	}
	else
	{
		GetDlgItem(IDC_RADIOCV)->GetWindowText(strRet);
	}
	return strRet;
}
