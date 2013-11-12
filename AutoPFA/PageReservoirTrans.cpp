// PageReservoirTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageReservoirTrans.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageReservoirTrans dialog


PageReservoirTrans::PageReservoirTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageReservoirTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageReservoirTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageReservoirTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageReservoirTrans, PageTrans)
	//{{AFX_MSG_MAP(PageReservoirTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageReservoirTrans message handlers

BOOL PageReservoirTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageReservoirTrans::Init(Transient &ref,CString strUnit)
{
	UnitTypeID id = Length;
    CString strType = _T("表面高度");
	InitTransient(ref,id,strType,strUnit,&m_dlgSpecial);
}

BOOL PageReservoirTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}