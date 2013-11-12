// CalcDeadEndFace.cpp: implementation of the CalcDeadEndFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcDeadEndFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcDeadEndFace::CalcDeadEndFace()
{

}

CalcDeadEndFace::~CalcDeadEndFace()
{

}

CalcJunFace* CalcDeadEndFace::Creator()
{
	static CalcDeadEndFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcDeadEndFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here

	return CalcJunFace::Save(pData,pModel);
}