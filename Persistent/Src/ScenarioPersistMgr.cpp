// ScenarioPersistMgr.cpp: implementation of the ScenarioPersistMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ScenarioPersistMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ScenarioPersistMgr::ScenarioPersistMgr()
{

}

ScenarioPersistMgr::~ScenarioPersistMgr()
{
	NetModelPersist *pNet = NULL;
	POSITION pos = m_NetList.GetHeadPosition();
	while (pos)
	{
		pNet = m_NetList.GetNext(pos);
		delete pNet;
	}
}

Iterator<NetModelPersist>* ScenarioPersistMgr::CreateIt()
{
	return new ListIterator<NetModelPersist>(&m_NetList);
}

NetModelPersist* ScenarioPersistMgr::GetBase()
{
	if(m_NetList.IsEmpty())
	{
//		ModelList* m_NetList = new ModelList;
//		return m_NetList->GetHead();
		return NULL;
	}
	else
	{
		return m_NetList.GetHead();
	}
}

NetModelPersist* ScenarioPersistMgr::CreatNetModel()
{
	NetModelPersist* pNet = new NetModelPersist;
	m_NetList.AddTail(pNet);
	return pNet;
}


int ScenarioPersistMgr::GetModelNum()
{
	return m_NetList.GetCount();
}


