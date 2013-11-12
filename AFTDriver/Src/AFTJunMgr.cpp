// AFTJunMgr.cpp: implementation of the AFTJunMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTJunMgr.h"
#include "Junperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTJunMgr::AFTJunMgr()
{
	m_factory = JunFaceFactory::Instance();
}

AFTJunMgr::~AFTJunMgr()
{

}

ErrorStatus::FileError AFTJunMgr::Read(JunctionsMgr &Data,JunManager& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	AFTJunFace *pJunFace = NULL;
	JunctionData *pJunData = NULL;
	Junperisist *pJunPerisist = NULL;
	IteratorPtr<JunctionData> JunitPtr(Data.CreatIterator());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJunData = &JunitPtr->CurrentItem();
		pJunFace = CreatJunFace(pJunData->ID());
		pJunPerisist = model.CreatJunperisist(pJunData->ID());
		if(pJunPerisist != NULL&&pJunFace != NULL)
		{
			errorMark = pJunFace->Read(pJunData,pJunPerisist);
		}
		else
		{
			errorMark = ErrorStatus::eReadFileError;
		}
		if(ErrorStatus::eFileOK != errorMark)
			break;
	}
	return errorMark;
}
ErrorStatus::FileError AFTJunMgr::Save(JunctionsMgr &Data,JunManager& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	AFTJunFace *pJunFace = NULL;
	JunctionData *pJunData = NULL;
	Junperisist *pJunPerisist = NULL;
	Data.SetJunNum(model.GetJunNum());
	IteratorPtr<Junperisist> JunitPtr(model.CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJunPerisist = &JunitPtr->CurrentItem();
		pJunFace = CreatJunFace(pJunPerisist->ID());
		pJunData = Data.CreatJun(pJunPerisist->ID());
		if(pJunData != NULL&&pJunFace != NULL)
		{
			pJunData->Init();
		    errorMark = pJunFace->Save(pJunData,pJunPerisist);
		}
		else
		{
			errorMark = ErrorStatus::eReadFileError;
		}
		if(ErrorStatus::eFileOK != errorMark)
			break;
	}
	return errorMark;
}

AFTJunFace* AFTJunMgr::CreatJunFace(int nID)
{
	AFTJunFace* pJunFace = m_factory->CreatObject(nID);
	return pJunFace;
}
