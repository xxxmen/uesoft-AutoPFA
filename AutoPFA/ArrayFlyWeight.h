#ifndef ARRAYFLYWEIGHT_H
#define ARRAYFLYWEIGHT_H
#include "StdAfx.h"
#include "FlyWeight.h"
#include "ListFlyWeightImp.h"
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：ArrayFiyWeight.h
  摘要：    
  author  : LSP          
*/
template<UINT size>
class ArrayFlyWeight:public FlyWeight 
{
public:
	void SetNull();
	BOOL IsEmpty()const;
	void Assign(FlyWeight *pFly);
	BOOL IsEqual(FlyWeight &ref)const;
    BOOL GetValue(CString &strValue)const;
    BOOL GetValue(CString &strValue,CString &strUnit)const;
	CString GetValue(int Index = 0)const;
	int GetnValue(int Index = 0)const;
	float GetfValue(int Index = 0)const;
	void SetValue(CString strValue,int Index = 0);
	void SetValue(int nValue,int Index = 0);
	void SetValue(float dValue,int Index = 0);
    StrArray<size>& GetData();
	void SetData(const StrArray<size>& ref);
	static FlyWeight* CreatArrayFlyWeight();
	ArrayFlyWeight();
	ArrayFlyWeight(const ArrayFlyWeight &ref);
	ArrayFlyWeight& operator=(const ArrayFlyWeight &ref);
	virtual ~ArrayFlyWeight(){};
private:
	StrArray<size> m_array;
	virtual FlyWeight*  DoClone();
};

template<UINT size>
StrArray<size>& ArrayFlyWeight<size>::GetData()
{
	return m_array;
}

template<UINT size>
void ArrayFlyWeight<size>::SetData(const StrArray<size>& ref)
{
	m_array = ref;
}

template<UINT size>
void ArrayFlyWeight<size>::SetNull()
{
	m_array.InitData(_T(""));
}

template<UINT size>
BOOL ArrayFlyWeight<size>::IsEmpty()const
{
	return m_array.IsEmpty();
}

template<UINT size>
void ArrayFlyWeight<size>::Assign(FlyWeight *pFly)
{
	assert(typeid(*this)==typeid(*pFly));
	*this = *dynamic_cast<ArrayFlyWeight<size>* >(pFly);
}

template<UINT size>
BOOL ArrayFlyWeight<size>::IsEqual(FlyWeight &ref)const
{
	ArrayFlyWeight<size> *pComp = NULL;
	if(typeid(*this)==typeid(ref))
	{
		pComp = dynamic_cast<ArrayFlyWeight<size>*>(&ref);
		return (m_array==pComp->m_array);
	}
	else
	{
		return FALSE;
	}
}

template<UINT size>
CString ArrayFlyWeight<size>::GetValue(int Index)const
{
	ASSERT(Index<size);
	return m_array.Data(Index);
}

template<UINT size>
int ArrayFlyWeight<size>::GetnValue(int Index)const
{
	ASSERT(Index<size);
	return m_array.nData(Index);
}

template<UINT size>
float ArrayFlyWeight<size>::GetfValue(int Index)const
{
	ASSERT(Index<size);
	return m_array.fData(Index);
}

template<UINT size>
void ArrayFlyWeight<size>::SetValue(CString strValue,int Index)
{
	ASSERT(Index<size);
	m_array.Data(strValue,Index);
}

template<UINT size>
void ArrayFlyWeight<size>::SetValue(int nValue,int Index)
{
	ASSERT(Index<size);
	m_array.Data(nValue,Index);
}
template<UINT size>
void ArrayFlyWeight<size>::SetValue(float fValue,int Index)
{
	ASSERT(Index<size);
	m_array.Data(fValue,Index);
}

template<UINT size>
BOOL ArrayFlyWeight<size>::GetValue(CString &strValue)const
{
	strValue.Empty();
	return TRUE;
}

template<UINT size>
BOOL ArrayFlyWeight<size>::GetValue(CString &strValue,CString &strUnit)const
{
	if(size>=3)
	{
		//特殊处理
		strValue = m_array.Data(size-2) + _T(" ") + m_array.Data(size-1);
		strUnit.Empty();
	}
	else
	{
		strValue.Empty();
		strUnit.Empty();
	}
	return TRUE;
}

template<UINT size>
ArrayFlyWeight<size>::ArrayFlyWeight()
{
}

template<UINT size>
ArrayFlyWeight<size>::ArrayFlyWeight(const ArrayFlyWeight<size> &ref):FlyWeight(ref)
{
	m_array = ref.m_array;
}

template<UINT size>
ArrayFlyWeight<size>& ArrayFlyWeight<size>::operator=(const ArrayFlyWeight<size> &ref)
{
	//判断自赋值
	if(this == &ref)
		return *this;
    //调用基类赋值
	FlyWeight::operator =(ref);
	//释放堆内存
	//重新分配堆内存
	//赋值
	m_array = ref.m_array;
	return *this;
}

template<UINT size>
FlyWeight* ArrayFlyWeight<size>::DoClone()
{
	return new ArrayFlyWeight<size>(*this);
}

template<UINT size>
FlyWeight* ArrayFlyWeight<size>::CreatArrayFlyWeight()
{
	return new ArrayFlyWeight<size>();
}
#endif