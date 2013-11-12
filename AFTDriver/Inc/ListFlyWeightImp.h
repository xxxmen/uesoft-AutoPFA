#ifndef LISTFLYWEIHTIMP_H
#define LISTFLYWEIHTIMP_H
#include "Iterator.h"

/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：LISTFLYWEIHTIMP_H
  摘要：  StrArray为可以设置长度的CString数组，  
  author  : LSP          
*/

template<UINT size> 
class StrArray
{
public:
	virtual ~StrArray() {};
	StrArray(){};
	StrArray(int nKey)
	{
		InitData(_T("0"));
		assert(size>0);
		CString strKey;
		strKey.Format(_T("%d"),nKey);
		m_Data[0] = strKey;
	};
	int Key();   //数组的第一个数转化成整型作为Key
	CString Data(int nIndex =0)const;//得到指点索引的字符
	int nData(int nIndex =0)const;
	float fData(int nIndex =0)const;
 	void Data(CString strData,int nIndex = 0);//设置指定索引的值；
	void Data(int nData,int nIndex);//设置指定索引的值；
	void Data(float fData,int nIndex);//设置指定索引的值；
	void Data(double dData,int nIndex);//设置指定索引的值；
	void InitData(CString strData);//初始化所有字符
	BOOL IsEmpty()const;
	BOOL operator==(const StrArray<size> &ref) const;//判断数组是否相等
	StrArray(const StrArray<size> &ref);
	StrArray& operator=(const StrArray<size> &ref);

private:
	CString m_Data[size];
};

template<UINT size>
StrArray<size>::StrArray(const StrArray<size> &ref)
{
	for(int i=0;i<size;i++)
	{
		m_Data[i] = ref.m_Data[i];
	}
}

template<UINT size>
StrArray<size>& StrArray<size>::operator=(const StrArray<size> &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	//释放堆内存
	
	//重新分配堆内存
	//赋值
	for(int i=0;i<size;i++)
	{
		m_Data[i] = ref.m_Data[i];
	}
	return *this;
}

template<UINT size>
BOOL StrArray<size>::operator==(const StrArray<size> &ref) const
{
	for(UINT i=0;i<size;i++)
	{
		if(m_Data[i].CompareNoCase(ref.m_Data[i])!=0)
			return FALSE;
	}
	return TRUE;
}

template<UINT size>
int StrArray<size>::Key()
{
	ASSERT(size>0);
	return _ttoi(m_Data[0]);
}

template<UINT size>
void StrArray<size>::Data(CString strData,int nIndex)
{
	ASSERT(size>nIndex);
	m_Data[nIndex] = strData;
}

template<UINT size>
void StrArray<size>::Data(int nData,int nIndex)
{
	ASSERT(size>nIndex);
	m_Data[nIndex].Format(_T("%d"),nData);
}

template<UINT size>
void StrArray<size>::Data(float fData,int nIndex)
{
	ASSERT(size>nIndex);
	m_Data[nIndex].Format(_T("%f"),fData);
}

template<UINT size>
void StrArray<size>::Data(double dData,int nIndex)
{
	ASSERT(size>nIndex);
	m_Data[nIndex].Format(_T("%.12f"),dData);
}

template<UINT size>
CString StrArray<size>::Data(int nIndex)const
{
	ASSERT(size>nIndex);
	return m_Data[nIndex];
}
template<UINT size>
int StrArray<size>::nData(int nIndex)const
{
	ASSERT(size>nIndex);
	return _ttoi(m_Data[nIndex]);
}
template<UINT size>
float StrArray<size>::fData(int nIndex)const
{
	ASSERT(size>nIndex);
	return float(_tcstod(m_Data[nIndex] , '\0') );
}
template<UINT size>
void StrArray<size>::InitData(CString strData)
{
	for(int i=0;i<size;i++)
	{
		m_Data[i] =strData;
	}
}

template<UINT size>
BOOL StrArray<size>::IsEmpty()const
{
	for(int i=0;i<size;i++)
	{
		if(!m_Data[i].IsEmpty())
			return FALSE;
	}
	return TRUE;
}

template<class Item>
class ListImp
{
public:
	ListImp(){};
	~ListImp();
	ListImp(const CList<Item*,Item*> &ref);
	ListImp(const ListImp<Item> &ref);
	ListImp& operator=(const ListImp<Item> &ref);
	
	Iterator<Item>* CreatIterator()const;
	int GetCount()const;
	Item* GetHead()const;
	Item& AddUniqueItem(Item &item);
	void AddItem(Item &item);
	void AddItem(Item *pItem);
	void AddItem(Item &item,int nKey);//如果存在nKey or -nKey都不增加
	BOOL DelItem(Item &item);
	BOOL DelKey(int nKey);
	BOOL IsEmpty()const;
	BOOL IsEqual(ListImp &ref)const;
	void DelList();
	BOOL IsExistKey(Item *&pItem,int nKey);
	BOOL IsExist(Item &item,Item *&pItem);
	BOOL IsExist(Item &item)const;

