// DlgCommon.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgCommon.h"
#include "Pipe.h"
#include "DlgFind.h"
#include "DlgCopyData.h"
#include "ComponentStatus.h"



#include "AutoPFADoc.h"
#include "NetModel.h"
#include "ScenariManage.h"
#include "Scenario.h"
#include "MainFrm.h"
#include "ChildFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgCommon dialog


DlgPipe::DlgPipe(UnitSubSystem &UnitSys,ComponentManager &manager,Pipe *pPipe,CWnd* pParent /*=NULL*/)
	: CDialog(DlgPipe::IDD, pParent)
	,m_manager(manager)
	,m_page1(UnitSys,manager)
	,m_page3(UnitSys)
	,m_UnitSys(UnitSys)
{
	//{{AFX_DATA_INIT(DlgCommon)
	m_nID = 0;
	m_strName = _T("");
	m_strInJunID = _T("");
	m_strOutJunID = _T("");
	//}}AFX_DATA_INIT
	m_pPipe =pPipe;
	m_pPipeTemp = (Pipe*)pPipe->Clone();
	m_nOldSel = 0;
	m_bReadOnly = FALSE;
}


void DlgPipe::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgCommon)
	DDX_Control(pDX, IDC_BUTTON2, m_btnext);
	DDX_Control(pDX, IDC_BUTTON1, m_btPre);
	DDX_Control(pDX, IDC_EOUTJUNID, m_EditOutJun);
	DDX_Control(pDX, IDC_EINJUNID, m_EditInJun);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_CNAMELIST, m_cboName);
	DDX_Text(pDX, IDC_EID, m_nID);
	DDX_Text(pDX, IDC_ENAME, m_strName);
	DDX_Text(pDX, IDC_EINJUNID, m_strInJunID);
	DDX_Text(pDX, IDC_EOUTJUNID, m_strOutJunID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgPipe, CDialog)
	//{{AFX_MSG_MAP(DlgCommon)
	ON_CBN_SELCHANGE(IDC_CNAMELIST, OnSelchangePipe)
	ON_BN_CLICKED(IDC_JUMP, OnJump)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgCommon message handlers

