// DlgCScenarioManager.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "DlgCScenarioManager.h"
#include "Scenario.h"
#include "NetModel.h"
#include "DlgScenarioName.h"
#include "PersistentMgr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgCScenarioManager dialog


DlgCScenarioManager::DlgCScenarioManager(ScenariManage &manager,CWnd* pParent /*=NULL*/)
	: CDialog(DlgCScenarioManager::IDD, pParent),m_manager(manager)
{
	//{{AFX_DATA_INIT(DlgCScenarioManager)
	m_strCurScenario = _T("");
	//}}AFX_DATA_INIT
}


void DlgCScenarioManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgCScenarioManager)
	DDX_Control(pDX, IDC_TABINFO, m_tab);
	DDX_Control(pDX, IDC_TREESCENRIO, m_tree);
	DDX_Text(pDX, IDC_CURSCENARIO, m_strCurScenario);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(DlgCScenarioManager, CDialog)
	//{{AFX_MSG_MAP(DlgCScenarioManager)
	ON_BN_CLICKED(IDOK, OnSetCur)
	ON_BN_CLICKED(IDC_BCREATCHILD, OnCreatChild)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREESCENRIO, OnSelchanged)
	//}}AFX_MSG_MAP
    ON_COMMAND(ID_CREATCHILD, OnCreatChild)
	ON_COMMAND(ID_CLONEWITHCHILD, OnCloneWithChild)
	ON_COMMAND(ID_CLONEWITHOUT, OnCloneWithOutChild)
	ON_COMMAND(ID_PROMOTE, OnPromote)
	ON_COMMAND(ID_DELSCENARIO, OnDelete)
	ON_COMMAND(ID_RENAME, OnReName)
	ON_COMMAND(ID_SAVESCENARIO, OnSave)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgCScenarioManager message handlers

void DlgCScenarioManager::InitTree(Scenario* pScenario,HTREEITEM htreeitem)
{
	HTREEITEM temp = InsertTree(pScenario,htreeitem);
	Scenario *pChild = NULL;
	IteratorPtr<Scenario> iteratorPtr(pScenario->CreatIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pChild = &iteratorPtr->CurrentItem();
		InitTree(pChild,temp);
	}
}

HTREEITEM DlgCScenarioManager::InsertTree(Scenario *pScenario, HTREEITEM htreeitem)
{
	HTREEITEM temp = m_tree.InsertItem(pScenario->GetName(),htreeitem);
	m_tree.Expand(temp,TVE_EXPAND);
	m_tree.SelectItem(temp);
	m_tree.SetItemData(temp,pScenario->GetKey());
	return temp;
}

BOOL DlgCScenarioManager::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_tab.AddPage(IDS_STRSUMMARY, &m_page1, IDD_SUMMARY);
	m_tab.AddPage(IDS_STRDETAILS, &m_page2, IDD_DETAILS);
	m_tab.Show();

	m_strCurScenario = m_manager.GetCurAncestName();
	InitTree(m_manager.GetBaseScenario());
	m_tree.SelectItem(m_tree.GetRootItem());
    InitPage();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

Scenario* DlgCScenarioManager::GetCurScenario()
{
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return NULL;
    //根据key值找到对应的工况
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);
	return pScenario;
}

void DlgCScenarioManager::OnCreatChild() 
{
	// TODO: Add your command handler code here
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return;
    //根据key值找到对应的工况
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = GetCurScenario();
	
	DlgScenarioName dlg;
	if(IDOK == dlg.DoModal())
	{
		//检查名称没有存在子工况则增加一个子工况
		CString strName = dlg.GetName();
		if(pScenario->CheckName(strName))
		{
			InsertTree(m_manager.AddChildScenario(pScenario,strName),hItem);
			InitPage();
			UpdateData(FALSE);
		}
		else
		{
			AfxMessageBox(IDS_NAMEERROR);
		}
	}

}

void DlgCScenarioManager::OnCloneWithChild() 
{
	// TODO: Add your command handler code here
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return;
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);
	Scenario *pClone = m_manager.CloneWithChild(pScenario,DefaultName(pScenario));
	if(pClone != NULL)
	{
		InitTree(pClone,m_tree.GetParentItem(hItem));
		InitPage();
		UpdateData(FALSE);
	}
}

