// PageSurgeTrans.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageSurgeTrans.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageSurgeTrans dialog


PageSurgeTrans::PageSurgeTrans(UnitSubSystem &UnitSys,ComponentManager &manager,CWnd* pParent /*=NULL*/)
	: PageTrans(UnitSys,manager,pParent)
{
	//{{AFX_DATA_INIT(PageSurgeTrans)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageSurgeTrans::DoDataExchange(CDataExchange* pDX)
{
	PageTrans::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageSurgeTrans)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageSurgeTrans, PageTrans)
	//{{AFX_MSG_MAP(PageSurgeTrans)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageSurgeTrans message handlers

BOOL PageSurgeTrans::OnInitDialog() 
{
	PageTrans::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgSpecial.Create(IDD_TWOSPECIAL,this);
	Combine(this,m_Box1,m_dlgSpecial);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageSurgeTrans::Init(Transient &ref,CString strUnit)
{
	UnitTypeID id = Pressure;
    CString strType = _T("±Ì√Ê—π¡¶");
	InitTransient(ref,id,strType,strUnit,&m_dlgSpecial);
}

BOOL PageSurgeTrans::UpData(Transient &ref)
{
	return UpDataTransient(ref,&m_dlgSpecial);
}