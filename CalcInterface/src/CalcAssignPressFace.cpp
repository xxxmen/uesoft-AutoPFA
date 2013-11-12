// CalcAssignPressFace.cpp: implementation of the CalcAssignPressFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcAssignPressFace.h"
#include "CalcAssignPress.h"
#include "assignpressperisist.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcAssignPressFace::CalcAssignPressFace()
{

}

CalcAssignPressFace::~CalcAssignPressFace()
{

}

CalcJunFace* CalcAssignPressFace::Creator()
{
	static CalcAssignPressFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcAssignPressFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here

	CalcAssignPress *pAssignPressData = dynamic_cast<CalcAssignPress*>(pData);
	ASSERT(pAssignPressData != NULL);
	AssignPressPerisist *pAssignPressModel = dynamic_cast<AssignPressPerisist*>(pModel);
	ASSERT(pAssignPressModel != NULL);
	int nType = 0;
	double dValue = 0;
	pAssignPressData->PipeInfo(pAssignPressModel->PipeInfoToStd());
	GetTypeAndValue(pAssignPressModel->Pressure(),nType,dValue);
	pAssignPressData->PressType(nType);
	pAssignPressData->Press(dValue);
	
	CalcTransDataFace face;
	face.Save(pAssignPressData->m_TranData,pAssignPressModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}
