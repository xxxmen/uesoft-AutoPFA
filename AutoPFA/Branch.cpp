// Branch.cpp: implementation of the Branch class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Branch.h"
#include "DlgBranch.h"
#include "branchperisist.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NameArray Branch::s_StateName;
CBitmap Branch::m_bitmap;
const int Branch::m_nTypeID = 1;
CString Branch::s_typeName;
TableFlyWeight<4> Branch::ms_PipeInfo;
ArrayFlyWeight<3> Branch::ms_ImposeFlow;
StrFlyWeight Branch::ms_DistanceUnit;
Transient    Branch::ms_Transient;

Branch::Branch()
{
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}
//Branch::Branch(const Branch &ref):Jun(ref)
//{
//}
//
//Branch& Branch::operator=(const Branch &ref)
//{
//	//判断自赋值
//	if(this == &ref)
//		return *this;
//    //调用基类赋值
//	Jun::operator =(ref);
//	//释放堆内存
//	//重新分配堆内存
//	//赋值
//	return *this;
//}
Branch::~Branch()
{

}

void Branch::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,6,34);
	ScenarioObject::InitAttr(s_StateName,IDS_STRIMPOSEFLOE,7,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRELEDELTAUNIT,8,1);
    
	ms_Transient.Instance(s_StateName,50);//50~61
	
	m_bitmap.LoadBitmap(IDB_BRANCH);
	s_typeName.LoadString(IDS_STRBRANCH);
}


Component* Branch::CreatBranch()
{
	Branch *pBranch = new Branch;
	pBranch->Init();
	pBranch->SetSpecial(-1);
	return pBranch;
}

ScenarioObject* Branch::DoClone()
{
	return new Branch(*this);
}

int Branch::GetID()
{
	return m_nTypeID;
}

CString Branch::GetTypeName()
{
	return s_typeName;
}

BOOL Branch::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	BranchPerisist *pBranchPerisist = dynamic_cast<BranchPerisist*>(pPersistent);
	ASSERT(pBranchPerisist != NULL);
	ms_PipeInfo.SetData(pBranchPerisist->PipeInfo());
	ms_ImposeFlow.SetData(pBranchPerisist->ImposeFlow());
	ms_DistanceUnit.SetValue(pBranchPerisist->DistanceUnit());
	ms_Transient.Read(pBranchPerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL Branch::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	BranchPerisist *pBranchPerisist = dynamic_cast<BranchPerisist*>(pPersistent);
	ASSERT(pBranchPerisist != NULL);
	pBranchPerisist->PipeInfo(ms_PipeInfo.GetData(),m_nLinkPipeNum);
	pBranchPerisist->ImposeFlow(ms_ImposeFlow.GetData());
	pBranchPerisist->DistanceUnit(ms_DistanceUnit.GetValue());
	ms_Transient.Save(pBranchPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	
	return bRet;
}

BOOL Branch::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgBranch dlg(UnitSys,*pManager,this);
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

void Branch::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_PipeInfo,6);
	GetValue(ms_ImposeFlow,7);
	GetValue(ms_DistanceUnit,8);
	ms_Transient.InitData(this);
}

void Branch::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_PipeInfo,6);
	SetValue(ms_ImposeFlow,7);
	SetValue(ms_DistanceUnit,8);
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL Branch::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 25)
	{
		return TRUE;
	}
	return FALSE;
}

void Branch::AddLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	AddPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,6);
}

void Branch::DelLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	DelPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,6);
}

void Branch::EmptyPipeInfo()
{
	ms_PipeInfo.Empty();
	SetValue(ms_PipeInfo,6);
}

Transient* Branch::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void Branch::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
}
