// ScenarioObject.h: interface for the ScenarioObject class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：ScenarioObject.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENARIOOBJECT_H__A25A1469_8434_4A96_9FF9_FB6D99BB1183__INCLUDED_)
#define AFX_SCENARIOOBJECT_H__A25A1469_8434_4A96_9FF9_FB6D99BB1183__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "FlyWeight.h"
#include "FlyWeightFactory.h"
#include "StateName.h"

class Scenario;
class FlyWeightFactory;

class ScenarioObject  
{
public:
	BOOL IsEmpty();
	void CloneShare(ScenarioObject* ppPrototype);
	void Init();
	virtual int GetType()=0;
	virtual NameArray& GetArray()=0;
	void Promote(ScenarioObject* pParent);
	ScenarioObject* CloneChild();
	ScenarioObject* Clone();
	virtual void InitState(Scenario *pCurScenario);
	void DelShareState();
	ScenarioObject();
	ScenarioObject(const ScenarioObject&ref);
	ScenarioObject& operator=(const ScenarioObject&ref);
	virtual ~ScenarioObject();

	FlyWeight* GetPrivate(int nStateKey);
	
	FlyWeight* LookUp(int nStateKey,Scenario*pCurScenario,CString &ScenarioName = CString());
	FlyWeight* LookAncest(int nStateKey,Scenario*pCurScenario,CString &ScenarioName = CString());
	void SetKey(int nKey);
	int GetKey();
	template<class T> void GetValue(T &fly,int nStateKey){
		FlyWeight *pFly = GetValue(nStateKey);
		if(pFly != NULL)
		{
			fly = *dynamic_cast<T*>(pFly);
		}
		else
		{
			fly.SetNull();
		}
	};
	FlyWeight* GetValue(int nStateKey);
	void SetValue(FlyWeight &fly,int nStateKey);

public:
	static void InitAttr(NameArray &array,UINT nID,int nKey, int nType,BOOL bShow = TRUE);
	static void InitAttr(NameArray &array,int nKey, int nType);
	
private:
	BOOL DelPrivateState(int nStateKey);
	BOOL IsExistShare(int nStateKey);
	BOOL IsExistPrivate(int nStateKey);
	void SetValue(int nStateKey,FlyWeight *fly);
	virtual ScenarioObject* DoClone()=0;
	void InitState(Scenario*pCurScenario,const NameArray &array,int nObjectType);
	void DelPrivateState();

private:
	typedef CMap<int,int,FlyWeight*,FlyWeight*> StateMap;
	StateMap m_privateMap;
	StateMap m_shareMap;
	int m_nObjectKey;
	void ClonePrivateState(const StateMap &mapFrom);
	void CloneShareState(const StateMap &mapFrom);
};

inline void ScenarioObject::SetKey(int nKey)
{
	m_nObjectKey = nKey;
}
inline int ScenarioObject::GetKey()
{
	return m_nObjectKey;
}
#endif // !defined(AFX_SCENARIOOBJECT_H__A25A1469_8434_4A96_9FF9_FB6D99BB1183__INCLUDED_)
