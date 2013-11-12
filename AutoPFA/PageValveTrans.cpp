// PageValveTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageValveTrans.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageValveTrans dialog


PageValveTrans::PageValveTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageValveTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageValveTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageValveTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageValveTrans, PageTrans)
	//{{AFX_MSG_MAP(PageValveTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageValveTrans message handlers

BOOL PageValveTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageValveTrans::Init(Transient &ref,CString strType)
{
	InitTransient(ref,None,strType,_T(""),&m_dlgSpecial);
}

BOOL PageValveTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}