// OutMgr.cpp: implementation of the OutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "OutMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

OutMgr::OutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:m_unitsys(unitsys)
,m_OutPutData(OutPutData)
{
	
}

OutMgr::~OutMgr()
{
	DelMap<ComponentStmOut>(m_outMap);
}

OutAttrArray& OutMgr::GetArray()
{
	//for( int i = 0; i < m_attrArray.GetSize(); i++ )
	//{
	//	m_staticArray[i] = m_attrArray[i];
	//}
	//return m_staticArray;
	return m_attrArray;
}

OutAttrArray& OutMgr::GetAllArray()
{
	return m_attAllArray;
}

void OutMgr::EmptyOut()
{
	m_attrArray.RemoveAll();
	DelMap<ComponentStmOut>(m_outMap);
	InitAttrArray();
}


Iterator<ComponentStmOut>* OutMgr::CreatIterator()
{
	return new MapIterator<ComponentStmOut>(&m_outMap);
}

ComponentStmOut* OutMgr::LookUp(int nKey)
{
	return LookMap<ComponentStmOut>(m_outMap,nKey);
}

int OutMgr::GetCount()
{
	return m_outMap.GetCount();
}

BOOL OutMgr::IsEmpty()
{
	return m_outMap.IsEmpty();
}
