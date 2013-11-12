// AssignedFlow.cpp: implementation of the AssignedFlow class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "AssignedFlow.h"
#include "DlgAssignedFlow.h"
#include "assignflowperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NameArray AssignedFlow::s_StateName;
CBitmap AssignedFlow::m_bitmap;
const int AssignedFlow::m_nTypeID = 3;
CString AssignedFlow::s_typeName;
ArrayFlyWeight<3> AssignedFlow::ms_Flow;			
StrFlyWeight      AssignedFlow::ms_FlowDir;		
StrFlyWeight      AssignedFlow::ms_K;				
ArrayFlyWeight<4> AssignedFlow::ms_InitPress;
Transient         AssignedFlow::ms_Transient;

AssignedFlow::AssignedFlow()
{
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}

AssignedFlow::~AssignedFlow()
{

}

void AssignedFlow::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFLOWRATE,6,13);//ms_Flow
	ScenarioObject::InitAttr(s_StateName,IDS_STRFLOWDIR,7,1);//ms_FlowDir
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,8,1);//ms_K
	ScenarioObject::InitAttr(s_StateName,IDS_STRINITPRESS,9,14);//ms_InitPress
	//50~61
	ms_Transient.Instance(s_StateName,50);
	
	m_bitmap.LoadBitmap(IDB_ASSIGNFLOW);
	s_typeName.LoadString(IDS_STRASSIGNFLOW);
}


Component* AssignedFlow::CreatAssignedFlow()
{
	AssignedFlow *pAssignedFlow = new AssignedFlow;
	pAssignedFlow->Init();
	return pAssignedFlow;
}

ScenarioObject* AssignedFlow::DoClone()
{
	return new AssignedFlow(*this);
}

int AssignedFlow::GetID()
{
	return m_nTypeID;
}

CString AssignedFlow::GetTypeName()
{
	return s_typeName;
}

BOOL AssignedFlow::Read(Junperisist *pPersistent)
{
	// TODO: Add extra initialization here
	AssignFlowPerisist *pAssignFlowPerisist = dynamic_cast<AssignFlowPerisist*>(pPersistent);
	ASSERT(pAssignFlowPerisist != NULL);
	ms_Flow.SetData(pAssignFlowPerisist->Flow());
	ms_FlowDir.SetValue(pAssignFlowPerisist->FlowDir());
	ms_K.SetValue(pAssignFlowPerisist->K());
	ms_InitPress.SetData(pAssignFlowPerisist->InitPress());
	ms_Transient.Read(pAssignFlowPerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL AssignedFlow::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra initialization here
	AssignFlowPerisist *pAssignFlowPerisist = dynamic_cast<AssignFlowPerisist*>(pPersistent);
	ASSERT(pAssignFlowPerisist != NULL);

	pAssignFlowPerisist->Flow(ms_Flow.GetData());
	pAssignFlowPerisist->FlowDir(ms_FlowDir.GetValue());
	pAssignFlowPerisist->K(ms_K.GetValue());
	pAssignFlowPerisist->InitPress(ms_InitPress.GetData());
	ms_Transient.Save(pAssignFlowPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	return bRet;
}

BOOL AssignedFlow::Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnly)
{
	DlgAssignedFlow dlg(UnitSys,*pManager,this);
	dlg.ReadOnly(bReadOnly);
	if(IDOK == dlg.DoModal())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void AssignedFlow::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Flow,6);
	GetValue(ms_FlowDir,7);
	GetValue(ms_K,8);
	GetValue(ms_InitPress,9);
	ms_Transient.InitData(this);
}

void AssignedFlow::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Flow,6);
	SetValue(ms_FlowDir,7);
	SetValue(ms_K,8);
	SetValue(ms_InitPress,9);
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL AssignedFlow::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 1)
	{
		return TRUE;
	}
	return FALSE;
}

void AssignedFlow::AddLinkPipeInfo(UINT nKey)
{

}

void AssignedFlow::DelLinkPipeInfo(UINT nKey)
{

}

void AssignedFlow::EmptyPipeInfo()
{

}

Transient* AssignedFlow::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void AssignedFlow::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
	if(IsExistOutPipe()&&ms_FlowDir.GetnValue()==1
		||IsExistInPipe()&&ms_FlowDir.GetnValue()==0)
		ref.Add(5);
	if(ms_Flow.GetfValue(1)<=0)
		ref.Add(6);
	if(ms_SpecialMark.GetnValue()==1
		&&ms_InitPress.GetfValue()==0)
	{
		ref.Add(9);
	}
}
