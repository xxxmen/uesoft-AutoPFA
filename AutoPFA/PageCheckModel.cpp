// PageCheckModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagecheckmodel.h"
#include "CheckValve.h"
#include "CurveWrapper.h"
#include "DlgCheckValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageCheckModel dialog


PageCheckModel::PageCheckModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageCheckModel::IDD, pParent)
	,m_dlgBasisArea(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbPressUnit(&m_EditPress)
	,m_cmbVelocityUnit(&m_EditVelocity)
{
	//{{AFX_DATA_INIT(PageCheckModel)
	m_strPressUnit = _T("");
	m_strVelocityUnit = _T("");
	m_strCvOrK = _T("");
	m_strPress = _T("");
	m_strVelocity = _T("");
	m_nPressType = -1;
	m_nLossType = -1;
	//}}AFX_DATA_INIT
}


void PageCheckModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageCheckModel)
	DDX_Control(pDX, IDC_EVELOCITY, m_EditVelocity);
	DDX_Control(pDX, IDC_EDEFFICPRESS, m_EditPress);
	DDX_Control(pDX, IDC_ECVORK, m_EditCvOrK);
	DDX_Control(pDX, IDC_CMBVELOCITYUNIT, m_cmbVelocityUnit);
	DDX_Control(pDX, IDC_CMBDEFFICPRESSUNIT, m_cmbPressUnit);
	DDX_Control(pDX, IDC_BOX, m_Box);
	DDX_CBString(pDX, IDC_CMBDEFFICPRESSUNIT, m_strPressUnit);
	DDX_CBString(pDX, IDC_CMBVELOCITYUNIT, m_strVelocityUnit);
	DDX_Text(pDX, IDC_ECVORK, m_strCvOrK);
	DDX_Text(pDX, IDC_EDEFFICPRESS, m_strPress);
	DDX_Text(pDX, IDC_EVELOCITY, m_strVelocity);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPressType);
	DDX_Radio(pDX, IDC_RADIOCONSTCV, m_nLossType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageCheckModel, BaseDlg)
	//{{AFX_MSG_MAP(PageCheckModel)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_RADIOCONSTCV, OnRadioConstCv)
	ON_BN_CLICKED(IDC_RADIOCONSTK, OnRadioConstK)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageCheckModel message handlers

BOOL PageCheckModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgBasisArea.Create(IDD_DLGBASISAREA,this);
	Combine(this,m_Box,m_dlgBasisArea);

	InitUnitCbo(m_UnitSys,Velocity,m_cmbVelocityUnit,m_strVelocityUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageCheckModel::Init()
{
	CurveWrapper wrapper(CheckValve::ms_Curve);
	m_nLossType = wrapper.GetLossType();
	InitTypeNum(m_nPressType,m_strPress,m_strPressUnit,CheckValve::ms_ReOpenPress);
	m_strCvOrK = CheckValve::ms_KOrCv.GetValue();
	m_dlgBasisArea.Init(CheckValve::ms_BasisArea);
	InitNum(m_strVelocity,m_strVelocityUnit,CheckValve::ms_CloseVel);
	InitPressUnit();
	UpdateData(FALSE);
}

BOOL PageCheckModel::UpData()
{
	UpdateData(TRUE);
	CurveWrapper wrapper(CheckValve::ms_Curve);
	wrapper.SetLossType(m_nLossType);
	SetTypeNum(m_nPressType,m_strPress,m_strPressUnit,CheckValve::ms_ReOpenPress);
	CheckValve::ms_KOrCv.SetValue(m_strCvOrK);
	m_dlgBasisArea.UpData(CheckValve::ms_BasisArea);
	SetNum(m_strVelocity,m_strVelocityUnit,CheckValve::ms_CloseVel);
	return TRUE;
}

void PageCheckModel::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	InitPressUnit();
}

void PageCheckModel::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}

void PageCheckModel::OnRadioConstCv() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 0;
	LossStatus();
}

void PageCheckModel::OnRadioConstK() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 1;
	LossStatus();
}

void PageCheckModel::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbPressUnit,m_strPressUnit);
}

void PageCheckModel::LossStatus()
{
	CString strText;
	if(0== m_nLossType)
	{
		strText.LoadString(IDS_STRCONSTCV);
	}
	else
	{
		strText.LoadString(IDS_STRCONSTK);
	}
	GetDlgItem(IDC_STATICCVORK)->SetWindowText(strText);
	DlgCheckValve *pCheck = dynamic_cast<DlgCheckValve*>(GetParent()->GetParent());
	pCheck->ChangeType(strText);
}

CString PageCheckModel::LossString()
{
	CString strRet;
	GetDlgItem(IDC_STATICCVORK)->GetWindowText(strRet);
	return strRet;
}