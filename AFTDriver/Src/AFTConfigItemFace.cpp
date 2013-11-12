// AFTConfigItemFace.cpp: implementation of the AFTConfigItemFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTConfigItemFace.h"
#include "AFTTransDataFace.h"
#include "AFTTwoDTableFace.h"
#include "ScenarioDataMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTConfigItemFace::AFTConfigItemFace()
{

}

AFTConfigItemFace::~AFTConfigItemFace()
{

}

ErrorStatus::FileError AFTConfigItemFace::Read(PumpConfigData *pData,ConfigItemPerisist *pModel)
{
	// TODO: Add extra Read here
	pModel->Name(pData->Name());
	pModel->RPM(pData->RPM());
	pModel->ImpellerDia(pData->ImpellerDia());
	pModel->MaxFlow(pData->MaxFlow());
	pModel->Curve1(pData->Curve1());
	pModel->ID(pData->ID());
	pModel->Curve2(pData->Curve2());
	pModel->Affiniity(pData->Affiniity());
	pModel->Curve3(pData->Curve3());
	pModel->CurveEndFlow(pData->CurveEndFlow());
	pModel->BEP(pData->BEP());

	CString strKey = pModel->ID();
	if(-1!=strKey.Find(_T("RDS")))
	{
		RawDataTable<4> *pRawData = NULL;
		if(ScenarioDataMgr::GetRawData().FindRawData(pRawData,strKey))
		{
			AFTTableFace face;
			face.Read(*pRawData,pModel->m_RawData);
		}
		else
		{
			return ErrorStatus::eReadFileError;
		}
	}
	return ErrorStatus::eFileOK;
}
ErrorStatus::FileError AFTConfigItemFace::Save(PumpConfigData *pData,ConfigItemPerisist *pModel)
{
	// TODO: Add extra Save here
	pData->Name(pModel->Name());
	pData->RPM(pModel->RPM());
	pData->ImpellerDia(pModel->ImpellerDia());
	pData->MaxFlow(pModel->MaxFlow());
	pData->Curve1(pModel->Curve1());
	pData->ID(pModel->ID());
	pData->Curve2(pModel->Curve2());
	pData->Affiniity(pModel->Affiniity());
	pData->Curve3(pModel->Curve3());
	pData->CurveEndFlow(pModel->CurveEndFlow());
	pData->BEP(pModel->BEP());

	CString strKey = pModel->ID();
	RawDataTable<4> *pRawData = NULL;
	if(-1!=strKey.Find(_T("RDS"))&&!ScenarioDataMgr::GetRawData().FindRawData(pRawData,strKey))
	{
		StrArray<2> array;
		array.Data(strKey);
		array.Data(3,1);
		ScenarioDataMgr::GetRawData().CreatRawData(pRawData);
		pRawData->Unkown(array);
		AFTTableFace face;
		face.Save(*pRawData,pModel->m_RawData);
	}
	return ErrorStatus::eFileOK;
}