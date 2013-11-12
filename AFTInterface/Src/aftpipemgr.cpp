// AFTPipeMgr.cpp: implementation of the AFTPipeMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTPipeMgr.h"
#include "AFTPipeFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTPipeMgr::AFTPipeMgr()
{

}

AFTPipeMgr::~AFTPipeMgr()
{

}
ErrorStatus::FileError AFTPipeMgr::Read(PipesMgr &Data,PipesManager& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	AFTPipeFace pipeFace;
	PipeData *pPipeData = NULL;
	PipePerisist *pPipePerisist = NULL;
	IteratorPtr<PipeData> PipeitPtr(Data.CreatIterator());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipeData = &PipeitPtr->CurrentItem();
		pPipePerisist = model.CreatPipePerisit();
	    if(pPipePerisist != NULL)
		{
			errorMark = pipeFace.Read(pPipeData,pPipePerisist);
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
ErrorStatus::FileError AFTPipeMgr::Save(PipesMgr &Data,PipesManager& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	AFTPipeFace pipeFace;
	PipeData *pPipeData = NULL;
	PipePerisist *pPipePerisist = NULL;
	Data.SetPipeNum(model.GetPipeNum());
	IteratorPtr<PipePerisist> PipeitPtr(model.CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipePerisist = &PipeitPtr->CurrentItem();
		pPipeData = Data.CreatPipe();
		if(pPipeData != NULL)
		{
			pPipeData->Init();
			errorMark = pipeFace.Save(pPipeData,pPipePerisist);
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
