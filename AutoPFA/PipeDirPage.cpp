// PipeDirPage.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PipeDirPage.h"
#include "Jun.h"
#include "GlobalUse.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PipeDirPage dialog


PipeDirPage::PipeDirPage(CWnd* pParent /*=NULL*/)
	: BaseDlg(PipeDirPage::IDD, pParent)
{
	//{{AFX_DATA_INIT(PipeDirPage)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void PipeDirPage::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PipeDirPage)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_LISTPIPEDIR, m_list);
}


BEGIN_MESSAGE_MAP(PipeDirPage, BaseDlg)
	//{{AFX_MSG_MAP(PipeDirPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PipeDirPage message handlers

BOOL PipeDirPage::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PipeDirPage::InitList()
{
	m_list.DeleteAllItems();
	m_list.InsertColumn(_T("管道"));
    m_list.InsertColumn(_T("流向"));
	m_list.SetFixedRowCount();
	m_list.SetFixedColumnCount();
	m_list.SetColumnCount(2);
}

void PipeDirPage::Init()
{
	InitList();
	InitPipeDir(Jun::ms_PipeID,m_list);
}
