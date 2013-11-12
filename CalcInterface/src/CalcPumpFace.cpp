// CalcPumpFace.cpp: implementation of the CalcPumpFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPumpFace.h"
#include "CalcPump.h"
#include "pumpperisist.h"
#include "CalcTransDataFace.h"
#include "CalcPumpConfigFace.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPumpFace::CalcPumpFace()
{

}

CalcPumpFace::~CalcPumpFace()
{

}

CalcJunFace* CalcPumpFace::Creator()
{
	static CalcPumpFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcPumpFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcPump *pPumpData = dynamic_cast<CalcPump*>(pData);
	ASSERT(pPumpData != NULL);
	PumpPerisist *pPumpModel = dynamic_cast<PumpPerisist*>(pModel);
	ASSERT(pPumpModel != NULL);
	int nType = 0;
	double dValue = 0;
	pPumpData->AntiReverse(_atoi(pPumpModel->AntiReverse()));
	pPumpData->ExitCheck(_atoi(pPumpModel->ExitCheck()));
	pPumpData->CloseVel(TransStd(pPumpModel->CloseVel()));
	pPumpData->PressType(_atoi(pPumpModel->PumpType()));
	StrArray<4> &ref = pPumpModel->SubmergePump();
	pPumpData->SelSubmerge(ref.nData(0));
	pPumpData->SubmergePressType(ref.nData(1));
	pPumpData->SuctionPress(TransStd(ref.Data(2),ref.Data(3)));
	pPumpData->PumpSet(_atoi(pPumpModel->PumpSet()));
	pPumpData->PumpType(_atoi(pPumpModel->PumpType()));
	GetTypeAndValue(pPumpModel->PumpFlow(),nType,dValue);
	pPumpData->PumpFlow(dValue);
	pPumpData->SpeedRatio(strtod(pPumpModel->SpeedRatio()));

	StrArray<4> &ref1 = pPumpModel->PumpControl();
	//参照变速泵界面
	int nPumpControl = abs(ref1.nData(0));
	int nControlType = abs(ref1.nData(1));
	int nNewPumpControl = 0;
	if(nPumpControl ==2)
	{
		nNewPumpControl = 5 + nControlType;
	}
	else
	{
		nNewPumpControl = nPumpControl + nControlType;
	}
	pPumpData->PumpControl(nNewPumpControl);
	pPumpData->ControlType(nControlType);
	pPumpData->ControlValue(TransStd(ref1.Data(2),ref1.Data(3)));
	pPumpData->ControlApply(_atoi(pPumpModel->ControlApply()));
	GetTypeAndValue(pPumpModel->ReOpenPress(),nType,dValue);
	pPumpData->ReOpenPressType(nType);
	pPumpData->ReOpenPress(dValue);
	pPumpData->TranModel(_atoi(pPumpModel->m_TransPersistent.TranModel()));
	pPumpData->RotateInertia(TransStd(pPumpModel->m_TransPersistent.RotateInertia()));
	pPumpData->Speed(strtod(pPumpModel->m_TransPersistent.Speed()));
	pPumpData->FourQuadrantAngle(pPumpModel->m_TransPersistent.FourQuadrant().nData(2));
	pPumpData->FourQuadrantData(pPumpModel->m_TransPersistent.m_FourquadTable.DataToStd());

	CalcPumpConfigFace ConfigFace;
	ConfigFace.Save(pPumpData->m_Config,pPumpModel->m_ConfigPerisist);

	CalcTransDataFace face;
	face.Save(pPumpData->m_TranData,pPumpModel->m_TransPersistent);
	return CalcJunFace::Save(pData,pModel);
}