void DlgCScenarioManager::OnCloneWithOutChild() 
{
	// TODO: Add your command handler code here
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return;
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);
	Scenario *pClone = m_manager.CloneWithOutChild(pScenario,DefaultName(pScenario));
	if(pClone != NULL)
	{
		InitTree(pClone,m_tree.GetParentItem(hItem));
		InitPage();
		UpdateData(FALSE);
	}
}

void DlgCScenarioManager::OnPromote() 
{
	// TODO: Add your command handler code here
	if(IDCANCEL ==AfxMessageBox(IDS_PROMOTESCENARIOMSG,MB_OKCANCEL))
		return;
	
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return;
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);
    if(m_manager.Promote(pScenario))
	{
		InitTree(pScenario,m_tree.GetParentItem(m_tree.GetParentItem(hItem)));
		m_tree.DeleteItem(hItem);
	}
	InitPage();
}

void DlgCScenarioManager::OnDelete() 
{
	// TODO: Add your command handler code here
	if(IDCANCEL ==AfxMessageBox(IDS_DELSCENARIOMSG,MB_OKCANCEL))
		return;

	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return;
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);
	//如果当前删除工况为基本工况FALSE
	if(m_manager.DelScenario(pScenario))
	{
		m_tree.DeleteItem(hItem);
	}
	InitPage();
}

void DlgCScenarioManager::OnReName() 
{
	// TODO: Add your command handler code here
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return;
    //根据key值找到对应的工况
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);
	Scenario *pAnScenario = pScenario->GetAnScenario();
	DlgScenarioName dlg;
	dlg.m_strName = pScenario->GetName();
	if(IDOK == dlg.DoModal())
	{
		CString strName = dlg.GetName();
		if(pAnScenario != NULL)
		{
			if(pAnScenario->CheckName(strName))
			{
				pScenario->SetName(strName);
				m_tree.SetItemText(hItem,strName);
				UpdateData(FALSE);
			}
			else
			{
				AfxMessageBox(IDS_NAMEERROR);
			}
		}
		else
		{
			pScenario->SetName(strName);
			m_tree.SetItemText(hItem,strName);
			UpdateData(FALSE);
		}
	}

}


void DlgCScenarioManager::OnSetCur() 
{
	// TODO: Add your control notification handler code here
	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
	{
		CString strMsg;
		strMsg.LoadString(IDS_SELECTSCENARIO);
		AfxMessageBox(strMsg);
		return;
	}
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);
	m_manager.SetCurScenario(pScenario);
	CDialog::OnOK();
}

void DlgCScenarioManager::InitPage()
{
	int nKey = m_tree.GetItemData(m_tree.GetSelectedItem());
	Scenario* pScenario = m_manager.LookUp(nKey);
	if(pScenario != NULL)
	{
		m_page1.Init(pScenario);
		m_page2.Init(pScenario);
	}
}

void DlgCScenarioManager::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	InitPage();
	*pResult = 0;
}

CString DlgCScenarioManager::DefaultName(Scenario *pScenario)
{
	Scenario *pAnScenario = pScenario->GetAnScenario();
	CString strName = pScenario->GetName();
	CString strNewName;
	if(pAnScenario != NULL)
	{
		int i = 2;
		do {
			strNewName.Format(_T("%s(%d)"),strName,i);
			i++;
		} while(!pAnScenario->CheckName(strNewName));
	}
	return strNewName;
}

void DlgCScenarioManager::OnSave() 
{
	// TODO: Add your command handler code here

	HTREEITEM hItem = m_tree.GetSelectedItem();
	if(hItem == NULL)
		return;
	DWORD key = m_tree.GetItemData(hItem);
	Scenario *pScenario = m_manager.LookUp(key);

	BOOL bRet = TRUE;
	PersistentModel model;
	PersistentMgr persistentMgr;
	bRet = m_manager.SaveCurModel(model.GetScenarioPersist(),pScenario);
	if(bRet)
	{
		static TCHAR BASED_CODE szFilter[] = _T("AFT原始数据(*.imp)|*.imp|PFA计算文件(*.calc)|*.calc|All Files (*.*)|*.*||");

		CFileDialog dlg(FALSE,_T("imp"),pScenario->GetName(),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,szFilter);
		if(IDOK == dlg.DoModal())
		{
			persistentMgr.Save(dlg.GetPathName(),model);
		}
	}
}
