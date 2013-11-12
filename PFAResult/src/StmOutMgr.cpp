// StmOutMgr.cpp: implementation of the StmOutMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "StmOutMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

StmOutMgr::StmOutMgr(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:OutMgr(unitsys,OutPutData)
{

}

StmOutMgr::~StmOutMgr()
{
	
}

ComponentStmOut* StmOutMgr::CreatorComponent(int nKey)
{
	ASSERT(LookUp(nKey)==NULL);
	ComponentStmOut* pStmOut = Creator();
	if(pStmOut==NULL)
	{
		ASSERT(FALSE);
		return NULL;
	}
	pStmOut->Key(nKey);
	m_outMap.SetAt(nKey,pStmOut);
	return pStmOut;
}




