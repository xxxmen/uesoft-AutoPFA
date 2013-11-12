// MOCAssignFlow.cpp: implementation of the MOCAssignFlow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCAssignFlow.h"
#include "CalcAssignFlow.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCAssignFlow::MOCAssignFlow()
{
	m_dK = 0;					
	m_dFlow = 0;			
	m_dInitPress = 0;	
	m_bSelInitPress = 0;
}

MOCAssignFlow::~MOCAssignFlow()
{

}

MOCJun* MOCAssignFlow::Creator()
{
	MOCAssignFlow *pData = new MOCAssignFlow;
	return pData;
}

BOOL MOCAssignFlow::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcAssignFlow *pAssignFlowData = dynamic_cast<CalcAssignFlow*>(pData);
	ASSERT(pAssignFlowData != NULL);
	m_dK = pAssignFlowData->K()*m_dDesignFactor;					
	m_dFlow = pAssignFlowData->Flow();
	m_bSelInitPress = pAssignFlowData->SelInitPress();
	m_tranData.Read(pAssignFlowData->m_TranData);
	m_tranData.TranRel(RelToAbs,m_dFlow);
	if(0==pAssignFlowData->FlowType())
	{
		m_dFlow = MOCFluid::TranQToMass(m_dFlow);
		m_tranData.Tran(MOCFluid::TranQToMass);
	}
	m_dInitPress = pAssignFlowData->InitPress();
	if(0==pAssignFlowData->InitPressType())
		m_dInitPress = MOCFluid::TranHGLToPress(m_dInitPress);

	return TRUE;
}

BOOL MOCAssignFlow::InitEndInfo()
{
	EndInfo *pEnd = NULL;
	IteratorPtr<EndInfo> ItPtr(m_EndList.CreatEndIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pEnd = &ItPtr->CurrentItem();
		ASSERT(pEnd != NULL);
		pEnd->SetMass(m_dFlow);
		pEnd->SetPress(m_dInitPress);
		pEnd->SetZ(m_dInEle);
		pEnd->InJunK(m_dK);
		pEnd->OutJunK(m_dK);
	}
	m_dLossK = m_dK;
	return TRUE;
}

void MOCAssignFlow::CalcStm()
{
	CalcStm(m_dFlow,m_dInitPress);
}
void MOCAssignFlow::CalcStm(double dFlow,double dPress)
{
	if(m_bSelInitPress==0)
	{
		m_EndList.FlowStrategy(dFlow);
// 		EndInfo *pInEnd = m_EndList.GetInEnd();
// 		EndInfo *pOutEnd = m_EndList.GetOutEnd();
// 		if (pInEnd != NULL)
// 		{
// 			double dTempPress = pInEnd->GetPress()-0.5*m_dLossK*MOCFluid::Density()*pInEnd->GetVelocity();
// 			pInEnd->SetPress(dTempPress);
// 		}
// 		else
// 		{
// 			double dTempPress = pOutEnd->GetPress()-0.5*m_dLossK*MOCFluid::Density()*pOutEnd->GetVelocity();
// 			pOutEnd->SetPress(dTempPress);
// 		}
	}
	else
	{
		m_EndList.StagPressStrategy(dPress);
	}
}
void MOCAssignFlow::UpdataEnd()
{
//	UpdataOneEnd();
	EndInfo *pEnd = m_EndList.GetInEnd(); 
	if(pEnd != NULL)
	{
		MOCJun::UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
		MOCJun::UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
		m_dInStagPress = m_dOutStagPress + 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
		m_dInStaticPress = m_dOutStaticPress + 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
		// 由流量Q计算得到的滞止压力为指定流量入口处的压力
// 		MOCJun::UpdataEnd(pEnd,m_dInStaticPress,m_dInStagPress,m_dInEGL,m_dInHGL);
// 		MOCJun::UpdataEnd(pEnd,m_dOutStaticPress,m_dOutStagPress,m_dOutEGL,m_dOutHGL);
		return;	
	}
	pEnd = m_EndList.GetOutEnd();
	if(pEnd != NULL)
	{
		MOCJun::UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
		MOCJun::UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
		m_dOutStagPress = m_dInStagPress - 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
		m_dOutStaticPress = m_dInStaticPress - 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
		//由流量Q计算得到的滞止压力为指定流量入口处的压力
		// 		MOCJun::UpdataEnd(pEnd,m_dInStaticPress,m_dInStagPress,m_dInEGL,m_dInHGL);
// 		MOCJun::UpdataEnd(pEnd,m_dOutStaticPress,m_dOutStagPress,m_dOutEGL,m_dOutHGL);
	}
}

BOOL MOCAssignFlow::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	return TRUE;
}

void MOCAssignFlow::CalcImpulse(MOCTrans &trans, double dTime)
{//需要增加无反射管道
	double dFlow = m_tranData.GeTransY(dTime,m_dFlow,trans.StartTime());
	CalcStm(dFlow,m_dInitPress);
}


