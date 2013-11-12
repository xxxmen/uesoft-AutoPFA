// DlgWorkspaceRef.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgWorkspaceRef.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgWorkspaceRef dialog


DlgWorkspaceRef::DlgWorkspaceRef(WorkSpaceRef &workSpace,CWnd* pParent /*=NULL*/)
	: CDialog(DlgWorkspaceRef::IDD, pParent),m_workSpaceRef(workSpace)
{
	//{{AFX_DATA_INIT(DlgWorkspaceRef)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgWorkspaceRef::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgWorkspaceRef)
	DDX_Control(pDX, IDC_TAB1, m_tab);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgWorkspaceRef, CDialog)
	//{{AFX_MSG_MAP(DlgWorkspaceRef)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgWorkspaceRef message handlers

BOOL DlgWorkspaceRef::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage("管道和节点",&m_page1,IDD_GRAPHICSREF);
	m_tab.AddPage("颜色和字体",&m_page2,IDD_COLORFONTREF);
	m_tab.Show();

	m_page1.Init(m_workSpaceRef);
	m_page2.Init(m_workSpaceRef);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgWorkspaceRef::OnOK() 
{
	// TODO: Add extra validation here
	m_page1.Updata();
	m_page2.Updata();
	CDialog::OnOK();
}
