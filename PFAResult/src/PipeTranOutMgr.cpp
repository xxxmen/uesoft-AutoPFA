// PipeTranOutMgr.cpp: implementation of the PipeTranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipeTranOutMgr.h"
#include "PipeTranOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipeTranOutMgr::PipeTranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:TranOutMgr(unitsys,OutPutData)
{

}

PipeTranOutMgr::~PipeTranOutMgr()
{
	
}

ComponentTranOut* PipeTranOutMgr::Creator()
{
	return new PipeTranOut;
}
OutAttrArray& PipeTranOutMgr::GetStationArray()
{
	return m_StationAttrArray;
}
OutAttrArray& PipeTranOutMgr::GetMaxMinArray()
{
	return m_MaxMinArray;
}
void PipeTranOutMgr::EmptyOut()
{
	m_StationAttrArray.RemoveAll();
	m_MaxMinArray.RemoveAll();
	TranOutMgr::EmptyOut();
}

void PipeTranOutMgr::InitAttrArray()
{
	PipeTranOut::Instance(m_StationAttrArray,m_unitsys);
	PipeTranOut::InstancePipeMaxMin(m_attrArray,m_unitsys);
	PipeTranOut::InstanceStationMaxMin(m_MaxMinArray,m_unitsys);
}

void PipeTranOutMgr::InitMaxMin()
{
	PipeTranOut *pPipe = NULL;
	IteratorPtr<ComponentStmOut> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pPipe = dynamic_cast<PipeTranOut*>(&ItPtr->CurrentItem());
		ASSERT(pPipe != NULL);
		pPipe->InitMaxMin(m_TimeStep);
	}
}



ComponentStmOut* PipeTranOutMgr::LookUpMaxMin(int nKey, int nSubKey)
{
	PipeTranOut *pPipe = dynamic_cast<PipeTranOut*>(LookUp(nKey));
	if(pPipe != NULL)
		return pPipe->LookUpMaxMin(nSubKey);
	return NULL;
}
