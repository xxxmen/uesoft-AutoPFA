// JunctionsMgr.cpp: implementation of the JunctionsMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunctionsMgr.h"
#include "JunDataFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunctionsMgr::JunctionsMgr()
{
	m_pFactory = JunDataFactory::Instance();
	m_RowArray.SetSize(1);
	m_RowArray.SetAt(0,&m_NumOfJun);
	SetID("\n[JUNCTIONS]");
	Init();
}

JunctionsMgr::~JunctionsMgr()
{
	DelList();
}

void JunctionsMgr::DelList()
{
	JunctionData *Obj = NULL;
	POSITION pos = m_junList.GetHeadPosition();
	while(pos)
	{
		Obj = m_junList.GetNext(pos);
		delete Obj;
	}
	m_junList.RemoveAll();
}

void JunctionsMgr::Init()
{
	CString strArray[1];
	strArray[0] = _T("NumberOfJunctions= 0");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==1);
		m_RowArray.GetAt(i)->InitRow(strArray[i]);
	}
}

BOOL JunctionsMgr::Save(CStdioFile &file)
{
	BOOL bRet = SaveData(file);

	JunctionData *pObj = NULL;
	POSITION pos = m_junList.GetHeadPosition();
	while(pos)
	{
		pObj = m_junList.GetNext(pos);
		pObj->Save(file);
	}
	return bRet;
}

BOOL JunctionsMgr::Read(CStdioFile &file)
{
	CString strTemp;
	BOOL bRet =file.ReadString(strTemp);
	m_NumOfJun.InitRow(strTemp);
	int nNum = GetJunNum();
	JunctionData *Obj = NULL;
	for(int i=0;i<nNum;i++)
	{
		CString strTemp;
		RowObject temp;
		int nID = 0;
		file.ReadString(strTemp);
		temp.Read(strTemp);
		temp.GetData(nID);
		Obj = CreatJun(nID);
		if(Obj != NULL)
		{
			Obj->Read(strTemp);
		}
	}
	return bRet;
}

int JunctionsMgr::GetJunNum()
{
	int nRet=0;
	m_NumOfJun.GetData(nRet,1);
	return nRet;
}
void JunctionsMgr::SetJunNum(int nNum)
{
	m_NumOfJun.SetData(nNum,1);
}
JunctionData* JunctionsMgr::CreatJun(int nID)
{
	JunctionData *Obj = m_pFactory->CreatObject(nID);
	if(Obj != NULL)
	{
		m_junList.AddTail(Obj);
	}
	return Obj;
}

Iterator<JunctionData>* JunctionsMgr::CreatIterator()
{
	return new ListIterator<JunctionData>(&m_junList);
}
