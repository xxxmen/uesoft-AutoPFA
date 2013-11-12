// PCFSurgeFace.cpp: implementation of the PCFSurgeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSurgeFace.h"
#include "PCFSurge.h"
#include "surgeperisist.h"
#include "PCFJunFace.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSurgeFace::PCFSurgeFace()
{
	
}

PCFSurgeFace::~PCFSurgeFace()
{
	
}

ErrorStatus::FileError PCFSurgeFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFSurge *pSurgeData = dynamic_cast<PCFSurge*>(pData);
	ASSERT(pSurgeData != NULL);
	SurgePerisist *pSurgeModel = dynamic_cast<SurgePerisist*>(pModel);
	ASSERT(pSurgeModel != NULL);
	pSurgeModel->DistanceUnit(pSurgeData->DistanceUnit());
	pSurgeModel->SurgeHeight(pSurgeData->SurgeHeight());
	pSurgeModel->ConstArea(pSurgeData->ConstArea());
	pSurgeModel->SurfacePress(pSurgeData->SurfacePress());
	pSurgeModel->Orifice(pSurgeData->Orifice());
	pSurgeModel->ShortPipe(pSurgeData->ShortPipe());
	pSurgeModel->OneWay(pSurgeData->OneWay());
	pSurgeModel->Vessel(pSurgeData->Vessel());
	pSurgeModel->Variable(pSurgeData->Variable());
	pSurgeModel->InitSurfaceH(pSurgeData->InitSurfaceH());
	pSurgeModel->Check(pSurgeData->Check());

	return PCFJunFace::Read(pData,pModel);
}

PCFJunFace* PCFSurgeFace::Creator()
{
	static PCFSurgeFace sSurge;
	return &sSurge;
}
