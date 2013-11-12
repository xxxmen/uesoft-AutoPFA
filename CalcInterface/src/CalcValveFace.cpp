// CalcValveFace.cpp: implementation of the CalcValveFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcValveFace.h"
#include "CalcValve.h"
#include "valveperisist.h"
#include "PersistentHeader.h"
#include "CalcCurveFace.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcValveFace::CalcValveFace()
{

}

CalcValveFace::~CalcValveFace()
{

}

CalcJunFace* CalcValveFace::Creator()
{
	static CalcValveFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcValveFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcValve *pValveData = dynamic_cast<CalcValve*>(pData);
	ASSERT(pValveData != NULL);
	ValvePerisist *pValveModel = dynamic_cast<ValvePerisist*>(pModel);
	ASSERT(pValveModel != NULL);
	int nType = 0;
	double dValue = 0;
	pValveData->KOrCv(strtod(pValveModel->KOrCv()));
	GetTypeAndValue(pValveModel->BasisArea(),nType,dValue);
	pValveData->BasisAreaType(nType);
	pValveData->BasisArea(dValue);
	pValveData->Type(_atoi(pValveModel->Type()));
	GetTypeAndValue(pValveModel->ExitPress(),nType,dValue);
	pValveData->ExitPressType(nType);
	pValveData->ExitPress(dValue);
	CalcCurveFace curveface;
	curveface.LossType(nType,pValveModel->Curve());
	pValveData->LossType(nType);


	CalcTransDataFace face;
	face.Save(pValveData->m_TranData,pValveModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}