/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：RawDataTable.h
  摘要：    
  author  : LSP          
*/

#ifndef RAWDATATABLE_H
#define RAWDATATABLE_H
#include "PersistentObj.h"
#include "TableData.h"


template<UINT size>
class RawDataTable: public Table<size>
{
public:
	static RawDataTable<size>* CreatRawDataTable();
	BOOL Save(CStdioFile &file);
	BOOL Read(CStdioFile &file);
	void Init();
	RawDataTable();
	virtual ~RawDataTable(){};
private:
	void AppendArray();
	
};

template<UINT size>
RawDataTable<size>::RawDataTable()
{
	AppendArray();
}

template<UINT size>
RawDataTable<size>* RawDataTable<size>::CreatRawDataTable()
{
	return new RawDataTable<size>();
}

template<UINT size>
void RawDataTable<size>:: AppendArray()
{
	m_Unit.SetSeparator('\n');
	m_RowArray.SetSize(4);
	m_RowArray.SetAt(0,&m_Unkown.Data());
	m_RowArray.SetAt(1,&m_Num.Data());
	m_RowArray.SetAt(2,&m_Unit.Data());
	m_RowArray.SetAt(3,&m_Data.Data());
}

template<UINT size>
BOOL RawDataTable<size>::Read(CStdioFile &file)
{
	CString strTemp;
	file.ReadString(strTemp);
	InitData(strTemp);
	return TRUE;
}
template<UINT size>
BOOL RawDataTable<size>::Save(CStdioFile &file)
{
	BOOL bRet = TRUE;
	CString strSave;
	int nNum = m_RowArray.GetSize();
	for(int i=0;i<nNum;i++)
	{
		RowObject *pObject = m_RowArray.GetAt(i);
		strSave += pObject->Save();
	}
	file.WriteString(strSave);
	return bRet;
}

template<UINT size>
void RawDataTable<size>::Init()
{
	
}

#endif
