// NetModelPersist.h: interface for the NetModelPersist class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETMODELPERSIST_H__620D4695_5A52_4A6F_BE64_4689D1FFB151__INCLUDED_)
#define AFX_NETMODELPERSIST_H__620D4695_5A52_4A6F_BE64_4689D1FFB151__INCLUDED_
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：NetModelPersist.h
  摘要： 管网模型持久化模型
  author  : LSP          
*/
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PipesManager.h"
#include "JunManager.h"
#include "SysProperty.h"
#include "SteadyPersistent.h"
#include "SectionPipePersistent.h"
#include "TransControlPerisistent.h"
#include "OutputRefPersist.h"


class AFX_EXT_CLASS NetModelPersist  
{
public:
	SectionPipePerisistent& GetSectionPipe();
	TransControlPerisistent& GetTransControl();
	SteadyPersistent& GetSteady();
	PropertyPersistent& GetSysProperty();
	OutputRefPersist& GetOutputRef();
	JunManager& GetJunMgr();
	PipesManager& GetPipesMgr();

	int Key();
	int ParentKey();
	CString Ancest();
	CString Name();
	void Key(int iKey);
	void ParentKey(int iParentKey);
	void Ancest(CString strAncest);
	void Name(CString strName);
	NetModelPersist();
	virtual ~NetModelPersist();

private:
	CString m_strName;
	CString m_strAncest;
	int     m_iKey;
	int     m_iParentKey;
	PipesManager m_pipesMgr;
	JunManager   m_junMgr;
	PropertyPersistent m_SysProperty;
	SteadyPersistent m_Steady;
	SectionPipePerisistent m_SectionPipe;
	TransControlPerisistent m_TransControl;
	OutputRefPersist m_OutputRef;
	
};

inline CString NetModelPersist::Name()
{
	return m_strName;
}

inline CString NetModelPersist::Ancest()
{
	return m_strAncest;
}

inline int NetModelPersist::Key()
{
	return m_iKey;
}

inline int NetModelPersist::ParentKey()
{
	return m_iParentKey;
}

inline void NetModelPersist::Name(CString strName)
{
	m_strName = strName;
}

inline  void NetModelPersist::Ancest(CString strAncest)
{
	m_strAncest = strAncest;
}

inline void NetModelPersist::Key(int iKey)
{
	m_iKey = iKey;
}

inline void NetModelPersist::ParentKey(int iParentKey)
{
	m_iParentKey = iParentKey;
}

inline PipesManager& NetModelPersist::GetPipesMgr()
{
	return m_pipesMgr;
}

inline JunManager& NetModelPersist::GetJunMgr()
{
	return m_junMgr;
}

inline PropertyPersistent& NetModelPersist::GetSysProperty()
{
	return m_SysProperty;
}

inline SteadyPersistent& NetModelPersist::GetSteady()
{
	return m_Steady;
}
inline SectionPipePerisistent& NetModelPersist::GetSectionPipe()
{
	return m_SectionPipe;
}
inline TransControlPerisistent& NetModelPersist::GetTransControl()
{
	return m_TransControl;
}
inline OutputRefPersist& NetModelPersist::GetOutputRef()
{
	return m_OutputRef;
}


#endif // !defined(AFX_NETMODELPERSIST_H__620D4695_5A52_4A6F_BE64_4689D1FFB151__INCLUDED_)
