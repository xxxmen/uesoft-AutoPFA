// CalcSurgeFace.cpp: implementation of the CalcSurgeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcSurge.h"
#include "surgeperisist.h"
#include "CalcOrificeFace.h"
#include "CalcShortPipeFace.h"
#include "CalcSurgeFace.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcSurgeFace::CalcSurgeFace()
{

}

CalcSurgeFace::~CalcSurgeFace()
{

}

CalcJunFace* CalcSurgeFace::Creator()
{
	static CalcSurgeFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcSurgeFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcSurge *pSurgeData = dynamic_cast<CalcSurge*>(pData);
	ASSERT(pSurgeData != NULL);
	SurgePerisist *pSurgeModel = dynamic_cast<SurgePerisist*>(pModel);
	ASSERT(pSurgeModel != NULL);
	int nType = 0;
	double dValue = 0;
	pSurgeData->PipeInfo(pSurgeModel->PipeInfoToStd());
	pSurgeData->OneWay(_atoi(pSurgeModel->OneWay()));
	StrArray<4> &ref1 = pSurgeModel->Vessel();
	pSurgeData->SelVessel(ref1.nData(0));
	pSurgeData->VesselHeight(TransStd(ref1.Data(1),ref1.Data(2)));
	pSurgeData->Polytropic(ref1.fData(3));
	GetTypeAndValue(pSurgeModel->InitSurfaceH(),nType,dValue);
	pSurgeData->SelSurfaceH(nType);
	pSurgeData->InitSurfaceH(dValue);
	StrArray<5> ref2 = pSurgeModel->Check(); 
	pSurgeData->CheckCv(ref2.fData(0));
	pSurgeData->Position(ref2.nData(1));
	pSurgeData->ReOpenPressType(ref2.nData(2));
	pSurgeData->ReOpenPress(TransStd(ref2.Data(3),ref2.Data(4)));
	pSurgeData->SurgeHeight(TransStd(pSurgeModel->SurgeHeight()));
	pSurgeData->ConstArea(TransStd(pSurgeModel->ConstArea()));
	pSurgeData->SurfacePress(TransStd(pSurgeModel->SurfacePress()));
	CalcOrificeFace face1;
	face1.Save(pSurgeData->m_Orifice,pSurgeModel->Orifice());
	CalcShortPipeFace face2;
	face2.Save(pSurgeData->m_ShortPipe,pSurgeModel->ShortPipe());

    pSurgeData->AreaTable(pSurgeModel->m_AreaTable.DataToStd());

	CalcTransDataFace face;
	face.Save(pSurgeData->m_TranData,pSurgeModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}