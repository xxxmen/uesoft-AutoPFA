// MOCReservior.cpp: implementation of the MOCReservior class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCReservior.h"
#include "CalcReservior.h"
#include "MOCFluid.h"
#include "PressJunStrategy.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCReservior::MOCReservior()
{
	m_dSurfacePress = 0;
	m_nEleOrDepthType = 0;
}

MOCReservior::~MOCReservior()
{

}

MOCJun* MOCReservior::Creator()
{
	MOCReservior *pData = new MOCReservior;
	return pData;
}

BOOL MOCReservior::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcReservior *pReserviorData = dynamic_cast<CalcReservior*>(pData);
	ASSERT(pReserviorData != NULL);
	m_dSurfacePress = pReserviorData->SurfacePress();
	m_nEleOrDepthType = pReserviorData->EleOrDepthType();
	m_PipeInfo = pReserviorData->PipeInfo();
	m_tranData.Read(pReserviorData->m_TranData);
	m_tranData.TranRel(RelToAbs,m_dInEle);
	return TRUE;
}

BOOL MOCReservior::InitEndInfo()
{
	m_EndList.SetPress(m_dSurfacePress);
	InitPipeInfo(m_dInEle);
	return TRUE;
}

void MOCReservior::CalcStm()
{
	m_EndList.StagPressStrategy();
}

void MOCReservior::InitPipeInfo(double dEle)
{
	double m_dLossKup;
	double m_dLossKdown;
	StrArray<6> Info;
	double dPress = 0;
	EndInfo *pEnd = NULL;
	IteratorPtr<StrArray<6> > ItPtr(m_PipeInfo.CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		Info = ItPtr->CurrentItem();
		pEnd = m_EndList.Find(Info.nData(0));
		if(pEnd == NULL)
		{
//			ASSERT(FALSE);
			return;
		}
		pEnd->InJunK(Info.fData(3));
		pEnd->OutJunK(Info.fData(2));

		m_dLossKup=Info.fData(2);
		m_dLossKdown=Info.fData(3);

		if(m_nEleOrDepthType == 0)
		{//深度
			pEnd->SetZ(dEle-Info.fData(5));
		}
		else
		{//标高
			pEnd->SetZ(Info.fData(5));
		}
		dPress = MOCFluid::TranHToPress(dEle-pEnd->GetZ());
		pEnd->SetPress(pEnd->GetPress()+dPress);
		if ( Info.nData(0) > 0 )
		{
			m_dLossK = m_dLossKdown;
		} 
		else
		{
			m_dLossK = m_dLossKup;
		}
	}
// 	EndInfo *pEndfind = m_EndList.GetInEnd(); //输出水库的损失系数；
// 	if(pEndfind != NULL)
// 	{
// 		m_dLossK = m_dLossKdown;
// 	}
// 	pEndfind = m_EndList.GetOutEnd();
// 	if(pEndfind != NULL)
// 	{
// 		m_dLossK = m_dLossKup;
// 	}
}

void MOCReservior::UpdataEnd()
{
	UpdataOneEnd();
	//入口的滞压和静压都为指定的表面压力值
	UpdataPress(m_dSurfacePress,m_dSurfacePress,m_dInEle,m_dInStagPress,m_dInStaticPress,m_dOutEGL,m_dOutHGL);
	m_dOutStaticPress = m_dOutStagPress;
}

BOOL MOCReservior::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	return TRUE;
}

void MOCReservior::CalcImpulse(MOCTrans &trans, double dTime)
{
	double dZ = m_tranData.GeTransY(dTime,m_dInEle,trans.StartTime());
	SetTransZ(dZ);
	CalcStm();
}

void MOCReservior::SetTransZ(double dZ)
{
	m_EndList.SetPress(m_dSurfacePress);
	InitPipeInfo(dZ);
}
