// PageGeneralOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageGeneralOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageGeneralOption dialog


PageGeneralOption::PageGeneralOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageGeneralOption::IDD, pParent)
	,m_dlgOption(UnitSys)
{
	//{{AFX_DATA_INIT(PageGeneralOption)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageGeneralOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageGeneralOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageGeneralOption, BaseDlg)
	//{{AFX_MSG_MAP(PageGeneralOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageGeneralOption message handlers

BOOL PageGeneralOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageGeneralOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

BOOL PageGeneralOption::UpData()
{
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}