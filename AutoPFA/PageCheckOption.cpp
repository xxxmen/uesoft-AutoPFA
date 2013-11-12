// PageCheckOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageCheckOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageCheckOption dialog


PageCheckOption::PageCheckOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageCheckOption::IDD, pParent)
	,m_dlgOption(UnitSys)
{
	//{{AFX_DATA_INIT(PageCheckOption)
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void PageCheckOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageCheckOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageCheckOption, BaseDlg)
	//{{AFX_MSG_MAP(PageCheckOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageCheckOption message handlers

BOOL PageCheckOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageCheckOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	if(m_nSpecial != 0)
		m_nSpecial -= 1;
	UpdateData(FALSE);
}

BOOL PageCheckOption::UpData()
{
	UpdateData(TRUE);
	if(m_nSpecial != 0)
		m_nSpecial += 1;
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

