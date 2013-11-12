// AFTScenarioMgr.cpp: implementation of the AFTScenarioMgr class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AFTScenarioMgr.h"
#include "ScenarioDataMgr.h"
#include "AFTNetModel.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

AFTScenarioMgr::AFTScenarioMgr()
{

}

AFTScenarioMgr::~AFTScenarioMgr()
{

}

ErrorStatus::FileError AFTScenarioMgr::Read(ScenarioDataMgr &Data,ScenarioPersistMgr& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	NetModelPersist *pNet = NULL;
	ScenarioInfo* pInfo = NULL;
	AFTNetModel AFTModel;
	IteratorPtr<ScenarioInfo> InfoitPtr(Data.CreatIterator());
	for(InfoitPtr->Fist();!InfoitPtr->IsDone();InfoitPtr->Next())
	{
		pInfo = &InfoitPtr->CurrentItem();
		int iKey = pInfo->GetKey();
		CString strName = pInfo->GetName(); 
		
	
		
		CString strAncest = pInfo->GetAncestPath();	
		pNet = model.CreatNetModel();
		pNet->Key(iKey);
		pNet->Name(strName);
		pNet->Ancest(strAncest);
		pNet->ParentKey(Data.LookUpKey(pInfo->GetAncestPath()));
		AFTModel.Read(*pInfo->GetModelData(),*pNet);

		
		
	}
	model.CurKey(Data.StartScenario());
	
	return errorMark;
}
ErrorStatus::FileError AFTScenarioMgr::Save(ScenarioDataMgr &Data,ScenarioPersistMgr& model)
{
	ErrorStatus::FileError errorMark = ErrorStatus::eFileOK;
	NetModelPersist *pNet = NULL;
	ScenarioInfo* pInfo = NULL;
	AFTNetModel AFTModel;
	int iAFTKey = 1;
	int iCurKey =model.CurKey();
	int iPFAKey = 1;
	IteratorPtr<NetModelPersist> NetitPtr(model.CreateIt());
	for(NetitPtr->Fist();!NetitPtr->IsDone();NetitPtr->Next())
	{
		pNet = &NetitPtr->CurrentItem();
		iPFAKey = pNet->Key();//AFT工况的KEY值需要连续的数值
		CString strName = pNet->Name();
		CString strAncest = pNet->Ancest();
		pInfo = Data.Creat(iAFTKey,strName,strAncest);//这一步对NetModel进行了初使化
		AFTModel.Save(*pInfo->GetModelData(),*pNet);
		if(iCurKey == iPFAKey)
		{
			//PFA当前工况转化成AFT当前工况
			iCurKey = iAFTKey;
		}
		iAFTKey ++;
	}
	Data.ScenarioNum(model.GetModelNum());
	Data.StartScenario(iCurKey);
	return errorMark;
}

