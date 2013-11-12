// PageControlTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageControlTrans.h"
#include "ControlValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageControlTrans dialog


PageControlTrans::PageControlTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageControlTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageControlTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageControlTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageControlTrans, PageTrans)
	//{{AFX_MSG_MAP(PageControlTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageControlTrans message handlers

BOOL PageControlTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	m_dlgInitTrans.HideDualEvent();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageControlTrans::Init(Transient &ref,CString strType,CString strUnit)
{
	InitTransient(ref,None,strType,strUnit,&m_dlgSpecial);
}

BOOL PageControlTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}