// JunTranOutMgr.cpp: implementation of the JunTranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "JunTranOutMgr.h"
#include "JunTranOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunTranOutMgr::JunTranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:TranOutMgr(unitsys,OutPutData)
{

}

JunTranOutMgr::~JunTranOutMgr()
{

}

ComponentTranOut* JunTranOutMgr::Creator()
{
	return new JunTranOut;
}

void JunTranOutMgr::EmptyOut()
{
	TranOutMgr::EmptyOut();
}

void JunTranOutMgr::InitAttrArray()
{
	JunTranOut::Instance(m_attrArray,m_unitsys);
}

ComponentStmOut* JunTranOutMgr::LookUpMaxMin(int nKey, int nSubKey)
{
	return NULL;
}
