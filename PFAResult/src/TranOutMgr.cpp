// TranOutMgr.cpp: implementation of the TranOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TranOutMgr.h"
#include "ComponentTranOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TranOutMgr::TranOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:OutMgr(unitsys,OutPutData)
{
	m_TimeStep = 0;
}

TranOutMgr::~TranOutMgr()
{
}
ComponentStmOut* TranOutMgr::CreatorComponent(int nKey)
{
	ComponentStmOut* pTranOut = LookUp(nKey);
	if(pTranOut==NULL)
	{
		pTranOut = Creator();
		pTranOut->Key(nKey);
	    m_outMap.SetAt(nKey,pTranOut);
	}
	return pTranOut;
}

void TranOutMgr::TimeStep(double dTime)
{
	m_TimeStep = dTime;
}

