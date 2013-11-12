// ScenarioObject.cpp: implementation of the ScenarioObject class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "ScenarioObject.h"
#include "Scenario.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ScenarioObject::ScenarioObject()
{
	m_nObjectKey = 0;
	m_privateMap.RemoveAll();
	m_shareMap.RemoveAll();
}

ScenarioObject::ScenarioObject(const ScenarioObject&ref)
{
	m_privateMap.RemoveAll();
	m_shareMap.RemoveAll();
	m_nObjectKey = ref.m_nObjectKey;
	ClonePrivateState(ref.m_privateMap);
	//CloneShareState(ref.m_shareMap);
}

ScenarioObject& ScenarioObject::operator=(const ScenarioObject&ref)
{
	if(this == &ref)
		return *this;

	DelPrivateState();
	DelShareState();

	m_nObjectKey = ref.m_nObjectKey;
	ClonePrivateState(ref.m_privateMap);
	//CloneShareState(ref.m_shareMap);
	
	return *this;
}

ScenarioObject::~ScenarioObject()
{
	DelPrivateState();
}

//--------------------------------------------
//Parameters:	  pCurScenario[In]         工况名称
//    return:                          
//      Memo:	  初始化pCurScenario工况的对象从祖先共享的状态
//				
//---------------------------------------------

void ScenarioObject::InitState(Scenario*pCurScenario)
{
	//Template Method (模扳方法)
	InitState(pCurScenario,GetArray(),GetType());
}

//--------------------------------------------
//Parameters:	  pCurScenario[In]         工况名称
//                array[In]                ScenarioObject派生对象拥有的状态
//                nObjectType[In]          对象的类型
//    return:                          
//      Memo:	  初始化pCurScenario工况的对象从祖先共享的状态
//				
//---------------------------------------------
void ScenarioObject::InitState(Scenario *pCurScenario,const NameArray &array,int nObjectType)
{
    int n = array.GetSize();
    FlyWeight *pFly = NULL;
	int nStateKey;
	for(int i=0; i<n; i++)
	{
		StateName& stateName = (StateName)array[i];
		nStateKey = stateName.Key();
		if(!m_privateMap.Lookup(nStateKey,pFly))
		{
			if(pCurScenario->GetAnScenario()!=NULL)
			{
				pFly = pCurScenario->GetAnScenario()->LookUp(nObjectType,m_nObjectKey,nStateKey);
				assert(pFly != NULL);
				m_shareMap.SetAt(nStateKey,pFly);
			}
		}
	}
}

//--------------------------------------------
//Parameters:	  pParent[In]         工况名称
//    return:                          
//      Memo:	  将this工况提升为pParent工况的兄弟工况并复制从pParent工况共享的状态
//				
//---------------------------------------------
void ScenarioObject::Promote(ScenarioObject *pParent)
{
	NameArray &Array = GetArray();
	int n = Array.GetSize();
    FlyWeight *pFly = NULL;
	int nStateKey;
	for(int i=0; i<n; i++)
	{   
		nStateKey = Array[i].Key();
		if(!m_privateMap.Lookup(nStateKey,pFly))
		{
			if(pParent->m_privateMap.Lookup(nStateKey,pFly))
			{
				m_privateMap.SetAt(nStateKey,pFly->Clone());
			}
		}
	}
}

//--------------------------------------------
//Parameters:	  
//    return:                          
//      Memo:	  克隆
//				
//---------------------------------------------
ScenarioObject* ScenarioObject::Clone()
{
	ScenarioObject* pClone = DoClone();
	assert(typeid(*this)==typeid(*pClone));
	return pClone;
}

//--------------------------------------------
//Parameters:	  
//    return:                          
//      Memo:	  克隆对象但是不克隆对象的状态
//				
//---------------------------------------------
ScenarioObject* ScenarioObject::CloneChild()
{
	ScenarioObject* pClone = Clone();
	pClone->DelPrivateState();
	return pClone;
}

//--------------------------------------------
//Parameters:	  
//    return:                          
//      Memo:	  移出对象共享祖先的外部状态
//				
//---------------------------------------------
void ScenarioObject::DelShareState()
{
	m_shareMap.RemoveAll();
}

