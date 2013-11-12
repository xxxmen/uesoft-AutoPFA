// PageAssignedFlowTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageAssignedFlowTrans.h"
#include "AssignedFlow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageAssignedFlowTrans dialog


PageAssignedFlowTrans::PageAssignedFlowTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
	,m_dlgPeriodit(UnitSys)
{
	//{{AFX_DATA_INIT(PageAssignedFlowTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageAssignedFlowTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageAssignedFlowTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageAssignedFlowTrans, PageTrans)
	//{{AFX_MSG_MAP(PageAssignedFlowTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageAssignedFlowTrans message handlers

BOOL PageAssignedFlowTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_THREESPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	m_dlgPeriodit.Create(IDD_PERIODIC,this);
	Combine(this,m_Box2,m_dlgPeriodit);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageAssignedFlowTrans::Init(Transient &ref,UnitTypeID id,CString strType,CString strUnit)
{
	InitTransient(ref,id,strType,strUnit,&m_dlgSpecial,&m_dlgPeriodit);
}

BOOL PageAssignedFlowTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial,&m_dlgPeriodit);
}


