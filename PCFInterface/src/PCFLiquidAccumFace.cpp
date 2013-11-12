// PCFLiquidAccumFace.cpp: implementation of the PCFLiquidAccumFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFLiquidAccumFace.h"
#include "PCFLiquidAccum.h"
#include "liquidaccumperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFLiquidAccumFace::PCFLiquidAccumFace()
{
	
}

PCFLiquidAccumFace::~PCFLiquidAccumFace()
{
	
}

ErrorStatus::FileError PCFLiquidAccumFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFLiquidAccum *pLiquidAccumData = dynamic_cast< PCFLiquidAccum* >( pData );
	ASSERT(pLiquidAccumData != NULL);
	LiquidAccumPerisist *pLiquidAccumModel = dynamic_cast< LiquidAccumPerisist* >( pModel );
	ASSERT(pLiquidAccumModel != NULL);
	pLiquidAccumModel->Elastic(pLiquidAccumData->Elastic());
	pLiquidAccumModel->InitVolume(pLiquidAccumData->InitVolume());
	return PCFJunFace::Read(pData,pModel);
}


PCFJunFace* PCFLiquidAccumFace::Creator()
{
	static PCFLiquidAccumFace sLiquidAccum ;
	return &sLiquidAccum;
}
