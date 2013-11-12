// PageFailTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageFailTrans.h"
#include "ControlValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageFailTrans dialog


PageFailTrans::PageFailTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageFailTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageFailTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageFailTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageFailTrans, PageTrans)
	//{{AFX_MSG_MAP(PageFailTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageFailTrans message handlers

BOOL PageFailTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgInitTrans.ShowWindow(SW_HIDE);
	m_dlgTransData.ChangeName();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageFailTrans::Init(Transient &ref,CString strType)
{
	ControlValve::ms_FailTransient.m_TranType.SetValue(3);//设置为循环事件
	InitTransient(ref,None,strType,_T(""));
}

BOOL PageFailTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref);
}
