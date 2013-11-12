// DlgInerailTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgInerailTrans.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgInerailTrans dialog


DlgInerailTrans::DlgInerailTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: BaseDlg(DlgInerailTrans::IDD, pParent)
	,m_dlgInitPumpIneria(UnitSys,manager,m_dlgPumpTranData)
	,m_dlgPumpTranData(UnitSys,manager)
{
	//{{AFX_DATA_INIT(DlgInerailTrans)
	//}}AFX_DATA_INIT
}


void DlgInerailTrans::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgInerailTrans)
	DDX_Control(pDX, IDC_BOX3, m_Box3);
	DDX_Control(pDX, IDC_BOX4, m_Box4);
	DDX_Control(pDX, IDC_BOX1, m_Box1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgInerailTrans, BaseDlg)
	//{{AFX_MSG_MAP(DlgInerailTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgInerailTrans message handlers

BOOL DlgInerailTrans::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgTransSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgTransSpecial);
	m_dlgInitPumpIneria.Create(IDD_INITTRANS,this);
	Combine(this,m_Box3,m_dlgInitPumpIneria);
	m_dlgPumpTranData.Create(IDD_PUMPDATASHEEP,this);
	Combine(this,m_Box4,m_dlgPumpTranData);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL DlgInerailTrans::UpData(PumpTransient &ref)
{
	UpdateData(TRUE);
	m_dlgTransSpecial.UpData(ref.m_Special);
	m_dlgInitPumpIneria.UpData(ref);
	m_dlgPumpTranData.UpData(ref);
	return TRUE;
}

void DlgInerailTrans::Init(PumpTransient &ref)
{
	EnableSpecial();
	EnableEvent();
	EnableUnit();
	ShowInitPage(0);
	ShowInitPage(1);
	ShowInitPage(2);
	ShowDataPage(0);
	ShowDataPage(1);
	m_dlgTransSpecial.Init(ref.Special());
	
	m_dlgPumpTranData.Init(ref);
	m_dlgInitPumpIneria.Init(ref);
	UpdateData(FALSE);
}

void DlgInerailTrans::EnableSpecial(BOOL bEnable)
{
	m_dlgTransSpecial.Enable(bEnable);
}
void DlgInerailTrans::EnableUnit(BOOL bEnable)
{
	m_dlgPumpTranData.Show(bEnable);
}
void DlgInerailTrans::EnableEvent(BOOL bEnable)
{
	m_dlgInitPumpIneria.EnableEvent(bEnable);
}
void DlgInerailTrans::TimeEvent(BOOL bEnable)
{
	m_dlgInitPumpIneria.TimeEvent(bEnable);
}
void DlgInerailTrans::ShowInitPage(int nIndex,BOOL bShow)
{
	m_dlgInitPumpIneria.ShowPage(nIndex,bShow);
}

void DlgInerailTrans::SetInitCurSel(int nCur)
{
	m_dlgInitPumpIneria.SetCurSel(nCur);
}
void DlgInerailTrans::ShowDataPage(int nIndex,BOOL bShow)
{
	m_dlgPumpTranData.ShowPage(nIndex,bShow);
}

void DlgInerailTrans::SetDataCurSel(int nCur)
{
	m_dlgPumpTranData.SetCurSel(nCur);
}

void DlgInerailTrans::ShowFB(BOOL bShow)
{
	m_dlgPumpTranData.FourQuadTable().ShowFB(bShow);
}
