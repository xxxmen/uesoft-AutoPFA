// PCFValveFace.cpp: implementation of the PCFValveFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFValveFace.h"
#include "PCFValve.h"
#include "ValvePerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFValveFace::PCFValveFace()
{

}

PCFValveFace::~PCFValveFace()
{

}
PCFJunFace* PCFValveFace::Creator()
{
	static PCFValveFace sValve;
	return &sValve;
}

ErrorStatus::FileError PCFValveFace::Read(PCFJun *pData, Junperisist *pModel)
{
	PCFValve *pValveData = dynamic_cast<PCFValve*>(pData);
	ASSERT(pValveData != NULL);
	ValvePerisist *pValveModel = dynamic_cast<ValvePerisist*>(pModel);
	ASSERT(pValveModel != NULL);
	return PCFJunFace::Read(pData,pModel);
}