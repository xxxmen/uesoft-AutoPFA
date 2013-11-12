// PCFJunsMgr.cpp: implementation of the PCFJunsMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFJunsMgr.h"
#include "PCFPipesMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFJunsMgr::PCFJunsMgr()
{
	m_pFactory = PCFJunFactory::Instance();
}

PCFJunsMgr::~PCFJunsMgr()
{
	DelMap<PCFJun>(m_junMap);
}

PCFJun* PCFJunsMgr::Creator(CString strKey)
{
	PCFJun* pJun = m_pFactory->CreatObject(strKey);
	if(pJun != NULL)
	{
		int nKey = CreatKey<PCFJun>(m_junMap);
		pJun->SetKey(nKey);
		m_junMap.SetAt(nKey,pJun);
	}
	return pJun;
}

Iterator<PCFJun>* PCFJunsMgr::CreateIt()
{
	return new MapIterator<PCFJun>(&m_junMap);
}

//1、根据节点的端点坐标查找与端点连接的管道将管道端点坐标改成节点中心坐标
void PCFJunsMgr::TripLen(PCFPipesMgr &PipeMgr)
{
	PCFJun *pJun = NULL;
	IteratorPtr<PCFJun> JunitPtr(CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJun = &JunitPtr->CurrentItem();
		ASSERT(pJun != NULL);
		if(pJun->IsPFAJun())
			pJun->TripLen(PipeMgr);
	}
}

void PCFJunsMgr::Tran3dTo2d()
{
	PCFJun *pJun = NULL;
	IteratorPtr<PCFJun> JunitPtr(CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJun = &JunitPtr->CurrentItem();
		ASSERT(pJun != NULL);
		pJun->Tran3dTo2d();
	}
}

// void PCFJunsMgr::CombinationPipes(PCFPipesMgr &PipeMgr)
// {
// 	PCFJun *pJun = NULL;
// 	IteratorPtr<PCFJun> JunitPtr(CreateIt());
// 	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
// 	{
// 		pJun = &JunitPtr->CurrentItem();
// 		ASSERT(pJun != NULL);
// 		{
// 			AcGePoint3d* pPt1 = pJun->GetPtList().GetHead();
// 			AcGePoint3d* pPt2 = pJun->GetPtList().GetTail();
// 			if(pPt1 != NULL&&pPt2!=NULL)
// 			{
// 				if(!PipeMgr.ChangePort(*pPt1,*pPt2))
// 					PipeMgr.ChangePort(*pPt2,*pPt1);
// 			}
// 		}
// 	}
// }

void PCFJunsMgr::OffSet(AcGePoint3d &OriginPt)
{
	PCFJun *pJun = NULL;
	IteratorPtr<PCFJun> JunitPtr(CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJun = &JunitPtr->CurrentItem();
		ASSERT(pJun != NULL);
		pJun->OffSet(OriginPt);
	}
}

void PCFJunsMgr::InitNetLink(PCFPipesMgr &PipeMgr)
{
	PCFJun *pJun = NULL;
	IteratorPtr<PCFJun> JunitPtr(CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJun = &JunitPtr->CurrentItem();
		ASSERT(pJun != NULL);
		if(pJun->IsPFAJun())
			pJun->InitNetLink(PipeMgr);
	}
}

PCFJun* PCFJunsMgr::LookUp(int nKey)
{
	return LookMap<PCFJun>(m_junMap,nKey);
}

void PCFJunsMgr::CombinationFit(PCFPipesMgr &PipeMgr)
{
	CombinationFit(PipeMgr,100);//PCFFlange
	CombinationFit(PipeMgr,101);//PCFGasket	
}

void PCFJunsMgr::CombinationFit(PCFPipesMgr &PipeMgr, int nType)
{
	PCFJun *pJun = NULL;
	IteratorPtr<PCFJun> JunitPtr(CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJun = &JunitPtr->CurrentItem();
		ASSERT(pJun != NULL);
		if(pJun->GetID()==nType)
		{
			AcGePoint3d* pPt1 = pJun->GetPtList().GetHead();
			AcGePoint3d* pPt2 = pJun->GetPtList().GetTail();
			if(pPt1 != NULL&&pPt2!=NULL)
			{
				if(!PipeMgr.ChangePort(*pPt1,*pPt2))
					PipeMgr.ChangePort(*pPt2,*pPt1);
			}
		}
	}
}

void PCFJunsMgr::CombinationPipe(PCFPipesMgr &PipeMgr)
{
	CombinationPipe(PipeMgr,102);//PCFSupport
	CombinationPipe(PipeMgr,103);//PCFTrap
	CombinationPipe(PipeMgr,104);//PCFWeld
}
void PCFJunsMgr::CombinationPipe(PCFPipesMgr &PipeMgr, int nType)
{
	PCFJun *pJun = NULL;
	IteratorPtr<PCFJun> JunitPtr(CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJun = &JunitPtr->CurrentItem();
		ASSERT(pJun != NULL);
		if(pJun->GetID()==nType)
		{
			AcGePoint3d* pPt1 = pJun->GetPtList().GetHead();
			AcGePoint3d* pPt2 = pJun->GetPtList().GetTail();
			if(pPt1 != NULL&&pPt2!=NULL)
			{
				PipeMgr.CombinationPipe(*pPt1,*pPt2);
			}
		}
	}
}

void PCFJunsMgr::ChangeOrigin(AcGePoint3d& OriginPt)
{
	PCFJun *pJun = NULL;
	IteratorPtr<PCFJun> JunitPtr(CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJun = &JunitPtr->CurrentItem();
		ASSERT(pJun != NULL);
		pJun->ChangeOrigin(OriginPt);
	}
}
