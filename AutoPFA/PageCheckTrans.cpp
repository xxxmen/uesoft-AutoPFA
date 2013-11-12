// PageCheckTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageCheckTrans.h"
#include "CheckValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageCheckTrans dialog


PageCheckTrans::PageCheckTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageCheckTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageCheckTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageCheckTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageCheckTrans, PageTrans)
	//{{AFX_MSG_MAP(PageCheckTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageCheckTrans message handlers

BOOL PageCheckTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	m_dlgInitTrans.ShowWindow(SW_HIDE);
	m_dlgTransData.ChangeName();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageCheckTrans::Init(Transient &ref,CString strType)
{
	CheckValve::ms_Transient.m_TranType.SetValue(3);//设置为循环事件
	InitTransient(ref,None,strType,_T(""),&m_dlgSpecial);
}

BOOL PageCheckTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}