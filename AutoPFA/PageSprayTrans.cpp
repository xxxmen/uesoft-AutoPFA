// PageSprayTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageSprayTrans.h"
#include "SprayDischarge.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageSprayTrans dialog


PageSprayTrans::PageSprayTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageSprayTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageSprayTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageSprayTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageSprayTrans, PageTrans)
	//{{AFX_MSG_MAP(PageSprayTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageSprayTrans message handlers

BOOL PageSprayTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageSprayTrans::Init(Transient &ref,CString strType,CString strUnit)
{
	InitTransient(ref,None,strType,strUnit,&m_dlgSpecial);
}

BOOL PageSprayTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}