//--------------------------------------------
//Parameters:	  
//    return:                          
//      Memo:	  删除对象保存的状态
//				
//---------------------------------------------
void ScenarioObject::DelPrivateState()
{
	POSITION pos = m_privateMap.GetStartPosition();
	FlyWeight *pFly = NULL;
	int nKey;
	while(pos)
	{
		m_privateMap.GetNextAssoc(pos,nKey,pFly);
		delete pFly;
	}
	m_privateMap.RemoveAll();
}

//--------------------------------------------
//Parameters:	  mapFrom[In]           状态表
//    return:                          
//      Memo:	  克隆mapFrom的状态作为私有状态保存
//				
//---------------------------------------------
void ScenarioObject::ClonePrivateState(const StateMap &mapFrom)
{
	POSITION pos = mapFrom.GetStartPosition();
	FlyWeight *pFly = NULL;
	int nKey;
	while(pos)
	{
		mapFrom.GetNextAssoc(pos,nKey,pFly);
		m_privateMap.SetAt(nKey,pFly->Clone());
	}
}

//--------------------------------------------
//Parameters:	  mapFrom[In]           状态表
//    return:                          
//      Memo:	  把mapFrom的状态作为共享状态保存
//				
//---------------------------------------------
void ScenarioObject::CloneShareState(const StateMap &mapFrom)
{
	POSITION pos = mapFrom.GetStartPosition();
	FlyWeight *pFly = NULL;
	int nKey;
	while(pos)
	{
		mapFrom.GetNextAssoc(pos,nKey,pFly);
		m_shareMap.SetAt(nKey,pFly);
	}
}

//--------------------------------------------
//Parameters:	  
//    return:                          
//      Memo:	  使用模扳方法初始化ScenarioObject派生类
//				
//---------------------------------------------
void ScenarioObject::Init()
{
	FlyWeightFactory *m_factory = FlyWeightFactory::Instance();
	NameArray &Array = GetArray();
	int n = Array.GetSize();
    FlyWeight *pFly = NULL;
	int nStateKey;
	for(int i=0; i<n; i++)
	{   
		nStateKey = Array[i].Key();
		pFly = m_factory->CreatObject(Array[i].TypeKey());
		m_privateMap.SetAt(nStateKey,pFly);
	}
}

//--------------------------------------------
//Parameters:	  nStateKey[In]      状态Key值
//    return:                          
//      Memo:	  根据状态的Key值先从本对象的私有再到共享状态中查找状态
//				
//---------------------------------------------
FlyWeight* ScenarioObject::GetValue(int nStateKey)
{
	FlyWeight *pFly = NULL;
	if(!m_privateMap.Lookup(nStateKey,pFly))
	{
		m_shareMap.Lookup(nStateKey,pFly);
	}
	return pFly;
}

