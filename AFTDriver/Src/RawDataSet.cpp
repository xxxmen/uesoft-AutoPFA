// RawDataSet.cpp: implementation of the RawDataSet class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RawDataSet.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

RawDataSet::RawDataSet()
{
	m_RowArray.SetSize(1);
	m_RowArray.SetAt(0,&m_NumOfRawData);
	SetID("\n[RAW DATA SETS]");
	Init();
}

RawDataSet::~RawDataSet()
{

}

void RawDataSet::Init()
{
	CString strArray[1];
	strArray[0] = _T("Number Raw Data Sets= 0");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==1);
		m_RowArray.GetAt(i)->InitRow(strArray[i]);
	}
}

int RawDataSet::GetRawDataNum()
{
	int nRet=0;
	m_NumOfRawData.GetData(nRet,1);
	return nRet;
}
void RawDataSet::SetRawDataNum(int nNum)
{
	m_NumOfRawData.SetData(nNum,1);
}

BOOL RawDataSet::Save(CStdioFile &file)
{
	SetRawDataNum(m_list.GetCount());
	SaveRow(file);
	TableBase *pObj = NULL;
	IteratorPtr<TableBase> ItPtr(m_list.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pObj = &ItPtr->CurrentItem();
		pObj->Save(file);
	}
	return TRUE;
}

BOOL RawDataSet::Read(CStdioFile &file)
{
	CString strTemp;
	BOOL bRet =file.ReadString(strTemp);
	m_NumOfRawData.InitRow(strTemp);
	int nNum = GetRawDataNum();
	RawDataTable<2> *pObj2 = NULL;
	RawDataTable<4> *pObj4 = NULL;
	for(int i=0;i<nNum;i++)
	{
		RowObject temp;
		int nID = 0;
		file.ReadString(strTemp);
		temp.Read(strTemp,2);
		temp.GetData(nID,1);
		if(nID == 3)
		{
			CreatRawData(pObj4);
			pObj4->InitData(strTemp);
		}
		if(nID ==1)
		{
			CreatRawData(pObj2);
			pObj2->InitData(strTemp);
		}
		
	}
	return TRUE;
}


void RawDataSet::RemoveAll()
{
	m_list.DelList();
}
