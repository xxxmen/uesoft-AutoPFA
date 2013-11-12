// ComponentTranOutMgr.cpp: implementation of the ComponentTranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ComponentTranOutMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ComponentTranOutMgr::ComponentTranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:m_junOutMgr(unitsys,OutPutData)
,m_pipeOutMgr(unitsys,OutPutData)
{

}

ComponentTranOutMgr::~ComponentTranOutMgr()
{

}

JunTranOutMgr& ComponentTranOutMgr::JunOutMgr()
{
	return m_junOutMgr;
}

PipeTranOutMgr& ComponentTranOutMgr::PipeOutMgr()
{
	return m_pipeOutMgr;
}

void ComponentTranOutMgr::EmptyOut()
{
	m_pipeOutMgr.EmptyOut();
	m_junOutMgr.EmptyOut();
}

void ComponentTranOutMgr::TimeStep(double dTime)
{
	m_pipeOutMgr.TimeStep(dTime);
	m_junOutMgr.TimeStep(dTime);
}

BOOL ComponentTranOutMgr::IsEmpty()
{
	return (m_pipeOutMgr.IsEmpty()&&m_junOutMgr.IsEmpty());
}


