// AFTPipeFace.cpp: implementation of the AFTPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTPipeFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTPipeFace::AFTPipeFace()
{

}

AFTPipeFace::~AFTPipeFace()
{

}

ErrorStatus::FileError AFTPipeFace::Read(PipeData *pData,PipePerisist *pModel)
{
	pModel->Key(pData->GetNum());
	pModel->Name(pData->Name());
	pModel->StartPtX(pData->StartPtX());
	pModel->StartPtY(pData->StartPtY());
	pModel->EndPtX(pData->EndPtX());
	pModel->EndPtY(pData->EndPtY());
	pModel->InJunID(pData->InJunID());
	pModel->OutJunID(pData->OutJunID());
	pModel->InDia(pData->InDia());
	pModel->InDiaUnit(pData->InDiaUnit());
	pModel->Len(pData->Len());
	pModel->LenUnit(pData->LenUnit());
	pModel->WaveSpeed(pData->WaveSpeed());
	pModel->WaveSpeedUnit(pData->WaveSpeedUnit());
	pModel->B(pData->B());
	pModel->Material(pData->Material());
	pModel->Size(pData->Size());
	pModel->PipeType(pData->PipeType());
	pModel->Thick(pData->Thick());
	pModel->ThickUnit(pData->ThickUnit());
	pModel->Elasticity(pData->Elasticity());
	pModel->ElasticityUnit(pData->ElasticityUnit());
	pModel->PossionRatio(pData->PossionRatio());
	pModel->CalcWave(pData->CalcWave());
	pModel->SupportType(pData->SupportType());
	pModel->C1(pData->C1());
	pModel->FrictionModel(pData->FrictionModel());
	pModel->Friction(pData->Friction());
	pModel->FrictionUnit(pData->FrictionUnit());
	pModel->InDiaReduce(pData->InDiaReduce());
	pModel->LocalK(pData->LocalK());
	pModel->PipeFactor(pData->PipeFactor());
	pModel->FitFactor(pData->FitFactor());
	pModel->InitFlow(pData->InitFlow());
	pModel->SectionNum(pData->SectionNum());
	pModel->ParaNum(pData->ParaNum());
	pModel->PartFull(pData->PartFull());

	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTPipeFace::Save(PipeData *pData,PipePerisist *pModel)
{
	pData->SetNum(pModel->Key());
	pData->Name(pModel->Name());
	pData->StartPtX(pModel->StartPtX());
	pData->StartPtY(pModel->StartPtY());
	pData->EndPtX(pModel->EndPtX());
	pData->EndPtY(pModel->EndPtY());
	pData->InJunID(pModel->InJunID());
	pData->OutJunID(pModel->OutJunID());
	pData->InDia(pModel->InDia());
	pData->InDiaUnit(pModel->InDiaUnit());
	pData->Len(pModel->Len());
	pData->LenUnit(pModel->LenUnit());
	pData->WaveSpeed(pModel->WaveSpeed());
	pData->WaveSpeedUnit(pModel->WaveSpeedUnit());
	pData->B(pModel->B());
	pData->Material(pModel->Material());
	pData->Size(pModel->Size());
	pData->PipeType(pModel->PipeType());
	pData->Thick(pModel->Thick());
	pData->ThickUnit(pModel->ThickUnit());
	pData->Elasticity(pModel->Elasticity());
	pData->ElasticityUnit(pModel->ElasticityUnit());
	pData->PossionRatio(pModel->PossionRatio());
	pData->CalcWave(pModel->CalcWave());
	pData->SupportType(pModel->SupportType());
	pData->C1(pModel->C1());
	pData->FrictionModel(pModel->FrictionModel());
	pData->Friction(pModel->Friction());
	pData->FrictionUnit(pModel->FrictionUnit());
	pData->InDiaReduce(pModel->InDiaReduce());
	pData->InDiaReduce(pModel->InDiaReduce());
	pData->LocalK(pModel->LocalK());
	pData->PipeFactor(pModel->PipeFactor());
	pData->FitFactor(pModel->FitFactor());
	pData->InitFlow(pModel->InitFlow());
	pData->SectionNum(pModel->SectionNum());
	pData->ParaNum(pModel->ParaNum());
	pData->PartFull(pModel->PartFull());
	return ErrorStatus::eFileOK;
}