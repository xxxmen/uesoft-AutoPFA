// CalcAreaChangeFace.cpp: implementation of the CalcAreaChangeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcAreaChangeFace.h"
#include "CalcAreaChange.h"
#include "areachangeperisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcAreaChangeFace::CalcAreaChangeFace()
{

}

CalcAreaChangeFace::~CalcAreaChangeFace()
{

}

CalcJunFace* CalcAreaChangeFace::Creator()
{
	static CalcAreaChangeFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcAreaChangeFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcAreaChange *pAreaChangeData = dynamic_cast<CalcAreaChange*>(pData);
	ASSERT(pAreaChangeData != NULL);
	AreaChangePerisist *pAreaChangeModel = dynamic_cast<AreaChangePerisist*>(pModel);
	ASSERT(pAreaChangeModel != NULL);
	int nType = 0;
	double dValue = 0;
	pAreaChangeData->Type(_ttoi(pAreaChangeModel->Type()));
	pAreaChangeData->Angle(_tcstod(pAreaChangeModel->Angle() , '\0'));
	pAreaChangeData->K(_tcstod(pAreaChangeModel->K() , '\0'));

	GetTypeAndValue(pAreaChangeModel->BasisArea(),nType,dValue);
	pAreaChangeData->BasisAreaType(nType);
	pAreaChangeData->BasisArea(dValue);
	return CalcJunFace::Save(pData,pModel);
}