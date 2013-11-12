// PagePipeOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PagePipeOption.h"
#include "Pipe.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PagePipeOption dialog


PagePipeOption::PagePipeOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PagePipeOption::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbFlowUnit(&m_EditFlow)
{
	//{{AFX_DATA_INIT(PagePipeOption)
	m_strFlowUnit = _T("");
	m_strFitFactor = _T("");
	m_strFlowValue = _T("");
	m_strParaNum = _T("");
	m_strPipeFactor = _T("");
	m_bPartFull = FALSE;
	m_strPartFull = _T("");
	//}}AFX_DATA_INIT
	m_nCurFlowType = 0;
}


void PagePipeOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PagePipeOption)
	DDX_Control(pDX, IDC_EFLOWVALUE, m_EditFlow);
	DDX_Control(pDX, IDC_CMBFLOWUNIT, m_cmbFlowUnit);
	DDX_Control(pDX, IDC_CMBFLOWTYPE, m_cmbFlowType);
	DDX_CBString(pDX, IDC_CMBFLOWUNIT, m_strFlowUnit);
	DDX_Text(pDX, IDC_EFITFACTOR, m_strFitFactor);
	DDX_Text(pDX, IDC_EFLOWVALUE, m_strFlowValue);
	DDX_Text(pDX, IDC_EPARANUM, m_strParaNum);
	DDX_Text(pDX, IDC_EPIPEFACTOR, m_strPipeFactor);
	DDX_Check(pDX, IDC_CHECKPARTFULL, m_bPartFull);
	DDX_Text(pDX, IDC_EDITPARTFULL, m_strPartFull);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PagePipeOption, BaseDlg)
	//{{AFX_MSG_MAP(PagePipeOption)
	ON_CBN_SELCHANGE(IDC_CMBFLOWTYPE, OnSelchangeType)
	ON_BN_CLICKED(IDC_CHECKPARTFULL, OnCheckPartFull)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PagePipeOption message handlers
void PagePipeOption::Init()
{
	InitTypeNum(m_nCurFlowType,m_strFlowValue,m_strFlowUnit,Pipe::ms_InitFlow);
	InitDataCmb(Pipe::ms_FlowType,3,m_cmbFlowType,m_nCurFlowType);
	m_strPipeFactor = Pipe::ms_PipeFactor.GetValue();
	m_strFitFactor  = Pipe::ms_FitFactor.GetValue();
	m_strParaNum    = Pipe::ms_ParaNum.GetValue();
	int n = Pipe::ms_PartFull.GetnValue();
	if(n <= 0)
	{
		m_bPartFull = FALSE;
	}
	else
	{
		m_bPartFull = TRUE;
	}
	m_strPartFull = Pipe::ms_PartFull.GetValue();
	PartFullStatus();
	SetFlowUnit();
	UpdateData(FALSE);
}

BOOL PagePipeOption::UpData()
{
	UpdateData(TRUE);
	SetTypeNum(m_nCurFlowType,m_strFlowValue,m_strFlowUnit,Pipe::ms_InitFlow);
	Pipe::ms_PipeFactor.SetValue(m_strPipeFactor);
	Pipe::ms_FitFactor.SetValue(m_strFitFactor);
	Pipe::ms_ParaNum.SetValue(m_strParaNum);
	if(m_bPartFull)
	{
		Pipe::ms_PartFull.SetValue(m_strPartFull);
	}
	else
	{
		Pipe::ms_PartFull.SetValue(-1);
	}
	return TRUE;
}

void PagePipeOption::SetFlowUnit()
{
	switch(m_nCurFlowType) {
	case 0:
		InitUnitCbo(m_UnitSys,VolumetricFlow,m_cmbFlowUnit,m_strFlowUnit);
		break;
	case 1:
		InitUnitCbo(m_UnitSys,MassFlow,m_cmbFlowUnit,m_strFlowUnit);
		break;
	case 2:
		InitUnitCbo(m_UnitSys,Velocity,m_cmbFlowUnit,m_strFlowUnit);
		break;
	default:
		ASSERT(FALSE);
	}
}

void PagePipeOption::OnSelchangeType() 
{
	// TODO: Add your control notification handler code here
	GetCurKey(m_cmbFlowType,m_nCurFlowType);
	SetFlowUnit();
}

void PagePipeOption::PartFullStatus()
{
	GetDlgItem(IDC_EDITPARTFULL)->EnableWindow(m_bPartFull);
	if(m_bPartFull)
	{
		GetDlgItem(IDC_EDITPARTFULL)->SetWindowText(_T("100"));
	}
	else
	{
		m_strPartFull.Empty();
		GetDlgItem(IDC_EDITPARTFULL)->SetWindowText(_T(""));
	}
}

void PagePipeOption::OnCheckPartFull() 
{
	// TODO: Add your control notification handler code here
	m_bPartFull = !m_bPartFull;
	PartFullStatus();
}
