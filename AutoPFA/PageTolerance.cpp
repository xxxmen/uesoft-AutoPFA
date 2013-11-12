// PageTolerance.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageTolerance.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTolerance dialog


PageTolerance::PageTolerance(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageTolerance::IDD, pParent)
	,m_PressTol(UnitSys,Pressure)
	,m_FlowTol(UnitSys,VolumetricFlow)
{
	//{{AFX_DATA_INIT(PageTolerance)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageTolerance::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTolerance)
	DDX_Control(pDX, IDC_BOX2, m_Box2);
	DDX_Control(pDX, IDC_BOX1, m_Box1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTolerance, BaseDlg)
	//{{AFX_MSG_MAP(PageTolerance)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTolerance message handlers

BOOL PageTolerance::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_PressTol.Create(IDD_DlGTOLERANCE,this);
	Combine(this,m_Box1,m_PressTol);
	m_FlowTol.Create(IDD_DlGTOLERANCE,this);
	Combine(this,m_Box2,m_FlowTol);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageTolerance::Init()
{
	m_PressTol.Init(SteadySet::ms_PresTolType,SteadySet::ms_PresAbsTol,SteadySet::ms_PresRelTol);
	m_FlowTol.Init(SteadySet::ms_FlowTolType,SteadySet::ms_FlowAbsTol,SteadySet::ms_FlowRelTol);
	UpdateData(FALSE);
}

BOOL PageTolerance::Updata()
{
	UpdateData(TRUE);
	m_PressTol.Updata(SteadySet::ms_PresTolType,SteadySet::ms_PresAbsTol,SteadySet::ms_PresRelTol);
	m_FlowTol.Updata(SteadySet::ms_FlowTolType,SteadySet::ms_FlowAbsTol,SteadySet::ms_FlowRelTol);
	return TRUE;
}