BOOL DlgPipe::OnInitDialog() 
{
	CDialog::OnInitDialog();
	// TODO: Add extra initialization here
	CString strTitle;
	strTitle.LoadString(IDS_STRPIPE);
	SetWindowText(strTitle);
	m_tab.AddPage(IDS_STRPIPEMODEL,&m_page1,IDD_PAGEPIPEMODEL);
	m_tab.AddPage(IDS_STRFITLOSS,&m_page2,IDD_PAGEFITLOSS);
	m_tab.AddPage(IDS_STRPAGEOPTION,&m_page3,IDD_PAGEPIPEOPTION);
	m_tab.AddPage(IDS_STRSTATUS,&m_page4,IDD_PAGESTATUS);
	m_tab.Show();
	Init();
	/*CBitmap bitmapbt;
	bitmapbt.DeleteObject();
	bitmapbt.LoadBitmap(IDB_BITMAPPRE);
	m_btPre.SetBitmap(bitmapbt);
	*/
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

	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgPipe::InitCmb()
{
	InitPipeCmb(m_cboName,m_manager);
	//排除自己节点
	CString strName;
	CString strText;
	int nKey;
	int nIndex;
	nKey = m_pPipeTemp->GetKey();
	strName = m_pPipe->GetName();
	strText.Format(_T("%d(%s)"),nKey,strName);
	nIndex = m_cboName.FindString( -1 , strText );
	if ( nIndex >= 0 )
	{
		m_cboName.DeleteString( nIndex );
	}
	m_cboName.SetCurSel( -1 );
}

void DlgPipe::OnOK() 
{
	// TODO: Add extra validation here
	if ( !m_bReadOnly )
	{
		SaveData();
	}

	if ( m_pPipeTemp != NULL )
	{
		delete m_pPipeTemp;
	}
	CDialog::OnOK();
}
void DlgPipe::OnCancel()
{
	if ( m_pPipeTemp != NULL )
	{
		delete m_pPipeTemp;
	}
	CDialog::OnCancel();
}

void DlgPipe::UpData()
{
	UpdateData(TRUE);
	Component::ms_Name.SetValue(m_strName);
	m_page1.UpData();
	m_page2.UpData();
	m_page3.UpData();
}
void DlgPipe::SaveData()
{
	UpData();
	m_pPipe->SaveData();
}
void DlgPipe::Init()
{
	int FirstPipe = 100000;
	int LastPipe = 0;
	Component *pTemp = NULL;
	Component *pPre = NULL;
	IteratorPtr<Component> iteratorPtr(m_manager.CreatPipeIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		int temp = pTemp->GetKey();
		FirstPipe = min(FirstPipe,temp);
		LastPipe = max(LastPipe,temp);
	}
	if (FirstPipe == m_pPipeTemp->GetKey())
		m_btnext.EnableWindow(false);
//		m_btPre.EnableWindow(false);
	if (LastPipe == m_pPipeTemp->GetKey())
		m_btPre.EnableWindow(false);
	//	m_btnext.EnableWindow(false);
	m_nID = m_pPipeTemp->GetKey();
	m_pPipeTemp->InitAllData();
	m_strName = Component::ms_Name.GetValue();
	m_strInJunID = Pipe::ms_InJun.GetValue();
	m_strOutJunID = Pipe::ms_OutJun.GetValue();
	m_page2.Init();
	m_page3.Init();
	InitCmb();
	Init(m_pPipeTemp);
	UpdateData(FALSE);
}
void DlgPipe::Init(Pipe *pPipe)
{
	ASSERT(pPipe != NULL);
	pPipe->InitData();
	m_page1.Init();
	UpdateData(FALSE);
}

void DlgPipe::OnSelchangePipe() 
{
	// TODO: Add your control notification handler code here
    UpData();
	int nIndex = m_cboName.GetCurSel();
	if(CB_ERR != nIndex)
	{
		int nKey = m_cboName.GetItemData(nIndex);
		if(CB_ERR != nKey)
		{
			Pipe *pPipe = m_manager.LookUpPipe(nKey);
			if(pPipe != NULL)
			{
				DlgCopyData dlgCopyData( pPipe , m_pPipeTemp );
				if ( dlgCopyData.DoModal() == IDOK )
				{
					Init();
					UpdateData( FALSE );
					m_cboName.SetCurSel( nIndex );
				}
			}
		}
	}
	UpdateData(FALSE);
}



void DlgPipe::OnJump() 
{
	// TODO: Add your control notification handler code here
	Component *pComponent = NULL;
	DlgFind dlg(m_manager);
	if(IDOK == dlg.DoModal())
	{
		Component *pComponent = m_manager.LookUp(dlg.m_nObjectType,dlg.m_nObjectKey);
		if(pComponent !=NULL)
		{
			if(pComponent->GetID()==m_pPipeTemp->GetID())
			{
				SaveData();
				m_pPipeTemp = dynamic_cast<Pipe*>(pComponent);
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

BOOL DlgPipe::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	int nCurSel = m_tab.GetCurSel();
	int nCheckSel = m_tab.GetItemCount()-1;
	if(nCurSel != m_nOldSel
	   &&nCurSel == nCheckSel)
	{
		if(m_pPipeTemp != NULL)
		{
			UpData();
			ComponentStatus status(m_pPipeTemp->GetArray());
			m_pPipeTemp->Status(status);
			m_page4.Init(status);
		}
	}
	m_nOldSel = nCurSel;
	return CDialog::OnNotify(wParam, lParam, pResult);
}

void DlgPipe::OnButton1() 
{
	// TODO: Add your control notification handler code here
	int iKey = 0;
	Component *pTemp = NULL;
	Component *pPre = NULL;
	IteratorPtr<Component> iteratorPtr(m_manager.CreatPipeIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		iKey = iteratorPtr->CurrentKey();
		if( m_pPipeTemp->GetKey() == iKey )
		{
			if( pPre != NULL )
			{
				OnOK();
				pPre->Show(m_UnitSys,&m_manager);
				return;
			}
			else
			{
                return;
			}
		}
		pPre = pTemp;
	}
}

void DlgPipe::OnButton2() 
{
	// TODO: Add your control notification handler code here
	int iKey = 0;
	Component *pTemp = NULL;
	IteratorPtr<Component> iteratorPtr(m_manager.CreatPipeIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		iKey = iteratorPtr->CurrentKey();
		if( m_pPipeTemp->GetKey() == iKey )
		{
			iteratorPtr->Next();
			if( !iteratorPtr->IsDone() )
			{
				pTemp = &iteratorPtr->CurrentItem(); 
				OnOK();
				pTemp->Show(m_UnitSys,&m_manager);
				return;
			}
			else
			{
                return;
			}
		}
	}
}


void DlgPipe::ReadOnly(BOOL bReadOnly)
{
	m_bReadOnly = bReadOnly;
}
