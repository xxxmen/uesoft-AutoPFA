// AFTLiquidAccumFace.cpp: implementation of the AFTLiquidAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTLiquidAccumFace.h"
#include "LiquidAccumData.h"
#include "liquidaccumperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTLiquidAccumFace::AFTLiquidAccumFace()
{

}

AFTLiquidAccumFace::~AFTLiquidAccumFace()
{

}

ErrorStatus::FileError AFTLiquidAccumFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	LiquidAccumData *pLiquidAccumData = dynamic_cast<LiquidAccumData*>(pData);
	ASSERT(pLiquidAccumData != NULL);
	LiquidAccumPerisist *pLiquidAccumModel = dynamic_cast<LiquidAccumPerisist*>(pModel);
	ASSERT(pLiquidAccumModel != NULL);
	pLiquidAccumModel->Elastic(pLiquidAccumData->Elastic());
	pLiquidAccumModel->InitVolume(pLiquidAccumData->InitVolume());
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTLiquidAccumFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	LiquidAccumData *pLiquidAccumData = dynamic_cast<LiquidAccumData*>(pData);
	ASSERT(pLiquidAccumData != NULL);
	LiquidAccumPerisist *pLiquidAccumModel = dynamic_cast<LiquidAccumPerisist*>(pModel);
	ASSERT(pLiquidAccumModel != NULL);
	pLiquidAccumData->Elastic(pLiquidAccumModel->Elastic());
	pLiquidAccumData->InitVolume(pLiquidAccumModel->InitVolume());
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTLiquidAccumFace::Creator()
{
	static AFTLiquidAccumFace sLiquidAccum ;
	return &sLiquidAccum;
}
