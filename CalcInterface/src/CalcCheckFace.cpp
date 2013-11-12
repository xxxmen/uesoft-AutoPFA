// CalcCheckFace.cpp: implementation of the CalcCheckFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcCheckFace.h"
#include "CalcCheck.h"
#include "checkperisist.h"
#include "CalcCurveFace.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcCheckFace::CalcCheckFace()
{

}

CalcCheckFace::~CalcCheckFace()
{

}

CalcJunFace* CalcCheckFace::Creator()
{
	static CalcCheckFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcCheckFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcCheck *pCheckValveData = dynamic_cast<CalcCheck*>(pData);
	ASSERT(pCheckValveData != NULL);
	CheckPerisist *pCheckValveModel = dynamic_cast<CheckPerisist*>(pModel);
	ASSERT(pCheckValveModel != NULL);
	int nType = 0;
	double dValue = 0;
	GetTypeAndValue(pCheckValveModel->ReOpenPress(),nType,dValue);
	pCheckValveData->ReOpenPressType(nType);
	pCheckValveData->ReOpenPress(dValue);
	pCheckValveData->KOrCv(_tcstod(pCheckValveModel->KOrCv(),'\0'));
	GetTypeAndValue(pCheckValveModel->BasisArea(),nType,dValue);
	pCheckValveData->BasisAreaType(nType);
	pCheckValveData->BasisArea(dValue);
	pCheckValveData->CloseVel(TransStd(pCheckValveModel->CloseVel()));
	CalcCurveFace curveface;
	curveface.LossType(nType,pCheckValveModel->Curve());
	pCheckValveData->LossType(nType);
	CalcTransDataFace face;
	face.Save(pCheckValveData->m_TranData,pCheckValveModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}
