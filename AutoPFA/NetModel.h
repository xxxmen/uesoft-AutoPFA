// NetModel.h: interface for the NetModel class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称： NetModel.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETMODEL_H__BB8ED939_8192_40BE_BF22_266D81C3D612__INCLUDED_)
#define AFX_NETMODEL_H__BB8ED939_8192_40BE_BF22_266D81C3D612__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ComponentManager.h"
#include "CalcManager.h"

class Scenario;
class FlyWeight;
class NetModelPersist;

class NetModel  
{
public:
	NetModel();
	NetModel(const NetModel &ref);
	NetModel& operator=(const NetModel &ref);
	virtual ~NetModel();

	NetModel* Clone();
	void Promote(const NetModel *pParent);
	NetModel* CloneChild();
	void InitState(Scenario *pCurScenario);
	FlyWeight* LookUp(int nObjectType,int nObjectKey, int nStateKey);
	void DelState();

public:
	void CheckModel(BOOL bOK[],BOOL bTran);
	BOOL Read(NetModelPersist* pNet);
	BOOL Save(NetModelPersist* pNet);
	CalcManager m_calcManager;
	ComponentManager m_compManager;

};

#endif // !defined(AFX_NETMODEL_H__BB8ED939_8192_40BE_BF22_266D81C3D612__INCLUDED_)
