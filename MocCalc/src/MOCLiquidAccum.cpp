// MOCLiquidAccum.cpp: implementation of the MOCLiquidAccum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCLiquidAccum.h"
#include "CalcLiquidAccum.h"
#include "BrachJunStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCLiquidAccum::MOCLiquidAccum()
{
	m_dElastic = 0;				 
	m_dInitVolume = 0;	
	m_dMass = 0;
}

MOCLiquidAccum::~MOCLiquidAccum()
{

}

MOCJun* MOCLiquidAccum::Creator()
{
	MOCLiquidAccum *pData = new MOCLiquidAccum;
	return pData;
}

BOOL MOCLiquidAccum::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcLiquidAccum *pLiquidAccumData = dynamic_cast<CalcLiquidAccum*>(pData);
	ASSERT(pLiquidAccumData != NULL);
	m_dElastic = pLiquidAccumData->Elastic();				 
	m_dInitVolume = pLiquidAccumData->InitVolume();
	return TRUE;
}

BOOL MOCLiquidAccum::InitEndInfo()
{
	return InitInOutEle();
}

void MOCLiquidAccum::CalcStm()
{
	m_EndList.BranchStrategy(0);
}

void MOCLiquidAccum::UpdataEnd()
{
	UpdataTwoEnd();
}

void MOCLiquidAccum::CalcImpulse(MOCTrans &trans,double dTime)
{
	m_EndList.LiquidJunStrategy(m_dElastic,m_dInitVolume,m_dMass);
}
