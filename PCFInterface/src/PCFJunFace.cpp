// PCFJunFace.cpp: implementation of the PCFJunFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFJunFace.h"
#include "PCFJunMgrFace.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFJunFace::PCFJunFace()
{

}

PCFJunFace::~PCFJunFace()
{

}

ErrorStatus::FileError PCFJunFace::Read(PCFJun *pData, Junperisist *pModel)
{
	pModel->ID(pData->GetID());
	pModel->Key(pData->GetKey());
	pModel->Name(pData->GetName());
	pModel->CenterPtX(pData->CenterPtX());
	pModel->CenterPtY(pData->CenterPtY());
 	pModel->m_list.SetData(pData->PipeID());
 	pModel->InEle(ftoStr(pData->Ele()/1000));
 	pModel->InEleUnit(_T("meters"));
 	pModel->OutEle(ftoStr(pData->Ele()/1000));
 	pModel->OutEleUnit(_T("meters"));
 	pModel->DesignFactor(_T("1"));
 	pModel->RawKey(_T(""));
// 	pModel->InitGuess(pData->InitGuess());
// 	pModel->SpecialMark(pData->SpecialMark());

/*
	bool bCheck = TRUE;
	AcGePoint3d* pPoint3d = NULL;
	IteratorPtr<AcGePoint3d> JunItPtr(pData->GetPtList().CreatIterator());
	for(JunItPtr->Fist();!JunItPtr->IsDone();JunItPtr->Next())
	{
		bCheck = TRUE;
		pPoint3d = &JunItPtr->CurrentItem();
		iterator itpoint = PCFJunMgrFace::UnJun.begin();
		for(;itpoint != PCFJunMgrFace::UnJun.end();itpoint++)
		{
			
			//如果此点是两个节点直接连接，则增加一个虚拟管道
			if(itpoint == *pPoint3d)
			{
				
				PCFJunMgrFace::UnJun.erase(itpoint);
				bCheck = FALSE;
				break;
			}
			
		}
		if(bCheck)
		{
            PCFJunMgrFace::UnJun.push_back(*pPoint3d);
		}
		
	}
*/



	return ErrorStatus::eFileOK;
}
