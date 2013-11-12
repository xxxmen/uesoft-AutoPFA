// AFTReserviorFace.cpp: implementation of the AFTReserviorFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTReserviorFace.h"
#include "ReserviorData.h"
#include "reservoirperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTReserviorFace::AFTReserviorFace()
{

}

AFTReserviorFace::~AFTReserviorFace()
{

}

ErrorStatus::FileError AFTReserviorFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	ReserviorData *pReserviorData = dynamic_cast<ReserviorData*>(pData);
	ASSERT(pReserviorData != NULL);
	ReservoirPerisist *pReserviorModel = dynamic_cast<ReservoirPerisist*>(pModel);
	ASSERT(pReserviorModel != NULL);
	pReserviorModel->PipeInfo(pReserviorData->PipeInfo());
	pReserviorModel->EleOrDepth(pReserviorData->EleOrDepth());
	pReserviorModel->SurfacePress(pReserviorData->SurfacePress());
	pReserviorModel->Teamperature(pReserviorData->Teamperature());
	pReserviorModel->Density(pReserviorData->Density());
	pReserviorModel->EleOrDepthType(pReserviorData->EleOrDepthType());

	AFTTransDataFace face;
	face.Read(pReserviorData->m_TranData,pReserviorModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTReserviorFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	ReserviorData *pReserviorData = dynamic_cast<ReserviorData*>(pData);
	ASSERT(pReserviorData != NULL);
	ReservoirPerisist *pReserviorModel = dynamic_cast<ReservoirPerisist*>(pModel);
	ASSERT(pReserviorModel != NULL);
	pReserviorData->PipeInfo(pReserviorModel->PipeInfo());
	pReserviorData->EleOrDepth(pReserviorModel->EleOrDepth());
	pReserviorData->SurfacePress(pReserviorModel->SurfacePress());
	pReserviorData->Teamperature(pReserviorModel->Teamperature());
	pReserviorData->Density(pReserviorModel->Density());
	pReserviorData->EleOrDepthType(pReserviorModel->EleOrDepthType());

	AFTTransDataFace face;
	face.Save(pReserviorData->m_TranData,pReserviorModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTReserviorFace::Creator()
{
	static AFTReserviorFace sReservior;
	return &sReservior;
}
