// PageAssignedPressOption.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageAssignedPressOption.h"
#include "Jun.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageAssignedPressOption dialog


PageAssignedPressOption::PageAssignedPressOption(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageAssignedPressOption::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageAssignedPressOption)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PageAssignedPressOption::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageAssignedPressOption)
	DDX_Control(pDX, IDC_BOX, m_Box);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageAssignedPressOption, BaseDlg)
	//{{AFX_MSG_MAP(PageAssignedPressOption)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageAssignedPressOption message handlers

BOOL PageAssignedPressOption::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dlgDesignFactor.Create(IDD_DESIGNFACTOR,this);
	Combine(this,m_Box,m_dlgDesignFactor);
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
void PageAssignedPressOption::Init()
{
	m_dlgDesignFactor.Init(Jun::ms_DisignFactor);
}

BOOL PageAssignedPressOption::UpData()
{
	return m_dlgDesignFactor.UpData(Jun::ms_DisignFactor);
}