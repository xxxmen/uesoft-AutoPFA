// DlgNoInerialTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgNoInerialTrans.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgNoInerialTrans dialog


DlgNoInerialTrans::DlgNoInerialTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(DlgNoInerialTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgNoInerialTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgNoInerialTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgNoInerialTrans, PageTrans)
	//{{AFX_MSG_MAP(DlgNoInerialTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgNoInerialTrans message handlers

BOOL DlgNoInerialTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgNoInerialTrans::Init(Transient &ref)
{
	InitTransient(ref,None,_T(""),_T(""),&m_dlgSpecial);
}

BOOL DlgNoInerialTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}