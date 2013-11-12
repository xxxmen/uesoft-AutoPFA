// AFTReliefFace.cpp: implementation of the AFTReliefFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTReliefFace.h"
#include "ReliefData.h"
#include "reliefperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTReliefFace::AFTReliefFace()
{

}

AFTReliefFace::~AFTReliefFace()
{

}

ErrorStatus::FileError AFTReliefFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	ReliefData *pReliefData = dynamic_cast<ReliefData*>(pData);
	ASSERT(pReliefData != NULL);
	ReliefPerisist *pReliefModel = dynamic_cast<ReliefPerisist*>(pModel);
	ASSERT(pReliefModel != NULL);
	pReliefModel->Type(pReliefData->Type());
	pReliefModel->Curve(pReliefData->Curve());
	pReliefModel->CrackExitPress(pReliefData->CrackExitPress());
	pReliefModel->KOrCv(pReliefData->KOrCv());
	pReliefModel->BasisArea(pReliefData->BasisArea());

	AFTTransDataFace face;
	face.Read(pReliefData->m_TranData,pReliefModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTReliefFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	ReliefData *pReliefData = dynamic_cast<ReliefData*>(pData);
	ASSERT(pReliefData != NULL);
	ReliefPerisist *pReliefModel = dynamic_cast<ReliefPerisist*>(pModel);
	ASSERT(pReliefModel != NULL);
	pReliefData->Type(pReliefModel->Type());
	pReliefData->Curve(pReliefModel->Curve());
	pReliefData->CrackExitPress(pReliefModel->CrackExitPress());
	pReliefData->KOrCv(pReliefModel->KOrCv());
	pReliefData->BasisArea(pReliefModel->BasisArea());

	AFTTransDataFace face;
	face.Save(pReliefData->m_TranData,pReliefModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTReliefFace::Creator()
{
	static AFTReliefFace sRelief;
	return &sRelief;
}
