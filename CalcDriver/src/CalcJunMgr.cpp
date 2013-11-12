// CalcJunMgr.cpp: implementation of the CalcJunMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcJunMgr.h"
#include "CalcJun.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcJunMgr::CalcJunMgr()
{
	m_pFactory = CalcJunFactory::Instance();
}

CalcJunMgr::~CalcJunMgr()
{
	DelList();
}
void CalcJunMgr::DelList()
{
	CalcJun *Obj = NULL;
	POSITION pos = m_junList.GetHeadPosition();
	while(pos)
	{
		Obj = m_junList.GetNext(pos);
		delete Obj;
	}
	m_junList.RemoveAll();
}

CalcJun* CalcJunMgr::CreatJun(int nType)
{
	CalcJun *Obj = m_pFactory->CreatObject(nType);
	if(Obj != NULL)
	{
		m_junList.AddTail(Obj);
	}
	else
	{
		ASSERT(FALSE);
	}
	return Obj;
}
Iterator<CalcJun>* CalcJunMgr::CreateIt()
{
	return new ListIterator<CalcJun>(&m_junList);
}

ostream& operator<< (ostream &CalcOut,const CalcJunMgr &ref)
{
	CalcOut<<ref.m_junList.GetCount()<<endl;
	CalcJun *pObj = NULL;
	POSITION pos = ref.m_junList.GetHeadPosition();
	while(pos)
	{
		pObj = ref.m_junList.GetNext(pos);
		CalcOut<<*pObj;
	}
	return CalcOut;
}