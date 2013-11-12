// pagereliefmodel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagereliefmodel.h"
#include "ReliefValve.h"
#include "CurveWrapper.h"
#include "DlgReliefValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageReliefModel dialog


PageReliefModel::PageReliefModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageReliefModel::IDD, pParent)
	,m_dlgBasisArea(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbExitPress(&m_EditExitPress)
	,m_cmbCrackPress(&m_EditCrackPress)
{
	//{{AFX_DATA_INIT(PageReliefModel)
	m_strCrackPressUnit = _T("");
	m_strExitPressUnit = _T("");
	m_strCrackPress = _T("");
	m_strCvOrK = _T("");
	m_strExitPress = _T("");
	m_nPressType = 0;
	m_nLossType = 0;
	m_nType = 1;
	//}}AFX_DATA_INIT
}


void PageReliefModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageReliefModel)
	DDX_Control(pDX, IDC_TABCV, m_tab1);
	DDX_Control(pDX, IDC_EEXITPRESS, m_EditExitPress);
	DDX_Control(pDX, IDC_ECVORK, m_EditCvOrK);
	DDX_Control(pDX, IDC_ECRACKPRESS, m_EditCrackPress);
	DDX_Control(pDX, IDC_CMBEXITPRESSUNIT, m_cmbExitPress);
	DDX_Control(pDX, IDC_CMBCRACKPRESSUNIT, m_cmbCrackPress);
	DDX_Control(pDX, IDC_BOX, m_Box);
	DDX_CBString(pDX, IDC_CMBCRACKPRESSUNIT, m_strCrackPressUnit);
	DDX_CBString(pDX, IDC_CMBEXITPRESSUNIT, m_strExitPressUnit);
	DDX_Text(pDX, IDC_ECRACKPRESS, m_strCrackPress);
	DDX_Text(pDX, IDC_ECVORK, m_strCvOrK);
	DDX_Text(pDX, IDC_EEXITPRESS, m_strExitPress);
	DDX_Radio(pDX, IDC_RADIOABSHEAD, m_nPressType);
	DDX_Radio(pDX, IDC_RADIOCONSTCV, m_nLossType);
	DDX_Radio(pDX, IDC_RADIOINTER, m_nType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageReliefModel, BaseDlg)
	//{{AFX_MSG_MAP(PageReliefModel)
	ON_BN_CLICKED(IDC_RADIOEXIT, OnRadioExit)
	ON_BN_CLICKED(IDC_RADIOINLINE, OnRadioInline)
	ON_BN_CLICKED(IDC_RADIOINTER, OnRadioInter)
	ON_BN_CLICKED(IDC_RADIOVARIABLECV, OnRadioVariableCv)
	ON_BN_CLICKED(IDC_RADIOABSHEAD, OnRadioAbsHead)
	ON_BN_CLICKED(IDC_RADIOABSPRESS, OnRadioAbsPress)
	ON_BN_CLICKED(IDC_RADIOCONSTCV, OnRadioConstCv)
	ON_BN_CLICKED(IDC_RADIOCONSTK, OnRadioConstK)
	ON_BN_CLICKED(IDC_RADIODIFFHEAD, OnRadioDiffHead)
	ON_BN_CLICKED(IDC_RADIODIFFPRESS, OnRadioDiffPress)
	ON_BN_CLICKED(IDC_CURVEDATA, OnCurveData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageReliefModel message handlers

BOOL PageReliefModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgBasisArea.Create(IDD_DLGBASISAREA,this);
	Combine(this,m_Box,m_dlgBasisArea);
	m_tab1.AddPage(_T("图表"),&m_page1,IDD_PAGECHART);
	m_tab1.Show();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageReliefModel::Init()
{
	m_nType = ReliefValve::ms_Type.GetnValue()-1;
	m_nPressType = ReliefValve::ms_CrackExitPress.GetnValue();
	InitNum(m_strCrackPress,m_strCrackPressUnit,ReliefValve::ms_CrackExitPress,1);
	InitNum(m_strExitPress,m_strExitPressUnit,ReliefValve::ms_CrackExitPress,3);
	m_strCvOrK = ReliefValve::ms_KOrCv.GetValue();
	m_dlgBasisArea.Init(ReliefValve::ms_BasisArea);
	CurveWrapper wrapper(ReliefValve::ms_Curve);
	m_nLossType = wrapper.GetLossType();
	wrapper.InitChart(m_page1,Jun::ms_RawData);

	InitPressUnit();
    SetExitStatus();
	SetLossStatus();
	UpdateData(FALSE);
}

BOOL PageReliefModel::UpData()
{
	UpdateData(TRUE);
	ReliefValve::ms_Type.SetValue(m_nType+1);
	ReliefValve::ms_CrackExitPress.SetValue(m_nPressType);
	ReliefValve::ms_CrackExitPress.SetValue(m_strCrackPress,1);
	ReliefValve::ms_CrackExitPress.SetValue(m_strCrackPressUnit,2);
	ReliefValve::ms_CrackExitPress.SetValue(m_strExitPress,3);
	ReliefValve::ms_CrackExitPress.SetValue(m_strExitPressUnit,4);
	ReliefValve::ms_KOrCv.SetValue(m_strCvOrK);
	m_dlgBasisArea.UpData(ReliefValve::ms_BasisArea);
	CurveWrapper wrapper(ReliefValve::ms_Curve);
	wrapper.SetLossType(m_nLossType);
	return TRUE;
}

void PageReliefModel::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbCrackPress,m_strCrackPressUnit);
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbExitPress,m_strExitPressUnit);
}

