// JunManager.cpp: implementation of the JunManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunManager::JunManager()
{
	m_factory = JunPerisistFactory::Instance();
}

JunManager::~JunManager()
{
	DelList();
}

Iterator<Junperisist>* JunManager::CreateIt()
{
	return new ListIterator<Junperisist>(&m_junList);
}

Junperisist* JunManager::CreatJunperisist(int nID)
{
	Junperisist* pJun = m_factory->CreatObject(nID);
	if(pJun != NULL)
	{
		m_junList.AddTail(pJun);
	}
	return pJun;
}

int JunManager::GetJunNum()
{
	return m_junList.GetCount();
}

void JunManager::DelList()
{
	Junperisist *pJun = NULL;
	POSITION pos = m_junList.GetHeadPosition();
	while(pos)
	{
		pJun = m_junList.GetNext(pos);
		delete pJun;
	}
	m_junList.RemoveAll();
}
