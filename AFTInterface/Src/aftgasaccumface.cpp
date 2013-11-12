// AFTGasAccumFace.cpp: implementation of the AFTGasAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTGasAccumFace.h"
#include "GasAccumData.h"
#include "gasaccumperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTGasAccumFace::AFTGasAccumFace()
{

}

AFTGasAccumFace::~AFTGasAccumFace()
{

}

ErrorStatus::FileError AFTGasAccumFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	GasAccumData *pGasAccumData = dynamic_cast<GasAccumData*>(pData);
	ASSERT(pGasAccumData != NULL);
	GasAccumPerisist *pGasAccumModel = dynamic_cast<GasAccumPerisist*>(pModel);
	ASSERT(pGasAccumModel != NULL);
	pGasAccumModel->Polytropic(pGasAccumData->Polytropic());
	pGasAccumModel->InitVolume(pGasAccumData->InitVolume());
	pGasAccumModel->Orifice(pGasAccumData->Orifice());
	pGasAccumModel->ShortPipe(pGasAccumData->ShortPipe());
	pGasAccumModel->MaxVolume(pGasAccumData->MaxVolume());
	pGasAccumModel->MinVolume(pGasAccumData->MinVolume());
	pGasAccumModel->InitPress(pGasAccumData->InitPress());
	pGasAccumModel->GasVolume(pGasAccumData->GasVolume());

	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTGasAccumFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	GasAccumData *pGasAccumData = dynamic_cast<GasAccumData*>(pData);
	ASSERT(pGasAccumData != NULL);
	GasAccumPerisist *pGasAccumModel = dynamic_cast<GasAccumPerisist*>(pModel);
	ASSERT(pGasAccumModel != NULL);
	pGasAccumData->Polytropic(pGasAccumModel->Polytropic());
	pGasAccumData->InitVolume(pGasAccumModel->InitVolume());
	pGasAccumData->Orifice(pGasAccumModel->Orifice());
	pGasAccumData->ShortPipe(pGasAccumModel->ShortPipe());
	pGasAccumData->MaxVolume(pGasAccumModel->MaxVolume());
	pGasAccumData->MinVolume(pGasAccumModel->MinVolume());
	pGasAccumData->InitPress(pGasAccumModel->InitPress());
	pGasAccumData->GasVolume(pGasAccumModel->GasVolume());
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTGasAccumFace::Creator()
{
	static AFTGasAccumFace sGasAcuum;
	return &sGasAcuum;
}
