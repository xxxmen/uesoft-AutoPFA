// PCFPipeMgrFace.cpp: implementation of the PCFPipeMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPipeMgrFace.h"
#include "PCFPipeFace.h"
#include "PCFPipe.h"
#include "pipeperisist.h"
#include "PCFPipesMgr.h"
#include "pipesmanager.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPipeMgrFace::PCFPipeMgrFace()
{

}

PCFPipeMgrFace::~PCFPipeMgrFace()
{

}

ErrorStatus::FileError PCFPipeMgrFace::Read(PCFPipesMgr &Data, PipesManager &model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	PCFPipeFace pipeFace;
	PCFPipe *pPipeData = NULL;
	PipePerisist *pPipePerisist = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(Data.CreateIt());
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