void PageReliefModel::OnRadioExit() 
{
	// TODO: Add your control notification handler code here
	m_nType = 1;
	SetExitStatus();
}

void PageReliefModel::OnRadioInline() 
{
	// TODO: Add your control notification handler code here
	m_nType = 2;
	SetExitStatus();
}

void PageReliefModel::OnRadioInter() 
{
	// TODO: Add your control notification handler code here
	m_nType = 0;
	SetExitStatus();
}

void PageReliefModel::OnRadioVariableCv() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 2;
	SetLossStatus();
}

void PageReliefModel::OnRadioAbsHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	InitPressUnit();
}

void PageReliefModel::OnRadioAbsPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}

void PageReliefModel::OnRadioConstCv() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 0;
	SetLossStatus();
}

void PageReliefModel::OnRadioConstK() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 1;
	SetLossStatus();
	
}

void PageReliefModel::OnRadioDiffHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 2;
	InitPressUnit();
}

void PageReliefModel::OnRadioDiffPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 3;
	InitPressUnit();
}

void PageReliefModel::SetExitStatus()
{
	if(m_nType ==0)
	{//内部安全阀（internal relief）
		GetDlgItem(IDC_STATICEXIT)->EnableWindow(FALSE);
		m_EditExitPress.EnableWindow(FALSE);
		m_cmbExitPress.EnableWindow(FALSE);
		m_strExitPress.Empty();
		m_strExitPressUnit.Empty();
	}
	else
	{
		GetDlgItem(IDC_STATICEXIT)->EnableWindow(TRUE);
		m_EditExitPress.EnableWindow(TRUE);
		m_cmbExitPress.EnableWindow(TRUE);
	}
}

void PageReliefModel::SetLossStatus()
{
	CString strText;
	if(m_nLossType==0)
	{//流量系数模型
		strText.LoadString(IDS_STRCONSTCV);
		GetDlgItem(IDC_STATICCVORK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CURVEDATA)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATICCVORK)->SetWindowText(strText);
		m_EditCvOrK.ShowWindow(SW_SHOW);
		m_tab1.ShowWindow(SW_HIDE);
	}
	else if(m_nLossType==1)
	{//K系数模型
		strText.LoadString(IDS_STRCONSTK);
		GetDlgItem(IDC_STATICCVORK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CURVEDATA)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_STATICCVORK)->SetWindowText(strText);
		m_EditCvOrK.ShowWindow(SW_SHOW);
		m_tab1.ShowWindow(SW_HIDE);
	}
	else
	{//变流量系数
		GetDlgItem(IDC_STATICCVORK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CURVEDATA)->ShowWindow(SW_SHOW);
		m_EditCvOrK.ShowWindow(SW_HIDE);
		m_tab1.ShowWindow(SW_SHOW);
	}

	DlgReliefValve *pCheck = dynamic_cast<DlgReliefValve*>(GetParent()->GetParent());
	pCheck->ChangeType(strText,IsShowTrans());
}

CString PageReliefModel::LossString()
{
	CString strRet;
	GetDlgItem(IDC_STATICCVORK)->GetWindowText(strRet);
	return strRet;
}

BOOL PageReliefModel::IsShowTrans()
{
	if(2 == m_nLossType)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

void PageReliefModel::OnCurveData() 
{
	// TODO: Add your control notification handler code here
	
}
