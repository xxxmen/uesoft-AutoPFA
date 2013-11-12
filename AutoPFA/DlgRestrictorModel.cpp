// DlgRestrictorModel.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgRestrictorModel.h"
#include "RestrictorWrapper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgRestrictorModel dialog


DlgRestrictorModel::DlgRestrictorModel(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgRestrictorModel::IDD, pParent)
	,m_UnitSys(UnitSys)
	,m_cmbAreaUnit(&m_EditArea)
{
	//{{AFX_DATA_INIT(DlgRestrictorModel)
	m_bModel = FALSE;
	m_strAreaUnit = _T("");
	m_strArea = _T("");
	m_strInFlowCD = _T("");
	m_strOutlowCD = _T("");
	//}}AFX_DATA_INIT
}


void DlgRestrictorModel::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgRestrictorModel)
	DDX_Control(pDX, IDC_EOUTFLOWCD, m_EditOutFlowCD);
	DDX_Control(pDX, IDC_EINFLOWCD, m_EditInFlowCD);
	DDX_Control(pDX, IDC_EFLOWAREA, m_EditArea);
	DDX_Control(pDX, IDC_CMBAREAUNIT, m_cmbAreaUnit);
	DDX_Check(pDX, IDC_CHECKMODEL, m_bModel);
	DDX_CBString(pDX, IDC_CMBAREAUNIT, m_strAreaUnit);
	DDX_Text(pDX, IDC_EFLOWAREA, m_strArea);
	DDX_Text(pDX, IDC_EINFLOWCD, m_strInFlowCD);
	DDX_Text(pDX, IDC_EOUTFLOWCD, m_strOutlowCD);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgRestrictorModel, BaseDlg)
	//{{AFX_MSG_MAP(DlgRestrictorModel)
	ON_BN_CLICKED(IDC_CHECKMODEL, OnCheckModel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgRestrictorModel message handlers

BOOL DlgRestrictorModel::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	InitUnitCbo(m_UnitSys,Area,m_cmbAreaUnit,m_strAreaUnit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgRestrictorModel::Init(ArrayFlyWeight<5> &ref)
{
	RestrictorWrapper wrapper(ref);
	m_bModel = wrapper.GetModel();
	m_strInFlowCD = wrapper.GetInFlowCD();
	m_strOutlowCD = wrapper.GetOutFlowCD();
	wrapper.GetArea(m_strArea,m_strAreaUnit);
	ModelStatus();
	UpdateData(FALSE);
}

BOOL DlgRestrictorModel::UpData(ArrayFlyWeight<5> &ref)
{
	UpdateData(TRUE);
	RestrictorWrapper wrapper(ref);
	wrapper.SetModel(m_bModel);
	wrapper.SetInFlowCD(m_strInFlowCD);
	wrapper.SetOutFlowCD(m_strOutlowCD);
	wrapper.SetArea(m_strArea,m_strAreaUnit);
	return TRUE;
}

void DlgRestrictorModel::ModelStatus()
{
	m_EditOutFlowCD.EnableWindow(m_bModel);
	m_EditInFlowCD.EnableWindow(m_bModel);
	m_EditArea.EnableWindow(m_bModel);
	m_cmbAreaUnit.EnableWindow(m_bModel);
	if(!m_bModel)
	{
		m_strArea.Empty();
		m_strInFlowCD.Empty();
		m_strOutlowCD.Empty();
	}
}

void DlgRestrictorModel::OnCheckModel() 
{
	// TODO: Add your control notification handler code here
	m_bModel = !m_bModel;
	ModelStatus();
	UpdateData(FALSE);
}
