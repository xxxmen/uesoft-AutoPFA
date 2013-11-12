// CalcBreakerFace.cpp: implementation of the CalcBreakerFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcBreakerFace.h"
#include "CalcBrecker.h"
#include "breakerperisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcBreakerFace::CalcBreakerFace()
{

}

CalcBreakerFace::~CalcBreakerFace()
{

}

CalcJunFace* CalcBreakerFace::Creator()
{
	static CalcBreakerFace sFace;
	return &sFace;
}

ErrorStatus::FileError CalcBreakerFace::Save(CalcJun *pData,Junperisist *pModel)
{
	// TODO: Add extra Save here
	CalcBrecker *pBreckerData = dynamic_cast<CalcBrecker*>(pData);
	ASSERT(pBreckerData != NULL);
	BreakerPerisist *pBreakerModel = dynamic_cast<BreakerPerisist*>(pModel);
	ASSERT(pBreakerModel != NULL);
	int nType = 0;
	double dValue = 0;
	GetTypeAndValue(pBreakerModel->CrackPress(),nType,dValue);
	pBreckerData->CrackPressType(nType);
	pBreckerData->CrackPress(dValue);
	pBreckerData->OrificeInCdA(TransStd(pBreakerModel->OrificeInCdA()));
	pBreckerData->OrificeOutCdA(TransStd(pBreakerModel->OrificeOutCdA()));
	GetTypeAndValue(pBreakerModel->LiquidTemp(),nType,dValue);
	pBreckerData->LiquidTempType(nType);
	pBreckerData->LiquidTemp(dValue);
	pBreckerData->ConnectPipe(_ttoi(pBreakerModel->ConnectPipe()));
	pBreckerData->Type(_ttoi(pBreakerModel->ValveType()));
	pBreckerData->InterMediateCdA(TransStd(pBreakerModel->InterMediateCdA()));
	GetTypeAndValue(pBreakerModel->MediateActivation(),nType,dValue);
	pBreckerData->MediateActivationType(nType);
	pBreckerData->MediateActivation(dValue);
	StrArray<9> &ref = pBreakerModel->GasProperty();
	pBreckerData->GasWeight(ref.fData(1));
	pBreckerData->CpCv(ref.fData(2));
	pBreckerData->GasTemp(TransStd(ref.Data(3),ref.Data(4)));
	pBreckerData->GasPress(TransStd(ref.Data(5),ref.Data(6)));
	pBreckerData->GasMass(TransStd(ref.Data(7),ref.Data(8)));
	pBreckerData->ConnectPipe(_ttoi(pBreakerModel->ConnectPipe()));
	return CalcJunFace::Save(pData,pModel);
}
