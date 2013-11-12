// ComponentManager.h: interface for the ComponentManager class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：ComponentManager.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENTMANAGER_H__5BCD404B_F643_46F3_BFF9_489B63CB1466__INCLUDED_)
#define AFX_COMPONENTMANAGER_H__5BCD404B_F643_46F3_BFF9_489B63CB1466__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SysProperties.h"
#include "ComponentFactory.h"
#include "Iterator.h"
#include "Component.h"
class Manipulator;
class MacroManipulator;
class Scenario;
class FlyWeight;
class JunManager;
class PipesManager;
class PropertyPersistent;

typedef CMap<int,int,Component*,Component*> ComponentMap;

class ComponentManager  
{
public:
	CRect GetRect();
	Component* Pick(CPoint point,int Size);
	void Draw(CDC *pDc,WorkSpaceRef &ref);
public:
	void Promote(const ComponentManager &parent);
	void CloneChild(const ComponentManager &parent);
	void InitState(Scenario *pCurScenario);
	void Delete(int nObjectType,int nObjectKey);
	FlyWeight* LookUp(int nObjectType,int nObjectKey, int nStateKey);
	void DelState();
	ComponentManager();
	ComponentManager(const ComponentManager &ref);
	ComponentManager& operator=(const ComponentManager &ref);
	virtual ~ComponentManager();
	int GetJunNum();
	int GetPipeNum();
	Iterator<Component>* CreatPipeIterator();
	Iterator<Component>* CreatJunIterator();
	Component* CreatComponent(int nID);
	Component* CreatComponent(int nID,int nKey);
	Component* CreatComponent(Component* pPrototype);
	Manipulator* CreatManipulator(int nID,CPoint point,int Size);
	void InitSelectTool(CRect rc,MacroManipulator *pManipulator);

	void GetAllUndefinedPipes( ComponentMap* pUndefinedPipesMap );
	void GetAllUndefinedJuns( ComponentMap* pUndefinedJunsMap);
private:
	Manipulator* CreatSelectTool(int Size);
    Manipulator* CreatPipeTool(int nID,int Size);
	Manipulator* CreatJunTool(int nID,int Size);
	void InitState(ComponentMap &map,Scenario *pCurScenario);
	void DelState(ComponentMap &map);
	void Clone(ComponentMap &toMap,const ComponentMap &fromMap);
    void CloneChild(ComponentMap &toMap,const ComponentMap &fromMap);
    void Promote(ComponentMap &toMap,const ComponentMap &fromMap);

public:
	void GetSmallViewRect(CRect& rect);
	double GetPipeArea(int nKey);
	void CalcWave();
	void SaveSection(ListImp<StrArray<8> > &table);
	void SectionTable(ListImp<StrArray<8> > &table,double dStepTime);
	BOOL SearchSection(StrArray<5> &array,double dStepTime,double dMaxError);
	BOOL IsAllPipeDefine(BOOL bTrans);
	BOOL IsAllJunDefine(BOOL bTrans);
	BOOL SearchControlPipe(Pipe *&pPipe);
	SysProperties& SysProperty();
	Component* LookUp(int nObjectType,int nObjectKey);
	Pipe* LookUpPipe(int nObjectKey);
	Jun* LookUpJun(int nObjectKey);
	BOOL Save(PropertyPersistent &sysProperty);
	BOOL Save(PipesManager &PipesMgr);
	BOOL Save(JunManager &junMgr);
	BOOL Read(PropertyPersistent &sysProperty);
	BOOL Read(PipesManager &PipesMgr);
	BOOL Read(JunManager &junMgr);

private:
	void InitComponent(Component* pComponent);//为新增加组件设置默认值
	void Add(Component* pComponent);
	ComponentFactory *m_factory;
    ComponentMap m_pipeMap;
	ComponentMap m_junMap;
	SysProperties m_sysProperties;
};
inline SysProperties& ComponentManager::SysProperty()
{
	return m_sysProperties;
}



#endif // !defined(AFX_COMPONENTMANAGER_H__5BCD404B_F643_46F3_BFF9_489B63CB1466__INCLUDED_)
