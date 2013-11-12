// CalcBendFace.cpp: implementation of the CalcBendFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcBendFace.h"
#include "CalcBend.h"
#include "BendPerisist.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcBendFace::CalcBendFace()
{

}

CalcBendFace::~CalcBendFace()
{

}
CalcJunFace* CalcBendFace::Creator()
{
	static CalcBendFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcBendFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcBend *pBendData = dynamic_cast<CalcBend*>(pData);
	ASSERT(pBendData != NULL);
	BendPerisist *pBendModel = dynamic_cast<BendPerisist*>(pModel);
	ASSERT(pBendModel != NULL);
	int nType = 0;
	double dValue = 0;
	pBendData->K(_tcstod(pBendModel->K() ,'\0'));
	GetTypeAndValue(pBendModel->BasisArea(),nType,dValue);
	pBendData->BasisAreaType(nType);
	pBendData->BasisArea(dValue);
	return CalcJunFace::Save(pData,pModel);
}