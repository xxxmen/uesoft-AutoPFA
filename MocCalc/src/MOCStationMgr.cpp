// MOCStationMgr.cpp: implementation of the MOCStationMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCStationMgr.h"
#include "MOCPipe.h"
#include "MOCTrans.h"
#include "MOCFluid.h"
#include "StationOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCStationMgr::MOCStationMgr()
{
	m_dHPress = 0;
	m_dStamR = 0;
}

MOCStationMgr::~MOCStationMgr()
{
	Empty();
}

BOOL MOCStationMgr::Init(MOCPipe *pPipe,int nSectionNum)
{
	ASSERT(m_pPipe != NULL);
	Empty();
	if(nSectionNum < 1)
	{
		ASSERT(FALSE);
		return FALSE;
	}
	m_pPipe = pPipe;
	m_dStamR = pPipe->CalcR()/nSectionNum;
	MOCStation *pStation = NULL;
	for(int i=1;i<nSectionNum;i++)
	{
		pStation = Creator(i);
		Init(pStation,i,nSectionNum);
	}
	m_dHPress = pPipe->GetDeltaG()/nSectionNum;
	return TRUE;
}

MOCStation* MOCStationMgr::Creator(int nKey)
{
	MOCStation *pStation = MOCStation::Creator();
	ASSERT(pStation != NULL);
	pStation->Key(nKey);
	m_stationMap.SetAt(nKey,pStation);
	return pStation;
}

void MOCStationMgr::Init(MOCStation *pStation,int nIndex,int nSectionNum)
{
	ASSERT(pStation != NULL);
	EndInfo *pInEnd = m_pPipe->GetInEnd();
	EndInfo *pOutEnd = m_pPipe->GetOutEnd();
	double dArea = pInEnd->Area();
	double dMass = (pInEnd->GetMass()+pOutEnd->GetMass()) / 2;
	double dInPress = pInEnd->GetPress();
	double dDeltaPress = (pOutEnd->GetPress()-dInPress) / nSectionNum;
	double dInZ = pInEnd->GetZ();
	double dDeltaZ = (pOutEnd->GetZ()-dInZ) / nSectionNum;
	pStation->SetMass(dMass);
	pStation->SetPress(dInPress+dDeltaPress*nIndex);
	pStation->SetZ(dInZ+dDeltaZ*nIndex);
	pStation->SetArea(dArea);
}

void MOCStationMgr::Empty()
{
	DelMap<MOCStation>(m_stationMap);
}

Iterator<MOCStation>* MOCStationMgr::CreatIterator()
{
	return new MapIterator<MOCStation>(&m_stationMap);
}

MOCStation* MOCStationMgr::LookUp(int nKey)
{
	return LookMap<MOCStation>(m_stationMap,nKey);
}

void MOCStationMgr::CalcImpulse(MOCTrans &trans)
{
	CalcCB();
	CalcStation(trans);
}

void MOCStationMgr::CalcCB()
{
	ASSERT(m_pPipe != NULL);
	MOCStation *pMOCStation = NULL;
	double dF = m_pPipe->FrictionCalc();
	int nSectionNum = m_stationMap.GetCount()+1;
	EndInfo *pInEnd = m_pPipe->GetInEnd();
	EndInfo *pOutEnd = NULL;
	for(int i=1;i<nSectionNum;i++)
	{
		pMOCStation = LookUp(i);
		ASSERT(pMOCStation != NULL);
		pOutEnd = pMOCStation->GetInEnd();
	    CalcCB(pInEnd,pOutEnd,dF,nSectionNum);
		pInEnd = pMOCStation->GetOutEnd();
	}
	pOutEnd = m_pPipe->GetOutEnd();
	CalcCB(pInEnd,pOutEnd,dF,nSectionNum);
}

void MOCStationMgr::CalcStation(MOCTrans &trans)
{
	MOCStation *pMOCStation = NULL;
	IteratorPtr<MOCStation> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCStation = &ItPtr->CurrentItem();
		ASSERT(pMOCStation != NULL);
		pMOCStation->CalcImpulse(trans);
	}
}

void MOCStationMgr::CalcCB(EndInfo *pInEnd,EndInfo *pOutEnd,double dF,int nSectionNum)
{
	double dR = m_dStamR;
	if(MOCFluid::IsVariableR())
		dR = m_pPipe->CalcR(dF,pInEnd->OutJunK() + pOutEnd->InJunK(),nSectionNum);
	double dB = m_pPipe->B();
	double dCp = pInEnd->GetPress() + dB*pInEnd->GetMass() - m_dHPress;
	double dCm = pOutEnd->GetPress() - dB*pOutEnd->GetMass()  + m_dHPress;
	double dBp = dB + dR*fabs(pInEnd->GetMass());
	double dBm = dB + dR*fabs(pOutEnd->GetMass());
	pInEnd->SetCpm(dCm);
	pInEnd->SetBpm(dBm);
	pOutEnd->SetCpm(dCp);
	pOutEnd->SetBpm(dBp);
}

void MOCStationMgr::Result(StationOut &out, MOCPipe* pMocPipe)
{
	MOCStation *pMOCStation = NULL;
	int nSectionNum = m_stationMap.GetCount()+1;
	EndInfo *pEnd = m_pPipe->GetInEnd();
	Result(out,pEnd,0,pMocPipe, pEnd->CalcEndLoss());
	//加上输出控制来控制是否输出内部节点
	for(int i=1;i<nSectionNum;i++)
	{
		pMOCStation = LookUp(i);
		ASSERT(pMOCStation != NULL);
		pEnd = pMOCStation->GetInEnd();
		Result(out,pEnd,i, pMocPipe);
	}
	pEnd = m_pPipe->GetOutEnd();
	Result(out,pEnd,nSectionNum,pMocPipe, -pEnd->CalcEndLoss());
}

void MOCStationMgr::Result(StationOut &out,EndInfo *pEnd,int nKey, MOCPipe* pMocPipe, double dLoss)
{
	StationStmOut *pOut = out.Creator(nKey);
	pOut->SetValue(nKey, 29);
	if ( NULL != pMocPipe )
	{
//		pOut->SetValue(pMocPipe->Key(), 29);
		pOut->Key(pMocPipe->Key());
	}

	double dEL = MOCFluid::TranPressToH(dLoss);
	pOut->SetMassFlow(pEnd->GetMass());
	pOut->SetVolumeFlow(pEnd->GetVolumeFlow());
	pOut->SetVelocity(pEnd->GetVelocity());
	pOut->SetStagPress(pEnd->GetStagPress()-dLoss);
	pOut->SetStaticPress(pEnd->GetStaticPress()-dLoss);
	pOut->SetEGL(pEnd->GetEGL()-dEL);
	pOut->SetHGL(pEnd->GetHGL()-dEL);
	pOut->SetVopor(pEnd->VaporVolume());
}