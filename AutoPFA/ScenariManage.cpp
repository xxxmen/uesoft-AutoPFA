// ScenariManage.cpp: implementation of the ScenariManage class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "ScenariManage.h"
#include "Scenario.h"
#include "NetModelPersist.h"
#include "ScenarioPersistMgr.h"
#include "NetModel.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ScenariManage::ScenariManage()
{
	m_pBaseScenario = new Scenario;
	m_pCurScenario = m_pBaseScenario;
}

ScenariManage::~ScenariManage()
{
	delete m_pBaseScenario;
	m_pBaseScenario = NULL;
	m_pCurScenario = NULL;
}

//--------------------------------------------
//Parameters:	 pScenario[IN]	    当前选择工况
//    return:    
//      Memo:	 设置当前工作区工况为当前选择工况
//				
//---------------------------------------------
void ScenariManage::SetCurScenario(Scenario* pScenario)
{
	assert(pScenario != NULL);
	if(LookUp(m_pCurScenario->GetKey()) != NULL)
	{
		m_pCurScenario->DelState();
	}
	m_pCurScenario = pScenario;
	pScenario->InitState();
}

//--------------------------------------------
//Parameters:	 pScenario[IN]	      当前选择工况
//               strName[IN]          当前选择工况的子工况名称   
//    return:                         子工况                     
//      Memo:	 为当前选择工况增加一个名称为strName的子工况
//				
//---------------------------------------------
Scenario* ScenariManage::AddChildScenario(Scenario* pScenario,CString strName)
{
	assert(pScenario != NULL);
	return pScenario->AddChild(strName);
}

//--------------------------------------------
//Parameters:	 pScenario[IN]	      当前选择工况
//               strName[IN]          当前选择工况的兄弟工况名称   
//    return:                         增加的兄弟工况                     
//      Memo:	 当前选择工况增加一个名称为strName的兄弟工况并复制当前工况的子孙工况
//				
//---------------------------------------------
Scenario* ScenariManage::CloneWithChild(Scenario* pScenario,CString strName)
{
	assert(pScenario != NULL);
	if(pScenario->GetAnScenario()!=NULL)
	{
		return pScenario->CloneWithChild(strName);
	}
	else
	{
		return NULL;
	}

	
}

//--------------------------------------------
//Parameters:	 pScenario[IN]	      当前选择工况
//               strName[IN]          当前选择工况的兄弟工况名称   
//    return:                         增加的兄弟工况                     
//      Memo:	 当前选择工况增加一个名称为strName的兄弟工况不包括当前工况的子孙工况
//				
//---------------------------------------------
Scenario* ScenariManage::CloneWithOutChild(Scenario* pScenario,CString strName)
{
	assert(pScenario != NULL);
	if(pScenario->GetAnScenario()!=NULL)
	{
		return pScenario->CloneWithOutChild(strName);
	}
	else
	{
		return NULL;
	}
}

//--------------------------------------------
//Parameters:	 pScenario[IN]	      当前选择工况         
//    return:                         增加的兄弟工况                     
//      Memo:	 删除当前选择工况包括当前工况的子工况
//				
//---------------------------------------------
BOOL ScenariManage::DelScenario(Scenario* pScenario)
{
	assert(pScenario != NULL);
	Scenario *pAnScenario = pScenario->GetAnScenario();
	if(pAnScenario != NULL)
	{
		if(m_pCurScenario == pScenario)
		{
			m_pCurScenario = pAnScenario;
		}
		pAnScenario->DelChild(pScenario);
		return TRUE;
	}
	else
	{
		return FALSE;
	}

}

//--------------------------------------------
//Parameters:	 pScenario[IN]	      当前选择工况         
//    return:                                             
//      Memo:	 提升当前选择工况作为其父工况的兄弟工况
//				
//---------------------------------------------
BOOL ScenariManage::Promote(Scenario* pScenario)
{
	assert(pScenario != NULL);
	if(pScenario->GetAnScenario()!=NULL
		&&pScenario->GetAnScenario()->GetAnScenario()!=NULL)
	{
		pScenario->Promote();
		return TRUE;
	}
	else
	{
		return FALSE;
	}
	
}

