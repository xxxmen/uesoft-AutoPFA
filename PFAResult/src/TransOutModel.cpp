// TransOutModel.cpp: implementation of the TransOutModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TransOutModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TransOutModel::TransOutModel(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:m_unitsys(unitsys)
,m_Mgr(unitsys,OutPutData)
,m_OutPutData(OutPutData)
{

}

TransOutModel::~TransOutModel()
{

}

void TransOutModel::EmptyOut()
{
	m_Mgr.EmptyOut();
}

ComponentTranOutMgr& TransOutModel::ComponentOutMgr()
{
	return m_Mgr;
}

BOOL TransOutModel::HasData()
{
	return (!m_Mgr.IsEmpty());
}
