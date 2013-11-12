#ifndef TABLEFLYWEIGHT_H
#define TABLEFLYWEIGHT_H
#include "StdAfx.h"
#include "FlyWeight.h"
#include "ListFlyWeightImp.h"
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：TableFiyWeight.h
  摘要：    
  author  : LSP          
*/

//
template<UINT size>
class TableFlyWeight:public FlyWeight 
{
public:
	int GetCount()const;
	void SetNull();
	void Empty();
	void DelItem(int nKey);
	BOOL LookUp(StrArray<size>*& pItem,int nKey);
	void AddItem(StrArray<size>& Item,int nKey);
	void AddItem(StrArray<size>& Item);
	Iterator<StrArray<size> >* CreatIterator()const;
	BOOL IsEmpty()const;
	void Assign(FlyWeight *pFly);
	BOOL IsEqual(FlyWeight &ref)const;
    BOOL GetValue(CString &strValue)const;
    BOOL GetValue(CString &strValue,CString &strUnit)const;
	
	ListImp<StrArray<size> >& GetData();
	void SetData(const ListImp<StrArray<size> >& ref);
	static FlyWeight* CreatTableFlyWeight();
	TableFlyWeight();
	TableFlyWeight(const TableFlyWeight &ref);
	TableFlyWeight& operator=(const TableFlyWeight &ref);
	virtual ~TableFlyWeight(){};
private:
	ListImp<StrArray<size> > m_list;
	virtual FlyWeight*  DoClone();
};

template<UINT size>
ListImp<StrArray<size> >& TableFlyWeight<size>::GetData()
{
	return m_list;
}
template<UINT size>
void TableFlyWeight<size>::SetData(const ListImp<StrArray<size> >& ref)
{
	m_list = ref;
}

template<UINT size>
int TableFlyWeight<size>::GetCount()const
{
	 return m_list.GetCount();
}

template<UINT size>
void TableFlyWeight<size>::SetNull()
{
	 Empty();
}

template<UINT size>
void TableFlyWeight<size>::Empty()
{
	 m_list.DelList();
}

template<UINT size>
void TableFlyWeight<size>::AddItem(StrArray<size> &item,int nKey)
{
	m_list.AddItem(item,nKey);
}

template<UINT size>
void TableFlyWeight<size>::AddItem(StrArray<size> &item)
{
	m_list.AddItem(item);
}

template<UINT size>
BOOL TableFlyWeight<size>::LookUp(StrArray<size> *&pItem,int nKey)
{
	if(m_list.IsExistKey(pItem,nKey)
		||m_list.IsExistKey(pItem,-nKey))
	{
		return TRUE;
	}
	return FALSE;
}

template<UINT size>
void TableFlyWeight<size>::DelItem(int nKey)
{
	m_list.DelKey(nKey);
}

template<UINT size>
BOOL TableFlyWeight<size>::IsEmpty()const
{
	return m_list.IsEmpty();
}

template<UINT size>
void TableFlyWeight<size>::Assign(FlyWeight *pFly)
{
	assert(typeid(*this)==typeid(*pFly));
	*this = *dynamic_cast<TableFlyWeight<size>* >(pFly);
}

template<UINT size>
BOOL TableFlyWeight<size>::IsEqual(FlyWeight &ref)const
{
	TableFlyWeight<size> *pComp = NULL;
	if(typeid(*this)==typeid(ref))
	{
		pComp = dynamic_cast<TableFlyWeight<size>*>(&ref);
		return m_list.IsEqual(pComp->m_list);
	}
	else
	{
		return FALSE;
	}
}

template<UINT size>
BOOL TableFlyWeight<size>::GetValue(CString &strValue)const
{
	strValue.Empty();
	return TRUE;
}

template<UINT size>
BOOL TableFlyWeight<size>::GetValue(CString &strValue,CString &strUnit)const
{
	strValue.Empty();
	strUnit.Empty();
	return TRUE;
}

template<UINT size>
TableFlyWeight<size>::TableFlyWeight()
{
}

template<UINT size>
TableFlyWeight<size>::TableFlyWeight(const TableFlyWeight<size> &ref):FlyWeight(ref)
{
	m_list = ref.m_list;
}

template<UINT size>
TableFlyWeight<size>& TableFlyWeight<size>::operator=(const TableFlyWeight<size> &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	FlyWeight::operator =(ref);
	//释放堆内存
	//重新分配堆内存
	//赋值
	m_list = ref.m_list;
	return *this;
}

template<UINT size>
FlyWeight* TableFlyWeight<size>::DoClone()
{
	return new TableFlyWeight<size>(*this);
}

template<UINT size>
FlyWeight* TableFlyWeight<size>::CreatTableFlyWeight()
{
	return new TableFlyWeight<size>();
}

template<UINT size>
Iterator<StrArray<size> >* TableFlyWeight<size>::CreatIterator()const
{
	return m_list.CreatIterator();
}
#endif