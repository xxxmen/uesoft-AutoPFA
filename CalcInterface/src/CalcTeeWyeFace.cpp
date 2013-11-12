// CalcTeeWyeFace.cpp: implementation of the CalcTeeWyeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcTeeWyeFace.h"
#include "CalcTeeWye.h"
#include "teewyeperisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcTeeWyeFace::CalcTeeWyeFace()
{

}

CalcTeeWyeFace::~CalcTeeWyeFace()
{

}

CalcJunFace* CalcTeeWyeFace::Creator()
{
	static CalcTeeWyeFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcTeeWyeFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcTeeWye *pTeeWyeData = dynamic_cast<CalcTeeWye*>(pData);
	ASSERT(pTeeWyeData != NULL);
	TeeWyePerisist *pTeeWyeModel = dynamic_cast<TeeWyePerisist*>(pModel);
	ASSERT(pTeeWyeModel != NULL);
	pTeeWyeData->Type(_atoi(pTeeWyeModel->Type()));
	pTeeWyeData->Angle(strtod(pTeeWyeModel->Angle()));
	pTeeWyeData->Model(_atoi(pTeeWyeModel->Model()));
	return CalcJunFace::Save(pData,pModel);
}