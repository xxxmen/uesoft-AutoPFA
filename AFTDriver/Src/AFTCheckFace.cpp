// AFTCheckFace.cpp: implementation of the AFTCheckFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTCheckFace.h"
#include "CheckValveData.h"
#include "checkperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTCheckFace::AFTCheckFace()
{

}

AFTCheckFace::~AFTCheckFace()
{

}

ErrorStatus::FileError AFTCheckFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	CheckValveData *pCheckValveData = dynamic_cast<CheckValveData*>(pData);
	ASSERT(pCheckValveData != NULL);
	CheckPerisist *pCheckValveModel = dynamic_cast<CheckPerisist*>(pModel);
	ASSERT(pCheckValveModel != NULL);
	pCheckValveModel->ReOpenPress(pCheckValveData->ReOpenPress());
	pCheckValveModel->Curve(pCheckValveData->Curve());
	pCheckValveModel->KOrCv(pCheckValveData->KOrCv());
	pCheckValveModel->BasisArea(pCheckValveData->BasisArea());
	pCheckValveModel->CloseVel(pCheckValveData->CloseVel());
	
	AFTTransDataFace face;
	face.Read(pCheckValveData->m_TranData,pCheckValveModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTCheckFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CheckValveData *pCheckValveData = dynamic_cast<CheckValveData*>(pData);
	ASSERT(pCheckValveData != NULL);
	CheckPerisist *pCheckValveModel = dynamic_cast<CheckPerisist*>(pModel);
	ASSERT(pCheckValveModel != NULL);
	pCheckValveData->ReOpenPress(pCheckValveModel->ReOpenPress());
	pCheckValveData->Curve(pCheckValveModel->Curve());
	pCheckValveData->KOrCv(pCheckValveModel->KOrCv());
	pCheckValveData->BasisArea(pCheckValveModel->BasisArea());
	pCheckValveData->CloseVel(pCheckValveModel->CloseVel());

	AFTTransDataFace face;
	face.Save(pCheckValveData->m_TranData,pCheckValveModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTCheckFace::Creator()
{
	static AFTCheckFace sCheck;
	return &sCheck;
}
