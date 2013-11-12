// GraphSet.cpp: implementation of the GraphSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "GraphSet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

GraphSet::GraphSet()
{
	InitArray();
}

GraphSet::GraphSet(const GraphSet &ref):PersistentObj(ref)
{
	m_NumofGraph = ref.m_NumofGraph;
	m_RecentSet  = ref.m_RecentSet;
	CloneList(ref.m_ItemList);
}

GraphSet& GraphSet::operator=(const GraphSet &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	PersistentObj::operator =(ref);
	//释放堆内存
	DelList();
	//重新分配堆内存
	CloneList(ref.m_ItemList);
	//赋值
	m_NumofGraph = ref.m_NumofGraph;
	m_RecentSet  = ref.m_RecentSet;
	return *this;
}


GraphSet::~GraphSet()
{
	DelList();
}

BOOL GraphSet::Read(CStdioFile &file)
{
	CString strTemp;
	ReadMark(file);
	file.ReadString(strTemp);
	m_NumofGraph.InitRow(strTemp);

	GraphItem *pItem = NULL;
	int nNum = GetGraphNum();
	for(int i=0;i<nNum; i++)
	{
		m_ItemList.AddTail(new GraphItem());
	}

	POSITION pos = m_ItemList.GetHeadPosition();
	while(pos)
	{
		pItem = m_ItemList.GetNext(pos);
		pItem->Read(file);
	}

    file.ReadString(strTemp);
	m_RecentSet.InitRow(strTemp);
	return TRUE;
}

BOOL GraphSet::Save(CStdioFile &file)
{
	SaveMark(file);
	file.WriteString(m_NumofGraph.Save());
	GraphItem *pItem = NULL;
	POSITION pos = m_ItemList.GetHeadPosition();
	while(pos)
	{
		pItem = m_ItemList.GetNext(pos);
		pItem->Save(file);
	}
	file.WriteString(m_RecentSet.Save());
	return TRUE;
}

void GraphSet::InitArray()
{
	m_RowArray.SetSize(2);
	m_RowArray.SetAt(0,&m_NumofGraph);
	m_RowArray.SetAt(1,&m_RecentSet);
	SetID("\n[GRAPH SETS]");
}

void GraphSet::Init()
{
	CString strArray[4];
	strArray[0] = _T("Number of Graph Sets=0");
	strArray[1] = _T("RecentSet = None");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==2);
		m_RowArray.GetAt(i)->InitRow(strArray[i]);
	}
}

int GraphSet::GetGraphNum()
{
	int nRet=0;
	m_NumofGraph.GetData(nRet,1);
	return nRet;
}

void GraphSet::DelList()
{
	GraphItem *pItem = NULL;
	POSITION pos = m_ItemList.GetHeadPosition();
	while(pos)
	{
		pItem = m_ItemList.GetNext(pos);
		delete pItem;
	}
	m_ItemList.RemoveAll();
}

void GraphSet::CloneList(const GraphItemList &itemList)
{
	GraphItem *pItem = NULL;
	POSITION pos = itemList.GetHeadPosition();
	while(pos)
	{
		 pItem = itemList.GetNext(pos);
		 m_ItemList.AddTail(new GraphItem(*pItem));
	}
}
