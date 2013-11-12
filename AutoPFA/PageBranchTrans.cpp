// PageBranchTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageBranchTrans.h"
#include "UnitSubSystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageBranchTrans dialog


PageBranchTrans::PageBranchTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(PageBranchTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageBranchTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageBranchTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageBranchTrans, PageTrans)
	//{{AFX_MSG_MAP(PageBranchTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageBranchTrans message handlers

BOOL PageBranchTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageBranchTrans::Init(Transient &ref)
{
	UnitTypeID id = VolumetricFlow;
    CString strType = _T("体积流量");
	CString strUnit = m_UnitSys.FindCurSymbol(VolumetricFlow);
	InitTransient(ref,id,strType,strUnit,&m_dlgSpecial);
}

BOOL PageBranchTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}