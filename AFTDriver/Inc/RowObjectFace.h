#ifndef ROWOBJECTFACE_H
#define ROWOBJECTFACE_H
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：RowObjectFace.h
  摘要：  RowObjectFace能够从一串字符中读出指定个数的分割符号和分割符号间的字符
          提供接口得到和设置RowObjectFace的字符。
  author  : LSP          
*/
#include "RowObject.h"
#include "ListFlyWeightImp.h"

template<int size> 
class RowObjectFace
{
public:
	virtual ~RowObjectFace() {};
	RowObjectFace();

public:
	RowObject& Data();
	CString InitData(CString strData);
	CString InitData(CString strData,int nNum);
	void SetArray(const StrArray<size> &ref);
	void SetData(int nData,int nIndex=0);
	void SetData(double dData,int nIndex=0);
	void SetData(CString strData,int nIndex=0);
	void SetSeparator(TCHAR chSeparator);
	TCHAR GetSeparator();
	void SetData(long nData,int nIndex=0);
	
	StrArray<size> GetArray();
	void GetData(int &nData,int nIndex=0);
	void GetData(double &dData,int nIndex=0);
	void GetData(CString &strData,int nIndex=0);
	void GetData(long &nData,int nIndex=0);
	CString GetData();

private:
	RowObjectFace(const RowObjectFace &ref);
	RowObjectFace& operator=(const RowObjectFace &ref);
	RowObject m_Data;
};

template<int size>
RowObjectFace<size>::RowObjectFace()
{
	RowObject Object;
	for(int i=1;i<size;i++)
	{
		m_Data.AddChild(Object);
	}
}


template<int size>
RowObject& RowObjectFace<size>::Data()
{
	return m_Data;
}

template<int size>
CString RowObjectFace<size>::InitData(CString strData)
{
	strData = m_Data.Read(strData);
	RowObject Object;
	for(int i=1;i<size;i++)
	{
		strData = Object.Read(strData);
		m_Data.SetChild(i,Object);
	}
	return strData;
}

template<int size>
CString RowObjectFace<size>::InitData(CString strData,int nNum)
{
	ASSERT(nNum<size);
	strData = m_Data.Read(strData);
	RowObject Object;
	for(int i=1;i<size;i++)
	{
		if(i<nNum+1)
		{
			strData = Object.Read(strData);
		}
		else
		{
			//call by ControlvalveData
			Object.SetData(_T(""));
			Object.SetSeparator(_T(' '));
		}	
		m_Data.SetChild(i,Object);
	}
	return strData;
}

template<int size>
CString RowObjectFace<size>::GetData()
{
	return m_Data.GetData();
}

template<int size>
void RowObjectFace<size>::SetArray(const StrArray<size> &ref)
{
	CString strTemp;
	for(int i=0;i<size;i++)
	{
		strTemp = ref.Data(i);
		SetData(strTemp,i);
	}
}

template<int size>
StrArray<size> RowObjectFace<size>::GetArray()
{
	 CString strTemp;
	 StrArray<size> ret;
	 for(int i=0;i<size;i++)
	 {
		 GetData(strTemp,i);
		 ret.Data(strTemp,i);
	 }
	 return ret;
}

template<int size>
void RowObjectFace<size>::GetData(CString &strData,int Index)
{
	ASSERT(Index<size);
	 m_Data.GetData(strData,Index);
}

template<int size>
void RowObjectFace<size>::GetData(int &nData,int nIndex)
{
	ASSERT(nIndex<size);
	m_Data.GetData(nData,nIndex);
}

template<int size>
void RowObjectFace<size>::GetData(double &dData,int nIndex)
{
	ASSERT(nIndex<size);
	m_Data.GetData(dData,nIndex);
}

template<int size>
void RowObjectFace<size>::GetData(long &nData,int nIndex)
{
	ASSERT(Index<size);
	m_Data.GetData(nData,Index);
}
template<int size>
void RowObjectFace<size>::SetData(CString strData,int nIndex)
{
	ASSERT(nIndex<size);
	m_Data.SetData(strData,nIndex);
}

template<int size>
void RowObjectFace<size>::SetData(int nData,int nIndex)
{
	ASSERT(nIndex<size);
	m_Data.SetData(nData,nIndex);
}

template<int size>
void RowObjectFace<size>::SetData(double dData,int nIndex)
{
	ASSERT(nIndex<size);
	m_Data.SetData(dData,nIndex);
}

template<int size>
void RowObjectFace<size>::SetData(long nData,int nIndex)
{
	ASSERT(nIndex<size);
	m_Data.SetData(nData,nIndex);
}
template<int size>
void RowObjectFace<size>::SetSeparator(TCHAR chSeparator)
{
	m_Data.SetSeparator(chSeparator,size-1);
}

