// CalcJunFace.cpp: implementation of the CalcJunFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcJunFace.h"
#include "CalcJun.h"
#include "junperisist.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcJunFace::CalcJunFace()
{

}

CalcJunFace::~CalcJunFace()
{

}

ErrorStatus::FileError CalcJunFace::Save(CalcJun *pData,Junperisist *pModel)
{
	int nType = 0;
	double dValue = 0;

	pData->Name(pModel->Name());
	pData->ID(pModel->ID());
	pData->Key(pModel->Key());
 	pData->PipeID(pModel->m_list.GetData());
	pData->InEle(TransStd(pModel->InEle(),pModel->InEleUnit()));
	if(pModel->OutEle().CollateNoCase(_T("0"))==0 && pModel->InEle().CollateNoCase(_T("0"))!=0)
	{
		pData->OutEle(TransStd(pModel->InEle(),pModel->InEleUnit()));
	}
	else
	{
		pData->OutEle(TransStd(pModel->OutEle(),pModel->InEleUnit()));
	}
	pData->DesignFactor(_tcstod(pModel->DesignFactor(),'\0'));
	
	GetTypeAndValue(pModel->InitGuess(),nType,dValue);
	pData->InitGuessType(nType);
	pData->InitGuess(dValue);
	pData->CurveData(pModel->m_RawData.DataToStd());

	StrArray<3> &ref = pModel->SpecialMark();
	pData->SpecialMark(ref.nData());
	return ErrorStatus::eFileOK;
}

void CalcJunFace::GetTypeAndValue(StrArray<3> &ref,int &ntype,double &dValue)
{
	ntype = ref.nData();
	dValue = TransStd(ref.Data(1),ref.Data(2));
}
