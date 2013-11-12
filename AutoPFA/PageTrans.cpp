// PageTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageTrans.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTrans dialog


PageTrans::PageTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageTrans::IDD, pParent)
	,m_dlgInitTrans(UnitSys,manager,m_dlgTransData)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(PageTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pDlgPeriodic = NULL;
}


void PageTrans::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTrans)
	DDX_Control(pDX, IDC_BOX4, m_Box4);
	DDX_Control(pDX, IDC_BOX3, m_Box3);
	DDX_Control(pDX, IDC_BOX2, m_Box2);
	DDX_Control(pDX, IDC_BOX1, m_Box1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTrans, BaseDlg)
	//{{AFX_MSG_MAP(PageTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTrans message handlers

BOOL PageTrans::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	// TODO: Add extra initialization here
	m_dlgTransData.Create(IDD_TARASDATASHEEP,this);
	Combine(this,m_Box4,m_dlgTransData);
	m_dlgInitTrans.Create(IDD_INITTRANS,this);
	Combine(this,m_Box3,m_dlgInitTrans);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageTrans::InitTransient(Transient &ref,UnitTypeID id,CString strType,CString strUnit,DlgTransSpecial *pSpecial,DlgPeriodic *pPeriodic)
{
	if(pSpecial != NULL)
		pSpecial->Init(ref.Special());
	if(pPeriodic != NULL)
	{
		m_pDlgPeriodic = pPeriodic;
		pPeriodic->Init(ref.Periodic(),m_UnitSys,id);
	}
	m_dlgInitTrans.Init(ref);
	m_dlgTransData.Init(ref,strType,strUnit);
	UpdateData(FALSE);
}

BOOL PageTrans::UpDataTransient(Transient &ref,DlgTransSpecial *pSpecial,DlgPeriodic *pPeriodic)
{
	UpdateData(TRUE);
	if(pSpecial != NULL)
		pSpecial->UpData(ref.m_Special);
	if(pPeriodic != NULL)
		pPeriodic->UpData(ref.m_Periodic);
	m_dlgInitTrans.UpData(ref);
	m_dlgTransData.UpData(ref);
	return TRUE;
}

void PageTrans::SetType(UnitTypeID id,CString strType)
{
	if(m_pDlgPeriodic != NULL)
	{
		m_pDlgPeriodic->SetUnit(m_UnitSys,id);
	}
	m_dlgTransData.SetType(strType);
}

void PageTrans::SetUnit(CString strUnit)
{
	m_dlgTransData.SetUnit(strUnit);
}


