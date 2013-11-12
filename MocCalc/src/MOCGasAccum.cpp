// MOCGasAccum.cpp: implementation of the MOCGasAccum class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCGasAccum.h"
#include "MOCFluid.h"
#include "CalcGasAccum.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCGasAccum::MOCGasAccum()
{
	m_dPolytropic = 0;				
	m_nType = 0;				
	m_dInitVolume = 0;				
	m_dRefPress = 0;				   
	m_dMaxVolume = 0;					 
	m_dMinVolume = 0;					  											
	m_bSelInitPress = 0;					 
	m_dInitPress = 0;	
	m_dMass = 0;
}

MOCGasAccum::~MOCGasAccum()
{

}

MOCJun* MOCGasAccum::Creator()
{
	MOCGasAccum *pData = new MOCGasAccum;
	return pData;
}

BOOL MOCGasAccum::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcGasAccum *pGasAccumData = dynamic_cast<CalcGasAccum*>(pData);
	ASSERT(pGasAccumData != NULL);
	m_dPolytropic = pGasAccumData->Polytropic();				
	m_nType = pGasAccumData->Type();				
	m_dInitVolume = pGasAccumData->InitVolume();				
	m_dRefPress = pGasAccumData->RefPress();				   
	m_dMaxVolume = pGasAccumData->MaxVolume();					 
	m_dMinVolume = pGasAccumData->MinVolume();					  											
	m_bSelInitPress = pGasAccumData->SelInitPress();					 
	m_dInitPress = pGasAccumData->InitPress();
	if(0==pGasAccumData->InitPressType())
		m_dInitPress = MOCFluid::TranHGLToPress(m_dInitPress);
	m_lumpedInertia.Read(pGasAccumData->m_Orifice,pGasAccumData->m_ShortPipe);
	return TRUE;
}

BOOL MOCGasAccum::InitEndInfo()
{
	return InitInOutEle();
}

void MOCGasAccum::CalcStm()
{
	m_EndList.BranchStrategy(0);
}

void MOCGasAccum::UpdataEnd()
{
	UpdataOneEnd();
}

void MOCGasAccum::CalcImpulse(MOCTrans &trans, double dTime)
{
	m_EndList.GasJunStrategy(m_lumpedInertia,m_dPolytropic, m_dCA,m_dMass,m_dRefPress,m_dInitVolume);
}

BOOL MOCGasAccum::InitTranData(MOCComponentMgr &mgr)
{
	if(0==m_nType)
		m_dRefPress = m_EndList.GetPress()-m_lumpedInertia.ElePress();
	m_dCA = m_dRefPress*pow(m_dInitVolume,m_dPolytropic);
	m_dMass = 0;
	return TRUE;
}

void MOCGasAccum::Result(JunTranOut &out, int nStep)
{
	JunOut *pOut = out.Creator(nStep);
	pOut->SetTime(nStep*MOCFluid::SetpTime());
	pOut->SetGasAccumPress(m_dRefPress);
	pOut->SetGasAccumVolume(m_dInitVolume);
}
