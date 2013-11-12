// AFTAssignFlowFace.cpp: implementation of the AFTAssignFlowFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTAssignFlowFace.h"
#include "AssignFlowData.h"
#include "assignflowperisist.h"
#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTAssignFlowFace::AFTAssignFlowFace()
{

}

AFTAssignFlowFace::~AFTAssignFlowFace()
{

}

ErrorStatus::FileError AFTAssignFlowFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	AssignFlowData *pAssignFlowData = dynamic_cast<AssignFlowData*>(pData);
	ASSERT(pAssignFlowData != NULL);
	AssignFlowPerisist *pAssignFlowModel = dynamic_cast<AssignFlowPerisist*>(pModel);
	ASSERT(pAssignFlowModel != NULL);
	pAssignFlowModel->Flow(pAssignFlowData->Flow());
	pAssignFlowModel->FlowDir(pAssignFlowData->FlowDir());
	pAssignFlowModel->K(pAssignFlowData->K());
	pAssignFlowModel->InitPress(pAssignFlowData->InitPress());

	AFTTransDataFace face;
	face.Read(pAssignFlowData->m_TranData,pAssignFlowModel->m_TransPersistent);
	
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTAssignFlowFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	AssignFlowData *pAssignFlowData = dynamic_cast<AssignFlowData*>(pData);
	ASSERT(pAssignFlowData != NULL);
	AssignFlowPerisist *pAssignFlowModel = dynamic_cast<AssignFlowPerisist*>(pModel);
	ASSERT(pAssignFlowModel != NULL);
	pAssignFlowData->Flow(pAssignFlowModel->Flow());
	pAssignFlowData->FlowDir(pAssignFlowModel->FlowDir());
	pAssignFlowData->K(pAssignFlowModel->K());
	pAssignFlowData->InitPress(pAssignFlowModel->InitPress());

	AFTTransDataFace face;
	face.Save(pAssignFlowData->m_TranData,pAssignFlowModel->m_TransPersistent);

	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTAssignFlowFace::Creator()
{
	static AFTAssignFlowFace sFlow;
	return &sFlow;
}
