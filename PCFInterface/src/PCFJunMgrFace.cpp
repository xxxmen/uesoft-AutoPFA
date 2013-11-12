// PCFJunMgrFace.cpp: implementation of the PCFJunMgrFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFJunMgrFace.h"
#include "PCFJunsMgr.h"
#include "JunManager.h"
#include "PCFJunFace.h"



//#include "pagebendmodel.h"
//#include "Bend.h"
//#include "PageCalBendK1.h"
//#include "AutoPFADoc.h"
//#include "NetModel.h"
//#include "QuantityManager.h"
//#include "ScenariManage.h"
//#include "Scenario.h"
//#include "MainFrm.h"
//#include "ChildFrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFJunMgrFace::PCFJunMgrFace()
{
	m_factory = PCFJunFaceFactory::Instance();
}

PCFJunMgrFace::~PCFJunMgrFace()
{

}

ErrorStatus::FileError PCFJunMgrFace::Read(PCFJunsMgr &Data, JunManager &model)
{
    ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	PCFJunFace *pJunFace = NULL;
	PCFJun *pJunData = NULL;
	Junperisist *pJunPerisist = NULL;
	IteratorPtr<PCFJun> JunitPtr(Data.CreateIt());


	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJunData = &JunitPtr->CurrentItem();
		pJunFace = CreatJunFace(pJunData->GetID());
		pJunPerisist = model.CreatJunperisist(pJunData->GetID());
		if(pJunPerisist != NULL&&pJunFace != NULL)
		{
			errorMark = pJunFace->Read(pJunData,pJunPerisist);
		}

		
		/*bool bCheck = TRUE;
		AcGePoint3d* pPoint3d = NULL;

		//保存中心三维点到temp的第一个位置，其他位置放分支点坐标
		UnPoint temp;
		temp.push_back(pJunData->Get3dPtCenter());
		

		IteratorPtr<AcGePoint3d> JunItPtr(pJunData->GetPtList().CreatIterator());
		for(JunItPtr->Fist();!JunItPtr->IsDone();JunItPtr->Next())
		{
			bCheck = TRUE;
			pPoint3d = &JunItPtr->CurrentItem();

			Un::iterator itUnJun = UnJun.begin();
			for(;itUnJun != UnJun.end();itUnJun++)
			{
				if(itUnJun == NULL)
				{
					break;
				}
				UnPoint JunPointTemp = *itUnJun;
				UnPoint::iterator itPoint = JunPointTemp.begin();
				for(itPoint++;itPoint != JunPointTemp.end();itPoint++)
				{
                    //如果此点是两个节点直接连接，则增加一个虚拟管道
					if(*itPoint == *pPoint3d)
					{
	
		
						/*AcGePoint3d Acpoint = *itPoint;
						CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
						CChildFrame* pChildFrame = (CChildFrame*)pMainFrame->GetActiveFrame();
						CAutoPFADoc* pPfaDoc = (CAutoPFADoc*)pChildFrame->GetActiveDocument();
						Component *pComponent = NULL;
						Pipe Pipe;
						NetModel *pNetModeltemp = pPfaDoc->m_scenarioManager.GetCurScenario()->GetNetModel();
						//pComponentManager = &pNetModeltemp->m_compManager;
						Pipe.ms_StartPt.SetValue1(Acpoint.x);
						Pipe.ms_StartPt.SetValue2(Acpoint.y);
						Pipe.ms_StartPt.SetValue3(Acpoint.z);
						Pipe.ms_Len.SetValue(20);
						Pipe.ms_Len.SetUnit("mm");
					
						Pipe.ms_InDia.SetValue(350);
						Pipe.ms_InDia.SetUnit("mm");
						Pipe.SaveData();
						pNetModeltemp->m_compManager.Add(&Pipe);
						*/
						/*
						UnJun.erase(itUnJun);
						bCheck = FALSE;
						break;
					}
					if(bCheck)
					{
						temp.push_back(*pPoint3d);//放置分支点坐标
					}
				}
			}		
		}	
    UnJun.push_back(temp);*/	
	}


	return errorMark;
}

PCFJunFace* PCFJunMgrFace::CreatJunFace(int nID)
{
	PCFJunFace* pJunFace = m_factory->CreatObject(nID);
	return pJunFace;
}
