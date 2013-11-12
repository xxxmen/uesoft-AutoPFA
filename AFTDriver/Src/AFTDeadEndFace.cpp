// AFTDeadEndFace.cpp: implementation of the AFTDeadEndFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTDeadEndFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTDeadEndFace::AFTDeadEndFace()
{

}

AFTDeadEndFace::~AFTDeadEndFace()
{

}

ErrorStatus::FileError AFTDeadEndFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here

	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTDeadEndFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here

	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTDeadEndFace::Creator()
{
	static AFTDeadEndFace sDeadEnd;
	return &sDeadEnd;
}
