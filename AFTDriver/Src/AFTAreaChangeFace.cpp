// AFTAreaChangeFace.cpp: implementation of the AFTAreaChangeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTAreaChangeFace.h"
#include "AreaChangeData.h"
#include "areachangeperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTAreaChangeFace::AFTAreaChangeFace()
{

}

AFTAreaChangeFace::~AFTAreaChangeFace()
{

}

ErrorStatus::FileError AFTAreaChangeFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	AreaChangeData *pAreaChangeData = dynamic_cast<AreaChangeData*>(pData);
	ASSERT(pAreaChangeData != NULL);
	AreaChangePerisist *pAreaChangeModel = dynamic_cast<AreaChangePerisist*>(pModel);
	ASSERT(pAreaChangeModel != NULL);
	pAreaChangeModel->Type(pAreaChangeData->Type());
	pAreaChangeModel->K(pAreaChangeData->K());
	pAreaChangeModel->Dir(pAreaChangeData->Dir());
	pAreaChangeModel->Angle(pAreaChangeData->Angle());
	pAreaChangeModel->BasisArea(pAreaChangeData->BasisArea());
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTAreaChangeFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	AreaChangeData *pAreaChangeData = dynamic_cast<AreaChangeData*>(pData);
	ASSERT(pAreaChangeData != NULL);
	AreaChangePerisist *pAreaChangeModel = dynamic_cast<AreaChangePerisist*>(pModel);
	ASSERT(pAreaChangeModel != NULL);
	pAreaChangeData->Type(pAreaChangeModel->Type());
	pAreaChangeData->K(pAreaChangeModel->K());
	pAreaChangeData->Dir(pAreaChangeModel->Dir());
	pAreaChangeData->Angle(pAreaChangeModel->Angle());
	pAreaChangeData->BasisArea(pAreaChangeModel->BasisArea());
	
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTAreaChangeFace::Creator()
{
	static AFTAreaChangeFace sAreaChange;
	return &sAreaChange;
}
