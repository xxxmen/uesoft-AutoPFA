// PageReliefTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageReliefTrans.h"
#include "ReliefValve.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageReliefTrans dialog


PageReliefTrans::PageReliefTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageReliefTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageReliefTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageReliefTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageReliefTrans, PageTrans)
	//{{AFX_MSG_MAP(PageReliefTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageReliefTrans message handlers

BOOL PageReliefTrans::OnInitDialog() 
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

void PageReliefTrans::Init(Transient &ref,CString strType)
{
	ref.m_TranType.SetValue(3);//设置为循环事件
	InitTransient(ref,None,strType,_T(""),&m_dlgSpecial);
}

BOOL PageReliefTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}