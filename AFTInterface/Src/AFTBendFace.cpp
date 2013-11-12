// AFTBendFace.cpp: implementation of the AFTBendFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTBendFace.h"
#include "BendData.h"
#include "BendPerisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTBendFace::AFTBendFace()
{

}

AFTBendFace::~AFTBendFace()
{

}

ErrorStatus::FileError AFTBendFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	BendData *pBendData = dynamic_cast<BendData*>(pData);
	ASSERT(pBendData != NULL);
	BendPerisist *pBendModel = dynamic_cast<BendPerisist*>(pModel);
	ASSERT(pBendModel != NULL);
	pBendModel->Type(pBendData->Type());
	pBendModel->Angle(pBendData->Angel());
	pBendModel->RD(pBendData->RD());
	pBendModel->K(pBendData->K());
	pBendModel->RestriFlowArea(pBendData->RestriFlowArea());
	pBendModel->BasisArea(pBendData->BasisArea());

	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTBendFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	BendData *pBendData = dynamic_cast<BendData*>(pData);
	ASSERT(pBendData != NULL);
	BendPerisist *pBendModel = dynamic_cast<BendPerisist*>(pModel);
	ASSERT(pBendModel != NULL);
	pBendData->Type(pBendModel->Type());
	pBendData->Angel(pBendModel->Angle());
	pBendData->RD(pBendModel->RD());
	pBendData->K(pBendModel->K());
	pBendData->RestriFlowArea(pBendModel->RestriFlowArea());
	pBendData->BasisArea(pBendModel->BasisArea());
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTBendFace::Creator()
{
	static AFTBendFace sBend;
	return &sBend;
}
