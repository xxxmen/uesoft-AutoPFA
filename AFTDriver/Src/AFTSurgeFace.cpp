// AFTSurgeFace.cpp: implementation of the AFTSurgeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTSurgeFace.h"
#include "SurgeData.h"
#include "surgeperisist.h"
#include "AFTTransDataFace.h"
#include "AFTTwoDTableFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTSurgeFace::AFTSurgeFace()
{

}

AFTSurgeFace::~AFTSurgeFace()
{

}

ErrorStatus::FileError AFTSurgeFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	SurgeData *pSurgeData = dynamic_cast<SurgeData*>(pData);
	ASSERT(pSurgeData != NULL);
	SurgePerisist *pSurgeModel = dynamic_cast<SurgePerisist*>(pModel);
	ASSERT(pSurgeModel != NULL);
	pSurgeModel->PipeInfo(pSurgeData->PipeInfo());
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

	AFTTableFace faceTable;
	faceTable.Read(pSurgeData->m_AreaTable,pSurgeModel->m_AreaTable);
	AFTTransDataFace face;
	face.Read(pSurgeData->m_TranData,pSurgeModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTSurgeFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	SurgeData *pSurgeData = dynamic_cast<SurgeData*>(pData);
	ASSERT(pSurgeData != NULL);
	SurgePerisist *pSurgeModel = dynamic_cast<SurgePerisist*>(pModel);
	ASSERT(pSurgeModel != NULL);
	pSurgeData->PipeInfo(pSurgeModel->PipeInfo());
	pSurgeData->DistanceUnit(pSurgeModel->DistanceUnit());
	pSurgeData->SurgeHeight(pSurgeModel->SurgeHeight());
	pSurgeData->ConstArea(pSurgeModel->ConstArea());
	pSurgeData->SurfacePress(pSurgeModel->SurfacePress());
	pSurgeData->Orifice(pSurgeModel->Orifice());
	pSurgeData->ShortPipe(pSurgeModel->ShortPipe());
	pSurgeData->OneWay(pSurgeModel->OneWay());
	pSurgeData->Vessel(pSurgeModel->Vessel());
	pSurgeData->Variable(pSurgeModel->Variable());
	pSurgeData->InitSurfaceH(pSurgeModel->InitSurfaceH());
	pSurgeData->Check(pSurgeModel->Check());

	AFTTableFace faceTable;
	faceTable.Save(pSurgeData->m_AreaTable,pSurgeModel->m_AreaTable);

	AFTTransDataFace face;
	face.Save(pSurgeData->m_TranData,pSurgeModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTSurgeFace::Creator()
{
	static AFTSurgeFace sSurge;
	return &sSurge;
}
