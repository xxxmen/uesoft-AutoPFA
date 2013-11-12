// Scenario.h: interface for the Scenario class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENARIO_H__6F14581D_6846_434F_89C7_676A5B9F5EA4__INCLUDED_)
#define AFX_SCENARIO_H__6F14581D_6846_434F_89C7_676A5B9F5EA4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Scenario.h
  摘要：    
  author  : LSP          
*/
#include "Iterator.h"
#include <afxtempl.h>
class FlyWeight;
class NetModel;
class ComponentManager;
class CalcManager;

// typedef CMap<int,int,CStringArray*,CStringArray*> OutPutArray;
class Scenario  
{
public:
	BOOL CheckName(CString strName);
	ComponentManager* GetCompManager();
	CalcManager* GetCalcManager();

	Scenario* LookUp(int nKey);
	Iterator<Scenario>* CreatIterator();
	FlyWeight* LookUp(int nObjectType,int nObjectKey,int nStateKey,CString &ScenarioName = CString());
	Scenario* GetAnScenario();
	void Promote();
	void AddChild(Scenario *pChild);//call by Promote
	void RemoveChild(Scenario *pChild);//call by Promote
	void DelChild(Scenario *pChild);
	Scenario* AddChild(CString strName);
	Scenario* CloneWithChild(CString strName);
	Scenario* CloneWithOutChild(CString strName);
	void InitState();
	void DelState();
	Scenario(Scenario* pAnScenario = NULL);
	virtual ~Scenario();
    void SetKey(int nKey);
	int GetKey();
	CStringArray* GetPipeSteadyArray();
	CStringArray* GetPipeStationArray();
	CStringArray* GetPipeTranArray();
	CStringArray* GetJunArray();
    void SetName(CString strName);
	CString GetName();
	CString GetAncestName();
	CString GetAncestPath();
	NetModel* GetNetModel();
private:
	void ChangeAncestor();
private:
	Scenario(const Scenario &ref);
	Scenario& operator=(const Scenario &ref);
	Scenario(Scenario *pAnScenario,CString strName);

	NetModel *m_pNetModel;
	typedef CList<Scenario*,Scenario*>ChildList;
	ChildList m_childList;
	Scenario *m_pAnScenario;
    CString m_strName;
	int m_nKey;
	static int s_nNewKey;
	CStringArray* m_PipeSteadyArray;
 	CStringArray* m_PipeStationArray;
 	CStringArray* m_PipeTranArray;
 	CStringArray* m_JunArray;
};


inline void Scenario::SetName(CString strName)
{
	m_strName = strName;
}

inline CString Scenario::GetName()
{
	return m_strName;
}

inline void Scenario::SetKey(int nKey)
{
	m_nKey = nKey;
}

inline int Scenario::GetKey()
{
	return m_nKey;
}

inline CStringArray* Scenario::GetPipeSteadyArray()
{
	return m_PipeSteadyArray;
}

inline CStringArray* Scenario::GetPipeStationArray()
{
	return m_PipeStationArray;
}

inline CStringArray* Scenario::GetPipeTranArray()
{
	return m_PipeTranArray;
}

inline CStringArray* Scenario::GetJunArray()
{
	return m_JunArray;
}

inline Scenario* Scenario::GetAnScenario()
{
	return m_pAnScenario;
}

inline NetModel* Scenario::GetNetModel()
{
	return m_pNetModel;
}
#endif // !defined(AFX_SCENARIO_H__6F14581D_6846_434F_89C7_676A5B9F5EA4__INCLUDED_)
