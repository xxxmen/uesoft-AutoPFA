// MOCDeadEnd.cpp: implementation of the MOCDeadEnd class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCDeadEnd.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCDeadEnd::MOCDeadEnd()
{

}

MOCDeadEnd::~MOCDeadEnd()
{

}

MOCJun* MOCDeadEnd::Creator()
{
	MOCDeadEnd *pData = new MOCDeadEnd;
	return pData;
}

BOOL MOCDeadEnd::Read(CalcJun *pData)
{
	ReadJun(pData);
	return TRUE;
}

BOOL MOCDeadEnd::InitEndInfo()
{
	return InitInOutEle();
}

void MOCDeadEnd::CalcStm()
{
	m_EndList.DeadStrategy();
	EndInfo* pInEnd = GetInEnd() ;
	EndInfo* pOutEnd = GetOutEnd() ;
	if ( pInEnd )
	{
		pInEnd->SetZeroMassFlag( TRUE ) ;
	}
	if ( pOutEnd )
	{
		pOutEnd->SetZeroMassFlag( TRUE ) ;
	}
}

void MOCDeadEnd::UpdataEnd()
{
	UpdataTwoEnd();
}

void MOCDeadEnd::CalcImpulse(MOCTrans &trans, double dTime)
{
	CalcStm();
}
