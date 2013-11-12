// DlgCheckList.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgCheckList.h"
#include "DlgSteadySet.h"
#include "Scenario.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgCheckList dialog


DlgCheckList::DlgCheckList(CWnd* pParent /*=NULL*/)
	: CDialog(DlgCheckList::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgCheckList)
	m_b1 = FALSE;
	m_b2 = FALSE;
	m_b3 = FALSE;
	m_b4 = FALSE;
	m_b5 = FALSE;
	//}}AFX_DATA_INIT
	m_bTran =FALSE;
	m_pCurDoc = NULL;
}


void DlgCheckList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgCheckList)
	DDX_Check(pDX, IDC_CHECK1, m_b1);
	DDX_Check(pDX, IDC_CHECK2, m_b2);
	DDX_Check(pDX, IDC_CHECK3, m_b3);
	DDX_Check(pDX, IDC_CHECK4, m_b4);
	DDX_Check(pDX, IDC_CHECK5, m_b5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgCheckList, CDialog)
	//{{AFX_MSG_MAP(DlgCheckList)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_BUT_ShowSteadySet, OnShowSteadySet)
	ON_BN_CLICKED(IDC_BUT_ShowSystemProper, OnShowSystemProper)
	ON_BN_CLICKED(IDC_BUT_ShowSectionPipe, OnShowSectionPipe)
	ON_BN_CLICKED(IDC_BUT_ShowTransControl, OnShowTransControl)
	ON_BN_CLICKED(IDC_BUT_UndefinedObjects, OnShowUndefinedObjects)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgCheckList message handlers

void DlgCheckList::Init(BOOL bCheck[],BOOL bTran)
{
	m_b1 = bCheck[0];
	m_b2 = bCheck[1];
	m_b3 = bCheck[2];
	m_b4 = bCheck[3];
	m_b5 = bCheck[4];
	m_bTran = bTran;
}

void DlgCheckList::OnCheck1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
}

void DlgCheckList::OnCheck2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
}

void DlgCheckList::OnCheck3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
}

void DlgCheckList::OnCheck4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
}

void DlgCheckList::OnCheck5() 
{
	// TODO: Add your control notification handler code here
	UpdateData(FALSE);
}

BOOL DlgCheckList::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!m_bTran)
	{
		GetDlgItem(IDC_CHECK4)->EnableWindow(FALSE);
		GetDlgItem(IDC_CHECK5)->EnableWindow(FALSE);
	}
	return TRUE; 
}

//显示恒定流分析控制对话框
void DlgCheckList::OnShowSteadySet() 
{
	if ( m_pCurDoc != NULL )
	{
		m_pCurDoc->OnSteadyControl();
	}
}

//设置当前操作文档
void DlgCheckList::SetCurDoc(CAutoPFADoc *pCurDoc)
{
   m_pCurDoc = pCurDoc;
}

//显示系统属性对话框
void DlgCheckList::OnShowSystemProper() 
{
	if ( m_pCurDoc != NULL )
	{
		m_pCurDoc->OnSystemProper();
	}
}

//显示管道分段对话框
void DlgCheckList::OnShowSectionPipe() 
{
	if ( m_pCurDoc != NULL )
	{
        m_pCurDoc->OnSectionPipe();
	}
}

//显示瞬变流分析控制对话框
void DlgCheckList::OnShowTransControl() 
{
	if ( m_pCurDoc != NULL )
	{
		m_pCurDoc->OnTransControl();
	}
}

void DlgCheckList::OnShowUndefinedObjects() 
{
	if ( m_pCurDoc != NULL )
	{
		//如果所有的PIPE和JUN都已经定义了则不显示对话框
		if ( m_pCurDoc->m_scenarioManager.GetCurScenario()->GetCompManager()->IsAllJunDefine( TRUE ) 
			&& m_pCurDoc->m_scenarioManager.GetCurScenario()->GetCompManager()->IsAllPipeDefine( TRUE ) )
		{
			return ;
		}
		CDlgUndefinedObjects m_dlgUndefinedObjects( &m_pCurDoc->m_unitSystem, m_pCurDoc->m_scenarioManager.GetCurScenario()->GetCompManager() );
        m_dlgUndefinedObjects.DoModal();		 	
	}
	m_pCurDoc->OnCheckModel();
}
