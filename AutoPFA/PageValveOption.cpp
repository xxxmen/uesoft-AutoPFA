// PageValveOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageValveOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageValveOption dialog


PageValveOption::PageValveOption(UnitSubSystem &UnitSys,CWnd* pParent /*=NULL*/)
	: BaseDlg(PageValveOption::IDD, pParent)
	,m_dlgOption(UnitSys)
{
	//{{AFX_DATA_INIT(PageValveOption)
	m_nSpecial = -1;
	//}}AFX_DATA_INIT
}


void PageValveOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageValveOption)
	DDX_Control(pDX, IDC_BOXOPTION, m_Box);
	DDX_Radio(pDX, IDC_RADIONONE, m_nSpecial);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageValveOption, BaseDlg)
	//{{AFX_MSG_MAP(PageValveOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageValveOption message handlers

BOOL PageValveOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgOption.Create(IDD_DIAOPTION,this);
	Combine(this,m_Box,m_dlgOption);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageValveOption::Init()
{
	m_dlgOption.Init(Jun::ms_InitGuess,Jun::ms_DisignFactor);
	m_nSpecial = Jun::ms_SpecialMark.GetnValue();
	UpdateData(FALSE);
}

BOOL PageValveOption::UpData()
{
	UpdateData(TRUE);
	Jun::ms_SpecialMark.SetValue(m_nSpecial);
	return m_dlgOption.UpData(Jun::ms_InitGuess,Jun::ms_DisignFactor);
}

