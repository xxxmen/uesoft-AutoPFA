// MOCPipeMgr.cpp: implementation of the MOCPipeMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCPipeMgr.h"
#include "CalcPipeMgr.h"
#include "PipeStmOutMgr.h"
#include "PipeTranOutMgr.h"
#include "PipeTranOut.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCPipeMgr::MOCPipeMgr()
{

}

MOCPipeMgr::~MOCPipeMgr()
{
	DelMap<MOCPipe>(m_pipeMap);
}

MOCPipe* MOCPipeMgr::CreatPipe(int nKey)
{
	ASSERT(LookUp(nKey)==NULL);
	MOCPipe *pPipe = new MOCPipe;
	if(pPipe==NULL)
	{
		return NULL;
	}
	pPipe->Key(nKey);
	m_pipeMap.SetAt(nKey,pPipe);
	return pPipe;
}

Iterator<MOCPipe>* MOCPipeMgr::CreatIterator()
{
	return new MapIterator<MOCPipe>(&m_pipeMap);
}

MOCPipe* MOCPipeMgr::LookUp(int nKey)
{
	return LookMap<MOCPipe>(m_pipeMap,nKey);
}

BOOL MOCPipeMgr::Read(CalcPipeMgr &data)
{
	Empty();
	CalcPipe *pCalcPipe = NULL;
	MOCPipe *pMOCPipe = NULL;
	IteratorPtr<CalcPipe> ItPtr(data.CreateIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pCalcPipe = &ItPtr->CurrentItem();
		pMOCPipe = CreatPipe(pCalcPipe->Key());
		if(pMOCPipe != NULL)
		{
			pMOCPipe->Read(*pCalcPipe);
		}
		else
		{
			ASSERT(FALSE);
			return FALSE;
		}
	}
	return TRUE;
}

void MOCPipeMgr::Empty()
{
	DelMap<MOCPipe>(m_pipeMap);
}

EndInfo* MOCPipeMgr::LookPipeEnd(int nKey)
{
	MOCPipe *pMOCPipe = LookUp(abs(nKey));
	if(pMOCPipe == NULL)
	{
		ASSERT(FALSE);
		return NULL;
	}
	if(nKey > 0)
	{
		return pMOCPipe->GetOutEnd();
	}
	else
	{
		return pMOCPipe->GetInEnd();
	}
	
}

void MOCPipeMgr::InitPipeEnd()
{
	MOCPipe *pMOCPipe = NULL;
	IteratorPtr<MOCPipe> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCPipe = &ItPtr->CurrentItem();
		ASSERT(pMOCPipe != NULL);
		pMOCPipe->InitEndInfo();
	}
}

void MOCPipeMgr::CalcStm()
{
	MOCPipe *pMOCPipe = NULL;
	IteratorPtr<MOCPipe> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCPipe = &ItPtr->CurrentItem();
		ASSERT(pMOCPipe != NULL);
		pMOCPipe->CalcStm();
	}
}


void MOCPipeMgr::Result(PipeStmOutMgr &out)
{
	MOCPipe *pMOCPipe = NULL;
	PipeStmOut *pOutPipe = NULL;
	IteratorPtr<MOCPipe> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCPipe = &ItPtr->CurrentItem();
		ASSERT(pMOCPipe != NULL);
		pOutPipe = dynamic_cast<PipeStmOut*>(out.CreatorComponent(pMOCPipe->Key()));
		ASSERT(pOutPipe != NULL);
		pMOCPipe->Result(*pOutPipe);
	}
}

void MOCPipeMgr::CheckTol(MOCSteady &Steady)
{
	MOCPipe *pMOCPipe = NULL;
	IteratorPtr<MOCPipe> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCPipe = &ItPtr->CurrentItem();
		ASSERT(pMOCPipe != NULL);
		pMOCPipe->CheckTol(Steady);
	}
}

BOOL MOCPipeMgr::InitStation()
{
	MOCPipe *pMOCPipe = NULL;
	IteratorPtr<MOCPipe> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCPipe = &ItPtr->CurrentItem();
		ASSERT(pMOCPipe != NULL);
		if(!pMOCPipe->InitStation())
			return FALSE;
	}
	return TRUE;
}

void MOCPipeMgr::CalcImpulse(MOCTrans &trans)
{
	MOCPipe *pMOCPipe = NULL;
	IteratorPtr<MOCPipe> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCPipe = &ItPtr->CurrentItem();
		ASSERT(pMOCPipe != NULL);
		pMOCPipe->CalcImpulse(trans);
	}
}

void MOCPipeMgr::Result(PipeTranOutMgr &out,int nStep)
{
	MOCPipe *pMOCPipe = NULL;
	PipeTranOut *pOutPipe = NULL;
	IteratorPtr<MOCPipe> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCPipe = &ItPtr->CurrentItem();
		ASSERT(pMOCPipe != NULL);
		pOutPipe = dynamic_cast<PipeTranOut*>(out.LookUp(pMOCPipe->Key()));
		if(pOutPipe == NULL)
			pOutPipe = dynamic_cast<PipeTranOut*>(out.CreatorComponent(pMOCPipe->Key()));
		ASSERT(pOutPipe != NULL);
		pMOCPipe->Result(*pOutPipe,nStep);
	}
}