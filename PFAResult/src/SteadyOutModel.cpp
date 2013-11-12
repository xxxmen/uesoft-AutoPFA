// SteadyOutModel.cpp: implementation of the SteadyOutModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SteadyOutModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SteadyOutModel::SteadyOutModel(UnitSubSystem &unitsys,OutputRefPersist &OutPutData)
:m_unitsys(unitsys)
,m_ComponentOutMgr(unitsys,OutPutData)
,m_OutPutData(OutPutData)
{
	m_iterations = 0;
	m_bOK = FALSE;
}

SteadyOutModel::~SteadyOutModel()
{

}
// OutputRefPersist& SteadyOutModel::OutPutData()
// {
// 	return m_OutPutData;
// }
ComponentStmOutMgr& SteadyOutModel::ComponentOutMgr()
{
	return m_ComponentOutMgr;
}

void SteadyOutModel::EmptyOut()
{
	m_ComponentOutMgr.EmptyOut();
}



int SteadyOutModel::Iterations()
{
	return m_iterations;
}

void SteadyOutModel::Iterations(int nIt)
{
	m_iterations = nIt;
}

BOOL SteadyOutModel::OK()
{
	return m_bOK;
}

void SteadyOutModel::OK(BOOL bOK)
{
	m_bOK = bOK;
}

CString SteadyOutModel::CurTime()
{
	return m_strCurTime;
}

void SteadyOutModel::CurTime(LPSYSTEMTIME lpSystemTime)
{
	WORD wYear = lpSystemTime->wYear; 
    WORD wMonth = lpSystemTime->wMonth; 
    WORD wDay = lpSystemTime->wDay; 
    WORD wHour = lpSystemTime->wHour+8; 
    WORD wMinute = lpSystemTime->wMinute; 
    WORD wSecond = lpSystemTime->wSecond; 
	
	m_strCurTime.Format(_T("%dÄê%dÔÂ%dÈÕ%d:%d:%d"),wYear,wMonth,wDay,wHour,wMinute,wSecond);
}