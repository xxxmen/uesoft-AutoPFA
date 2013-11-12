// TableData.h: interface for the TableData class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：TableData.h
  摘要：    AFTn维数据表格
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TABLEDATA_H__9F581750_6B02_45DB_828E_F7CC3D30F60F__INCLUDED_)
#define AFX_TABLEDATA_H__9F581750_6B02_45DB_828E_F7CC3D30F60F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "TableBase.h"

template <UINT size> 
class Table:public TableBase
{
public:
	virtual BOOL Read(CStdioFile &file);
	virtual BOOL Save(CStdioFile &file);
	virtual void Init();
public:
	Table(){};
    virtual ~Table(){};
	CString InitData(CString strData);
	TableData<size>& DataData();
	RowObjectFace<size>& UnitData();

public:
	StrArray<size> Unit();
	void Unit(const StrArray<size>& strValue);
	ListImp<StrArray<size> > Data();
	void Data(const ListImp<StrArray<size> >& strValue);

protected:
	RowObjectFace<size> m_Unit;			//第一项数据单位\第二项数据单位
	TableData<size>     m_Data;

//m_Num决定了Table读入数据的个数。AFT在保存子工况数据时这种表示数量的的数据都会写入文件，但是瞬变数据数量没有写入文件
//所以如果子工况的m_Num为空必须查找父工况m_Num来决定m_Data数据的个数。（）
};

template<UINT size>
BOOL Table<size>::Read(CStdioFile &file)
{
	return TRUE;
}

template<UINT size>
BOOL Table<size>::Save(CStdioFile &file)
{
	return TRUE;
}

template<UINT size>
void Table<size>::Init()
{
	
}

template<UINT size>
RowObjectFace<size>& Table<size>::UnitData()
{
	return m_Unit;
}

template<UINT size>
TableData<size>& Table<size>::DataData()
{
	return m_Data;
}

template<UINT size>
CString Table<size>::InitData(CString strData)
{
	strData = m_Unkown.InitData(strData);
	strData = m_Num.InitData(strData);
	strData = m_Unit.InitData(strData);
	strData = m_Data.InitData(strData,Num());
	return strData;
}


/*------------------------------------------*/
template<UINT size>
StrArray<size> Table<size>::Unit()
{
	return m_Unit.GetArray();
}

template<UINT size>
void Table<size>::Unit(const StrArray<size>& strValue)
{
	m_Unit.SetArray(strValue);
}

/*------------------------------------------*/
template<UINT size>
ListImp<StrArray<size> > Table<size>::Data()
{
	return m_Data.GetData();
}

template<UINT size>
void Table<size>::Data(const ListImp<StrArray<size> >& strValue)
{
	int n = strValue.GetCount();
	m_Num.SetData(n);
	m_Data.SetData(strValue);
	if(n > 0)
	{//瞬变数据表中存在数据，将瞬变数据前的分割符移到最后。瞬变数据前改为逗号分割
		TCHAR chSeparator = m_Unit.GetSeparator();
		m_Unit.SetSeparator(',');
		m_Data.SetSeparator(chSeparator);
	}
	
}


typedef  Table<2> TwoDTable;
typedef  Table<3> ThreeDTable;

#endif // !defined(AFX_TABLEDATA_H__9F581750_6B02_45DB_828E_F7CC3D30F60F__INCLUDED_)
