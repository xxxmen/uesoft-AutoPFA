// PCFGasAccumFace.cpp: implementation of the PCFGasAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFGasAccumFace.h"
#include "PCFGasAccum.h"
#include "gasaccumperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFGasAccumFace::PCFGasAccumFace()
{
	
}

PCFGasAccumFace::~PCFGasAccumFace()
{
	
}

ErrorStatus::FileError PCFGasAccumFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFGasAccum *pGasAccumData = dynamic_cast<PCFGasAccum*>(pData);
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
	
	return PCFJunFace::Read(pData,pModel);
}

PCFJunFace* PCFGasAccumFace::Creator()
{
	static PCFGasAccumFace sGasAcuum;
	return &sGasAcuum;
}
