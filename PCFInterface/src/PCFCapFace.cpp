// PCFCapFace.cpp: implementation of the PCFCapFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFCapFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFCapFace::PCFCapFace()
{

}

PCFCapFace::~PCFCapFace()
{

}

PCFJunFace* PCFCapFace::Creator()
{
	static PCFCapFace sCap;
	return &sCap;
}

ErrorStatus::FileError PCFCapFace::Read(PCFJun *pData, Junperisist *pModel)
{
	
	return ErrorStatus::eFileOK;
}