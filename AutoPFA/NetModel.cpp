// NetModel.cpp: implementation of the NetModel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "NetModel.h"
#include "NetModelPersist.h"
#include "SteadySet.h"
#include "SectionSet.h"
#include "TransientSet.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NetModel::NetModel()
{

}

NetModel::NetModel(const NetModel &ref)
{
	m_calcManager = ref.m_calcManager;
	m_compManager = ref.m_compManager;
}

NetModel& NetModel::operator=(const NetModel &ref)
{
	if(this == &ref)
    {
		return *this;
    }
	
	m_calcManager = ref.m_calcManager;
	m_compManager = ref.m_compManager;

	return *this;
}
NetModel::~NetModel()
{

}

FlyWeight* NetModel::LookUp(int nObjectType,int nObjectKey, int nStateKey)
{
	if(nObjectType>=0 && nObjectType<20)
	{
		return m_compManager.LookUp(nObjectType,nObjectKey,nStateKey);
	}
	else
	{
		return m_calcManager.LookUp(nObjectType,nObjectKey,nStateKey);
	}
}

void NetModel::DelState()
{
	m_calcManager.DelState();
	m_compManager.DelState();
}

void NetModel::InitState(Scenario *pCurScenario)
{
	m_calcManager.InitState(pCurScenario);
	m_compManager.InitState(pCurScenario);
}

NetModel* NetModel::CloneChild()
{
	NetModel *pChild = new NetModel;
	pChild->m_calcManager.CloneChild(m_calcManager);
	pChild->m_compManager.CloneChild(m_compManager);
	return pChild;
}

void NetModel::Promote(const NetModel *pParent)
{
	m_calcManager.Promote(pParent->m_calcManager);
	m_compManager.Promote(pParent->m_compManager);
}

NetModel* NetModel::Clone()
{
	return new NetModel(*this);
}

BOOL NetModel::Read(NetModelPersist* pNet)
{
	m_compManager.Read(pNet->GetJunMgr());
    m_compManager.Read(pNet->GetPipesMgr());
	m_compManager.Read(pNet->GetSysProperty());
	m_calcManager.GetSteadySet()->Read(pNet->GetSteady());
	m_calcManager.GetSectionSet()->Read(pNet->GetSectionPipe());
	m_calcManager.GetTransientSet()->Read(pNet->GetTransControl());
	return TRUE;
}

BOOL NetModel::Save(NetModelPersist* pNet)
{
	m_compManager.Save(pNet->GetJunMgr());
    m_compManager.Save(pNet->GetPipesMgr());
	m_compManager.Save(pNet->GetSysProperty());
	m_calcManager.GetSteadySet()->Save(pNet->GetSteady());
	m_calcManager.GetSectionSet()->Save(pNet->GetSectionPipe());
	m_calcManager.GetTransientSet()->Save(pNet->GetTransControl());
	return TRUE;
}

void NetModel::CheckModel(BOOL bOK[],BOOL bTran)
{
	if(m_calcManager.GetSteadySet()->IsDefine())
		bOK[0] = TRUE;
	if(m_compManager.SysProperty().IsFuildDefine())
		bOK[1] = TRUE;
	if(m_compManager.IsAllJunDefine(bTran)&&m_compManager.IsAllPipeDefine(bTran))
		bOK[2] = TRUE;
	if(bOK[2]&&bTran&&m_calcManager.GetSectionSet()->IsSection(m_compManager))
		bOK[3] = TRUE;
	if(bOK[3]&&bTran&&m_calcManager.GetTransientSet()->IsDefine())
		bOK[4] = TRUE;
}
