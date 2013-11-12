// CalcBranchFace.cpp: implementation of the CalcBranchFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcBranchFace.h"
#include "CalcBrach.h"
#include "branchperisist.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcBranchFace::CalcBranchFace()
{

}

CalcBranchFace::~CalcBranchFace()
{

}

CalcJunFace* CalcBranchFace::Creator()
{
	static CalcBranchFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcBranchFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcBrach *pBrachData = dynamic_cast<CalcBrach*>(pData);
	ASSERT(pBrachData != NULL);
	BranchPerisist *pBranchModel = dynamic_cast<BranchPerisist*>(pModel);
	ASSERT(pBranchModel != NULL);
	int nType = 0;
	double dValue = 0;
	pBrachData->PipeInfo(pBranchModel->PipeInfoToStd());
	GetTypeAndValue(pBranchModel->ImposeFlow(),nType,dValue);
	pBrachData->ImposeFlowType(nType);
	pBrachData->ImposeFlow(dValue);

	CalcTransDataFace face;
	face.Save(pBrachData->m_TranData,pBranchModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}