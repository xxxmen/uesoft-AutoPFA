// CalcManager.h: interface for the CalcManager class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：CalcManager.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ALCMANAGER_H__BF1A8ACC_DA08_4840_8270_4FF8C5EB04F0__INCLUDED_)
#define AFX_ALCMANAGER_H__BF1A8ACC_DA08_4840_8270_4FF8C5EB04F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class Scenario;
class FlyWeight;
class SysProperFactory;
class SteadySet;
class SectionSet;
class TransientSet;

class CalcManager  
{
public:
	void AnalysisType(int nType);
	int AnalysisType();
	SteadySet* GetSteadySet();
	SectionSet* GetSectionSet();
	TransientSet* GetTransientSet();
	void Promote(const CalcManager &parent);
	void CloneChild(const CalcManager &parent);
	void InitState(Scenario *pCurScenario);
	FlyWeight* LookUp(int nObjectType,int nObjectKey, int nStateKey);
	void DelState();
	CalcManager();
	virtual ~CalcManager();
	CalcManager(const CalcManager &ref);
	CalcManager& operator=(const CalcManager &ref);

private:
	SteadySet *m_pSteadySet;
	SectionSet *m_pSectionSet;
	TransientSet *m_pTransientSet;
	SysProperFactory *m_factory;
};
inline SteadySet* CalcManager::GetSteadySet()
{
	return m_pSteadySet;
}

inline SectionSet* CalcManager::GetSectionSet()
{
	return m_pSectionSet;
}

inline TransientSet* CalcManager::GetTransientSet()
{
	return m_pTransientSet;
}
#endif // !defined(AFX_ALCMANAGER_H__BF1A8ACC_DA08_4840_8270_4FF8C5EB04F0__INCLUDED_)
