// PageGraph.cpp : implementation file
//

#include "stdafx.h"
#include "autopfa.h"
#include "PageGraph.h"
#include "ComponentTranOut.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// PageGraph dialog


PageGraph::PageGraph(CWnd* pParent /*=NULL*/)
	: BaseDlg(PageGraph::IDD, pParent)
{
	//{{AFX_DATA_INIT(PageGraph)
	m_strXUnit = _T("");
	m_strYUnit = _T("");
	m_strYUnitText = _T("");
	//}}AFX_DATA_INIT
	m_pArray = NULL;
	m_nPipeKey = -1;
	m_nStationKey = -1;
	m_nCurSelRow = -1;
}


void PageGraph::DoDataExchange(CDataExchange* pDX)
{
	BaseDlg::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(PageGraph)
	DDX_Control(pDX, IDC_BMOVE, m_butMove);
	DDX_Control(pDX, IDC_BADD, m_butAdd);
	DDX_Control(pDX, IDC_TREE, m_tree);
	DDX_Control(pDX, IDC_BOX, m_box);
	DDX_Control(pDX, IDC_LIST, m_list);
	DDX_Control(pDX, IDC_CMBYUNIT, m_cbmYUnit);
	DDX_Control(pDX, IDC_CMBXUNIT, m_cbmXUnit);
	DDX_CBString(pDX, IDC_CMBXUNIT, m_strXUnit);
	DDX_CBString(pDX, IDC_CMBYUNIT, m_strYUnit);
	DDX_Text(pDX, IDC_STATICYUNIT, m_strYUnitText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(PageGraph, BaseDlg)
	//{{AFX_MSG_MAP(PageGraph)
	ON_LBN_SELCHANGE(IDC_BOX, OnSelChangeBox)
	ON_BN_CLICKED(IDC_BADD, OnAdd)
	ON_BN_CLICKED(IDC_BMOVE, OnMove)
	ON_BN_CLICKED(IDC_BCLEAR, OnClear)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE, OnSelChangedTree)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST, OnItemChangedList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// PageGraph message handlers

BOOL PageGraph::OnInitDialog() 
{
	BaseDlg::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

HTREEITEM PageGraph::InsertItem(CString strText,int nKey,HTREEITEM hitem)
{
	HTREEITEM hSubItem = m_tree.InsertItem(strText,hitem);
	m_tree.SetItemData(hSubItem,nKey);
	return hSubItem;
}

void PageGraph::InitAttr(OutAttrArray &array,int nStart)
{
	ASSERT(nStart>0);
	m_pArray = &array;
	int n = array.GetSize();
	int nIndex=0;
	for(int i=nStart;i<n;i++)
	{
		if(array[i].Show())
		{
			nIndex = m_box.AddString(array[i].Name());
			if(nIndex == LB_ERR)
				return;
			m_box.SetItemData(nIndex,i);	
		}
	}
	InitUnit(m_cbmXUnit,m_strXUnit,array[nStart-1]);
	InitUnit(m_cbmYUnit,m_strYUnit,array[nStart]);
	m_box.SetCurSel(0);
}


void PageGraph::InitUnit(CComboBox &cbo,CString &strUnit,OutDataAttr &attr)
{
	strUnit = attr.Unit();
	InitUnitCbo(attr.UnitSys(),attr.UnitType(),cbo,strUnit);
}


void PageGraph::OnSelChangeBox() 
{
	// TODO: Add your control notification handler code here
	int nIndex = m_box.GetCurSel();
	if(nIndex != LB_ERR)
	{
		int i = m_box.GetItemData(nIndex);
		m_box.GetText(nIndex,m_strYUnitText);
		ASSERT(m_pArray != NULL);
		InitUnit(m_cbmYUnit,m_strYUnit,m_pArray->GetAt(i));
	}
	UpdateData(FALSE);
}

void PageGraph::OnAdd() 
{
	// TODO: Add your control notification handler code here
	if(!Exist())
	{
		int nRow = m_list.GetItemCount();
		CString strText;
		strText.Format(_T("%d"),m_nPipeKey);
		m_list.InsertItem(nRow,strText);
		strText.Format(_T("%d"),m_nStationKey);
		m_list.SetItemText(nRow,1,strText);
	}
}

BOOL PageGraph::Exist()
{
	int nRow = m_list.GetItemCount();
	int nKey1=0;
	int nKey2=0;
	for(int i=0;i<nRow;i++)
	{
		nKey1 = _ttoi(m_list.GetItemText(i,0));
		nKey2 = _ttoi(m_list.GetItemText(i,1));
		if(nKey1==m_nPipeKey && nKey2==m_nStationKey)
			return TRUE;
	}
	return FALSE;
}

void PageGraph::OnMove() 
{
	// TODO: Add your control notification handler code here
	m_list.DeleteItem(m_nCurSelRow);
	m_butMove.EnableWindow(FALSE);
}

void PageGraph::OnClear() 
{
	// TODO: Add your control notification handler code here
	m_list.DeleteAllItems();
}

void PageGraph::OnSelChangedTree(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hitem = m_tree.GetNextItem(TVI_ROOT,TVGN_CARET);
	HTREEITEM hParentItem = NULL;
	if(hitem)
	{
		m_nStationKey = m_tree.GetItemData(hitem);
		hParentItem = m_tree.GetParentItem(hitem);
		if(hParentItem != NULL)
		{
			m_nPipeKey = m_tree.GetItemData(hParentItem);
			m_butAdd.EnableWindow(TRUE);
		}
		else
		{
			m_butAdd.EnableWindow(FALSE);
		}
	}
	*pResult = 0;
}


void PageGraph::OnItemChangedList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	m_nCurSelRow = m_list.GetNextItem(-1,LVNI_SELECTED);
	if(-1 != m_nCurSelRow)
	{
		 m_butMove.EnableWindow(TRUE);
	}
	else
	{
		m_butMove.EnableWindow(FALSE);
	}
	*pResult = 0;
}