//--------------------------------------------
//Parameters:	  nStateKey[In]      状态Key值
//    return:                          
//      Memo:	  根据状态的Key值本对象的私有状态中查找状态
//				
//---------------------------------------------
FlyWeight* ScenarioObject::GetPrivate(int nStateKey)
{
	FlyWeight *pFly = NULL;
    m_privateMap.Lookup(nStateKey,pFly);
	return pFly;
}
BOOL ScenarioObject::DelPrivateState(int nStateKey)
{
	FlyWeight *pFly = NULL;
	if(m_privateMap.Lookup(nStateKey,pFly))
	{
		delete pFly;
		m_privateMap.RemoveKey(nStateKey);
		return TRUE;
	}
	return FALSE;
}
BOOL ScenarioObject::IsExistShare(int nStateKey)
{
	FlyWeight *pFly = NULL;
    return m_shareMap.Lookup(nStateKey,pFly);
}
BOOL ScenarioObject::IsExistPrivate(int nStateKey)
{
	FlyWeight *pFly = NULL;
	return m_privateMap.Lookup(nStateKey,pFly);
}
//--------------------------------------------
//Parameters:	  nStateKey[In]      状态Key值
//                fly[In]                状态
//    return:                          
//      Memo:	 用状态fly更新nStateKey对应的状态
//               如果为私有状态直接更新如果为共享状态将fly保存为nStateKey对应的私有状态
//				 处理读文件时可以增加私有状态
//---------------------------------------------
void ScenarioObject::SetValue(int nStateKey,FlyWeight *fly)
{
	FlyWeight *pFlyShare = NULL;
	FlyWeight *pFlyPrivate = NULL;
	if(m_shareMap.Lookup(nStateKey,pFlyShare))
	{
		if(pFlyShare->IsEqual(*fly))
		{
			DelPrivateState(nStateKey);
		}
		else
		{
			m_privateMap.SetAt(nStateKey,fly->Clone());
		}
	}
	else
	{
		if(m_privateMap.Lookup(nStateKey,pFlyPrivate))
		{
			if(pFlyPrivate->IsEqual(*fly))
			{
			}
			else
			{
				pFlyPrivate->Assign(fly);
			}
		}
		else
		{
			m_privateMap.SetAt(nStateKey,fly->Clone());
		}
	}	
}
void ScenarioObject::SetValue(FlyWeight &fly,int nStateKey)
{
	if(fly.IsEmpty()
	   && !IsExistPrivate(nStateKey)
	   && !IsExistShare(nStateKey))
	{
		//读文件时子工况属性为空表示共享父工况属性
		//不存在私有属性和共享属性表示子工况在读文件初始化属性
		return;
	}
	else
	{
		SetValue(nStateKey,&fly);
	}
}

//--------------------------------------------
//Parameters:	  nStateKey[In]      状态Key值
//                pCurScenario[In]   当前对象对应的工况
//                ScenarioName[Out]  查找返回的状态对应的工况
//    return:     对象的nStateKey对应的状态                     
//      Memo:	  根据对象状态的Key值和当前对象所在的工况查找状态并输出状态所在的工况名称
//				
//---------------------------------------------
FlyWeight* ScenarioObject::LookUp(int nStateKey,Scenario*pCurScenario,CString &ScenarioName)
{
	FlyWeight *pFly = NULL;
	if(!m_privateMap.Lookup(nStateKey,pFly))
	{
		if(pCurScenario->GetAnScenario()!=NULL)
		pFly = pCurScenario->GetAnScenario()->LookUp(GetType(),m_nObjectKey,nStateKey,ScenarioName);
		return pFly;
	}
	else
	{
		ScenarioName = pCurScenario->GetName();
		return pFly;
	}
}

//--------------------------------------------
//Parameters:	  nStateKey[In]      状态Key值
//                pCurScenario[In]   当前对象对应的工况
//                ScenarioName[Out]  查找返回的状态对应的工况
//    return:     对象的nStateKey对应的状态                     
//      Memo:	  根据对象状态的Key值和当前对象所在的工况查找对象共享祖先的状态并输出状态所在的工况名称
//				
//---------------------------------------------
FlyWeight* ScenarioObject::LookAncest(int nStateKey,Scenario*pCurScenario,CString &ScenarioName)
{
	FlyWeight *pFly = NULL;
	pFly = LookUp(nStateKey,pCurScenario,ScenarioName);
	if(m_privateMap.Lookup(nStateKey,pFly))
	{
		pFly = NULL;
		ScenarioName.Empty();
	}
	return pFly;
}

void ScenarioObject::CloneShare(ScenarioObject* ppPrototype)
{
	//将原型的共享状态复制到复制品的私有状态中
	ClonePrivateState(ppPrototype->m_shareMap);
}

BOOL ScenarioObject::IsEmpty()
{
	if(m_privateMap.IsEmpty()
		&&m_shareMap.IsEmpty())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void ScenarioObject::InitAttr(NameArray &array,UINT nID,int nKey,int nType,BOOL bShow)
{
	CString strTemp;
	strTemp.LoadString(nID);
	StateName temp(strTemp,nKey,nType,bShow);
	array.Add(temp);
}
void ScenarioObject::InitAttr(NameArray &array,int nKey, int nType)
{
	StateName temp(nKey,nType);
	array.Add(temp);
}