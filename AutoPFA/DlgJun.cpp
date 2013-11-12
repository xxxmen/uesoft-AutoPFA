// DlgJun.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "DlgJun.h"
#include "GlobalUse.h"
#include "SysProperties.h"
#include "Fuild.h"
#include "DlgFind.h"
#include "DlgCopyData.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgJun dialog


DlgJun::DlgJun(UnitSubSystem &UnitSys,ComponentManager &manager,Jun *pJun,CWnd* pParent /*=NULL*/,UINT nIDTemplate)
	: CDialog(nIDTemplate, pParent)
	,m_manager(manager)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(DlgJun)
	m_nID = 0;
	m_strName = _T("");
	//}}AFX_DATA_INIT
	m_pJun = pJun;
	m_pJunTemp = (Jun*)pJun->Clone();
	m_nOldSel = 0;
	m_bReadOnly = FALSE;
}


void DlgJun::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgJun)
	DDX_Control(pDX, IDC_STATICSHEET, m_Box);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_CMBNAMELIST, m_cmbName);
	DDX_Text(pDX, IDC_EID, m_nID);
	DDX_Text(pDX, IDC_ENAME, m_strName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgJun, CDialog)
	//{{AFX_MSG_MAP(DlgJun)
	ON_BN_CLICKED(IDC_JUMP, OnJump)
	ON_CBN_SELCHANGE(IDC_CMBNAMELIST, OnChangeCmbNameList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgJun message handlers

BOOL DlgJun::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if ( m_bReadOnly )
	{
		GetDlgItem(IDOK)->EnableWindow(FALSE);
		GetDlgItem(IDC_JUMP)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDOK)->EnableWindow(TRUE);
		GetDlgItem(IDC_JUMP)->EnableWindow(TRUE);
	}
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgJun::Init()
{
	m_pJunTemp->InitAllData();
	//组件需要引用流体数据
	m_manager.SysProperty().GetFuild()->InitData();
	m_nID        = m_pJunTemp->GetKey();
	m_strName    = Component::ms_Name.GetValue();
	InitCmb();
	UpdateData(FALSE);
}

void DlgJun::SaveData()
{
	UpdateData(TRUE);
	Component::ms_Name.SetValue(m_strName);
	UpData();
	m_pJun->SaveData();
}

void DlgJun::InitCmb()
{
	InitJunCmb(m_cmbName,m_manager,m_pJunTemp->GetID());	
	//排除自己节点
	CString strName;
	CString strText;
	int nKey;
	int nIndex;
	nKey = m_pJunTemp->GetKey();
	strName = m_pJun->GetName();
	strText.Format(_T("%d(%s)"),nKey,strName);
	nIndex = m_cmbName.FindString( -1 , strText );
	if ( nIndex >= 0 )
	{
		m_cmbName.DeleteString( nIndex );
	}
	m_cmbName.SetCurSel( -1 );
}

void DlgJun::OnOK() 
{
	// TODO: Add extra validation here
	if ( !m_bReadOnly )
	{
		SaveData();
	}
	if ( m_pJunTemp != NULL )
	{
		delete m_pJunTemp;
	}
	CDialog::OnOK();
}

void DlgJun::OnCancel()
{
	if ( m_pJunTemp != NULL )
	{
		delete m_pJunTemp;
	}
   CDialog::OnCancel();
} 

void DlgJun::InitBox(CDialog &dlg)
{
	Combine(this,m_Box,dlg);
}


void DlgJun::OnJump() 
{
	// TODO: Add your control notification handler code here
	Component *pComponent = NULL;
	DlgFind dlg(m_manager);
	if(IDOK == dlg.DoModal())
	{
		Component *pComponent = m_manager.LookUp(dlg.m_nObjectType,dlg.m_nObjectKey);
		if(pComponent !=NULL)
		{
			if(pComponent->GetID()==m_pJunTemp->GetID())
			{
				UpData();
				m_pJunTemp = dynamic_cast<Jun*>(pComponent);
				Init();
			}
			else
			{
				OnOK();
				pComponent->Show(m_UnitSys,&m_manager);
			}
		}
	}
}


BOOL DlgJun::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	int nCurSel = m_tab.GetCurSel();
	int nCheckSel = m_tab.GetItemCount()-1;
	if(nCurSel != m_nOldSel
	   &&nCurSel == nCheckSel)
	{
		UpData();
		ComponentStatus status(m_pJunTemp->GetArray());
		m_pJunTemp->Status(status);
		m_pageStatus.Init(status);
	}
	m_nOldSel = nCurSel;
	return CDialog::OnNotify(wParam, lParam, pResult);
}

/************************************************************************
版本: 8.0  开发时间: [2009/3/28]  作者: [ue8] 评审人:
功能: 设置对话框的只读属性，即把应用和跳过两个按钮变灰                                                             
输入:                                                               
输出:                                                              
< 修改人 >    < 时间 >     < 版本 >        < 描述 >                                                                               
************************************************************************/
void DlgJun::ReadOnly( BOOL bReadOnly )
{
	m_bReadOnly = bReadOnly;
}

void DlgJun::OnChangeCmbNameList() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	int nIndex = m_cmbName.GetCurSel();
	int nKey = (int)m_cmbName.GetItemData( nIndex );

	Jun* pJun = m_manager.LookUpJun( nKey );
	if ( pJun == NULL || m_pJunTemp == NULL )
	{
		return;
	}
	DlgCopyData dlgCopyData( pJun , m_pJunTemp );
	if ( dlgCopyData.DoModal() == IDOK )
	{
		Init();
		UpdateData( FALSE );
		m_cmbName.SetCurSel( nIndex );
	}
}
