// PageAssignedFlowOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pageassignedflowoption.h"
#include "AssignedFlow.h"
#include "OptionTypeNumWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageAssignedFlowOption dialog


PageAssignedFlowOption::PageAssignedFlowOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageAssignedFlowOption::IDD, pParent)
	,m_dlgOption(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbPressUnit(&m_EditPress)
{
	//{{AFX_DATA_INIT(PageAssignedFlowOption)
	m_bInitPress = FALSE;
	m_strPressUnit = _T("");
	m_strInitPress = _T("");
	m_strK = _T("");
	m_nPressType = -1;
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void PageAssignedFlowOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageAssignedFlowOption)
	DDX_Control(pDX, IDC_EINITPRESS, m_EditPress);
	DDX_Control(pDX, IDC_CMBRESSUNIT, m_cmbPressUnit);
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Check(pDX, IDC_CHECKINITPRESS, m_bInitPress);
	DDX_CBString(pDX, IDC_CMBRESSUNIT, m_strPressUnit);
	DDX_Text(pDX, IDC_EINITPRESS, m_strInitPress);
	DDX_Text(pDX, IDC_EK, m_strK);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPressType);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageAssignedFlowOption, BaseDlg)
	//{{AFX_MSG_MAP(PageAssignedFlowOption)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_CHECKINITPRESS, OnCheckInitpress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageAssignedFlowOption message handlers

BOOL PageAssignedFlowOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageAssignedFlowOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	m_strK = AssignedFlow::ms_K.GetValue();
	OptionTypeNumWrapper wrapper(AssignedFlow::ms_InitPress);
	m_bInitPress = wrapper.GetModel();
	wrapper.GetPress(m_nPressType,m_strInitPress,m_strPressUnit);

	InitPressUnit();
	SetInitPressStatus();
	UpdateData(FALSE);
	
}

BOOL PageAssignedFlowOption::UpData()
{
	UpdateData(TRUE);
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	AssignedFlow::ms_K.SetValue(m_strK);
	OptionTypeNumWrapper wrapper(AssignedFlow::ms_InitPress);
	wrapper.SetModel(m_bInitPress);
	wrapper.SetPress(m_nPressType,m_strInitPress,m_strPressUnit);
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

void PageAssignedFlowOption::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 0;
	InitPressUnit();
}


void PageAssignedFlowOption::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}

void PageAssignedFlowOption::OnCheckInitpress() 
{
	// TODO: Add your control notification handler code here
	m_bInitPress = !m_bInitPress;
	SetInitPressStatus();
}

void PageAssignedFlowOption::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbPressUnit,m_strPressUnit);
}

void PageAssignedFlowOption::SetInitPressStatus()
{
	GetDlgItem(IDC_RADIOHEAD)->EnableWindow(m_bInitPress);
	GetDlgItem(IDC_RADIOPRESS)->EnableWindow(m_bInitPress);
	m_EditPress.EnableWindow(m_bInitPress);
	m_cmbPressUnit.EnableWindow(m_bInitPress);
}
