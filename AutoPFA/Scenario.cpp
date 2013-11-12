// Scenario.cpp: implementation of the Scenario class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Scenario.h"
#include "NetModel.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int Scenario::s_nNewKey = 1;

Scenario::Scenario(Scenario* pAnScenario)
{
	m_nKey = s_nNewKey++;
	m_pAnScenario = pAnScenario;
	m_strName = "基本工况";
	m_pNetModel = new NetModel;
	m_childList.RemoveAll();
 	m_PipeSteadyArray = new CStringArray;
	m_PipeStationArray = new CStringArray;
 	m_PipeTranArray = new CStringArray;
 	m_JunArray = new CStringArray;
}

Scenario::Scenario(Scenario *pAnScenario,CString strName)
{
    m_nKey = s_nNewKey++;
	m_pAnScenario = pAnScenario;
	m_pNetModel   = NULL;
	m_strName     = strName;
	m_childList.RemoveAll();
}

Scenario::Scenario(const Scenario &ref)
{
    m_nKey = s_nNewKey++;
	m_pAnScenario = ref.m_pAnScenario;
	m_pNetModel   = new NetModel(*ref.m_pNetModel);
	m_strName     = ref.m_strName;
	POSITION pos = ref.m_childList.GetHeadPosition();
	Scenario *pChild = NULL;
	while(pos)
	{
		pChild = ref.m_childList.GetNext(pos);
		m_childList.AddTail(new Scenario(*pChild));
	}
}

Scenario& Scenario::operator=(const Scenario &ref)
{
	if(this == &ref)
	return *this;

	POSITION pos = m_childList.GetHeadPosition();
	Scenario *pChild = NULL;
	while(pos)
	{
		pChild = m_childList.GetNext(pos);
		delete pChild;
	}
	m_childList.RemoveAll();
	delete m_pNetModel;

	m_nKey = s_nNewKey++;
    m_pAnScenario = ref.m_pAnScenario;
	m_pNetModel   = new NetModel(*ref.m_pNetModel);
	m_strName     = ref.m_strName;
    pos = ref.m_childList.GetHeadPosition();
	pChild = NULL;
	while(pos)
	{
		pChild = ref.m_childList.GetNext(pos);
		m_childList.AddTail(new Scenario(*pChild));
	}
	
	return *this;
}

Scenario::~Scenario()
{
	POSITION pos = m_childList.GetHeadPosition();
	Scenario *pChild = NULL;
	while(pos)
	{
		pChild = m_childList.GetNext(pos);
		delete pChild;
	}
	delete m_pNetModel;
	//内存泄
	delete m_PipeSteadyArray;
	delete m_PipeStationArray;
	delete m_PipeTranArray;
	delete m_JunArray;
}

//--------------------------------------------
//Parameters:	 nObjectType[IN]       对象的对应的类型
//               nObjectKey[IN]        对象的Key值
//               nStateKey[IN]         对象的状态对应的Key值         
//               ScenarioName[Out]	   查询的共享状态所在的工况的名称             
//    return:    状态享元对象的接口                                    
//      Memo:	 根据对象的类型Key值和对象的状态的Key值查找对象的状态并返回
//               该状态和输出该状态所在的工况名称。
//				
//---------------------------------------------
FlyWeight* Scenario::LookUp(int nObjectType,int nObjectKey,int nStateKey,CString &ScenarioName)
{
	//使用设计模式职责链沿着父工况查找直到找到
	FlyWeight *pFly = NULL;
	pFly = m_pNetModel->LookUp(nObjectType,nObjectKey,nStateKey);
	if(NULL==pFly)
	{
		ASSERT(m_pAnScenario != NULL);
		return m_pAnScenario->LookUp(nObjectType,nObjectKey,nStateKey,ScenarioName);
	}
	else
	{
		ScenarioName = m_strName;
		return pFly;
	}
}

//--------------------------------------------
//Parameters:	         
//    return:                                      
//      Memo:	 提升this工况使该工况成为父工况的兄弟工况
//				
//---------------------------------------------
void Scenario::Promote()
{
	ASSERT(m_pAnScenario != NULL);

	m_pAnScenario->RemoveChild(this);
	m_pNetModel->Promote(m_pAnScenario->m_pNetModel);
	m_pAnScenario = m_pAnScenario->GetAnScenario();
	m_pAnScenario->AddChild(this);
}

//--------------------------------------------
//Parameters:	 pChild[In]        工况
//    return:                                      
//      Memo:	为this工况增加pChild工况为它的子工况
//				
//---------------------------------------------
void Scenario::AddChild(Scenario *pChild)
{
	m_childList.AddTail(pChild);
}

//--------------------------------------------
//Parameters:	 pChild[In]        工况
//    return:                                      
//      Memo:	查找this工况的pChild子工况并从子工况中移出
//				
//---------------------------------------------
void Scenario::RemoveChild(Scenario *pChild)
{
	POSITION pos = m_childList.Find(pChild);
	ASSERT(pos != NULL);
	m_childList.RemoveAt(pos);
}

//--------------------------------------------
//Parameters:	 pChild[In]        工况
//    return:                                      
//      Memo:	查找this工况的pChild子工况并从子工况中删除
//				
//---------------------------------------------
void Scenario::DelChild(Scenario *pChild)
{
	POSITION pos = m_childList.Find(pChild);
	ASSERT(pos != NULL);
	delete pChild;
	m_childList.RemoveAt(pos);
}

