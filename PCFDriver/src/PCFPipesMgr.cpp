// PCFPipesMgr.cpp: implementation of the PCFPipesMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFPipe.h"
#include "PCFPipesMgr.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFPipesMgr::PCFPipesMgr()
{

}

PCFPipesMgr::~PCFPipesMgr()
{
	DelMap<PCFPipe>(m_pipeMap);
}

PCFPipe* PCFPipesMgr::Creator()
{
	PCFPipe* pPipe = new PCFPipe;
	int nKey = CreatKey<PCFPipe>(m_pipeMap);
	pPipe->SetKey(nKey);
	m_pipeMap.SetAt(nKey,pPipe);
	return pPipe;
}

Iterator<PCFPipe>* PCFPipesMgr::CreateIt()
{
	return new MapIterator<PCFPipe>(&m_pipeMap);
}

void PCFPipesMgr::GetMinXY(double &dMinX, double &dMinY)
{
	dMinX = 0;
	dMinY = 0;
	PCFPipe *pPipe = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		dMinX = min(pPipe->Start2dPt().x,dMinX);
		dMinX = min(pPipe->End2dPt().x,dMinX);
		dMinY = min(pPipe->Start2dPt().y,dMinY);
		dMinY = min(pPipe->End2dPt().y,dMinY);
	}
}

void PCFPipesMgr::Tran3dTo2d()
{
	PCFPipe *pPipe = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		pPipe->Tran3dTo2d();
	}
}

void PCFPipesMgr::OffSet(AcGePoint3d &OriginPt)
{
	PCFPipe *pPipe = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		pPipe->OffSet(OriginPt);
	}
}

BOOL PCFPipesMgr::ChangePort(const AcGePoint3d &OldPt,const AcGePoint3d &NewPt)
{
	PCFPipe *pPipe = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		if(IsEqual(pPipe->StartPt(),OldPt))
		{
			pPipe->StartPt(NewPt);
			return TRUE;
		}
		if(IsEqual(pPipe->EndPt(),OldPt))
		{
			pPipe->EndPt(NewPt);
			return TRUE;
		}
	}
	return FALSE;
}



void PCFPipesMgr::InitNetLink(AcGePoint3d &Pt,EndList &end,int nID)
{
	PCFPipe *pPipe = NULL;
	StrArray<1> item;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		if(IsEqual(pPipe->StartPt(),Pt))
		{
			pPipe->InJun(nID);
			item.Data(-pPipe->GetKey(),0);
			end.AddItem(item);
		}
		if(IsEqual(pPipe->EndPt(),Pt))
		{
			pPipe->OutJun(nID);
			item.Data(pPipe->GetKey(),0);
			end.AddItem(item);
		}
	}
}

PCFPipe* PCFPipesMgr::LookUp(int nKey)
{
	return LookMap<PCFPipe>(m_pipeMap,nKey);
}

void PCFPipesMgr::Del(int nKey)
{
	PCFPipe *pPipe = LookUp(nKey);
	if(pPipe != NULL)
	{
		m_pipeMap.RemoveKey(nKey);
		delete pPipe;
	}
}


void PCFPipesMgr::CombinationPipe(AcGePoint3d &Pt1,AcGePoint3d &Pt2)
{
	PCFPipe *pPipe = NULL;
	PCFPipe *pPipe1 = NULL;
	PCFPipe *pPipe2 = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		if(IsEqual(pPipe->EndPt(),Pt1))
		{
			pPipe1 = pPipe;
		}
		if(IsEqual(pPipe->StartPt(),Pt2))
		{
			pPipe2 = pPipe;
		}
	}
	if(pPipe1!=NULL&&pPipe2!=NULL)
	{
		pPipe1->EndPt(pPipe2->EndPt());
		Del(pPipe2->GetKey());
	}
}

void PCFPipesMgr::GetMaxXY(double &dMaxX, double &dMaxY)
{
	dMaxX = 0;
	dMaxY = 0;
	PCFPipe *pPipe = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		dMaxX = max(pPipe->Start2dPt().x,dMaxX);
		dMaxX = max(pPipe->End2dPt().x,dMaxX);
		dMaxY = max(pPipe->Start2dPt().y,dMaxY);
		dMaxY = max(pPipe->End2dPt().y,dMaxY);
	}
}

void PCFPipesMgr::ChangeOrigin(AcGePoint3d& OriginPt)
{
	PCFPipe *pPipe = NULL;
	IteratorPtr<PCFPipe> PipeitPtr(CreateIt());
	for(PipeitPtr->Fist();!PipeitPtr->IsDone();PipeitPtr->Next())
	{
		pPipe = &PipeitPtr->CurrentItem();
		ASSERT(pPipe != NULL);
		pPipe->ChangeOrigin(OriginPt);
	}
}
