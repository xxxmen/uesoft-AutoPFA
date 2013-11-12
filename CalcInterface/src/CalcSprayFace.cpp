// CalcSprayFace.cpp: implementation of the CalcSprayFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcSprayFace.h"
#include "CalcSpray.h"
#include "sprayperisist.h"
#include "CalcCurveFace.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcSprayFace::CalcSprayFace()
{

}

CalcSprayFace::~CalcSprayFace()
{

}

CalcJunFace* CalcSprayFace::Creator()
{
	static CalcSprayFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcSprayFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcSpray *pSprayData = dynamic_cast<CalcSpray*>(pData);
	ASSERT(pSprayData != NULL);
	SprayPerisist *pSprayModel = dynamic_cast<SprayPerisist*>(pModel);
	ASSERT(pSprayModel != NULL);
	int nType = 0;
	double dValue = 0;
	int nHoleNum = 0;
	StrArray<3> &ref = pSprayModel->ExitArea();
	if(0==_ttoi(pSprayModel->Type()))
	{
		nHoleNum = 1;
	}
	else
	{
		nHoleNum = abs(ref.nData(2));
	}
	pSprayData->ExitArea(TransStd(ref.Data(0),ref.Data(1)));
	pSprayData->HoleNum(nHoleNum);
	CalcCurveFace curveface;
	curveface.LossType(nType,pSprayModel->Curve());
	pSprayData->LossType(nType);
	if(nType == 1)
	{
		curveface.fireK(dValue,pSprayModel->Curve());
		pSprayData->KOrCv(strtod(pSprayModel->KOrCv())*dValue);
	}
	else
	{
		pSprayData->KOrCv(strtod(pSprayModel->KOrCv()));
	}
	GetTypeAndValue(pSprayModel->ExitPress(),nType,dValue);
	pSprayData->ExitPressType(nType);
	pSprayData->ExitPress(dValue);

	
	CalcTransDataFace face;
	face.Save(pSprayData->m_TranData,pSprayModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}