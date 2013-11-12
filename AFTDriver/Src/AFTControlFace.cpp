// AFTControlFace.cpp: implementation of the AFTControlFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTControlFace.h"
#include "ControlValveData.h"
#include "controlperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTControlFace::AFTControlFace()
{

}

AFTControlFace::~AFTControlFace()
{

}

ErrorStatus::FileError AFTControlFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	ControlValveData *pControlValveData = dynamic_cast<ControlValveData*>(pData);
	ASSERT(pControlValveData != NULL);
	ControlPerisist *pControlValveModel = dynamic_cast<ControlPerisist*>(pModel);
	ASSERT(pControlValveModel != NULL);
	pControlValveModel->ControlSet(pControlValveData->ControlSet());
	pControlValveModel->KOrCv(pControlValveData->KOrCv());
	pControlValveModel->ModelType(pControlValveData->ModelType());
	pControlValveModel->FailAction(pControlValveData->FailAction());
	pControlValveModel->m_KOrCvData.Unit(pControlValveData->KOrCvUnit());
	pControlValveModel->m_KOrCvData.Data(pControlValveData->KOrCvData());

	AFTTransDataFace face;
	face.Read(pControlValveData->m_TranData,pControlValveModel->m_TransPersistent);
	face.Read(pControlValveData->m_FailTranData,pControlValveModel->m_FailTransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTControlFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	ControlValveData *pControlValveData = dynamic_cast<ControlValveData*>(pData);
	ASSERT(pControlValveData != NULL);
	ControlPerisist *pControlValveModel = dynamic_cast<ControlPerisist*>(pModel);
	ASSERT(pControlValveModel != NULL);
	pControlValveData->ControlSet(pControlValveModel->ControlSet());
	pControlValveData->KOrCv(pControlValveModel->KOrCv());
	pControlValveData->ModelType(pControlValveModel->ModelType());
	pControlValveData->FailAction(pControlValveModel->FailAction());
	pControlValveData->KOrCvUnit(pControlValveModel->m_KOrCvData.Unit());
	pControlValveData->KOrCvData(pControlValveModel->m_KOrCvData.Data());
	AFTTransDataFace face;
	face.Save(pControlValveData->m_TranData,pControlValveModel->m_TransPersistent);
	face.Save(pControlValveData->m_FailTranData,pControlValveModel->m_FailTransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTControlFace::Creator()
{
	static AFTControlFace sContorl;
	return &sContorl;
}
