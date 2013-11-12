// PipesMgr.cpp: implementation of the PipesMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipesMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipesMgr::PipesMgr()
{
	m_RowArray.SetSize(1);
	m_RowArray.SetAt(0,&m_NumOfPipe);
	SetID("\n[PIPES]");
	Init();
}

PipesMgr::~PipesMgr()
{
	DelList();
}

void PipesMgr::Init()
{
	CString strArray[1];
	strArray[0] = _T("NumberOfPipes= 0");
	for(int i=0;i<m_RowArray.GetSize();i++)
	{
		ASSERT(m_RowArray.GetSize()==1);
		m_RowArray.GetAt(i)->InitRow(strArray[i]);
	}
}

BOOL PipesMgr::Save(CStdioFile &file)
{
	BOOL bRet = SaveData(file);

	PipeData *pObj = NULL;
	POSITION pos = m_pipeList.GetHeadPosition();
	while(pos)
	{
		pObj = m_pipeList.GetNext(pos);
		pObj->Save(file);
	}
	return bRet;
}

BOOL PipesMgr::Read(CStdioFile &file)
{
	CString strTemp;
	BOOL bRet =file.ReadString(strTemp);
	m_NumOfPipe.InitRow(strTemp);
	int nNum = GetPipeNum();
	PipeData *Obj = NULL;
	for(int i=0;i<nNum;i++)
	{
		Obj = CreatPipe();
		Obj->Read(file);
	}
	return bRet;
}

int PipesMgr::GetPipeNum()
{
	int nRet=0;
	m_NumOfPipe.GetData(nRet,1);
	return nRet;
}

void PipesMgr::SetPipeNum(int nNum)
{
	m_NumOfPipe.SetData(nNum,1);
}
PipeData* PipesMgr::CreatPipe()
{
	PipeData *Obj = new PipeData();
	m_pipeList.AddTail(Obj);
	return Obj;
}

void PipesMgr::DelList()
{
	PipeData *Obj = NULL;
	POSITION pos = m_pipeList.GetHeadPosition();
	while(pos)
	{
		Obj = m_pipeList.GetNext(pos);
		delete Obj;
	}
	m_pipeList.RemoveAll();
}

Iterator<PipeData>* PipesMgr::CreatIterator()
{
	return new ListIterator<PipeData>(&m_pipeList);
}
