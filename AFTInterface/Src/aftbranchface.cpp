// AFTBranchFace.cpp: implementation of the AFTBranchFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTBranchFace.h"
#include "BrachData.h"
#include "branchperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTBranchFace::AFTBranchFace()
{

}

AFTBranchFace::~AFTBranchFace()
{

}

ErrorStatus::FileError AFTBranchFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	BrachData *pBrachData = dynamic_cast<BrachData*>(pData);
	ASSERT(pBrachData != NULL);
	BranchPerisist *pBranchModel = dynamic_cast<BranchPerisist*>(pModel);
	ASSERT(pBranchModel != NULL);
	pBranchModel->PipeInfo(pBrachData->PipeInfo());
	pBranchModel->DistanceUnit(pBrachData->DistanceUnit());
	pBranchModel->ImposeFlow(pBrachData->ImposeFlow());
	
	AFTTransDataFace face;
	face.Read(pBrachData->m_TranData,pBranchModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTBranchFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	BrachData *pBrachData = dynamic_cast<BrachData*>(pData);
	ASSERT(pBrachData != NULL);
	BranchPerisist *pBranchModel = dynamic_cast<BranchPerisist*>(pModel);
	ASSERT(pBranchModel != NULL);
	pBrachData->PipeInfo(pBranchModel->PipeInfo());
	pBrachData->DistanceUnit(pBranchModel->DistanceUnit());
	pBrachData->ImposeFlow(pBranchModel->ImposeFlow());

	AFTTransDataFace face;
	face.Save(pBrachData->m_TranData,pBranchModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTBranchFace::Creator()
{
	static AFTBranchFace sBranch;
	return &sBranch;
}
