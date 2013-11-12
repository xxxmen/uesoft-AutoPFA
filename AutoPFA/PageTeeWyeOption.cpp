// PageTeeWyeOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageTeeWyeOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeOption dialog


PageTeeWyeOption::PageTeeWyeOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageTeeWyeOption::IDD, pParent)
	,m_dlgOption(UnitSys)
{
	//{{AFX_DATA_INIT(PageTeeWyeOption)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageTeeWyeOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageTeeWyeOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageTeeWyeOption, BaseDlg)
	//{{AFX_MSG_MAP(PageTeeWyeOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageTeeWyeOption message handlers

BOOL PageTeeWyeOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageTeeWyeOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

BOOL PageTeeWyeOption::UpData()
{
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}