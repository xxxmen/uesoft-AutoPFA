// SysProperties.h: interface for the SysProperties class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：SysProperties.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSPROPERTIES_H__5AED598C_D067_433E_9FBD_22AAE6538CF7__INCLUDED_)
#define AFX_SYSPROPERTIES_H__5AED598C_D067_433E_9FBD_22AAE6538CF7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class Fuild;
class Condition;
class FlyWeight;
class Scenario;
class SysProperFactory;
class PropertyPersistent;

class SysProperties  
{
public:
	BOOL IsFuildDefine();
	double BulkModulus();
	double Density();
	double Gravity();
	BOOL Read(PropertyPersistent &persistent);
	BOOL Save(PropertyPersistent &persistent);
	Fuild* GetFuild();
	Condition *GetCondition();
	void Promote(const SysProperties &parent);
	void CloneChild(const SysProperties &parent);
	void InitState(Scenario *pCurScenario);
	FlyWeight* LookUp(int nObjectType,int nObjectKey, int nStateKey);
	void DelState();
	SysProperties();
	SysProperties(const SysProperties &ref);
	SysProperties& operator=(const SysProperties &ref);
	virtual ~SysProperties();

private:
	Fuild *m_pFuild;
	Condition *m_pCondition;
	SysProperFactory *m_factory;

};

inline Fuild* SysProperties::GetFuild()
{
	return m_pFuild;
}

inline Condition* SysProperties::GetCondition()
{
	return m_pCondition;
}
#endif // !defined(AFX_SYSPROPERTIES_H__5AED598C_D067_433E_9FBD_22AAE6538CF7__INCLUDED_)