template<int size>
TCHAR RowObjectFace<size>::GetSeparator()
{
	return m_Data.GetSeparator(size-1);
}
/*------------------------------------------------------------*/
template<UINT size,UINT Index> 
class VariableFace
{
public:
	virtual ~VariableFace() {};
	VariableFace(){ASSERT(size>Index);};

public:
	RowObject& Data();
	CString InitData(CString strData);
	void SetArray(const StrArray<size> &ref);
	StrArray<size> GetArray();
private:
	VariableFace(const VariableFace &ref);
	VariableFace& operator=(const VariableFace &ref);
	RowObjectFace<size> m_Data;
};
template<UINT size,UINT Index>
RowObject& VariableFace<size,Index>::Data()
{
	return m_Data.Data();
}

template<UINT size,UINT Index>
CString VariableFace<size,Index>::InitData(CString strData)
{
	//读索引前面的数据包括索引（从0开始）
	strData = m_Data.Data().Read(strData);
	RowObject Object;
	int nNum = 0;
	for(int i=1;i<Index+1;i++)
	{
		strData = Object.Read(strData);
		m_Data.Data().SetChild(i,Object);
	}
	//得到索引处的数据；
	m_Data.GetData(nNum,Index);
	if(m_Data.Data().GetData().IsEmpty())
	{
		m_Data.SetData(_T(""),Index);
	}
	nNum = abs(nNum);
	//索引处的数据必须小于总剩下的空间即size - Index；
	ASSERT(nNum <= (size - Index));
	for(int j=1;j<nNum+1;j++)
	{
		strData = Object.Read(strData);
		m_Data.Data().SetChild(j+Index,Object);
	}
	for(int k=Index+nNum+1;k<size;k++)
	{
		Object.SetData(_T(""));
		Object.SetSeparator(_T(' '));
		m_Data.Data().SetChild(k,Object);
	}
	return strData;
}
template<UINT size,UINT Index>
void VariableFace<size,Index>::SetArray(const StrArray<size> &ref)
{
	int nNum = abs(ref.nData(Index));
	RowObject Object;
	m_Data.SetArray(ref);
	for(int k=Index+nNum+1;k<size;k++)
	{
		Object.SetData(_T(""));
		Object.SetSeparator(_T(' '));
		m_Data.Data().SetChild(k,Object);
	}
}

template<UINT size,UINT Index>
StrArray<size> VariableFace<size,Index>::GetArray()
{
	 return m_Data.GetArray();
}
/*----------------------------------------------------------*/
//AFT数据表
template<int colSize>
class TableData
{
public:
	virtual ~TableData() {};
	TableData(){m_RowSize=0;};
		
public:
	RowObject& Data();
	CString InitData(CString strData,int rowSize);
	void SetSeparator(TCHAR chSeparator);
	void SetData(const ListImp<StrArray<colSize> > &ref);
	ListImp<StrArray<colSize> > GetData();
		
private:
	TableData(const TableData &ref);
	TableData& operator=(const TableData &ref);
	RowObject m_Data;
	int m_RowSize;
};

template<int colSize>
void TableData<colSize>::SetData(const ListImp<StrArray<colSize> > &ref)
{
	m_Data.RemoveAll();
	m_RowSize = ref.GetCount();
	StrArray<colSize> array;
	CString strTemp;
	RowObject Object;
	int i = 0;
	IteratorPtr<StrArray<colSize> > IdItPtr(ref.CreatIterator());
	for(IdItPtr->Fist();!IdItPtr->IsDone();IdItPtr->Next())
	{
		array = IdItPtr->CurrentItem();
		for(int j=0;j<colSize;j++)
		{
			strTemp = array.Data(j);
			if(0==i && 0==j)
			{
				m_Data.SetData(strTemp);
				m_Data.SetSeparator(',');
			}
			else
			{
				Object.SetData(strTemp);
				m_Data.SetChild(i*colSize+j,Object);
			}
		}
		i++;
	}
}

template<int colSize>
ListImp<StrArray<colSize> > TableData<colSize>::GetData()
{
	if(m_RowSize != 0)
	{
		ASSERT(m_Data.GetChildNum()== m_RowSize*colSize-1);
	}
	ListImp<StrArray<colSize> > ret;
	CString strTemp;
	StrArray<colSize> array;
	ret.DelList();
	for(int i=0;i<m_RowSize*colSize;i++)
	{
		m_Data.GetData(strTemp,i);
		array.Data(strTemp,i%colSize);
		if(((i+1)%colSize)==0)
		{
			ret.AddItem(array);
		}
	}
	return ret;
}

template<int colSize>
RowObject& TableData<colSize>::Data()
{
	return m_Data;
}

template<int colSize>
CString TableData<colSize>::InitData(CString strData,int rowSize)
{
	m_RowSize = rowSize;
	strData = m_Data.Read(strData,colSize*rowSize);
	return strData;
}

template<int colSize>
void TableData<colSize>::SetSeparator(TCHAR chSeparator)
{
	m_Data.SetSeparator(chSeparator,colSize*m_RowSize-1);
}
#endif