//--------------------------------------------
//Parameters:	 strName[In]        工况名称
//    return:    当前增加的工况                                  
//      Memo:	为this工况增加一个名称为strName的子工况
//				
//---------------------------------------------
Scenario* Scenario::AddChild(CString strName)
{
	Scenario *pChild = new Scenario(this,strName);
	pChild->m_pNetModel = m_pNetModel->CloneChild();
	AddChild(pChild);
	return pChild;
}

//--------------------------------------------
//Parameters:	 strName[In]        工况名称
//    return:    当前增加的工况                                  
//      Memo:	复制this工况不包括子孙工况增加一个名称为strName的兄弟工况
//				
//---------------------------------------------
Scenario * Scenario::CloneWithOutChild(CString strName)
{
	assert(m_pAnScenario != NULL);
	Scenario *pClone = new Scenario(m_pAnScenario,strName);
	pClone->m_pNetModel = m_pNetModel->Clone();
	m_pAnScenario->AddChild(pClone);
	return pClone;
}

//--------------------------------------------
//Parameters:	 strName[In]        工况名称
//    return:    当前增加的工况                                  
//      Memo:	复制this工况包括子孙工况增加一个名称为strName的兄弟工况
//				
//---------------------------------------------
Scenario * Scenario::CloneWithChild(CString strName)
{
    Scenario *pClone = CloneWithOutChild(strName);
	
	POSITION pos = m_childList.GetHeadPosition();
	Scenario *pChild = NULL;
	while(pos)
	{
		pChild = m_childList.GetNext(pos);
		pClone->m_childList.AddTail(new Scenario(*pChild));
	}
	pClone->ChangeAncestor();
	return pClone;
}

//--------------------------------------------
//Parameters:	 
//    return:                             
//      Memo:	移出this工况中的对象从祖先工况共享来的状态
//				
//---------------------------------------------
void Scenario::DelState()
{
	m_pNetModel->DelState();
}

//--------------------------------------------
//Parameters:	 
//    return:                             
//      Memo:	从祖先工况查找this工况不存在的状态作为this工况的外部共享状态
//				
//---------------------------------------------
void Scenario::InitState()
{
	m_pNetModel->InitState(this);
}

//--------------------------------------------
//Parameters:	 
//    return:                             
//      Memo:	将this工况的子工况保存的父工况改为this
//				
//---------------------------------------------
void Scenario::ChangeAncestor()
{
	POSITION pos = m_childList.GetHeadPosition();
	Scenario *pChild = NULL;
	while(pos)
	{
		pChild = m_childList.GetNext(pos);
		pChild->m_pAnScenario = this;
		pChild->ChangeAncestor();
	}
}

//--------------------------------------------
//Parameters:	 
//    return:                             
//      Memo:	为this工况的子工况创建一个迭代器为外部访问子工况提供一个接口
//				
//---------------------------------------------
Iterator<Scenario>* Scenario::CreatIterator()
{
	return new ListIterator<Scenario>(&m_childList);
}

//--------------------------------------------
//Parameters:	 nKey[In]     工况的唯一标记Key
//    return:                             
//      Memo:	查找this工况的子孙工况的唯一标记Key=nKey的工况
//				
//---------------------------------------------
Scenario* Scenario::LookUp(int nKey)
{
	if(m_nKey == nKey)
	{
		return this;
	}
	else
	{
		POSITION pos = m_childList.GetHeadPosition();
		Scenario *pChild = NULL;
		Scenario *pFind = NULL;
		while(pos)
		{
			pChild = m_childList.GetNext(pos);
			pFind = pChild->LookUp(nKey);
			if(pFind != NULL)
				break;
		}
		return pFind;
	}
}

//--------------------------------------------
//Parameters:	 
//    return:   祖先工况名称路径                         
//      Memo:	生成this工况祖先路径
//				
//---------------------------------------------
CString Scenario::GetAncestName()
{
	if(m_pAnScenario == NULL)
	{
		return m_strName;
	}
	else
	{
		return m_pAnScenario->GetAncestName() + "/" + m_strName;
	}
}

CString Scenario::GetAncestPath()
{
	if(m_pAnScenario == NULL)
	{
		return "";
	}
	else
	{
		return m_pAnScenario->GetAncestName();
	}
}
//--------------------------------------------
//Parameters:	 
//    return:     组件管理器                     
//      Memo:	  返回this工况对应的组件管理器
//				
//---------------------------------------------
ComponentManager* Scenario::GetCompManager()
{
	 return &m_pNetModel->m_compManager;
}

CalcManager* Scenario::GetCalcManager()
{
	 return &m_pNetModel->m_calcManager;
}
//--------------------------------------------
//Parameters:	  strName[In]         工况名称
//    return:     如果this工况存在名称为strName的子工况返回Ture                     
//      Memo:	  检查strName是否被this工况的子工况使用
//				
//---------------------------------------------
BOOL Scenario::CheckName(CString strName)
{
	BOOL bRet = TRUE;
	POSITION pos = m_childList.GetHeadPosition();
	Scenario *pChild = NULL;
	while(pos)
	{
		pChild = m_childList.GetNext(pos);
		if(0 == strName.Compare(pChild->GetName()))
		{
			bRet = FALSE;
		}
	}
	return bRet;
}

