// PageBreakerOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageBreakerOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageBreakerOption dialog


PageBreakerOption::PageBreakerOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageBreakerOption::IDD, pParent)
	,m_DlgInitGuess(UnitSys)
{
	//{{AFX_DATA_INIT(PageBreakerOption)
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void PageBreakerOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageBreakerOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageBreakerOption, BaseDlg)
	//{{AFX_MSG_MAP(PageBreakerOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageBreakerOption message handlers

BOOL PageBreakerOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DlgInitGuess.Create(IDD_DLGINITPRESSGUESS,this);
	Combine(this,m_Box,m_DlgInitGuess);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageBreakerOption::Init()
{
	m_DlgInitGuess.Init(Jun::ms_InitGuess);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	if(m_nSpecial != 0)
		m_nSpecial -= 2;
	UpdateData(FALSE);
}

BOOL PageBreakerOption::UpData()
{
	UpdateData(TRUE);
	if(m_nSpecial != 0)
		m_nSpecial += 2;
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	return m_DlgInitGuess.UpData(Jun::ms_InitGuess);
}

