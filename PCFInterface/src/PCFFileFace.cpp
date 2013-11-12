// PCFFileFace.cpp: implementation of the PCFFileFace class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PCFFileFace.h"
#include "persistenmodel.h"
#include "PCFDriverModel.h"
//#include "AutoPFADoc.h"
#include "PCFPipeFace.h"
#include "PCFPipe.h"
#include "PCFPipesMgr.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PCFFileFace::PCFFileFace()
{

}

PCFFileFace::~PCFFileFace()
{

}

ErrorStatus::FileError PCFFileFace::Read(PCFDriverModel &Data, PersistentModel &model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	NetModelPersist *pModel = model.GetScenarioPersist().CreatNetModel();
	pModel->Key(1);
	pModel->Name(_T("基本工况"));
	if(pModel == NULL)
	{
		ASSERT(FALSE);
		return ErrorStatus::eReadFileError;
	}
	errorMark = m_SteadyFace.Read(pModel->GetSteady());
	if (pModel == NULL)
	{
		return errorMark;
	}
	errorMark = m_SysPropety.Read(pModel->GetSysProperty());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}


/*
	
	PCFPipeFace pipeFace;
	CStringArray straryPipe;
	straryPipe.Add("PIPE");
	straryPipe.Add("END-POINT");
	straryPipe.Add("-134750.000000");
	straryPipe.Add("53349.976563");
	straryPipe.Add("32800.000000");
	straryPipe.Add("495.299988");
	straryPipe.Add("END-POINT");
	straryPipe.Add("-134750.000000");
	straryPipe.Add("53349.976563");
	straryPipe.Add("32000.000000");
	PCFPipe* pPipeData = NULL;
	pPipeData = Data.GetPipeMgr().Creator();
	pPipeData->Init(straryPipe) ;
	pPipeData->Tran3dTo2d();
	pPipeData->InJun(14);
	pPipeData->OutJun(15);
	PipePerisist *pPipePerisist = NULL;
	pPipePerisist = pModel->GetPipesMgr().CreatPipePerisit();
	if(pPipePerisist != NULL)
	{
		errorMark = pipeFace.Read(pPipeData,pPipePerisist);
	}

*/
	errorMark = m_pipeMgrFace.Read(Data.GetPipeMgr(),pModel->GetPipesMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}
	errorMark = m_junMgrFace.Read(Data.GetJunMgr(),pModel->GetJunMgr());
	if(ErrorStatus::eFileOK != errorMark)
	{
		return errorMark;
	}

/*	PCFJunFace *pJunFace = NULL;
	PCFJun *pJunData = NULL;
	Junperisist *pJunPerisist = NULL;
	Iterator<Junperisist> JunitPtr(pModel->GetJunMgr().CreateIt());
	for(JunitPtr->Fist();!JunitPtr->IsDone();JunitPtr->Next())
	{
		pJunPerisist = &JunitPtr->CurrentItem();
		Jun* pJun = dynamic_cast<Jun*>pJunPerisist;
		pJun->ms_PipePort
	}
*/


/*	Junperisist* pJunperisist = NULL;
	Jun* pJun = NULL;
	IteratorPtr<Junperisist> PipeItPtr(pModel->m_junMgr.CreateIt());
	for(PipeItPtr->Fist();!PipeItPtr->IsDone();PipeItPtr->Next())
    {
         pJunperisist = &PipeItPtr->CurrentItem();
	     pJun = dynamic_cast<Jun*>(pJunperisist);
		 GetValue(ms_PipeID,5);
		 int nNum = ms_PipeID.GetCount();
	     if(CanLink(nNum,nKey))
		 

	*/
	return errorMark;
}



/*
CMainFrame* pMainFrame = (CMainFrame*)AfxGetApp()->m_pMainWnd;
CChildFrame* pChildFrame = (CChildFrame*)pMainFrame->GetActiveFrame();
CAutoPFADoc* pPfaDoc = (CAutoPFADoc*)pChildFrame->GetActiveDocument();
Pipe *pPipe = NULL;
NetModel *pNetModeltemp = pPfaDoc->m_scenarioManager.GetCurScenario()->GetNetModel();
ComponentManager *pComponentManager = &(pNetModeltemp->m_compManager);
if(pComponent == NULL)
{
	return FALSE;
}
ASSERT(pPipe = dynamic_cast<Pipe*>(pComponent));
m_pPipe = pPipe;
	Init();


	Component *pComponent = NULL;
	DlgFind dlg(m_manager);
	if(IDOK == dlg.DoModal())
	{
		Component *pComponent = m_manager.LookUp(dlg.m_nObjectType,dlg.m_nObjectKey);
		if(pComponent !=NULL)
		{
			if(pComponent->GetID()==m_pPipe->GetID())
			{
				SaveData();
				m_pPipe = dynamic_cast<Pipe*>(pComponent);
				Init();
			}
			else
			{
				OnOK();
				pComponent->Show(m_UnitSys,&m_manager);
			}
		}
	}

  */