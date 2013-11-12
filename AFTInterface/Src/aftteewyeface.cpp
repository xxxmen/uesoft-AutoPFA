// AFTTeeWyeFace.cpp: implementation of the AFTTeeWyeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTTeeWyeFace.h"
#include "TeeWyeData.h"
#include "teewyeperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTTeeWyeFace::AFTTeeWyeFace()
{

}

AFTTeeWyeFace::~AFTTeeWyeFace()
{

}

ErrorStatus::FileError AFTTeeWyeFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	TeeWyeData *pTeeWyeData = dynamic_cast<TeeWyeData*>(pData);
	ASSERT(pTeeWyeData != NULL);
	TeeWyePerisist *pTeeWyeModel = dynamic_cast<TeeWyePerisist*>(pModel);
	ASSERT(pTeeWyeModel != NULL);
	pTeeWyeModel->Type(pTeeWyeData->Type());
	pTeeWyeModel->Angle(pTeeWyeData->Angle());
	pTeeWyeModel->Model(pTeeWyeData->Model());
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTTeeWyeFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	TeeWyeData *pTeeWyeData = dynamic_cast<TeeWyeData*>(pData);
	ASSERT(pTeeWyeData != NULL);
	TeeWyePerisist *pTeeWyeModel = dynamic_cast<TeeWyePerisist*>(pModel);
	ASSERT(pTeeWyeModel != NULL);
	pTeeWyeData->Type(pTeeWyeModel->Type());
	pTeeWyeData->Angle(pTeeWyeModel->Angle());
	pTeeWyeData->Model(pTeeWyeModel->Model());
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTTeeWyeFace::Creator()
{
	static AFTTeeWyeFace sTeeWye;
	return &sTeeWye;
}
