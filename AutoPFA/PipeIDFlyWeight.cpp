// PipeIDFlyWeight.cpp: implementation of the PipeIDFlyWeight class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "PipeIDFlyWeight.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipeIDFlyWeight::PipeIDFlyWeight()
{

}
PipeIDFlyWeight::PipeIDFlyWeight(const PipeIDFlyWeight &ref):FlyWeight(ref)
{
	m_list = ref.m_list;
}

PipeIDFlyWeight& PipeIDFlyWeight::operator=(const PipeIDFlyWeight &ref)
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
PipeIDFlyWeight::~PipeIDFlyWeight()
{

}

FlyWeight* PipeIDFlyWeight::CreatPipeIDFlyWeight()
{
	return new PipeIDFlyWeight;
}

BOOL PipeIDFlyWeight::IsEmpty()const
{
	return m_list.IsEmpty();
}

void PipeIDFlyWeight::Assign(FlyWeight *pFly)
{
	assert(typeid(*this)==typeid(*pFly));
	*this = *dynamic_cast<PipeIDFlyWeight*>(pFly);
}

BOOL PipeIDFlyWeight::IsEqual(FlyWeight &ref) const
{
	PipeIDFlyWeight *pComp = NULL;
	if(typeid(*this)==typeid(ref))
	{
		pComp = dynamic_cast<PipeIDFlyWeight*>(&ref);
		return m_list.IsEqual(pComp->m_list);
	}
	else
	{
		return FALSE;
	}
}

FlyWeight* PipeIDFlyWeight::DoClone()
{
	return new PipeIDFlyWeight(*this);
}


void PipeIDFlyWeight::AddItem(int nKey)
{
	//由于int类型没有函数Key使用AddUniqueItem；
	m_list.AddUniqueItem(nKey);
}
void PipeIDFlyWeight::AddItem(CString strKey)
{
	AddItem(_ttoi(strKey));
}
void PipeIDFlyWeight::DelItem(int nKey)
{
	m_list.DelItem(nKey);
}
void PipeIDFlyWeight::Empty()
{
	m_list.DelList();
}
Iterator<int>* PipeIDFlyWeight::CreatIterator()const
{
	return m_list.CreatIterator();
}

int PipeIDFlyWeight::GetCount() const
{
	return m_list.GetCount();
}

BOOL PipeIDFlyWeight::GetValue(CString &StrValue, CString &strUnit) const
{
	StrValue.Empty();
	CString strItem;
	int nKey = 0;
	IteratorPtr<int> IdItPtr(m_list.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nKey = IdItPtr->CurrentItem();
		strItem.Format(_T("%d,"),nKey);
		StrValue +=strItem;
	}
	return TRUE;
}

BOOL PipeIDFlyWeight::GetValue(CString &strValue) const
{
	return FALSE;
}

BOOL PipeIDFlyWeight::IsExist(int nKey)
{
	return m_list.IsExist(nKey);
}

void PipeIDFlyWeight::SetData(const ListImp<StrArray<1> >&ref)
{
	Empty();
	StrArray<1> Item;
	IteratorPtr<StrArray<1> > IdItPtr(ref.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		Item = IdItPtr->CurrentItem();
		ASSERT(!Item.IsEmpty());
		AddItem(Item.Data());
	}
}

void PipeIDFlyWeight::GetData(ListImp<StrArray<1> >&ref)
{
	int nKey = 0;
	CString strTemp;
	StrArray<1> Item;
	ref.DelList();
	IteratorPtr<int> IdItPtr(CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		nKey = IdItPtr->CurrentItem();
		strTemp.Format(_T("%d"),nKey);
		Item.Data(strTemp);
		ref.AddItem(Item);
	}
}

void PipeIDFlyWeight::SetNull()
{
	Empty();
}
