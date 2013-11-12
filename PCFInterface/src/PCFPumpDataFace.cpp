// PCFPumpDataFace.cpp: implementation of the AFTAssignFlowFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPumpDataFace.h"
#include "PCFPumpData.h"
#include "PumpPerisist.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPumpDataFace::PCFPumpDataFace()
{
	
}

PCFPumpDataFace::~PCFPumpDataFace()
{
	
}

ErrorStatus::FileError PCFPumpDataFace::Read(PCFJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PCFPumpData *pPumpData = dynamic_cast<PCFPumpData*>(pData);
	ASSERT(pPumpData != NULL);
	PumpPerisist *pPumpModel = dynamic_cast<PumpPerisist*>(pModel);
	ASSERT(pPumpModel != NULL);
 	pPumpModel->PumpType(pPumpData->PumpType());
	pPumpModel->PumpFlow(pPumpData->PumpFlow());
	pPumpModel->SpeedRatio(pPumpData->SpeedRatio());
	pPumpModel->PumpControl(pPumpData->PumpControl());
	pPumpModel->ControlApply(pPumpData->ControlApply());
	pPumpModel->PressType(pPumpData->PressType());
	pPumpModel->SubmergePump(pPumpData->SubmergePump());
	pPumpModel->ExitCheck(pPumpData->ExitCheck());
	pPumpModel->CloseVel(pPumpData->CloseVel());
	pPumpModel->AntiReverse(pPumpData->AntiReverse());
	pPumpModel->ReOpenPress(pPumpData->ReOpenPress());
	pPumpModel->PumpSet(pPumpData->PumpSet());
	
// 	AFTConfigFace ConfigFace;
// 	ConfigFace.Read(pPumpData->m_Config,pPumpModel->m_ConfigPerisist);
// 	
// 	AFTTransDataFace face;
// 	face.Read(pPumpData->m_TranData,pPumpModel->m_TransPersistent);
	return PCFJunFace::Read(pData,pModel);
}

PCFJunFace* PCFPumpDataFace::Creator()
{
	static PCFPumpDataFace sPCFPumpDataFace;
	return &sPCFPumpDataFace;
}




