// JunStmOutMgr.cpp: implementation of the JunStmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunStmOutMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunStmOutMgr::JunStmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:StmOutMgr(unitsys,OutPutData)
{
}

JunStmOutMgr::~JunStmOutMgr()
{
}

ComponentStmOut* JunStmOutMgr::Creator()
{
	return new JunStmOut;
}

void JunStmOutMgr::InitAttrArray()
{
	JunStmOut::Instance(m_attrArray,m_unitsys,m_OutPutData,m_JunArray,m_OutPutSys);

	OutPutSystem outPutSys;
	JunStmOut::Instance(m_attAllArray,m_unitsys,m_OutPutData,m_JunArray,outPutSys);
}
