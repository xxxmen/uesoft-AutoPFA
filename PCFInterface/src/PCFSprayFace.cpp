// PCFSprayFace.cpp: implementation of the PCFSprayFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFSprayFace.h"
#include "PCFSpray.h"
#include "sprayperisist.h"
#include "PCFJun.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFSprayFace::PCFSprayFace()
{
	
}

PCFSprayFace::~PCFSprayFace()
{
	
}

ErrorStatus::FileError PCFSprayFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFSpray *pSprayData = dynamic_cast<PCFSpray*>(pData);
	ASSERT(pSprayData != NULL);
	SprayPerisist *pSprayModel = dynamic_cast<SprayPerisist*>(pModel);
	ASSERT(pSprayModel != NULL);
	pSprayModel->Type(pSprayData->Type());
	pSprayModel->Curve(pSprayData->Curve());
	pSprayModel->ExitArea(pSprayData->ExitArea());
	pSprayModel->KOrCv(pSprayData->KOrCv());
	pSprayModel->ExitPress(pSprayData->ExitPress());
	

	return PCFJunFace::Read(pData,pModel);
}


PCFJunFace* PCFSprayFace::Creator()
{
	static PCFSprayFace sSpray;
	return &sSpray;
}
