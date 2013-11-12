// AFTAssignPressFace.cpp: implementation of the AFTAssignPressFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTAssignPressFace.h"
#include "assignpressperisist.h"
#include "AssignPressData.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTAssignPressFace::AFTAssignPressFace()
{

}

AFTAssignPressFace::~AFTAssignPressFace()
{

}

ErrorStatus::FileError AFTAssignPressFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	AssignPressData *pAssignPressData = dynamic_cast<AssignPressData*>(pData);
	ASSERT(pAssignPressData != NULL);
	AssignPressPerisist *pAssignPressModel = dynamic_cast<AssignPressPerisist*>(pModel);
	ASSERT(pAssignPressModel != NULL);
	pAssignPressModel->PipeInfo(pAssignPressData->PipeInfo());
	pAssignPressModel->DistanceUnit(pAssignPressData->DistanceUnit());
	pAssignPressModel->Pressure(pAssignPressData->Pressure());
	
	AFTTransDataFace face;
	face.Read(pAssignPressData->m_TranData,pAssignPressModel->m_TransPersistent);
	
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTAssignPressFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here

	AssignPressData *pAssignPressData = dynamic_cast<AssignPressData*>(pData);
	ASSERT(pAssignPressData != NULL);
	AssignPressPerisist *pAssignPressModel = dynamic_cast<AssignPressPerisist*>(pModel);
	ASSERT(pAssignPressModel != NULL);
	pAssignPressData->PipeInfo(pAssignPressModel->PipeInfo());
	pAssignPressData->DistanceUnit(pAssignPressModel->DistanceUnit());
	pAssignPressData->Pressure(pAssignPressModel->Pressure());

	AFTTransDataFace face;
	face.Save(pAssignPressData->m_TranData,pAssignPressModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTAssignPressFace::Creator()
{
	static AFTAssignPressFace sPress;
	return &sPress;
}
