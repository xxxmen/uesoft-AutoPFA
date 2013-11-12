// PFAOutModel.cpp: implementation of the PFAOutModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PFAOutModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PFAOutModel::PFAOutModel(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:m_SteadyOut(unitsys,OutPutData)
,m_TransOut(unitsys,OutPutData)
,m_OutPutData(OutPutData)
{

}

PFAOutModel::~PFAOutModel()
{

}

OutputRefPersist& PFAOutModel::GetOutPutData()
{
	return m_OutPutData;
}

SteadyOutModel& PFAOutModel::SteadyOut()
{
	return m_SteadyOut;
}

TransOutModel& PFAOutModel::TransOut()
{
	return m_TransOut;
}

void PFAOutModel::EmptyOut()
{
	m_SteadyOut.EmptyOut();
	m_TransOut.EmptyOut();
}

BOOL PFAOutModel::HasTranData()
{
	return m_TransOut.HasData();
}
