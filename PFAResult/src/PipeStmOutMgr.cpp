// PipeStmOutMgr.cpp: implementation of the PipeStmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipeStmOutMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipeStmOutMgr::PipeStmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:StmOutMgr(unitsys,OutPutData)
{
	//ReadUnitOrder("UnitOder.txt");
	//InitUnit(strTemp);
	
}

PipeStmOutMgr::~PipeStmOutMgr()
{
}


ComponentStmOut* PipeStmOutMgr::Creator()
{
	return new PipeStmOut;
}

void PipeStmOutMgr::InitAttrArray()
{
	PipeStmOut::Instance(m_attrArray,m_unitsys,m_OutPutData,m_PipeArray,m_OutPutSys);
	OutPutSystem outPutSys;
	PipeStmOut::Instance(m_attAllArray, m_unitsys, m_OutPutData, m_PipeArray, outPutSys );
}


//-------------------------

//-------------------------
