// CalcAssignFlowFace.cpp: implementation of the CalcAssignFlowFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcAssignFlowFace.h"
#include "CalcAssignFlow.h"
#include "assignflowperisist.h"
#include "CalcTransDataFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcAssignFlowFace::CalcAssignFlowFace()
{

}

CalcAssignFlowFace::~CalcAssignFlowFace()
{

}

CalcJunFace* CalcAssignFlowFace::Creator()
{
	static CalcAssignFlowFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcAssignFlowFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcAssignFlow *pAssignFlowData = dynamic_cast<CalcAssignFlow*>(pData);
	ASSERT(pAssignFlowData != NULL);
	AssignFlowPerisist *pAssignFlowModel = dynamic_cast<AssignFlowPerisist*>(pModel);
	ASSERT(pAssignFlowModel != NULL);
	int nType = 0;
	double dValue = 0;
	GetTypeAndValue(pAssignFlowModel->Flow(),nType,dValue);
	pAssignFlowData->FlowType(nType);
	pAssignFlowData->Flow(dValue);
	pAssignFlowData->FlowDir(_ttoi(pAssignFlowModel->FlowDir()));
	pAssignFlowData->K(_tcstod(pAssignFlowModel->K() , '\0'));
	StrArray<4> &ref = pAssignFlowModel->InitPress();
	pAssignFlowData->SelInitPress(ref.nData(0));
	pAssignFlowData->InitPressType(ref.nData(1));
	pAssignFlowData->InitPress(TransStd(ref.Data(2),ref.Data(3)));

	CalcTransDataFace face;
	face.Save(pAssignFlowData->m_TranData,pAssignFlowModel->m_TransPersistent);

	return CalcJunFace::Save(pData,pModel);
}