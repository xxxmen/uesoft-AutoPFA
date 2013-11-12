// PipeIDList.h: interface for the PipeIDList class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPEIDLIST_H__8BB33DFD_E5C3_4E5C_BA36_20ACBA7F9B6E__INCLUDED_)
#define AFX_PIPEIDLIST_H__8BB33DFD_E5C3_4E5C_BA36_20ACBA7F9B6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ListFlyWeightImp.h"
template<UINT size>
class  TablePerisist  
{
public:
	int GetCount();
	ListImp<StrArray<size> >& GetData();
	void SetData(const ListImp<StrArray<size> > &ref,int nCount);//如果ListImp为空增加空字符串写到文件
	void SetData(const ListImp<StrArray<size> > &ref);//如果ListImp的字符串为空则表示属性为共享父共况属性
	void AddItem(StrArray<size> &ref);
	Iterator<StrArray<size> >* CreatIterator()const;
	void TranToStd(int nIndex,CString strUnit);
	
	TablePerisist();
	virtual ~TablePerisist();
private:
	void InitSize(int nCount);
	TablePerisist(const TablePerisist &ref);
	TablePerisist& operator=(const TablePerisist &ref);
	ListImp<StrArray<size> > m_list;
};

template<UINT size>
TablePerisist<size>::TablePerisist()
{
}

template<UINT size>
TablePerisist<size>::~TablePerisist()
{
}

template<UINT size>
int TablePerisist<size>::GetCount()
{
	return m_list.GetCount();
}

template<UINT size>
Iterator<StrArray<size> >* TablePerisist<size>::CreatIterator()const
{
	return m_list.CreatIterator();
}

template<UINT size>
void TablePerisist<size>::AddItem(StrArray<size> &array)
{
	m_list.AddItem(array);
}

template<UINT size>
void TablePerisist<size>::SetData(const ListImp<StrArray<size> > &ref,int nCount)
{
	if(ref.IsEmpty())
	{
		InitSize(nCount);
	}
	else
	{
		m_list = ref;
	}
}

template<UINT size>
void TablePerisist<size>::SetData(const ListImp<StrArray<size> > &ref)
{
	StrArray<size> Item;
	IteratorPtr<StrArray<size> > IdItPtr(ref.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		Item = IdItPtr->CurrentItem();
		if(Item.IsEmpty())
		{//为空字符表示共享父工况数据
			m_list.DelList();
			return;
		}
	}
	m_list = ref;
}

template<UINT size>
void TablePerisist<size>::TranToStd(int nIndex,CString strUnit)
{
	ASSERT(size > nIndex);
	double dOut = 0;
	CString strValue;
	IteratorPtr<StrArray<size> > IdItPtr(CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		StrArray<size> &Item = IdItPtr->CurrentItem();
		strValue = Item.Data(nIndex);
		if(strValue.CollateNoCase(_T("-9E+29"))==0)
			strValue.Empty();
		dOut = TransStd(strValue,strUnit);
		Item.Data(float(dOut),nIndex);
	}
}

template<UINT size>
ListImp<StrArray<size> >& TablePerisist<size>::GetData()
{
	return m_list;
}

template<UINT size>
void TablePerisist<size>::InitSize(int nCount)
{
	StrArray<size> array;
	for(int i=0; i<nCount; i++)
	{
		m_list.AddItem(array);
	}
}

#endif // !defined(AFX_PIPEIDLIST_H__8BB33DFD_E5C3_4E5C_BA36_20ACBA7F9B6E__INCLUDED_)
