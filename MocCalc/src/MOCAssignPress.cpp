// MOCAssignPress.cpp: implementation of the MOCAssignPress class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCAssignPress.h"
#include "CalcAssignPress.h"
#include "MOCFluid.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCAssignPress::MOCAssignPress()
{
	m_nPressType = 0;	
	m_dPress = 0;	
}

MOCAssignPress::~MOCAssignPress()
{

}

MOCJun* MOCAssignPress::Creator()
{
	MOCAssignPress *pData = new MOCAssignPress;
	return pData;
}

BOOL MOCAssignPress::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcAssignPress *pAssignPressData = dynamic_cast<CalcAssignPress*>(pData);
	ASSERT(pAssignPressData != NULL);
	m_nPressType = pAssignPressData->PressType();	
	m_dPress = pAssignPressData->Press();
	m_PipeInfo = pAssignPressData->PipeInfo();
	m_tranData.Read(pAssignPressData->m_TranData);
	m_tranData.TranRel(RelToAbs,m_dPress);
	return TRUE;
}

BOOL MOCAssignPress::InitEndInfo()
{
	m_EndList.SetPress(m_dPress);
	m_EndList.SetZ(m_dInEle,m_dInEle);
//	InitInfo(m_PipeInfo);

	StrArray<4> Info;
	EndInfo *pEnd = NULL;
	IteratorPtr<StrArray<4> > ItPtr(m_PipeInfo.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		Info = ItPtr->CurrentItem();
		pEnd = m_EndList.Find(Info.nData(0));
		if(pEnd == NULL)
		{
			ASSERT(FALSE);
			return FALSE;
		}
		pEnd->InJunK(Info.fData(2));
		pEnd->OutJunK(Info.fData(1));
		pEnd->SetZ(pEnd->GetZ()+Info.fData(3));

		m_dLossK = Info.fData(2); 
	}
	return TRUE;
}

void MOCAssignPress::CalcStm()
{
	CalcStm(m_dPress);
}
void MOCAssignPress::CalcStm(double dPress)
{
	EndInfo *pInEnd = m_EndList.GetInEnd();
	EndInfo *pOutEnd = m_EndList.GetOutEnd();
 	if(m_EndList.GetInEnd() != NULL)
 		dPress = dPress + 0.5*m_dLossK*MOCFluid::Density()*pInEnd->GetVelocity();
 	else
 		dPress = dPress - 0.5*m_dLossK*MOCFluid::Density()*pOutEnd->GetVelocity();
	if(m_nPressType==1)
	{	
		m_EndList.StaticPressStrategy(dPress);
	}
	else
	{
	//	m_EndList.StagPressStrategy(dPress+0.5*m_dLossK*MOCFluid::Density()*pEnd->GetVelocity());
		m_EndList.StagPressStrategy(dPress);
	}
	
}
void MOCAssignPress::UpdataEnd()
{
//	UpdataOneEnd();
	EndInfo *pEnd = m_EndList.GetInEnd(); 
	if(pEnd != NULL)
	{
		MOCJun::UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
		MOCJun::UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
		m_dInStagPress = m_dOutStagPress + 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
		m_dInStaticPress = m_dOutStaticPress + 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
		return;	
	}
	pEnd = m_EndList.GetOutEnd();
	if(pEnd != NULL)
	{
		MOCJun::UpdataEnd(pEnd,m_dInStagPress,m_dInStaticPress,m_dInEGL,m_dInHGL);
		MOCJun::UpdataEnd(pEnd,m_dOutStagPress,m_dOutStaticPress,m_dOutEGL,m_dOutHGL);
		m_dInStagPress = m_dOutStagPress - 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
		m_dInStaticPress = m_dOutStaticPress + 0.5*m_dLossK*MOCFluid::Density()*pow(pEnd->GetVelocity(),2);
	}
}

BOOL MOCAssignPress::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	return TRUE;
}

void MOCAssignPress::CalcImpulse(MOCTrans &trans, double dTime)
{
	double dPress = m_tranData.GeTransY(dTime,m_dPress,trans.StartTime());
	CalcStm(dPress);
}
