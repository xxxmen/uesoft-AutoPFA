// CalcReliefFace.cpp: implementation of the CalcReliefFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcReliefFace.h"
#include "CalcRelief.h"
#include "reliefperisist.h"
#include "CalcCurveFace.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcReliefFace::CalcReliefFace()
{

}

CalcReliefFace::~CalcReliefFace()
{

}

CalcJunFace* CalcReliefFace::Creator()
{
	static CalcReliefFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcReliefFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcRelief *pReliefData = dynamic_cast<CalcRelief*>(pData);
	ASSERT(pReliefData != NULL);
	ReliefPerisist *pReliefModel = dynamic_cast<ReliefPerisist*>(pModel);
	ASSERT(pReliefModel != NULL);
	int nType = 0;
	double dValue = 0;
	CalcCurveFace curveface;
	curveface.LossType(nType,pReliefModel->Curve());
	pReliefData->LossType(nType);
	curveface.Save(pReliefData->m_Curve,pReliefModel->Curve());
	pReliefData->Type(_atoi(pReliefModel->Type()));
	StrArray<5> &ref = pReliefModel->CrackExitPress();
	pReliefData->PressType(ref.nData(0));
	pReliefData->CrackPress(TransStd(ref.Data(1),ref.Data(2)));
	pReliefData->ExitPress(TransStd(ref.Data(3),ref.Data(4)));
	pReliefData->KOrCv(strtod(pReliefModel->KOrCv()));
	GetTypeAndValue(pReliefModel->BasisArea(),nType,dValue);
	pReliefData->BasisAreaType(nType);
	pReliefData->BasisArea(dValue);
	CalcTransDataFace face;
	face.Save(pReliefData->m_TranData,pReliefModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}
