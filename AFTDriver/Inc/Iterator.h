#ifndef ITERATOR_H
#define ITERATOR_H
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Itertor.h
  摘要：    
  author  : LSP          
*/


template<class ObjClass>
class Iterator
{
public:
	virtual ~Iterator() {};
	Iterator(){};
public:
	virtual void Fist() = 0;
	virtual bool IsDone() = 0;
	virtual void Next() = 0;
	virtual ObjClass& CurrentItem()const = 0;
	virtual int CurrentKey()const=0;
};


template<class ObjClass>
class IteratorPtr
{
public:
	IteratorPtr(Iterator<ObjClass> *i):m_i(i){}
	~IteratorPtr(){delete m_i;}
	Iterator<ObjClass>* operator->(){return m_i;}
	Iterator<ObjClass>& operator*(){return *m_i;}

private:
	Iterator<ObjClass> *m_i;
	IteratorPtr(const IteratorPtr&);
	IteratorPtr& operator=(const IteratorPtr&);
};

template<class ObjClass>
class ListIterator:public Iterator<ObjClass>
{
public:
	ListIterator(const CList<ObjClass*,ObjClass*> *list);
	virtual ~ListIterator(){};
    virtual void Fist();
	virtual bool IsDone();
	virtual void Next();
	virtual ObjClass& CurrentItem()const;
	virtual int CurrentKey()const;
private:
	const CList<ObjClass*,ObjClass*> *m_list;
	POSITION m_pos;
};

template<class ObjClass>
ListIterator<ObjClass>::ListIterator(const CList<ObjClass*,ObjClass*> *list)
:m_list(list),m_pos(NULL)
{
}

template<class ObjClass>
void ListIterator<ObjClass>::Fist()
{
	m_pos = m_list->GetHeadPosition();
}

template<class ObjClass>
bool ListIterator<ObjClass>::IsDone()
{
	if(m_pos)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

template<class ObjClass>
void ListIterator<ObjClass>::Next()
{
	m_list->GetNext(m_pos);
}

template<class ObjClass>
ObjClass& ListIterator<ObjClass>::CurrentItem()const
{
	ASSERT(m_pos != NULL);
	return *m_list->GetAt(m_pos);
}

template<class ObjClass>
int ListIterator<ObjClass>::CurrentKey()const
{
	return -1;
}
//
template<class ObjClass>
class MapIterator:public Iterator<ObjClass>
{
public:
	MapIterator(const CMap<int,int,ObjClass*,ObjClass*> *map);
	virtual ~MapIterator(){};
    virtual void Fist();
	virtual bool IsDone();
	virtual void Next();
	virtual ObjClass& CurrentItem()const;
	virtual int CurrentKey()const;
private:
	const CMap<int,int,ObjClass*,ObjClass*> *m_map;
	POSITION m_pos;
	ObjClass *m_CurItem;
	int      m_nKey;
};

template<class ObjClass>
MapIterator<ObjClass>::MapIterator(const CMap<int,int,ObjClass*,ObjClass*> *map)
:m_map(map),m_pos(NULL),m_CurItem(NULL)
{
	
}

template<class ObjClass>
void MapIterator<ObjClass>::Fist()
{
	m_pos = m_map->GetStartPosition();
}

template<class ObjClass>
bool MapIterator<ObjClass>::IsDone()
{
	if(m_pos)
	{
		m_map->GetNextAssoc(m_pos,m_nKey,m_CurItem);
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

template<class ObjClass>
void MapIterator<ObjClass>::Next()
{
	
}

template<class ObjClass>
ObjClass& MapIterator<ObjClass>::CurrentItem()const
{
	return *m_CurItem;
}

template<class ObjClass>
int MapIterator<ObjClass>::CurrentKey()const
{
	return m_nKey;
}

#endif