// PageGeneralModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pagegeneralmodel.h"
#include "General.h"
#include "CurveWrapper.h"
#include "DlgGenralCurve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageGeneralModel dialog


PageGeneralModel::PageGeneralModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageGeneralModel::IDD, pParent)
	,m_dlgBasisArea(UnitSys)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(PageGeneralModel)
	m_strCvOrK = _T("");
	m_nLossType = 0;
	//}}AFX_DATA_INIT
}


void PageGeneralModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageGeneralModel)
	DDX_Control(pDX, IDC_TABKR, m_tab);
	DDX_Control(pDX, IDC_ECVORK, m_EditCvOrK);
	DDX_Control(pDX, IDC_BOX, m_Box);
	DDX_Text(pDX, IDC_ECVORK, m_strCvOrK);
	DDX_Radio(pDX, IDC_RADIOCONSTK, m_nLossType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageGeneralModel, BaseDlg)
	//{{AFX_MSG_MAP(PageGeneralModel)
	ON_BN_CLICKED(IDC_RADIOCONSTK, OnRadioConstK)
	ON_BN_CLICKED(IDC_RADIORCURVE, OnRadioRCurve)
	ON_BN_CLICKED(IDC_RADIOVARIABLEK, OnRadioVariableK)
	ON_BN_CLICKED(IDC_CURVEDATA, OnCurveData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageGeneralModel message handlers

BOOL PageGeneralModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgBasisArea.Create(IDD_DLGBASISAREA,this);
	Combine(this,m_Box,m_dlgBasisArea);
	m_tab.AddPage(_T("图表"),&m_page1,IDD_PAGECHART);
	m_tab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageGeneralModel::OnRadioConstK() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 0;
	LossStatus();
}

void PageGeneralModel::OnRadioRCurve() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 1;
	LossStatus();
}

void PageGeneralModel::OnRadioVariableK() 
{
	// TODO: Add your control notification handler code here
	m_nLossType = 2;
	LossStatus();
}

void PageGeneralModel::LossStatus()
{
	if(m_nLossType == 0)
	{
		GetDlgItem(IDC_STATICCVORK)->ShowWindow(SW_SHOW);
		GetDlgItem(IDC_CURVEDATA)->ShowWindow(SW_HIDE);
		m_EditCvOrK.ShowWindow(SW_SHOW);
		m_tab.ShowWindow(SW_HIDE);
	}
	else
	{
		GetDlgItem(IDC_STATICCVORK)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_CURVEDATA)->ShowWindow(SW_SHOW);
		m_EditCvOrK.ShowWindow(SW_HIDE);
		m_tab.ShowWindow(SW_SHOW);
	}
}

void PageGeneralModel::Init()
{
	CurveWrapper wrapper(General::ms_Curve);
	m_nLossType = wrapper.GetLossType()-1;//1：K系数恒定，2：K系数变化，3：阻力曲线。
	wrapper.InitChart(m_page1,Jun::ms_RawData);
	if(m_nLossType<0)
		m_nLossType = 0;
	m_strCvOrK = General::ms_KOrCv.GetValue();
	m_dlgBasisArea.Init(General::ms_BasisArea);
	LossStatus();
	UpdateData(FALSE);
}

BOOL PageGeneralModel::UpData()
{
	UpdateData(TRUE);
	CurveWrapper wrapper(General::ms_Curve);
	wrapper.SetLossType(m_nLossType+1);
	General::ms_KOrCv.SetValue(m_strCvOrK);
	m_dlgBasisArea.UpData(General::ms_BasisArea);
	return TRUE;
}

void PageGeneralModel::OnCurveData() 
{
	// TODO: Add your control notification handler code here
	DlgGenralCurve dlgCurve(General::ms_Curve,m_UnitSys);
	if(IDOK == dlgCurve.DoModal())
	{
		CurveWrapper wrapper(General::ms_Curve);
		wrapper.InitChart(m_page1,Jun::ms_RawData);
	}
}
