// AFTJunFace.cpp: implementation of the AFTJunFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTJunFace.h"
#include "AFTTwoDTableFace.h"
#include "RawDataTable.h"
#include "ScenarioDataMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTJunFace::AFTJunFace()
{

}

AFTJunFace::~AFTJunFace()
{

}

ErrorStatus::FileError AFTJunFace::Read(JunctionData *pData,Junperisist *pModel)
{
	pModel->ID(pData->ID());
	pModel->Key(pData->Key());
	pModel->Name(pData->Name());
	pModel->CenterPtX(pData->CenterPtX());
	pModel->CenterPtY(pData->CenterPtY());
	pModel->m_list.SetData(pData->PipeID());
	pModel->InEle(pData->InEle());
	pModel->InEleUnit(pData->EleUnit());
	pModel->OutEle(pData->OutEle());
	pModel->OutEleUnit(pData->EleUnit());
	pModel->DesignFactor(pData->DesignFactor());
	pModel->RawKey(pData->RawKey());
	pModel->InitGuess(pData->InitGuess());
	pModel->SpecialMark(pData->SpecialMark());

	CString strKey = pModel->RawKey();
	if(-1!=strKey.Find(_T("RDS")))
	{
		RawDataTable<2> *pRawData = NULL;
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
ErrorStatus::FileError AFTJunFace::Save(JunctionData *pData,Junperisist *pModel)
{
	pData->ID(pModel->ID());
	pData->Key(pModel->Key());
	pData->Name(pModel->Name());
	pData->CenterPtX(pModel->CenterPtX());
	pData->CenterPtY(pModel->CenterPtY());
	pData->PipeID(pModel->m_list.GetData());
	pData->InEle(pModel->InEle());
	pData->OutEle(pModel->OutEle());
	pData->EleUnit(pModel->InEleUnit());
	pData->DesignFactor(pModel->DesignFactor());
	pData->RawKey(pModel->RawKey());
	pData->InitGuess(pModel->InitGuess());
	pData->SpecialMark(pModel->SpecialMark());

	CString strKey = pModel->RawKey();
	RawDataTable<2> *pRawData = NULL;
	if(-1!=strKey.Find(_T("RDS"))&&!ScenarioDataMgr::GetRawData().FindRawData(pRawData,strKey))
	{
		StrArray<2> array;
		array.Data(strKey);
		array.Data(1,1);
		ScenarioDataMgr::GetRawData().CreatRawData(pRawData);
		pRawData->Unkown(array);
		AFTTableFace face;
		face.Save(*pRawData,pModel->m_RawData);
	}
	return ErrorStatus::eFileOK;
}
