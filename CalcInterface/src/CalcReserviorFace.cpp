// CalcReserviorFace.cpp: implementation of the CalcReserviorFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcReserviorFace.h"
#include "CalcReservior.h"
#include "reservoirperisist.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcReserviorFace::CalcReserviorFace()
{

}

CalcReserviorFace::~CalcReserviorFace()
{

}

CalcJunFace* CalcReserviorFace::Creator()
{
	static CalcReserviorFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcReserviorFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcReservior *pReserviorData = dynamic_cast<CalcReservior*>(pData);
	ASSERT(pReserviorData != NULL);
	ReservoirPerisist *pReserviorModel = dynamic_cast<ReservoirPerisist*>(pModel);
	ASSERT(pReserviorModel != NULL);
	pReserviorData->PipeInfo(pReserviorModel->PipeInfoToStd());
	pReserviorData->SurfacePress(TransStd(pReserviorModel->SurfacePress()));
	pReserviorData->EleOrDepthType(_atoi(pReserviorModel->EleOrDepthType()));

	CalcTransDataFace face;
	face.Save(pReserviorData->m_TranData,pReserviorModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}