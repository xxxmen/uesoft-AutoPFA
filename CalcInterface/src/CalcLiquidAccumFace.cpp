// CalcLiquidAccumFace.cpp: implementation of the CalcLiquidAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcLiquidAccumFace.h"
#include "CalcLiquidAccum.h"
#include "liquidaccumperisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcLiquidAccumFace::CalcLiquidAccumFace()
{

}

CalcLiquidAccumFace::~CalcLiquidAccumFace()
{

}

CalcJunFace* CalcLiquidAccumFace::Creator()
{
	static CalcLiquidAccumFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcLiquidAccumFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcLiquidAccum *pLiquidAccumData = dynamic_cast<CalcLiquidAccum*>(pData);
	ASSERT(pLiquidAccumData != NULL);
	LiquidAccumPerisist *pLiquidAccumModel = dynamic_cast<LiquidAccumPerisist*>(pModel);
	ASSERT(pLiquidAccumModel != NULL);
	pLiquidAccumData->Elastic(TransStd(pLiquidAccumModel->Elastic()));
	pLiquidAccumData->InitVolume(TransStd(pLiquidAccumModel->InitVolume()));
	return CalcJunFace::Save(pData,pModel);
}