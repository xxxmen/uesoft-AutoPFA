// CalcJunMgrFace.cpp: implementation of the CalcJunMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcJunMgrFace.h"
#include "JunManager.h"
#include "CalcJunMgr.h"
#include "CalcJunFace.h"
#include "junperisist.h"
#include "CalcJun.h"
#include "CalcJunFaceFactory.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcJunMgrFace::CalcJunMgrFace()
{
	m_factory = CalcJunFaceFactory::Instance();
}

CalcJunMgrFace::~CalcJunMgrFace()
{

}

ErrorStatus::FileError CalcJunMgrFace::Save(CalcJunMgr &Data,JunManager& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	CalcJunFace *pJunFace = NULL;
	CalcJun *pCalcJun = NULL;
	Junperisist *pJunPerisist = NULL;
	IteratorPtr<Junperisist> JunitPtr(model.CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJunPerisist = &JunitPtr->CurrentItem();
		pJunFace = CreatJunFace(pJunPerisist->ID());
		pCalcJun = Data.CreatJun(pJunPerisist->ID());
		if(pCalcJun != NULL&&pJunFace != NULL)
		{
		    errorMark = pJunFace->Save(pCalcJun,pJunPerisist);
		}
		else
		{

			ASSERT(FALSE);
			errorMark = ErrorStatus::eReadFileError;
		}
		if(ErrorStatus::eFileOK != errorMark)
			break;
	}
	return errorMark;
}

CalcJunFace* CalcJunMgrFace::CreatJunFace(int nID)
{
	CalcJunFace* pJunFace = m_factory->CreatObject(nID);
	return pJunFace;
}