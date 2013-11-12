// dlgsteadyset.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgsteadyset.h"
#include "SteadySet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgSteadySet dialog


DlgSteadySet::DlgSteadySet(UnitSubSystem &UnitSys,SteadySet *pSteady,CWnd* pParent /*=NULL*/)
	: CDialog(DlgSteadySet::IDD, pParent)
	,m_page1(UnitSys)
{
	//{{AFX_DATA_INIT(DlgSteadySet)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pSteady = pSteady;
}


void DlgSteadySet::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgSteadySet)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgSteadySet, CDialog)
	//{{AFX_MSG_MAP(DlgSteadySet)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgSteadySet message handlers

BOOL DlgSteadySet::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRTOLERANCE,&m_page1,IDD_PAGETOLERANCE);
	m_tab.AddPage(IDS_STROTHER,&m_page2,IDD_PAGEOTHER);
	m_tab.Show();
	
	m_pSteady->InitData();
	m_page1.Init();
	m_page2.Init();

	return TRUE;  // return TRUE unless you set the focus to a control	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgSteadySet::OnOK() 
{
	// TODO: Add extra validation here
	m_page1.Updata();
	m_page2.Updata();
	m_pSteady->SaveData();
	CDialog::OnOK();
}

void DlgSteadySet::OnCancel() 
{
	// TODO: Add extra cleanup here
	CDialog::OnCancel();
}
