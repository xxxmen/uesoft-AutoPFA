// MOCSurge.cpp: implementation of the MOCSurge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCSurge.h"
#include "MOCFluid.h"
#include "BrachJunStrategy.h"
#include "CalcSurge.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCSurge::MOCSurge()
{
	m_dSurfacePress = 0;		
	m_dSurgeHeight = 0;			
	m_dConstArea = 0;					
	m_bOneWay = 0;				
	m_dCheckCv = 0;						
	m_nPosition = 0;					
	m_dReOpenPress = 0;				
	m_bSelVessel = 0;					
	m_dVesselHeight = 0;				
	m_dPolytropic = 0;				
	m_bSelSurfaceH = 0;			
	m_dInitSurfaceH = 0;
	m_dLiquldHeight = 0;
	m_dMass = 0;
}

MOCSurge::~MOCSurge()
{

}

MOCJun* MOCSurge::Creator()
{
	MOCSurge *pData = new MOCSurge;
	return pData;
}

BOOL MOCSurge::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcSurge *pSurgeData = dynamic_cast<CalcSurge*>(pData);
	ASSERT(pSurgeData != NULL);
	m_PipeInfo = pSurgeData->PipeInfo();
	m_dSurfacePress = pSurgeData->SurfacePress();		
	m_dSurgeHeight = pSurgeData->SurgeHeight();	
	m_AreaTable.SetData(pSurgeData->AreaTable());
	m_dConstArea = pSurgeData->ConstArea();					
	m_bOneWay = pSurgeData->OneWay();				
	m_dCheckCv = pSurgeData->CheckCv();						
	m_nPosition = pSurgeData->Position();					
	m_dReOpenPress = pSurgeData->ReOpenPress();	
	if(0==pSurgeData->ReOpenPressType())
		m_dReOpenPress = MOCFluid::TranHGLToPress(m_dReOpenPress);
	m_bSelVessel = pSurgeData->SelVessel();					
	m_dVesselHeight = pSurgeData->VesselHeight();				
	m_dPolytropic = pSurgeData->Polytropic();				
	m_bSelSurfaceH = pSurgeData->SelSurfaceH();			
	m_dInitSurfaceH = pSurgeData->InitSurfaceH();
	m_lumpedInertia.Read(pSurgeData->m_Orifice,pSurgeData->m_ShortPipe);
	m_tranData.Read(pSurgeData->m_TranData);
	m_tranData.TranRel(RelToAbs,m_dSurfacePress);
	return TRUE;
}
double MOCSurge::GetGL()
{
	return m_EndList.GetEGL();
}
void MOCSurge::UpdataEnd()
{
	UpdataOneEnd();
}

BOOL MOCSurge::InitEndInfo()
{
	InitInOutEle();
	InitInfo(m_PipeInfo);
	return TRUE;
}

void MOCSurge::CalcStm()
{
	if(m_bSelSurfaceH==0)
	{
		m_EndList.BranchStrategy(0);
	}
	else
	{
		double dPress = MOCFluid::TranHToPress(m_dInitSurfaceH-m_dInEle)+m_dSurfacePress;
		m_EndList.StagPressStrategy(dPress);
	}
}

BOOL MOCSurge::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	if(m_bSelSurfaceH==0)
	{
		m_dLiquldHeight = MOCFluid::TranPressToH(m_EndList.GetPress()-m_dSurfacePress)-m_lumpedInertia.EleChange();
	}
	else
	{
		m_dLiquldHeight = m_dInitSurfaceH-m_dInEle;
	}
	return TRUE;
}

void MOCSurge::CalcImpulse(MOCTrans &trans, double dTime)
{
	double dSurfacePress = m_tranData.GeTransY(dTime,m_dSurfacePress,trans.StartTime());
	double dArea = GetArea(m_dLiquldHeight);
	m_EndList.SurgeJunStrategy(m_lumpedInertia,m_dSurfacePress,dArea,m_dLiquldHeight,m_dMass);
}

double MOCSurge::GetArea(double dH)
{
	if(m_AreaTable.HasData())
	{
		return m_AreaTable.GetSetpValue(dH);
	}
	return m_dConstArea;
}


void MOCSurge::Result(JunTranOut &out, int nStep)
{
	JunOut *pOut = out.Creator(nStep);
	pOut->SetTime(nStep*MOCFluid::SetpTime());
	pOut->SetSurgeLiquidH(m_dLiquldHeight);
	pOut->SetSurgeHGL(m_EndList.GetEGL());
}
