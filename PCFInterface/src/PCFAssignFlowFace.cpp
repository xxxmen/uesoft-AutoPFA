// PCFAssignFlowFace.cpp: implementation of the AFTAssignFlowFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFAssignFlowFace.h"
#include "PCFAssignFlow.h"
#include "assignflowperisist.h"
//#include "AFTTransDataFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFAssignFlowFace::PCFAssignFlowFace()
{
	
}

PCFAssignFlowFace::~PCFAssignFlowFace()
{
	
}

ErrorStatus::FileError PCFAssignFlowFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFAssignFlow *pAssignFlow = dynamic_cast< PCFAssignFlow* >( pData );
	ASSERT( pAssignFlow != NULL );
	AssignFlowPerisist *pAssignFlowModel = dynamic_cast< AssignFlowPerisist* >( pModel );
	ASSERT( pAssignFlowModel != NULL );
 	pAssignFlowModel->Flow(pAssignFlow->GetAssignFlow());
 	pAssignFlowModel->FlowDir( pAssignFlow->GetAssignFlowDir() );
 	pAssignFlowModel->K( pAssignFlow->GetK() );
// 	pAssignFlowModel->InitPress( pAssignFlow->GetAssignInitPress() );
	
// 	AFTTransDataFace face;
// 	face.Read(pAssignFlow->m_TranData,pAssignFlowModel->m_TransPersistent);
	
	return PCFJunFace::Read( pData,pModel );
}

PCFJunFace* PCFAssignFlowFace::Creator()
{
	static PCFAssignFlowFace sPCFAssignFlowFace;
	return &sPCFAssignFlowFace;
}




