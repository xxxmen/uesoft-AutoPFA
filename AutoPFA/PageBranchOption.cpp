// PageBranchOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageBranchOption.h"
#include "Branch.h"
#include "DlgBranch.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageBranchOption dialog


PageBranchOption::PageBranchOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageBranchOption::IDD, pParent)
	,m_dlgOption(UnitSys)
	,m_UnitSys(UnitSys)
	,m_cmbFlowRate(&m_EditFlowRate)
{
	//{{AFX_DATA_INIT(PageBranchOption)
	m_strFlowRateUnit = _T("");
	m_strFlowRate = _T("");
	m_nFlowType = -1;
	//}}AFX_DATA_INIT
}


void PageBranchOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageBranchOption)
	DDX_Control(pDX, IDC_EFLOWRATE, m_EditFlowRate);
	DDX_Control(pDX, IDC_CMBFLOWUNIT, m_cmbFlowRate);
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_CBString(pDX, IDC_CMBFLOWUNIT, m_strFlowRateUnit);
	DDX_Text(pDX, IDC_EFLOWRATE, m_strFlowRate);
	DDX_Radio(pDX, IDC_RADIOVOLUMEFLOW, m_nFlowType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageBranchOption, BaseDlg)
	//{{AFX_MSG_MAP(PageBranchOption)
	ON_BN_CLICKED(IDC_RADIOVOLUMEFLOW, OnRadioVolumeflow)
	ON_BN_CLICKED(IDC_RADIOMASSFLOW, OnRadioMassflow)
	ON_CBN_SELCHANGE(IDC_CMBFLOWUNIT, OnSelchangeFlowUnit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageBranchOption message handlers

BOOL PageBranchOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageBranchOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
	InitTypeNum(m_nFlowType,m_strFlowRate,m_strFlowRateUnit,Branch::ms_ImposeFlow);

	InitFlowUnit();
	UpdateData(FALSE);
}

BOOL PageBranchOption::UpData()
{
	UpdateData(TRUE);
	SetTypeNum(m_nFlowType,m_strFlowRate,m_strFlowRateUnit,Branch::ms_ImposeFlow);
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

void PageBranchOption::InitFlowUnit()
{
	InitFlowUnitCbo(m_UnitSys,m_nFlowType,m_cmbFlowRate,m_strFlowRateUnit);
}

void PageBranchOption::OnRadioVolumeflow() 
{
	// TODO: Add your control notification handler code here
	m_nFlowType = 0;
	InitFlowUnit();
	ChangeType();
}

void PageBranchOption::OnRadioMassflow() 
{
	// TODO: Add your control notification handler code here
	m_nFlowType = 1;
	InitFlowUnit();
	ChangeType();
}

CString PageBranchOption::FlowUnit()
{
	return GetCmbText(m_cmbFlowRate);
}

CString PageBranchOption::FlowString()
{
	CString strRet;
	if(0 == m_nFlowType)
	{
		strRet.LoadString(IDS_STRVOLUMEFLOW);
	}
	else
	{
		strRet.LoadString(IDS_STRMASSFLOW);
	}
	return strRet;
}

void PageBranchOption::ChangeUnit()
{
	DlgBranch *pDlgBranch = dynamic_cast<DlgBranch*>(GetParent()->GetParent());
	pDlgBranch->ChangeUnit(FlowUnit());
}

void PageBranchOption::ChangeType()
{
	DlgBranch *pDlgBranch = dynamic_cast<DlgBranch*>(GetParent()->GetParent());
	pDlgBranch->ChangeFlowType(UnitTypeID(m_nFlowType),FlowString());
	ChangeUnit();
}

void PageBranchOption::OnSelchangeFlowUnit() 
{
	// TODO: Add your control notification handler code here
	ChangeUnit();
}
