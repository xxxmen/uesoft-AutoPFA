// DlgGenralCurve.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgGenralCurve.h"
#include "CurveWrapper.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgGenralCurve dialog


DlgGenralCurve::DlgGenralCurve(ArrayFlyWeight<13> &ref,UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: CDialog(DlgGenralCurve::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_Curve(ref)
{
	//{{AFX_DATA_INIT(DlgGenralCurve)
	// NOTE: the ClassWizard will add member initialization here
	m_strFlowUnit = _T("");
	m_strPressUnit = _T("");
	m_nPress = -1;
	m_nFlow = -1;
	//}}AFX_DATA_INIT
}


void DlgGenralCurve::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgGenralCurve)
	// NOTE: the ClassWizard will add DDX and DDV calls here
	DDX_Control(pDX, IDC_TAB, m_tab);
	DDX_Control(pDX, IDC_CMBPRESS, m_cmbPressUnit);
	DDX_Control(pDX, IDC_CMBFLOW, m_cmbFlowUnit);
	DDX_CBString(pDX, IDC_CMBFLOW, m_strFlowUnit);
	DDX_CBString(pDX, IDC_CMBPRESS, m_strPressUnit);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPress);
	DDX_Radio(pDX, IDC_RADIOVOLFLOW, m_nFlow);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgGenralCurve, CDialog)
	//{{AFX_MSG_MAP(DlgGenralCurve)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOMASSFLOW, OnRadioMassFlow)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_RADIOVOLFLOW, OnRadioVolFlow)
	ON_CBN_SELCHANGE(IDC_CMBFLOW, OnSelchangeFlow)
	ON_CBN_SELCHANGE(IDC_CMBPRESS, OnSelchangePress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgGenralCurve message handlers

BOOL DlgGenralCurve::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRJUNRAWDATA,&m_page1,IDD_PAGEPUMPDATA);
	m_tab.Show();

	Init();
	InitPage1();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgGenralCurve::Init()
{
	CurveWrapper wrapper(m_Curve);
	m_nFlow = wrapper.GetXAxisType();
	m_strFlowUnit = wrapper.GetXAxisUnit();
	m_nPress = wrapper.GetYAxisType();
	m_strPressUnit = wrapper.GetYAxisUnit();
	InitFlowUnit();
	InitPressUnit();
}

void DlgGenralCurve::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPress = 0;
	InitPressUnit();
	m_page1.m_RawData.SetHeader(PressName(m_nPress),PressUnit(),2);
}

void DlgGenralCurve::OnRadioMassFlow() 
{
	// TODO: Add your control notification handler code here
	m_nFlow = 1;
	InitFlowUnit();
	m_page1.m_RawData.SetHeader(FlowName(m_nFlow),FlowUnit(),1);
}

void DlgGenralCurve::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPress = 1;
	InitPressUnit();
	m_page1.m_RawData.SetHeader(PressName(m_nPress),PressUnit(),2);
}

void DlgGenralCurve::OnRadioVolFlow() 
{
	// TODO: Add your control notification handler code here
	m_nFlow = 0;
	InitFlowUnit();
	m_page1.m_RawData.SetHeader(FlowName(m_nFlow),FlowUnit(),1);
}

void DlgGenralCurve::OnSelchangeFlow() 
{
	// TODO: Add your control notification handler code here
	m_page1.m_RawData.SetUnit(FlowUnit(),1);
}


void DlgGenralCurve::OnSelchangePress() 
{
	// TODO: Add your control notification handler code here
	m_page1.m_RawData.SetUnit(PressUnit(),2);
}

void DlgGenralCurve::InitFlowUnit()
{
	InitFlowUnitCbo(m_UnitSys,m_nFlow,m_cmbFlowUnit,m_strFlowUnit);
	InitPressUnitCbo(m_UnitSys,m_nPress,m_cmbPressUnit,m_strPressUnit);
}

void DlgGenralCurve::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPress,m_cmbPressUnit,m_strPressUnit);
}


CString DlgGenralCurve::FlowUnit()
{
	return GetCmbText(m_cmbFlowUnit);
}

CString DlgGenralCurve::PressUnit()
{
	return GetCmbText(m_cmbPressUnit);
}


void DlgGenralCurve::InitPage1()
{
	m_page1.m_RawData.InsertColumn(_T("  "),_T(""));
	m_page1.m_RawData.InsertColumn(FlowName(m_nFlow),FlowUnit());
	m_page1.m_RawData.InsertColumn(PressName(m_nPress),PressUnit());
	m_page1.m_RawData.TableStatus();
	m_page1.m_RawData.SetDataNum(100);
	m_page1.Init(m_Curve);
}

void DlgGenralCurve::OnOK() 
{
	// TODO: Add extra validation here
	UpData();
	CDialog::OnOK();
}

void DlgGenralCurve::UpData()
{
	UpdateData(TRUE);
	CurveWrapper wrapper(m_Curve);
	wrapper.SetXAxisType(m_nFlow);
	wrapper.SetXAxisUnit(m_strFlowUnit);
	wrapper.SetYAxisType(m_nPress);
	wrapper.SetYAxisUnit(m_strPressUnit);
	StrArray<2> UnitArray;
	UnitArray.Data(m_strFlowUnit,0);
	UnitArray.Data(m_strPressUnit,1);
	Jun::ms_RawData.m_Unit.SetData(UnitArray);
	m_page1.UpData();
}