//--------------------------------------------
//Parameters:	 nKey[IN]	      工况的数字标记        
//    return:                     与数字标记对应的工况                                      
//      Memo:	 根据工况的唯一数字标记查询到工况并返回
//				
//---------------------------------------------
Scenario* ScenariManage::LookUp(int nKey)
{
	return m_pBaseScenario->LookUp(nKey);
}

//--------------------------------------------
//Parameters:	      
//    return:    得到当前工作区工况的祖先名称路径                                   
//      Memo:	 根据工况的唯一数字标记查询到工况并返回
//				
//---------------------------------------------
CString ScenariManage::GetCurAncestName()
{
	return m_pCurScenario->GetAncestName();
}

BOOL ScenariManage::Read(ScenarioPersistMgr &Persistent)
{
	BOOL bRet = TRUE;
	Scenario *pScenario = NULL;
	NetModelPersist *pNet = Persistent.GetBase();
	if(pNet != NULL)
	{
		m_pBaseScenario->SetKey(pNet->Key());
		m_pBaseScenario->SetName(pNet->Name());
		m_pBaseScenario->GetNetModel()->Read(pNet);
	}
	IteratorPtr<NetModelPersist> NetitPtr(Persistent.CreateIt());
	for(NetitPtr->Fist();!NetitPtr->IsDone();NetitPtr->Next())
	{
		pNet = &NetitPtr->CurrentItem();
		pScenario = LookUp(pNet->ParentKey());
		if(pScenario != NULL)
		{
			pScenario = AddChildScenario(pScenario,pNet->Name());
			pScenario->SetKey(pNet->Key());
			pScenario->GetNetModel()->Read(pNet);
		}
	}
	m_pCurScenario = LookUp(Persistent.CurKey());
	if(m_pCurScenario == NULL)
	{
		m_pCurScenario = m_pBaseScenario;
		bRet = FALSE;
	}
	else
	{
		SetCurScenario(m_pCurScenario);
	}
	return bRet;
}

BOOL ScenariManage::Save(ScenarioPersistMgr &Persistent)
{
	BOOL bRet = TRUE;
	Scenario *pScenario = m_pCurScenario;
	SetCurScenario(m_pBaseScenario);
	bRet = Save(Persistent,m_pBaseScenario);
	Persistent.CurKey(pScenario->GetKey());
	SetCurScenario(pScenario);
	return bRet;
}

BOOL ScenariManage::Save(ScenarioPersistMgr &Persistent,Scenario *pScenario)
{
	NetModelPersist *pNet = Persistent.CreatNetModel();
	pNet->Key(pScenario->GetKey());
	pNet->Name(pScenario->GetName());
	pNet->Ancest(pScenario->GetAncestPath());
	pScenario->GetNetModel()->Save(pNet);
	Scenario *pChild = NULL;
	IteratorPtr<Scenario> iteratorPtr(pScenario->CreatIterator());
	for(iteratorPtr->Fist();!iteratorPtr->IsDone();iteratorPtr->Next())
	{
		pChild = &iteratorPtr->CurrentItem();
		Save(Persistent,pChild);
	}
	return TRUE;
}

BOOL ScenariManage::SaveCurModel(ScenarioPersistMgr &Persistent,Scenario *pScenario)
{
	Scenario *pTempScenario = m_pCurScenario;
	SetCurScenario(pScenario);
	NetModelPersist *pNet = Persistent.CreatNetModel();
	pNet->Key(pScenario->GetKey());
	pNet->Name(pScenario->GetName());
	pNet->Ancest(pScenario->GetAncestPath());
	pScenario->GetNetModel()->Save(pNet);
	Persistent.CurKey(pScenario->GetKey());
	SetCurScenario(pTempScenario);
	return TRUE;
}