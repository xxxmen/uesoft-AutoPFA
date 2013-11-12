// DlgParamUnit.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "dlgparamunit.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgParamUnit dialog


DlgParamUnit::DlgParamUnit(UnitSubSystem &unitSystem,CWnd* pParent /*=NULL*/)
	: CDialog(DlgParamUnit::IDD, pParent)
	,m_unitSystem(unitSystem)
	,m_Ref(unitSystem)

{
	//{{AFX_DATA_INIT(DlgParamUnit)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgParamUnit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgParamUnit)
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgParamUnit, CDialog)
	//{{AFX_MSG_MAP(DlgParamUnit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgParamUnit message handlers

BOOL DlgParamUnit::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_Tab.AddPage("µ¥Î»",&m_page1,IDD_PAGEUNIT);
	m_Tab.Show();

	InitUnit();
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgParamUnit::InitUnit()
{
	m_page1.Init(&m_unitSystem);
}

void DlgParamUnit::OnOK() 
{
	// TODO: Add extra validation here
	m_page1.UpdataSymbol();
	m_Ref = m_unitSystem;
	CDialog::OnOK();
}
