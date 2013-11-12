// PageNotShowOutAtt.cpp : 实现文件
//

#include "stdafx.h"
#include "AutoPFA.h"
#include "PageNotShowOutAtt.h"
#include "StmOutMgr.h"


// PageNotShowOutAtt 对话框

IMPLEMENT_DYNAMIC(PageNotShowOutAtt, CDialog)

PageNotShowOutAtt::PageNotShowOutAtt(PFAOutModel &outModel, CWnd* pParent /*=NULL*/)
	: PageDataList(pParent)
	,m_outModel(outModel)
{
}

PageNotShowOutAtt::~PageNotShowOutAtt()
{
}

void PageNotShowOutAtt::DoDataExchange(CDataExchange* pDX)
{
	PageDataList::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(PageNotShowOutAtt, PageDataList)
END_MESSAGE_MAP()


// PageNotShowOutAtt 消息处理程序
BOOL PageNotShowOutAtt::OnInitDialog()
{
	PageDataList::OnInitDialog();
// 	OutAttrArray arrNotShow = m_pOutMgr->GetShowArray();
// 	OutAttrArray arrShow    = m_pOutMgr->GetArray();

	m_list.InsertColumn( 0 , _T("") , LVCFMT_CENTER , 100 );
	m_list.InsertColumn( 1 , _T("") , LVCFMT_CENTER , 100 );
//     OutMgr &outMgr = m_outModel.SteadyOut().ComponentOutMgr().PipeOutMgr();
// 	OutAttrArray& arr = outMgr.GetArray();
// 	int n = arr.GetSize();
// 	int nCol = 0;
// 	for(int i=0;i<n;i++)
// 	{
// 		m_list.InsertItem( i , arr[i].GetTitle() );
// 		m_list.SetItemData( i, arr[i].Key());
// 	}

	return TRUE;
}

int PageNotShowOutAtt::GetSelectedItem()
{
	POSITION pos = m_list.GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		TRACE0("No items were selected!\n");
		return -1;
	}
	else
	{
		while (pos)
		{
			int nItem = m_list.GetNextSelectedItem(pos);
			TRACE1("Item %d was selected!\n", nItem);
			// you could do your own processing on nItem here
			//int nKey = (int)m_list.GetItemData(nItem);
			return nItem;
		}
	}
	return -1;
}

BOOL PageNotShowOutAtt::DeleteItem(int nItem)
{
	return m_list.DeleteItem(nItem);
}

BOOL PageNotShowOutAtt::AddItem( CString strText,CString strUnit, int nKey )
{

	m_list.InsertItem( m_list.GetItemCount(),  strText );
    m_list.SetItemText( m_list.GetItemCount()-1, 1, strUnit );
	m_list.SetItemData( m_list.GetItemCount()-1, nKey);
	return TRUE;
}

void PageNotShowOutAtt::SetOutArray(OutAttrArray& arr)
{
	//m_attArr = arr;
	m_attArr.RemoveAll();
	int n = arr.GetSize();
}

int PageNotShowOutAtt::GetItemData( int nItem )
{
	return m_list.GetItemData(nItem);
}

CString PageNotShowOutAtt::GetItemText( int nRow, int nCol )
{
	return m_list.GetItemText(nRow, nCol);
}

void PageNotShowOutAtt::DeleteAllItems()
{
	m_list.DeleteAllItems();
}