	//当Item为StrArray
	BOOL ToDuoble(double dArray[],int nIndex)const;
	void ToDuoble(double dArray[],int nKey,int nSubKey)const;
	BOOL HasData(int nIndex)const;
	BOOL GetMaxMin(double &dMax,double &dMin,int nIndex = 0);
private:
	void CloneList(const ListImp &ref);
	CList<Item*,Item*> m_list;
};

template<class Item>
BOOL ListImp<Item>::GetMaxMin(double &dMax,double &dMin,int nIndex)
{
	double dArray[100];
	int nNum = m_list.GetCount();
	if(ToDuoble(dArray,nIndex))
	{
		MaxMin(dArray,nNum,dMax,dMin);
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

template<class Item>
BOOL ListImp<Item>::HasData(int nIndex)const
{
	int nNum = m_list.GetCount();
	if(nNum==0)
		return FALSE;
	ASSERT(nNum < 100);
	POSITION pos = m_list.GetHeadPosition();
	Item *pItem = NULL;
	int i = 0;
	double d;
	while(pos)
	{
		pItem = m_list.GetNext(pos);
		d = pItem->fData(nIndex);
		if(-0.000001>d || d>0.000001)
			return TRUE;
		i++;
	}
	return FALSE;
}

template<class Item>
BOOL ListImp<Item>::ToDuoble(double dArray[],int nIndex)const
{
	int nNum = m_list.GetCount();
	if(nNum==0)
		return FALSE;
	ASSERT(nNum < 100);
	POSITION pos = m_list.GetHeadPosition();
	Item *pItem = NULL;
	int i = 0;
	while(pos)
	{
		pItem = m_list.GetNext(pos);
		if(pItem->Data(nIndex).IsEmpty()
			||pItem->Data(nIndex).CompareNoCase(_T("-9E+29"))==0)
			return FALSE;
		dArray[i] = pItem->fData(nIndex);
		i++;
	}
	return TRUE;
}

template<class Item>
void ListImp<Item>::ToDuoble(double dArray[],int nKey,int nSubKey)const
{
	int nNum = m_list.GetCount();
	if(nNum==0)
		return;
	POSITION pos = m_list.GetHeadPosition();
	Item *pItem = NULL;
	int i = 0;
	while(pos)
	{
		pItem = m_list.GetNext(pos);
		dArray[i] = pItem->Data(nKey,nSubKey);
		i++;
	}
}

template<class Item>
Item* ListImp<Item>::GetHead()const
{
	return m_list.GetHead();
}

template<class Item>
void ListImp<Item>::DelList()
{
	POSITION pos = m_list.GetHeadPosition();
	Item *pItem = NULL;
	while(pos)
	{
		pItem = m_list.GetNext(pos);
		delete pItem;
	}
	m_list.RemoveAll();
}

template<class Item>
void ListImp<Item>::CloneList(const ListImp<Item> &ref)
{
	POSITION pos = ref.m_list.GetHeadPosition();
	Item *pItem = NULL;
	Item *pNewItem = NULL;
	while(pos)
	{
		pItem = ref.m_list.GetNext(pos);
		pNewItem = new Item(*pItem);
		m_list.AddTail(pNewItem);
	}
}

template<class Item>
ListImp<Item>::~ListImp()
{
	DelList();
}

template<class Item>
ListImp<Item>::ListImp(const ListImp<Item>&ref)
{
	CloneList(ref);
}

template<class Item>
ListImp<Item>::ListImp(const CList<Item*,Item*> &ref)
{
	POSITION pos = ref.GetHeadPosition();
	Item *pItem = NULL;
	Item *pNewItem = NULL;
	while(pos)
	{
		pItem = ref.GetNext(pos);
		pNewItem = new Item(*pItem);
		m_list.AddTail(pNewItem);
	}
}

template<class Item>
ListImp<Item>& ListImp<Item>::operator=(const ListImp<Item> &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	//释放堆内存
	DelList();
	//重新分配堆内存
	//赋值
    CloneList(ref);
	return *this;
}

template<class Item>
BOOL ListImp<Item>::IsExistKey(Item *&pItem,int nKey)
{
	POSITION pos = m_list.GetHeadPosition();
	while(pos)
	{
		pItem = m_list.GetNext(pos);
		if(pItem->Key() == nKey)
		{
			return TRUE;
		}
	}
	return FALSE;
}

template<class Item>
BOOL ListImp<Item>::IsExist(Item &item,Item *&pItem)
{
	POSITION pos = m_list.GetHeadPosition();
	while(pos)
	{
		pItem = m_list.GetNext(pos);
		if(*pItem == item)
		{
			return TRUE;
		}
	}
	return FALSE;
}
template<class Item>
BOOL ListImp<Item>::IsExist(Item &item)const
{
	Item *pItem = NULL;
	POSITION pos = m_list.GetHeadPosition();
	while(pos)
	{
		pItem = m_list.GetNext(pos);
		if(*pItem == item)
		{
			return TRUE;
		}
	}
	return FALSE;
}
template<class Item>
Item& ListImp<Item>::AddUniqueItem(Item &item)
{
	Item *pNewItem = NULL;
	if(!IsExist(item,pNewItem))
	{
		pNewItem = new Item(item);
		m_list.AddTail(pNewItem);
		return *pNewItem;
	}
	return *pNewItem;
}

template<class Item>
void ListImp<Item>::AddItem(Item &item,int nKey)
{
	Item *pNewItem = NULL;
	if(!(IsExistKey(pNewItem,nKey)||IsExistKey(pNewItem,-nKey)))
	{
		pNewItem = new Item(item);
	    m_list.AddTail(pNewItem);
	}
}

template<class Item>
void ListImp<Item>::AddItem(Item &item)
{
	Item *pNewItem = NULL;
	pNewItem = new Item(item);
	m_list.AddTail(pNewItem);
}

template<class Item>
void ListImp<Item>::AddItem(Item *pItem)
{
	m_list.AddTail(pItem);
}

template<class Item>
BOOL ListImp<Item>::DelKey(int nKey)
{
	Item *pItem = NULL;
	if(IsExistKey(pItem,nKey))
	{
		POSITION pos = m_list.Find(pItem);
		m_list.RemoveAt(pos);
		delete pItem;
		return TRUE;
	}
	return FALSE;
}

template<class Item>
BOOL ListImp<Item>::DelItem(Item &item)
{
	Item *pItem = NULL;
	if(IsExist(item,pItem))
	{
		POSITION pos = m_list.Find(pItem);
		m_list.RemoveAt(pos);
		delete pItem;
		return TRUE;
	}
	return FALSE;
}

template<class Item>
int ListImp<Item>::GetCount()const
{
	return m_list.GetCount();
}

template<class Item>
BOOL ListImp<Item>::IsEmpty()const
{
	return m_list.IsEmpty();
}
template<class Item>
BOOL ListImp<Item>::IsEqual(ListImp &ref)const
{
	if(ref.GetCount()!= GetCount())
		return FALSE;
	POSITION pos = ref.m_list.GetHeadPosition();
	Item *pItem = NULL;
	while(pos)
	{
		pItem = ref.m_list.GetNext(pos);
		if(!IsExist(*pItem))
			return FALSE;
	}
	return TRUE;
}
template<class Item>
Iterator<Item>*ListImp<Item>::CreatIterator()const
{
	return new ListIterator<Item>(&m_list);
}


template<UINT size1,UINT size2>StrArray<size1+size2> Combi(StrArray<size1> &array1,StrArray<size2> &array2)
{
	StrArray<size1+size2> array;
	for(int i=0;i<size1;i++)
	{
		array.Data(array1.Data(i),i);
	}
	for(int j=0;j<size2;j++)
	{
		array.Data(array2.Data(j),j+size1);
	}
	return array;
};

template<UINT size1,UINT size2> ListImp<StrArray<size1+size2> > Combi(ListImp<StrArray<size1> >&list1,ListImp<StrArray<size2> >&list2)
{
	ASSERT(list1.GetCount()==list2.GetCount());
	ListImp<StrArray<size1+size2> > list;
	StrArray<size1+size2> array;
	StrArray<size1> array1;
	StrArray<size2> array2;
	list.DelList();

	int i = 0;
	int j = 0;
	IteratorPtr<StrArray<size1> > IdItPtr(list1.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		array1 = IdItPtr->CurrentItem();
		j = 0;
		IteratorPtr<StrArray<size2> > IdItPtr(list2.CreatIterator());
		for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
		{
			array2 = IdItPtr->CurrentItem();
			if(j == i)
			{
				break;
			}
			j++;
		}
		array = Combi<size1,size2>(array1,array2);
		list.AddItem(array);
		i++;
	}
	return list;
}

template<UINT size1,UINT size2> void Divided(StrArray<size1> &array1,StrArray<size2> &array2,const StrArray<size1+size2> &array)
{
	for(int i=0;i<size1;i++)
	{
		array1.Data(array.Data(i),i);
	}
	for(int j=0;j<size2;j++)
	{
		array2.Data(array.Data(j+size1),j);
	}
};

template<UINT size1,UINT size2> void Divided(ListImp<StrArray<size1> >&list1,ListImp<StrArray<size2> >&list2,const ListImp<StrArray<size1+size2> >& list)
{
	StrArray<size1+size2> array;
	StrArray<size1> array1;
	StrArray<size2> array2;
	list1.DelList();
	list2.DelList();

	IteratorPtr<StrArray<size1+size2> > IdItPtr(list.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		array = IdItPtr->CurrentItem();
		Divided<size1,size2>(array1,array2,array);
		list1.AddItem(array1);
		list2.AddItem(array2);
	}
}

#endif;