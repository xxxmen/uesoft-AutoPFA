// CalcControlFace.cpp: implementation of the CalcControlFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcControlFace.h"
#include "CalcControl.h"
#include "controlperisist.h"
#include "CalcTransData.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcControlFace::CalcControlFace()
{

}

CalcControlFace::~CalcControlFace()
{

}

CalcJunFace* CalcControlFace::Creator()
{
	static CalcControlFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcControlFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcControl *pControlValveData = dynamic_cast<CalcControl*>(pData);
	ASSERT(pControlValveData != NULL);
	ControlPerisist *pControlValveModel = dynamic_cast<ControlPerisist*>(pModel);
	ASSERT(pControlValveModel != NULL);
	StrArray<5> &ref = pControlValveModel->ControlSet();
	pControlValveData->Type(ref.nData(0));
	pControlValveData->ControlType(ref.nData(1));
	pControlValveData->PressType(ref.nData(2));
	pControlValveData->ControlValue(TransStd(ref.Data(3),ref.Data(4)));
	pControlValveData->KOrCv(_tcstod(pControlValveModel->KOrCv() , '\0'));
	pControlValveData->LossType(_ttoi(pControlValveModel->ModelType()));
	StrArray<4> &ref1 = pControlValveModel->FailAction();
	pControlValveData->AlwayControl(ref1.nData(0));
	pControlValveData->UpInsuffic(ref1.nData(2));
	pControlValveData->DownExcess(ref1.nData(3));
	pControlValveData->CvTable(pControlValveModel->m_KOrCvData.DataToStd());

	CalcTransDataFace face;
	face.Save(pControlValveData->m_TranData,pControlValveModel->m_TransPersistent);
 	face.Save(pControlValveData->m_FailTranData,pControlValveModel->m_FailTransPersistent);
	return CalcJunFace::Save(pData,pModel);
}
