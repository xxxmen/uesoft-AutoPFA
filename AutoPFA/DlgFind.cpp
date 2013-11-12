// DlgFind.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgFind.h"
#include "ComponentManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgFind dialog


DlgFind::DlgFind(ComponentManager &compManager,CWnd* pParent /*=NULL*/)
	: CDialog(DlgFind::IDD, pParent)
	, m_CompManager(compManager)
{
	//{{AFX_DATA_INIT(DlgFind)
	m_nObjectKey = 0;
	//}}AFX_DATA_INIT
	m_nObjectType = 1;
}


void DlgFind::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgFind)
	DDX_Control(pDX, IDC_RJUN, m_RadioJun);
	DDX_Control(pDX, IDC_RPIPE, m_RadioPipe);
	DDX_Control(pDX, IDC_LISTPIPE, m_listPipe);
	DDX_Control(pDX, IDC_LISTJUN, m_listJun);
	DDX_Control(pDX, IDC_CMBJUNTYPE, m_cboJunType);
	DDX_Text(pDX, IDC_EID, m_nObjectKey);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgFind, CDialog)
	//{{AFX_MSG_MAP(DlgFind)
	ON_CBN_SELCHANGE(IDC_CMBJUNTYPE, OnSelchange)
	ON_BN_CLICKED(IDC_RJUN, OnRjun)
	ON_BN_CLICKED(IDC_RPIPE, OnRpipe)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTJUN, OnChangedJun)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LISTPIPE, OnChangedPipe)
	ON_NOTIFY(NM_SETFOCUS, IDC_LISTPIPE, OnSetFocusPipe)
	ON_NOTIFY(NM_SETFOCUS, IDC_LISTJUN, OnSetFocusJun)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgFind message handlers

void DlgFind::OnOK() 
{
	// TODO: Add extra validation here
	
	CDialog::OnOK();
}

BOOL DlgFind::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_RadioPipe.SetCheck(1);
	CRect rc;
	m_listPipe.GetWindowRect(rc);
	m_listPipe.InsertColumn(0,_T("ID"),LVCFMT_LEFT,rc.Width()/4);
	m_listPipe.InsertColumn(1,_T("Name"),LVCFMT_LEFT,rc.Width());
	DWORD styles = m_listPipe.GetExtendedStyle();
	m_listPipe.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);
	
	m_listJun.GetWindowRect(rc);
	m_listJun.InsertColumn(0,_T("ID"),LVCFMT_LEFT,rc.Width()/4);
	m_listJun.InsertColumn(1,_T("Name"),LVCFMT_LEFT,rc.Width());
	styles = m_listJun.GetExtendedStyle();
	m_listJun.SetExtendedStyle(styles|LVS_EX_FULLROWSELECT);
	InitCboJun();
	ShowJunList();
	ShowPipeList();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void DlgFind::OnSelchange() 
{
	// TODO: Add your control notification handler code here
	int nType;
	int	nIndex = m_cboJunType.GetCurSel();
	if(CB_ERR  != nIndex)
	{
		nType = m_cboJunType.GetItemData(nIndex);
		m_listJun.DeleteAllItems();
		ShowJunList(nType);
	}

}

void DlgFind::ShowPipeList(int nType)
{
	CString strText;
	CString strName;
	int nKey;
	int nID;
	int nRow = 0;
	Component *pTemp = NULL;
	IteratorPtr<Component> iteratorPtr(m_CompManager.CreatPipeIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		nKey = iteratorPtr->CurrentKey();
		nID = pTemp->GetKey();
		strName = pTemp->GetName();
		strText.Format(_T("%d"),nID);
		m_listPipe.InsertItem(nRow,strText);
		m_listPipe.SetItemText(nRow,1,strName);
		m_listPipe.SetItemData(nRow,nKey);
		nRow++;
	}
}

void DlgFind::ShowJunList(int nType)
{
	CString strText;
	CString strName;
	int nKey;
	int nRow = 0;
	int nID;
	Component *pTemp = NULL;
	IteratorPtr<Component> iteratorPtr(m_CompManager.CreatJunIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		if(nType == pTemp->GetID() || nType==0)
		{
			nKey = iteratorPtr->CurrentKey();
			nID = pTemp->GetKey();
			strName = pTemp->GetName();
			strText.Format(_T("%d"),nID);
			m_listJun.InsertItem(nRow,strText);
			m_listJun.SetItemText(nRow,1,strName);
			m_listJun.SetItemData(nRow,nKey);
			nRow++;
		}
	}
}

void DlgFind::InitCboJun()
{
	Component *pTemp = NULL;
	int nIndex = m_cboJunType.AddString(_T("所有节点"));
	m_cboJunType.SetItemData(nIndex,0);
	m_cboJunType.SetCurSel(nIndex);
	for(int i=1; i< 30; i++)
	{
		IteratorPtr<Component> iteratorPtr(m_CompManager.CreatJunIterator());
		for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
		{
			pTemp = &iteratorPtr->CurrentItem();
			if(i == pTemp->GetID())
			{
				nIndex = m_cboJunType.AddString(pTemp->GetTypeName());
				m_cboJunType.SetItemData(nIndex,i);
				break;
			}
		}
	}
	
}

void DlgFind::OnRjun() 
{
	// TODO: Add your control notification handler code here
	m_nObjectType = 2;
	m_RadioPipe.SetCheck(0);
	m_RadioJun.SetCheck(1);
}

void DlgFind::OnRpipe() 
{
	// TODO: Add your control notification handler code here
	m_nObjectType = 1;
	m_RadioPipe.SetCheck(1);
	m_RadioJun.SetCheck(0);
}

void DlgFind::OnChangedJun(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	int	nIndex = m_listJun.GetNextItem(-1,LVNI_SELECTED);
	if(-1 != nIndex)
	{
		 m_nObjectKey = m_listJun.GetItemData(nIndex);
	}
	else
	{
		m_nObjectKey = 0;
	}
	UpdateData(FALSE);
	*pResult = 0;
}

void DlgFind::OnChangedPipe(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	int	nIndex = m_listPipe.GetNextItem(-1,LVNI_SELECTED);
	if(-1 != nIndex)
	{
		 m_nObjectKey = m_listPipe.GetItemData(nIndex);
	}
	else
	{
		m_nObjectKey = 0;
	}
	UpdateData(FALSE);
	*pResult = 0;
}

void DlgFind::OnSetFocusPipe(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnRpipe();
	*pResult = 0;
}

void DlgFind::OnSetFocusJun(NMHDR* pNMHDR, LRESULT* pResult) 
{
	// TODO: Add your control notification handler code here
	OnRjun();
	*pResult = 0;
}
