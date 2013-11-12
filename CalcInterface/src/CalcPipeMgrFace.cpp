// CalcPipeMgrFace.cpp: implementation of the CalcPipeMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CalcPipeMgrFace.h"
#include "CalcPipeMgr.h"
#include "pipesmanager.h"
#include "CalcPipeFace.h"
#include "pipeperisist.h"
#include "CalcPipe.h"
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CalcPipeMgrFace::CalcPipeMgrFace()
{

}

CalcPipeMgrFace::~CalcPipeMgrFace()
{

}

ErrorStatus::FileError CalcPipeMgrFace::Save(CalcPipeMgr &Data,PipesManager& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	CalcPipeFace pipeFace;
	CalcPipe *pCalcPipe = NULL;
	PipePerisist *pPipePerisist = NULL;
	IteratorPtr<PipePerisist> PipeitPtr(model.CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipePerisist = &PipeitPtr->CurrentItem();
		pCalcPipe = Data.CreatPipe();
		if(pCalcPipe != NULL)
		{
			errorMark = pipeFace.Save(pCalcPipe,pPipePerisist);
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