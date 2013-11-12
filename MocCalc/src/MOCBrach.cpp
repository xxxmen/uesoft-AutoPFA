// MOCBrach.cpp: implementation of the MOCBrach class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCBrach.h"
#include "MOCFluid.h"
#include "CalcBrach.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCBrach::MOCBrach()
{
	m_dImposeFlow = 0;
}

MOCBrach::~MOCBrach()
{

}

MOCJun* MOCBrach::Creator()
{
	MOCBrach *pData = new MOCBrach;
	return pData;
}

BOOL MOCBrach::Read(CalcJun *pData)
{
	ReadJun(pData);
	CalcBrach *pBrachData = dynamic_cast<CalcBrach*>(pData);
	ASSERT(pBrachData != NULL);
	m_tranData.Read(pBrachData->m_TranData);
	m_PipeInfo = pBrachData->PipeInfo();
	m_dImposeFlow = pBrachData->ImposeFlow();
	m_tranData.TranRel(RelToAbs,m_dImposeFlow);
	if(0==pBrachData->ImposeFlowType())
	{
		m_dImposeFlow = MOCFluid::TranQToMass(m_dImposeFlow);
		m_tranData.Tran(MOCFluid::TranQToMass);
	}
	return TRUE;
}

BOOL MOCBrach::InitEndInfo()
{
	double m_dLossKup;
	double m_dLossKdown;
	InitInOutEle();
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
		m_dLossKup=Info.fData(1);
		m_dLossKdown=Info.fData(2);
		pEnd->SetZ(pEnd->GetZ()+Info.fData(3));

		if ( Info.nData(0) > 0 )
		{
			m_dLossK += m_dLossKdown;
		} 
		else
		{
			m_dLossK +=m_dLossKup;
		}
	}
	

	return TRUE;
}

void MOCBrach::CalcStm()
{
	CalcStm(m_dImposeFlow);
}

void MOCBrach::CalcStm(double dFlow)
{
	m_EndList.BranchStrategy(dFlow);
}

void MOCBrach::UpdataEnd()
{
	UpdataOneEnd();
}

BOOL MOCBrach::InitTranData(MOCComponentMgr &mgr)
{
	m_tranData.Init(mgr);
	return TRUE;
}

void MOCBrach::CalcImpulse(MOCTrans &trans, double dTime)
{
	double dFlow = m_tranData.GeTransY(dTime,m_dImposeFlow,trans.StartTime());
	CalcStm(dFlow);
}
