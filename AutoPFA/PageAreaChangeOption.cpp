// PageAreaChangeOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "pageareachangeoption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageAreaChangeOption dialog


PageAreaChangeOption::PageAreaChangeOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageAreaChangeOption::IDD, pParent)
	,m_dlgOption(UnitSys)
{
	//{{AFX_DATA_INIT(PageAreaChangeOption)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageAreaChangeOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageAreaChangeOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageAreaChangeOption, BaseDlg)
	//{{AFX_MSG_MAP(PageAreaChangeOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageAreaChangeOption message handlers

BOOL PageAreaChangeOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageAreaChangeOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

BOOL PageAreaChangeOption::UpData()
{
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}
