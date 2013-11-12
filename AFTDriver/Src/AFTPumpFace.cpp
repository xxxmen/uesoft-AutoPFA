// AFTPumpFace.cpp: implementation of the AFTPumpFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTPumpFace.h"
#include "PumpData.h"
#include "pumpperisist.h"
#include "AFTTransDataFace.h"
#include "AFTConfigFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTPumpFace::AFTPumpFace()
{

}

AFTPumpFace::~AFTPumpFace()
{

}

ErrorStatus::FileError AFTPumpFace::Read(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Read here
	PumpData *pPumpData = dynamic_cast<PumpData*>(pData);
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

	AFTConfigFace ConfigFace;
	ConfigFace.Read(pPumpData->m_Config,pPumpModel->m_ConfigPerisist);

	AFTTransDataFace face;
	face.Read(pPumpData->m_TranData,pPumpModel->m_TransPersistent);
	return AFTJunFace::Read(pData,pModel);
}
ErrorStatus::FileError AFTPumpFace::Save(JunctionData *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	PumpData *pPumpData = dynamic_cast<PumpData*>(pData);
	ASSERT(pPumpData != NULL);
	PumpPerisist *pPumpModel = dynamic_cast<PumpPerisist*>(pModel);
	ASSERT(pPumpModel != NULL);
	pPumpData->PressType(pPumpModel->PumpType());
	pPumpData->PumpFlow(pPumpModel->PumpFlow());
	pPumpData->SpeedRatio(pPumpModel->SpeedRatio());
	pPumpData->PumpControl(pPumpModel->PumpControl());
	pPumpData->ControlApply(pPumpModel->ControlApply());
	pPumpData->PressType(pPumpModel->PressType());
	pPumpData->SubmergePump(pPumpModel->SubmergePump());
	pPumpData->ExitCheck(pPumpModel->ExitCheck());
	pPumpData->CloseVel(pPumpModel->CloseVel());
	pPumpData->AntiReverse(pPumpModel->AntiReverse());
	pPumpData->ReOpenPress(pPumpModel->ReOpenPress());
	pPumpData->PumpSet(pPumpModel->PumpSet());
	AFTConfigFace ConfigFace;
	ConfigFace.Save(pPumpData->m_Config,pPumpModel->m_ConfigPerisist);

	AFTTransDataFace face;
	face.Save(pPumpData->m_TranData,pPumpModel->m_TransPersistent);
	return AFTJunFace::Save(pData,pModel);
}

AFTJunFace* AFTPumpFace::Creator()
{
	static AFTPumpFace sPump;
	return &sPump;
}
