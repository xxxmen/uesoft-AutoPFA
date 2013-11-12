// dlgsolvecontrol.cpp : implementation file
//

#include "stdafx.h"
#include "dlgsolvecontrol.h"
#include "ResourceInstance.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// dlgSolveControl dialog


dlgSolveControl::dlgSolveControl(CWnd* pParent /*=NULL*/)
	: CDialog(dlgSolveControl::IDD, pParent)
{
// 	CResourceInstance res;
	//{{AFX_DATA_INIT(dlgSolveControl)
	m_Total = 0;
	m_NowStep = 0;
	m_Stop = false;
	//}}AFX_DATA_INIT
}


void dlgSolveControl::DoDataExchange(CDataExchange* pDX)
{
//	CResourceInstance res;
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(dlgSolveControl)
	DDX_Control(pDX, IDC_PROGRESS_TEST, m_Progress);
	DDX_Text(pDX, IDC_EDIT_TEST1, m_Total);
	DDX_Text(pDX, IDC_EDIT_TEST2, m_NowStep);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(dlgSolveControl, CDialog)
	//{{AFX_MSG_MAP(dlgSolveControl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// dlgSolveControl message handlers

void dlgSolveControl::OnCancel() 
{
	m_Stop = true;
	CDialog::OnCancel();
}
