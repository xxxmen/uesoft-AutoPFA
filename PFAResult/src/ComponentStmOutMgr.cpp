// ComponentStmOutMgr.cpp: implementation of the ComponentStmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ComponentStmOutMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponentStmOutMgr::ComponentStmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:m_junOutMgr(unitsys,OutPutData)
,m_pipeOutMgr(unitsys,OutPutData)
,m_OutPutData(OutPutData)
{

}

ComponentStmOutMgr::~ComponentStmOutMgr()
{

}

OutputRefPersist& ComponentStmOutMgr::OutPutData()
{
	return m_OutPutData;
}

JunStmOutMgr& ComponentStmOutMgr::JunOutMgr()
{
	return m_junOutMgr;
}

PipeStmOutMgr& ComponentStmOutMgr::PipeOutMgr()
{
	return m_pipeOutMgr;
}

void ComponentStmOutMgr::EmptyOut()
{
	m_junOutMgr.EmptyOut();
	m_pipeOutMgr.EmptyOut();
}
