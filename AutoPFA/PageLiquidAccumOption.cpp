// PageLiquidAccumOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageLiquidAccumOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageLiquidAccumOption dialog


PageLiquidAccumOption::PageLiquidAccumOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageLiquidAccumOption::IDD, pParent)
	,m_DlgInitGuess(UnitSys)
{
	//{{AFX_DATA_INIT(PageLiquidAccumOption)
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void PageLiquidAccumOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageLiquidAccumOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageLiquidAccumOption, BaseDlg)
	//{{AFX_MSG_MAP(PageLiquidAccumOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageLiquidAccumOption message handlers

BOOL PageLiquidAccumOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_DlgInitGuess.Create(IDD_DLGINITPRESSGUESS,this);
	Combine(this,m_Box,m_DlgInitGuess);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageLiquidAccumOption::Init()
{
	m_DlgInitGuess.Init(Jun::ms_InitGuess);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	if(m_nSpecial != 0)
		m_nSpecial -= 2;
	UpdateData(FALSE);
}

BOOL PageLiquidAccumOption::UpData()
{
	UpdateData(TRUE);
	if(m_nSpecial != 0)
		m_nSpecial += 2;
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	return m_DlgInitGuess.UpData(Jun::ms_InitGuess);
}


