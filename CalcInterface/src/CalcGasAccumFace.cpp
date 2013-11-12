// CalcGasAccumFace.cpp: implementation of the CalcGasAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcGasAccumFace.h"
#include "CalcGasAccum.h"
#include "gasaccumperisist.h"
#include "CalcOrificeFace.h"
#include "CalcShortPipeFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcGasAccumFace::CalcGasAccumFace()
{

}

CalcGasAccumFace::~CalcGasAccumFace()
{

}

CalcJunFace* CalcGasAccumFace::Creator()
{
	static CalcGasAccumFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcGasAccumFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcGasAccum *pGasAccumData = dynamic_cast<CalcGasAccum*>(pData);
	ASSERT(pGasAccumData != NULL);
	GasAccumPerisist *pGasAccumModel = dynamic_cast<GasAccumPerisist*>(pModel);
	ASSERT(pGasAccumModel != NULL);
	int nType = 0;
	double dValue = 0;
	pGasAccumData->Polytropic(_tcstod(pGasAccumModel->Polytropic(),'\0'));
	pGasAccumData->InitVolume(TransStd(pGasAccumModel->InitVolume()));
	CString strUnit = pGasAccumModel->InitVolume().Data(1);
	pGasAccumData->MaxVolume(TransStd(pGasAccumModel->MaxVolume(),strUnit));
	pGasAccumData->MinVolume(TransStd(pGasAccumModel->MinVolume(),strUnit));
	StrArray<4> &ref = pGasAccumModel->InitPress();
	pGasAccumData->SelInitPress(ref.nData(0));
	pGasAccumData->InitPressType(ref.nData(1));
	pGasAccumData->InitPress(TransStd(ref.Data(2),ref.Data(3)));
	GetTypeAndValue(pGasAccumModel->GasVolume(),nType,dValue);
	pGasAccumData->Type(nType);
	pGasAccumData->RefPress(dValue);
	CalcOrificeFace face1;
	face1.Save(pGasAccumData->m_Orifice,pGasAccumModel->Orifice());
	CalcShortPipeFace face2;
	face2.Save(pGasAccumData->m_ShortPipe,pGasAccumModel->ShortPipe());
	return CalcJunFace::Save(pData,pModel);
}