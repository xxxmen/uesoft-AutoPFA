// PCFBranchFace.cpp: implementation of the PCFBranchFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFBranchFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
#include "PCFSetOnTee.h"
#include "BranchPerisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFBranchFace::PCFBranchFace()
{

}

PCFBranchFace::~PCFBranchFace()
{

}

PCFJunFace* PCFBranchFace::Creator()
{
	static PCFBranchFace sBranch;
	return &sBranch;
}

ErrorStatus::FileError PCFBranchFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFSetOnTee *pBrachData = dynamic_cast<PCFSetOnTee*>(pData);
	ASSERT(pBrachData != NULL);
	BranchPerisist *pBranchModel = dynamic_cast<BranchPerisist*>(pModel);
	ASSERT(pBranchModel != NULL);
	ListImp<StrArray<4> > strValve;
	pBranchModel->PipeInfo(strValve,pData->GetPtList().GetCount());
	pBranchModel->DistanceUnit(_T("meters"));
	return PCFJunFace::Read(pData,pModel);
}