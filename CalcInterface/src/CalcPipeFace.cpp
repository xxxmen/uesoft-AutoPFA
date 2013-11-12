// CalcPipeFace.cpp: implementation of the CalcPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPipeFace.h"
#include "CalcPipe.h"
#include "pipeperisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPipeFace::CalcPipeFace()
{

}

CalcPipeFace::~CalcPipeFace()
{

}

ErrorStatus::FileError CalcPipeFace::Save(CalcPipe *pData,PipePerisist *pModel)
{
	pData->Key(pModel->Key());
	pData->InJunID(_ttoi(pModel->InJunID()));
	pData->OutJunID(_ttoi(pModel->OutJunID()));
	pData->InDia(TransStd(pModel->InDia(),pModel->InDiaUnit()));
	pData->Len(TransStd(pModel->Len(),pModel->LenUnit()));
	pData->WaveSpeed(TransStd(pModel->WaveSpeed(),pModel->WaveSpeedUnit()));
	pData->B(_tcstod(pModel->B(),'\0'));
	pData->FrictionModel(_ttoi(pModel->FrictionModel()));
	pData->Friction(TransStd(pModel->Friction(),pModel->FrictionUnit()));
	pData->InDiaReduce(TransStd(pModel->InDiaReduce(),pModel->InDiaReduce()));
	pData->LocalK(_tcstod(pModel->LocalK(),'\0'));
	pData->PipeFactor(_tcstod(pModel->PipeFactor(),'\0'));
	pData->FitFactor(_tcstod(pModel->FitFactor(),'\0'));
	pData->SectionNum(_ttoi(pModel->SectionNum()));
	StrArray<3> &array = pModel->InitFlow();
	pData->InitFlowType(array.nData());
	pData->InitFlow(TransStd(array.Data(1),array.Data(2)));
	return ErrorStatus::eFileOK;
}