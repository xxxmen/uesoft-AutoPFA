// AssignFlowPage1.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "AssignFlowPage1.h"
#include "AssignedFlow.h"
#include "DlgAssignedFlow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// AssignFlowPage1 dialog


AssignFlowPage1::AssignFlowPage1(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(AssignFlowPage1::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbFlowUnit(&m_EditFlowRate)
{
	//{{AFX_DATA_INIT(AssignFlowPage1)
	m_strFlowUnit = _T("");
	m_strFlowRate = _T("");
	m_nDirType = 0;
	m_nFlowType = 0;
	//}}AFX_DATA_INIT
	m_FlowType = VolumetricFlow;
}


void AssignFlowPage1::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(AssignFlowPage1)
	DDX_Control(pDX, IDC_EFLOWRATE, m_EditFlowRate);
	DDX_Control(pDX, IDC_CMBFLOWUNIT, m_cmbFlowUnit);
	DDX_CBString(pDX, IDC_CMBFLOWUNIT, m_strFlowUnit);
	DDX_Text(pDX, IDC_EFLOWRATE, m_strFlowRate);
	DDX_Radio(pDX, IDC_RADIOIN, m_nDirType);
	DDX_Radio(pDX, IDC_RADIOVOLUMEFLOW, m_nFlowType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(AssignFlowPage1, BaseDlg)
	//{{AFX_MSG_MAP(AssignFlowPage1)
	ON_BN_CLICKED(IDC_RADIOVOLUMEFLOW, OnRadioVolumeFlow)
	ON_BN_CLICKED(IDC_RADIOMASSFLOW, OnRadioMassFlow)
	ON_CBN_SELCHANGE(IDC_CMBFLOWUNIT, OnSelchangeFlowunit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// AssignFlowPage1 message handlers

BOOL AssignFlowPage1::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void AssignFlowPage1::OnRadioVolumeFlow() 
{
	// TODO: Add your control notification handler code here
	m_nFlowType = 0;
	InitFlowUnit();
	DlgAssignedFlow *pAssignFlow = dynamic_cast<DlgAssignedFlow*>(GetParent()->GetParent());
	pAssignFlow->ChangeFlowType(FlowType(),FlowString());
	ChangeUnit();
	
}

void AssignFlowPage1::OnRadioMassFlow() 
{
	// TODO: Add your control notification handler code here
	m_nFlowType = 1;
	InitFlowUnit();
	DlgAssignedFlow *pAssignFlow = dynamic_cast<DlgAssignedFlow*>(GetParent()->GetParent());
	pAssignFlow->ChangeFlowType(FlowType(),FlowString());
	ChangeUnit();
}

void AssignFlowPage1::Init()
{
	m_nDirType = AssignedFlow::ms_FlowDir.GetnValue();

	InitTypeNum(m_nFlowType,m_strFlowRate,m_strFlowUnit,AssignedFlow::ms_Flow);
	InitFlowUnit();
	UpdateData(FALSE);
}

BOOL AssignFlowPage1::UpData()
{
	UpdateData(TRUE);
	AssignedFlow::ms_FlowDir.SetValue(m_nDirType);
	
	SetTypeNum(m_nFlowType,m_strFlowRate,m_strFlowUnit,AssignedFlow::ms_Flow);

	return TRUE;
}

void AssignFlowPage1::InitFlowUnit()
{
	m_FlowType = InitFlowUnitCbo(m_UnitSys,m_nFlowType,m_cmbFlowUnit,m_strFlowUnit);
}

BOOL AssignFlowPage1::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	//屏蔽对话框的“按ESC和Enter键退出"
	if(WM_KEYDOWN ==	pMsg->message)
	{
		int nKey = (int) pMsg->wParam;
		if(VK_ESCAPE == nKey||VK_RETURN == nKey)
			return TRUE;
	}
	return BaseDlg::PreTranslateMessage(pMsg);
}

UnitTypeID AssignFlowPage1::FlowType()
{
	return m_FlowType;
}

CString AssignFlowPage1::FlowUnit()
{
	return GetCmbText(m_cmbFlowUnit);
}

CString AssignFlowPage1::FlowString()
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

void AssignFlowPage1::OnSelchangeFlowunit() 
{
	// TODO: Add your control notification handler code here
	ChangeUnit();
}

void AssignFlowPage1::ChangeUnit()
{
	DlgAssignedFlow *pAssignFlow = dynamic_cast<DlgAssignedFlow*>(GetParent()->GetParent());
	pAssignFlow->ChangeUnit(FlowUnit());
}
