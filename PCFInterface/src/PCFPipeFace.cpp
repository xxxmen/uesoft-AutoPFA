// PCFPipeFace.cpp: implementation of the PCFPipeFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPipeFace.h"
#include "PCFPipe.h"
#include "pipeperisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPipeFace::PCFPipeFace()
{

}

PCFPipeFace::~PCFPipeFace()
{

}

ErrorStatus::FileError PCFPipeFace::Read(PCFPipe *pData, PipePerisist *pModel)
{
	pModel->Key(pData->GetKey());
	pModel->Name(_T("¹ÜµÀ"));
	AcGePoint3d &pts = pData->Start2dPt();
	pModel->StartPtX(GetX(pts));
	pModel->StartPtY(GetY(pts));
	AcGePoint3d &pte = pData->End2dPt();
	pModel->EndPtX(GetX(pte));
	pModel->EndPtY(GetY(pte));
 	pModel->InJunID(itoStr(pData->InJun()));
 	pModel->OutJunID(itoStr(pData->OutJun()));
	pModel->Size(ftoStr(pData->Bore()));

	if( fabs( pData->InDia() - 0.000001 ) < 0.000001 )
	{
		pModel->InDia(pModel->Size());
		pModel->InDiaUnit(_T("mm"));
	}
	else
	{
 	    pModel->InDia(ftoStr(pData->InDia()));
 	    pModel->InDiaUnit(_T("mm"));
	}

 	pModel->Len(ftoStr(pData->GetLen()/1000));
 	pModel->LenUnit(_T("meters"));
 	pModel->WaveSpeed(_T("2600"));
 	pModel->WaveSpeedUnit(_T("meters/sec"));
// 	pModel->B(pData->B());
// 	pModel->Material(pData->Material());
 	
// 	pModel->PipeType(pData->PipeType());
 	pModel->Thick(ftoStr(pData->Thick()));
 	pModel->ThickUnit(_T("mm"));
 	pModel->Elasticity(ftoStr(pData->Elasticity()));
 	pModel->ElasticityUnit(_T("Pascals"));
 	pModel->PossionRatio(ftoStr(pData->PossionRatio()));
// 	pModel->CalcWave(pData->CalcWave());
// 	pModel->SupportType(pData->SupportType());
// 	pModel->C1(pData->C1());
 	pModel->FrictionModel(_T("0"));
 	pModel->Friction(ftoStr(pData->AbsRoughness()));
 	pModel->FrictionUnit(_T("meters"));
// 	pModel->InDiaReduce(pData->InDiaReduce());
// 	pModel->LocalK(pData->LocalK());
	pModel->PipeFactor(_T("1"));
 	pModel->FitFactor(_T("1"));
// 	pModel->InitFlow(pData->InitFlow());
// 	pModel->SectionNum(pData->SectionNum());
// 	pModel->ParaNum(pData->ParaNum());
// 	pModel->PartFull(pData->PartFull());
	return ErrorStatus::eFileOK;
}
