// PCFTeeFace.cpp: implementation of the PCFTeeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFTeeFace.h"
#include "PCFTee.h"
#include "TeeWyePerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFTeeFace::PCFTeeFace()
{

}

PCFTeeFace::~PCFTeeFace()
{

}

PCFJunFace* PCFTeeFace::Creator()
{
	static PCFTeeFace sTee;
	return &sTee;
}

ErrorStatus::FileError PCFTeeFace::Read(PCFJun *pData, Junperisist *pModel)
{
	PCFTee *pTeeData = dynamic_cast<PCFTee*>(pData);
	ASSERT(pTeeData != NULL);
	TeeWyePerisist *pTeeModel = dynamic_cast<TeeWyePerisist*>(pModel);
	ASSERT(pTeeModel != NULL);
	
	//pTeeModel->Type(_T("0"));
	//pTeeModel->Angle(ftoStr(pTeeData->GetAngle()));
	// 	pBendModel->RD(pBendData->RD());
	// 	pBendModel->K(pBendData->K());
	// 	pBendModel->RestriFlowArea(pBendData->RestriFlowArea());
		// 	pBendModel->BasisArea(pBendData->BasisArea());
	return PCFJunFace::Read(pData,pModel);
	
	

	//return ErrorStatus::eFileOK;
}