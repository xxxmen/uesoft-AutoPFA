// CalcPipeMgr.cpp: implementation of the CalcPipeMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPipeMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPipeMgr::CalcPipeMgr()
{

}

CalcPipeMgr::~CalcPipeMgr()
{
	DelList();
}

void CalcPipeMgr::DelList()
{
	CalcPipe *Obj = NULL;
	POSITION pos = m_pipeList.GetHeadPosition();
	while(pos)
	{
		Obj = m_pipeList.GetNext(pos);
		delete Obj;
	}
	m_pipeList.RemoveAll();
}

CalcPipe* CalcPipeMgr::CreatPipe()
{
	CalcPipe *Obj = new CalcPipe;
	m_pipeList.AddTail(Obj);
	return Obj;
}

Iterator<CalcPipe>* CalcPipeMgr::CreateIt()
{
	return new ListIterator<CalcPipe>(&m_pipeList);
}

ostream& operator<< (ostream &CalcOut,const CalcPipeMgr &ref)
{
	CalcOut<<ref.m_pipeList.GetCount()<<endl;
	CalcPipe *pObj = NULL;
	POSITION pos = ref.m_pipeList.GetHeadPosition();
	while(pos)
	{
		pObj = ref.m_pipeList.GetNext(pos);
		CalcOut<<*pObj;
	}
	return CalcOut;
}