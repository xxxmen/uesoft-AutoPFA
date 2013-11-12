// DlgScenarioName.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgScenarioName.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgScenarioName dialog


DlgScenarioName::DlgScenarioName(CWnd* pParent /*=NULL*/)
	: CDialog(DlgScenarioName::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgScenarioName)
	m_strName = _T("");
	//}}AFX_DATA_INIT
}


void DlgScenarioName::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgScenarioName)
	DDX_Text(pDX, IDC_ENAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgScenarioName, CDialog)
	//{{AFX_MSG_MAP(DlgScenarioName)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgScenarioName message handlers

void DlgScenarioName::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	if(m_strName.Find('/') != -1)
	{
		AfxMessageBox(IDS_SCENARIONAMEERROR);
		return;
	}
	if(m_strName.IsEmpty())
	{
		AfxMessageBox(_T("名称不能为空"));
		return;
	}
	CDialog::OnOK();
}

CString DlgScenarioName::GetName()
{
	return m_strName;
}
