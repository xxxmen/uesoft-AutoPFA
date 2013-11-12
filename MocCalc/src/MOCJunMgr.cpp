// MOCJunMgr.cpp: implementation of the MOCJunMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCJunMgr.h"
#include "CalcJunMgr.h"
#include "MOCPipeMgr.h"
#include "CalcJun.h"
#include "JunStmOutMgr.h"
#include "JunTranOut.h"
#include "JunTranOutMgr.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCJunMgr::MOCJunMgr()
{
	m_pFactory = MOCJunFactory::Instance();
}

MOCJunMgr::~MOCJunMgr()
{
	Empty();
}

BOOL MOCJunMgr::Read(CalcJunMgr &data)
{
	Empty();
	CalcJun *pCalcJun = NULL;
	MOCJun *pMOCJun = NULL;
	IteratorPtr<CalcJun> ItPtr(data.CreateIt());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pCalcJun = &ItPtr->CurrentItem();
		pMOCJun = CreatJun(pCalcJun->ID(),pCalcJun->Key());
		if(pMOCJun != NULL)
		{
			pMOCJun->Read(pCalcJun);
		}
		else
		{
			ASSERT(FALSE);
			return FALSE;
		}
	}
	return TRUE;
}

void MOCJunMgr::Empty()
{
	DelMap<MOCJun>(m_junMap);
}

MOCJun* MOCJunMgr::CreatJun(int nType,int nKey)
{
	ASSERT(LookUp(nKey)==NULL);
	MOCJun *pJun = m_pFactory->CreatObject(nType);
	if(pJun==NULL)
	{
		return NULL;
	}
	pJun->Key(nKey);
	m_junMap.SetAt(nKey,pJun);
	return pJun;
}

Iterator<MOCJun>* MOCJunMgr::CreatIterator()
{
	return new MapIterator<MOCJun>(&m_junMap);
}

MOCJun* MOCJunMgr::LookUp(int nKey)
{
	return LookMap<MOCJun>(m_junMap,nKey);
}

BOOL MOCJunMgr::InitLinkInfo(MOCPipeMgr &mgr)
{
	MOCJun *pMOCJun = NULL;
	IteratorPtr<MOCJun> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCJun = &ItPtr->CurrentItem();
		ASSERT(pMOCJun != NULL);
		if(!pMOCJun->InitLinkEnd(mgr))
			return FALSE;
		if(!pMOCJun->InitEndInfo())
			return FALSE;
	}
	return TRUE;
}

void MOCJunMgr::CalcStm()
{
	MOCJun *pMOCJun = NULL;
	IteratorPtr<MOCJun> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCJun = &ItPtr->CurrentItem();
		ASSERT(pMOCJun != NULL);
		pMOCJun->CalcStm32();
	}
}

void MOCJunMgr::Result(JunStmOutMgr &out)
{
	MOCJun *pMOCJun = NULL;
	JunStmOut *pOutJun = NULL;
	IteratorPtr<MOCJun> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCJun = &ItPtr->CurrentItem();
		ASSERT(pMOCJun != NULL);
		pOutJun = dynamic_cast<JunStmOut*>(out.CreatorComponent(pMOCJun->Key()));
		ASSERT(pOutJun != NULL);
		pMOCJun->Result(*pOutJun);
	}
}

BOOL MOCJunMgr::InitTranData(MOCComponentMgr& mgr)
{
	MOCJun *pMOCJun = NULL;
	IteratorPtr<MOCJun> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCJun = &ItPtr->CurrentItem();
		ASSERT(pMOCJun != NULL);
		if(!pMOCJun->InitTranData(mgr))
			return FALSE;
	}
	return TRUE;
}

void MOCJunMgr::CalcImpulse(MOCTrans &trans,double dTime)
{
	MOCJun *pMOCJun = NULL;
	IteratorPtr<MOCJun> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCJun = &ItPtr->CurrentItem();
		ASSERT(pMOCJun != NULL);
		pMOCJun->CalcImpulse32(trans,dTime);
	}
}

void MOCJunMgr::Result(JunTranOutMgr &out,int nStep)
{
	MOCJun *pMOCJun = NULL;
	JunTranOut *pOutJun = NULL;
	IteratorPtr<MOCJun> ItPtr(CreatIterator());
	for(ItPtr->Fist();!ItPtr->IsDone();ItPtr->Next())
	{
		pMOCJun = &ItPtr->CurrentItem();
		ASSERT(pMOCJun != NULL);
		pOutJun = dynamic_cast<JunTranOut*>(out.LookUp(pMOCJun->Key()));
		if(pOutJun==NULL)
		{
			pOutJun = dynamic_cast<JunTranOut*>(out.CreatorComponent(pMOCJun->Key()));
			pOutJun->Name(pMOCJun->Name());
		}
		ASSERT(pOutJun != NULL);
		pMOCJun->Result(*pOutJun,nStep);
	}
}