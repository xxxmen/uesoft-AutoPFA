// AFTGeneralFace.cpp: implementation of the AFTGeneralFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTGeneralFace.h"
#include "GeneralData.h"
#include "generalperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTGeneralFace::AFTGeneralFace()
{

}

AFTGeneralFace::~AFTGeneralFace()
{

}

ErrorStatus::FileError AFTGeneralFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	GeneralData *pGeneralData = dynamic_cast<GeneralData*>(pData);
	ASSERT(pGeneralData != NULL);
	GeneralPerisist *pGeneralModel = dynamic_cast<GeneralPerisist*>(pModel);
	ASSERT(pGeneralModel != NULL);
	pGeneralModel->Type(pGeneralData->Type());
	pGeneralModel->Curve(pGeneralData->Curve());
	pGeneralModel->KOrCv(pGeneralData->KOrCv());
	pGeneralModel->BasisArea(pGeneralData->BasisArea());
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTGeneralFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	GeneralData *pGeneralData = dynamic_cast<GeneralData*>(pData);
	ASSERT(pGeneralData != NULL);
	GeneralPerisist *pGeneralModel = dynamic_cast<GeneralPerisist*>(pModel);
	ASSERT(pGeneralModel != NULL);
	pGeneralData->Type(pGeneralModel->Type());
	pGeneralData->Curve(pGeneralModel->Curve());
	pGeneralData->KOrCv(pGeneralModel->KOrCv());
	pGeneralData->BasisArea(pGeneralModel->BasisArea());
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTGeneralFace::Creator()
{
	static AFTGeneralFace sGeneral;
	return &sGeneral;
}
