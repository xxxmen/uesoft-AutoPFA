// PipesManager.cpp: implementation of the PipesManager class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PipesManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipesManager::PipesManager()
{
	
}

PipesManager::~PipesManager()
{
	DelList();
}

Iterator<PipePerisist>* PipesManager::CreateIt()
{
	return new ListIterator<PipePerisist>(&m_pipeList);
}

PipePerisist* PipesManager::CreatPipePerisit()
{
	PipePerisist *pPipe = new PipePerisist;
	m_pipeList.AddTail(pPipe);
	return pPipe;
}

int PipesManager::GetPipeNum()
{
	return m_pipeList.GetCount();
}

void PipesManager::DelList()
{
	PipePerisist *pPipe = NULL;
	POSITION pos = m_pipeList.GetHeadPosition();
	while(pos)
	{
		pPipe = m_pipeList.GetNext(pos);
		delete pPipe;
	}
	m_pipeList.RemoveAll();
}
