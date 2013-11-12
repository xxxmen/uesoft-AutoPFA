// ScenariManage.h: interface for the ScenariManage class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：ScenariManage.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SCENARIMANAGE_H__93FCE3C6_3635_4257_955A_B34B800C525B__INCLUDED_)
#define AFX_SCENARIMANAGE_H__93FCE3C6_3635_4257_955A_B34B800C525B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class Scenario;
class ScenarioPersistMgr;

class ScenariManage  
{
public:
	BOOL Read(ScenarioPersistMgr &Persistent);
	BOOL Save(ScenarioPersistMgr &Persistent);
	BOOL SaveCurModel(ScenarioPersistMgr &Persistent,Scenario *pScenario);
	Scenario* LookUp(int nKey);
	BOOL Promote(Scenario* pScenario);
	BOOL DelScenario(Scenario* pScenario);
	Scenario* CloneWithChild(Scenario* pScenario,CString strName);
	Scenario* CloneWithOutChild(Scenario* pScenario,CString strName);
	Scenario* AddChildScenario(Scenario* pScenario,CString strName);
	void SetCurScenario(Scenario* pScenario);

	Scenario* GetCurScenario();
	Scenario* GetBaseScenario();
	CString GetCurAncestName();
	ScenariManage();
	virtual ~ScenariManage();

private:
	BOOL Save(ScenarioPersistMgr &Persistent,Scenario *pScenario);
	ScenariManage(const ScenariManage &ref);
	ScenariManage& operator=(const ScenariManage &ref);
	Scenario *m_pBaseScenario;
	Scenario *m_pCurScenario;
};

inline Scenario* ScenariManage::GetBaseScenario()
{
	return m_pBaseScenario;
}

inline Scenario* ScenariManage::GetCurScenario()
{
	return m_pCurScenario;
}
#endif // !defined(AFX_SCENARIMANAGE_H__93FCE3C6_3635_4257_955A_B34B800C525B__INCLUDED_)
