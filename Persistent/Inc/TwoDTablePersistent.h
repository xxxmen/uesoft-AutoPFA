// TwoDTablePersistent.h: interface for the TwoDTablePersistent class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：TwoDTablePersistent.h
  摘要：    二维数据表格
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TWODTABLEPERSISTENT_H__6207C165_B601_4B3C_A73E_0653AE50543A__INCLUDED_)
#define AFX_TWODTABLEPERSISTENT_H__6207C165_B601_4B3C_A73E_0653AE50543A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipeIDList.h"
template<UINT size>
class GridTablePersistent  
{
public:
	GridTablePersistent(){};
	virtual ~GridTablePersistent(){};

public:
	int Num();
	StrArray<size>& Unit();
	void Unit(const StrArray<size>& strValue);
	ListImp<StrArray<size> >& Data();
	ListImp<StrArray<size> >& DataToStd();
	void Data(const ListImp<StrArray<size> >& strValue,int nCount);
	void Data(const ListImp<StrArray<size> >& strValue);

private:
	StrArray<size>          m_Unit;			//第一项数据单位\第二项数据单位
	TablePerisist<size>     m_Data;

};
/*------------------------------------------*/
template<UINT size>
int GridTablePersistent<size>::Num()
{
	return m_Data.GetCount();
}

/*------------------------------------------*/
template<UINT size>
StrArray<size>& GridTablePersistent<size>::Unit()
{
	return m_Unit;
}

template<UINT size>
void GridTablePersistent<size>::Unit(const StrArray<size>& strValue)
{
	m_Unit = strValue;
}
/*------------------------------------------*/
template<UINT size>
ListImp<StrArray<size> >& GridTablePersistent<size>::Data()
{
	return m_Data.GetData();
}

template<UINT size>
ListImp<StrArray<size> >& GridTablePersistent<size>::DataToStd()
{
	for(int i=0;i<size;i++)
	{
		m_Data.TranToStd(i,m_Unit.Data(i));
	}
	return m_Data.GetData();
}

template<UINT size>
void GridTablePersistent<size>::Data(const ListImp<StrArray<size> >& strValue,int nCount)
{
	m_Data.SetData(strValue,nCount);
}

template<UINT size>
void GridTablePersistent<size>::Data(const ListImp<StrArray<size> >& strValue)
{
	m_Data.SetData(strValue);
}


typedef GridTablePersistent<2>  TwoDTablePersistent;
typedef GridTablePersistent<3>  ThreeDTablePersistent;
typedef GridTablePersistent<4>  RawDataPersistent;
/*------------------------------------------*/
#endif // !defined(AFX_TWODTABLEPERSISTENT_H__6207C165_B601_4B3C_A73E_0653AE50543A__INCLUDED_)
