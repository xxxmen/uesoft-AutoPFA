// AFTSprayFace.cpp: implementation of the AFTSprayFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTSprayFace.h"
#include "SprayData.h"
#include "sprayperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTSprayFace::AFTSprayFace()
{

}

AFTSprayFace::~AFTSprayFace()
{

}

ErrorStatus::FileError AFTSprayFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	SprayData *pSprayData = dynamic_cast<SprayData*>(pData);
	ASSERT(pSprayData != NULL);
	SprayPerisist *pSprayModel = dynamic_cast<SprayPerisist*>(pModel);
	ASSERT(pSprayModel != NULL);
	pSprayModel->Type(pSprayData->Type());
	pSprayModel->Curve(pSprayData->Curve());
	pSprayModel->ExitArea(pSprayData->ExitArea());
	pSprayModel->KOrCv(pSprayData->KOrCv());
	pSprayModel->ExitPress(pSprayData->ExitPress());

	AFTTransDataFace face;
	face.Read(pSprayData->m_TranData,pSprayModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTSprayFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	SprayData *pSprayData = dynamic_cast<SprayData*>(pData);
	ASSERT(pSprayData != NULL);
	SprayPerisist *pSprayModel = dynamic_cast<SprayPerisist*>(pModel);
	ASSERT(pSprayModel != NULL);
	pSprayData->Type(pSprayModel->Type());
	pSprayData->Curve(pSprayModel->Curve());
	pSprayData->ExitArea(pSprayModel->ExitArea());
	pSprayData->KOrCv(pSprayModel->KOrCv());
	pSprayData->ExitPress(pSprayModel->ExitPress());

	AFTTransDataFace face;
	face.Save(pSprayData->m_TranData,pSprayModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTSprayFace::Creator()
{
	static AFTSprayFace sSpray;
	return &sSpray;
}
