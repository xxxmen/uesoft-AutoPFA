// PageDetail.cpp : implementation file
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "PageDetail.h"
#include "ComponentManager.h"
#include "Scenario.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageDetail dialog


PageDetail::PageDetail(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageDetail::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageDetail)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pCompManager = NULL;
    m_pScenario = NULL;
	m_nFilter = 0;
}


void PageDetail::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageDetail)
	DDX_Control(pDX, IDC_RADIOALL, m_RadioAll);
	DDX_Control(pDX, IDC_TREECOMPONENT, m_tree);
	DDX_Control(pDX, IDC_LISTATRRIBUTE, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageDetail, BaseDlg)
	//{{AFX_MSG_MAP(PageDetail)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREECOMPONENT, OnSelchangedTree)
	ON_BN_CLICKED(IDC_RADIOALL, OnRadioAll)
	ON_BN_CLICKED(IDC_RADIOANCEST, OnRadioAncest)
	ON_BN_CLICKED(IDC_RADIOSELECT, OnRadioSelect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageDetail message handlers

BOOL PageDetail::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
    m_RadioAll.SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void PageDetail::Init(Scenario *pScenario)
{
	m_pCompManager = pScenario->GetCompManager();
    m_pScenario = pScenario;
	InitTree();
}

void PageDetail::OnSelchangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	InitList();
	*pResult = 0;
}

void PageDetail::InitTree()
{
	m_tree.DeleteAllItems();
	CString strText;
	strText.Format(_T("管道(%d)"),m_pCompManager->GetPipeNum());
	HTREEITEM hPipeitem = m_tree.InsertItem(strText);
	m_tree.SetItemData(hPipeitem,1);
	InitPipe(hPipeitem);
	
    strText.Format(_T("节点(%d)"),m_pCompManager->GetJunNum());
	HTREEITEM hJunItem = m_tree.InsertItem(strText);
	InitJun(hJunItem);
}

void PageDetail::InitPipe(HTREEITEM hitem)
{
	CString strText;
	CString strName;
	int nKey;
	int nID;
	HTREEITEM hsubItem = NULL;
	Component *pTemp = NULL;
	IteratorPtr<Component> iteratorPtr(m_pCompManager->CreatPipeIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pTemp = &iteratorPtr->CurrentItem();
		nKey = iteratorPtr->CurrentKey();
		nID = pTemp->GetKey();
		strName = pTemp->GetName(m_pScenario);
		strText.Format(_T("P%d(%s)"),nID,strName);
		hsubItem = m_tree.InsertItem(strText,hitem);
		m_tree.SetItemData(hsubItem,nKey);
	}
}

void PageDetail::InitJun(HTREEITEM hitem)
{
	CString strSubText; //节点名称
	CString strMainText;//节点类型名称
	CString strName;
    CString strType;
	int nNum = 0;
	int nKey;
	int nID;
	HTREEITEM hMainItem = NULL;
    HTREEITEM hSubItem = NULL;
	Component *pTemp = NULL;
	for(int i=1; i< 30; i++)
	{
		nNum = 0;
		IteratorPtr<Component> iteratorPtr(m_pCompManager->CreatJunIterator());
		hMainItem = m_tree.InsertItem(strMainText,hitem);
		for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
		{
			pTemp = &iteratorPtr->CurrentItem();
			if(i == pTemp->GetID())
			{
				nKey = iteratorPtr->CurrentKey();
				nID = pTemp->GetKey();
				strName = pTemp->GetName(m_pScenario);
				strSubText.Format(_T("J%d(%s)"),nID,strName);
				hSubItem = m_tree.InsertItem(strSubText,hMainItem);
				m_tree.SetItemData(hSubItem,nKey);
				strType = pTemp->GetTypeName();
				nNum++;
			}
		}
		if(nNum != 0)
		{
			strMainText.Format(_T("%s(%d)"),strType,nNum);
			m_tree.SetItemText(hMainItem,strMainText);
			m_tree.SetItemData(hMainItem,2);
		}
		else
		{
			m_tree.DeleteItem(hMainItem);
		}
	}
}

void PageDetail::InitList()
{
	HTREEITEM hitem = m_tree.GetNextItem(TVI_ROOT,TVGN_CARET);
	HTREEITEM hParentItem = NULL;
	m_list.DeleteAllItems();
	m_list.InsertColumn(_T("属性"));
    m_list.InsertColumn(_T("值"));
	m_list.InsertColumn(_T("单位"));
	m_list.InsertColumn(_T("工况"));
	m_list.SetFixedRowCount();
	m_list.SetFixedColumnCount(0);
	m_list.SetColumnCount(4);
	if(hitem)
	{
		int nKey = m_tree.GetItemData(hitem);
		hParentItem = m_tree.GetParentItem(hitem);
		if(hParentItem == NULL)
			return;
		int nType = m_tree.GetItemData(hParentItem);
		Component *pTemp =m_pCompManager->LookUp(nType,nKey);
		if(pTemp != NULL)
		{
			InitList(pTemp);
		}
	}
}

void PageDetail::InitList(Component *pComponent)
{
	NameArray &array = pComponent->GetArray();
	CString strValve;
	CString strUnit;
	CString strScenario;
	FlyWeight *pFly = NULL;
	int n = array.GetSize();
	// m_list.SetRowCount(n+1);
	int nRow;
	for(int i=0;i<n;i++)
	{
		switch(m_nFilter)
		{
		case 0:
			pFly = pComponent->LookUp(array[i].Key(),m_pScenario,strScenario);
			break;

		case 1:
			pFly = pComponent->GetPrivate(array[i].Key());
            strScenario = m_pScenario->GetName();
			break;
           
		case 2:
			pFly = pComponent->LookAncest(array[i].Key(),m_pScenario,strScenario);
			break;
		default:
			pFly = NULL;
			break;
		}
		if(pFly != NULL)
		{
			if(pFly->GetValue(strValve,strUnit))
			{
				if(array[i].IsShow())
				{
					nRow = m_list.InsertRow(array[i].Name());
					m_list.SetItemText(nRow,1,strValve);
					m_list.SetItemText(nRow,2,strUnit);
					m_list.SetItemText(nRow,3,strScenario);
				}
			}
		}
	}
	m_list.AutoSizeColumns();
	m_list.SetEditable(FALSE);
}

void PageDetail::OnRadioAll() 
{
	// TODO: Add your control notification handler code here
	m_nFilter = 0;
	InitList();
}

void PageDetail::OnRadioSelect() 
{
	// TODO: Add your control notification handler code here
	m_nFilter = 1;
	InitList();
}

void PageDetail::OnRadioAncest() 
{
	// TODO: Add your control notification handler code here
	m_nFilter = 2;
	InitList();
}
