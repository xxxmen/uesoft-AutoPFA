// AFTValveFace.cpp: implementation of the AFTValveFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTValveFace.h"
#include "ValveData.h"
#include "valveperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTValveFace::AFTValveFace()
{

}

AFTValveFace::~AFTValveFace()
{

}

ErrorStatus::FileError AFTValveFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	ValveData *pValveData = dynamic_cast<ValveData*>(pData);
	ASSERT(pValveData != NULL);
	ValvePerisist *pValveModel = dynamic_cast<ValvePerisist*>(pModel);
	ASSERT(pValveModel != NULL);
	pValveModel->Type(pValveData->Type());
	pValveModel->Curve(pValveData->Curve());
	pValveModel->ExitPress(pValveData->ExitPress());
	pValveModel->KOrCv(pValveData->KOrCv());
	pValveModel->BasisArea(pValveData->BasisArea());

	AFTTransDataFace face;
	face.Read(pValveData->m_TranData,pValveModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTValveFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	ValveData *pValveData = dynamic_cast<ValveData*>(pData);
	ASSERT(pValveData != NULL);
	ValvePerisist *pValveModel = dynamic_cast<ValvePerisist*>(pModel);
	ASSERT(pValveModel != NULL);
	pValveData->Type(pValveModel->Type());
	pValveData->Curve(pValveModel->Curve());
	pValveData->ExitPress(pValveModel->ExitPress());
	pValveData->KOrCv(pValveModel->KOrCv());
	pValveData->BasisArea(pValveModel->BasisArea());

	AFTTransDataFace face;
	face.Save(pValveData->m_TranData,pValveModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTValveFace::Creator()
{
	static AFTValveFace sValve;
	return &sValve;
}
