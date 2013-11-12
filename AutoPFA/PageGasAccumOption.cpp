// PageGasAccumOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageGasAccumOption.h"
#include "GasAccumulator.h"
#include "OptionTypeNumWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageGasAccumOption dialog


PageGasAccumOption::PageGasAccumOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageGasAccumOption::IDD, pParent)
	,m_dlgOption(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbInitPress(&m_EditInitPress)
{
	//{{AFX_DATA_INIT(PageGasAccumOption)
	m_bInitPress = FALSE;
	m_strPressUnit = _T("");
	m_strInitPress = _T("");
	m_nPressType = -1;
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void PageGasAccumOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageGasAccumOption)
	DDX_Control(pDX, IDC_EINITPRESS, m_EditInitPress);
	DDX_Control(pDX, IDC_CMBRESSUNIT, m_cmbInitPress);
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Check(pDX, IDC_CHECKINITPRESS, m_bInitPress);
	DDX_CBString(pDX, IDC_CMBRESSUNIT, m_strPressUnit);
	DDX_Text(pDX, IDC_EINITPRESS, m_strInitPress);
	DDX_Radio(pDX, IDC_RADIOHEAD, m_nPressType);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageGasAccumOption, BaseDlg)
	//{{AFX_MSG_MAP(PageGasAccumOption)
	ON_BN_CLICKED(IDC_RADIOHEAD, OnRadioHead)
	ON_BN_CLICKED(IDC_RADIOPRESS, OnRadioPress)
	ON_BN_CLICKED(IDC_CHECKINITPRESS, OnCheckInitpress)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageGasAccumOption message handlers

BOOL PageGasAccumOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageGasAccumOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	OptionTypeNumWrapper wrapper(GasAccumulator::ms_InitPress);
	m_bInitPress = wrapper.GetModel();
	wrapper.GetPress(m_nPressType,m_strInitPress,m_strPressUnit);
	if(m_nSpecial != 0)
		m_nSpecial -= 2;

	InitPressUnit();
	SetInitPressStatus();
	UpdateData(FALSE);
}

BOOL PageGasAccumOption::UpData()
{
	UpdateData(TRUE);
	if(m_nSpecial != 0)
		m_nSpecial += 2;
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	OptionTypeNumWrapper wrapper(GasAccumulator::ms_InitPress);
	wrapper.SetModel(m_bInitPress);
	wrapper.SetPress(m_nPressType,m_strInitPress,m_strPressUnit);
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

void PageGasAccumOption::OnRadioHead() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}

void PageGasAccumOption::OnRadioPress() 
{
	// TODO: Add your control notification handler code here
	m_nPressType = 1;
	InitPressUnit();
}

void PageGasAccumOption::OnCheckInitpress() 
{
	// TODO: Add your control notification handler code here
	m_bInitPress = !m_bInitPress;
	SetInitPressStatus();
}

void PageGasAccumOption::InitPressUnit()
{
	InitPressUnitCbo(m_UnitSys,m_nPressType,m_cmbInitPress,m_strPressUnit);
}

void PageGasAccumOption::SetInitPressStatus()
{
	GetDlgItem(IDC_RADIOHEAD)->EnableWindow(m_bInitPress);
	GetDlgItem(IDC_RADIOPRESS)->EnableWindow(m_bInitPress);
	m_EditInitPress.EnableWindow(m_bInitPress);
	m_cmbInitPress.EnableWindow(m_bInitPress);
}
