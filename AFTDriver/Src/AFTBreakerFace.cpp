// AFTBreakerFace.cpp: implementation of the AFTBreakerFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTBreakerFace.h"
#include "breakerperisist.h"
#include "BreckerData.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTBreakerFace::AFTBreakerFace()
{

}

AFTBreakerFace::~AFTBreakerFace()
{

}

ErrorStatus::FileError AFTBreakerFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	BreckerData *pBreckerData = dynamic_cast<BreckerData*>(pData);
	ASSERT(pBreckerData != NULL);
	BreakerPerisist *pBreakerModel = dynamic_cast<BreakerPerisist*>(pModel);
	ASSERT(pBreakerModel != NULL);
	pBreakerModel->CrackPress(pBreckerData->CrackPress());
	pBreakerModel->OrificeInCdA(pBreckerData->OrificeInCdA());
	pBreakerModel->OrificeOutCdA(pBreckerData->OrificeOutCdA());
	pBreakerModel->LiquidTemp(pBreckerData->LiquidTemp());
	pBreakerModel->GasProperty(pBreckerData->GasProperty());
	pBreakerModel->ConnectPipe(pBreckerData->ConnectPipe());
	pBreakerModel->ValveType(pBreckerData->ValveType());
	pBreakerModel->InterMediateCdA(pBreckerData->InterMediateCdA());
	pBreakerModel->MediateActivation(pBreckerData->MediateActivation());
	
	
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTBreakerFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	BreckerData *pBreckerData = dynamic_cast<BreckerData*>(pData);
	ASSERT(pBreckerData != NULL);
	BreakerPerisist *pBreakerModel = dynamic_cast<BreakerPerisist*>(pModel);
	ASSERT(pBreakerModel != NULL);
	pBreckerData->CrackPress(pBreakerModel->CrackPress());
	pBreckerData->OrificeInCdA(pBreakerModel->OrificeInCdA());
	pBreckerData->OrificeOutCdA(pBreakerModel->OrificeOutCdA());
	pBreckerData->LiquidTemp(pBreakerModel->LiquidTemp());
	pBreckerData->GasProperty(pBreakerModel->GasProperty());
	pBreckerData->ConnectPipe(pBreakerModel->ConnectPipe());
	pBreckerData->ValveType(pBreakerModel->ValveType());
	pBreckerData->InterMediateCdA(pBreakerModel->InterMediateCdA());
	pBreckerData->MediateActivation(pBreakerModel->MediateActivation());
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTBreakerFace::Creator()
{
	static AFTBreakerFace sBreaker;
	return &sBreaker;
}
