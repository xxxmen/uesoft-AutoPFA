// PageReservoirOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageReservoirOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageReservoirOption dialog


PageReservoirOption::PageReservoirOption(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageReservoirOption::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageReservoirOption)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageReservoirOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageReservoirOption)
	DDX_Control(pDX, IDC_BOX, m_Box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageReservoirOption, BaseDlg)
	//{{AFX_MSG_MAP(PageReservoirOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageReservoirOption message handlers

BOOL PageReservoirOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgDesignFactor.Create(IDD_DESIGNFACTOR,this);
	Combine(this,m_Box,m_dlgDesignFactor);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageReservoirOption::Init()
{
	m_dlgDesignFactor.Init(Jun::ms_DisignFactor);
}

BOOL PageReservoirOption::UpData()
{
	return m_dlgDesignFactor.UpData(Jun::ms_DisignFactor);
}