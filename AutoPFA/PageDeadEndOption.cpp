// PageDeadEndOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageDeadEndOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageDeadEndOption dialog


PageDeadEndOption::PageDeadEndOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageDeadEndOption::IDD, pParent)
	,m_DlgInitGuess(UnitSys)
{
	//{{AFX_DATA_INIT(PageDeadEndOption)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageDeadEndOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageDeadEndOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageDeadEndOption, BaseDlg)
	//{{AFX_MSG_MAP(PageDeadEndOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageDeadEndOption message handlers

BOOL PageDeadEndOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DlgInitGuess.Create(IDD_DLGINITPRESSGUESS,this);
	Combine(this,m_Box,m_DlgInitGuess);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageDeadEndOption::Init()
{
	m_DlgInitGuess.Init(Jun::ms_InitGuess);
}

BOOL PageDeadEndOption::UpData()
{
	return m_DlgInitGuess.UpData(Jun::ms_InitGuess);
}