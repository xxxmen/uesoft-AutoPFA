// CalcGeneralFace.cpp: implementation of the CalcGeneralFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcGeneralFace.h"
#include "CalcGeneral.h"
#include "generalperisist.h"
#include "CalcCurveFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcGeneralFace::CalcGeneralFace()
{

}

CalcGeneralFace::~CalcGeneralFace()
{

}

CalcJunFace* CalcGeneralFace::Creator()
{
	static CalcGeneralFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcGeneralFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcGeneral *pGeneralData = dynamic_cast<CalcGeneral*>(pData);
	ASSERT(pGeneralData != NULL);
	GeneralPerisist *pGeneralModel = dynamic_cast<GeneralPerisist*>(pModel);
	ASSERT(pGeneralModel != NULL);
	int nType = 0;
	double dValue =0;
	CalcCurveFace curveface;
	curveface.LossType(nType,pGeneralModel->Curve());
	pGeneralData->LossType(nType);
	curveface.Save(pGeneralData->m_Curve,pGeneralModel->Curve());
	pGeneralData->K(_tcstod(pGeneralModel->KOrCv(),'\0'));
	GetTypeAndValue(pGeneralModel->BasisArea(),nType,dValue);
	pGeneralData->BasisAreaType(nType);
	pGeneralData->BasisArea(dValue);
	return CalcJunFace::Save(pData,pModel);
}