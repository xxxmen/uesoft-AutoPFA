// AssignedPressure.cpp: implementation of the AssignedPressure class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "AssignedPressure.h"
#include "DlgAssigPress.h"
#include "assignpressperisist.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NameArray AssignedPressure::s_StateName;
CBitmap AssignedPressure::m_bitmap;
const int AssignedPressure::m_nTypeID = 4;
CString AssignedPressure::s_typeName;
TableFlyWeight<4>AssignedPressure::ms_PipeInfo;
ArrayFlyWeight<3> AssignedPressure::ms_Pressure;
StrFlyWeight AssignedPressure::ms_DistanceUnit;
Transient    AssignedPressure::ms_Transient;

AssignedPressure::AssignedPressure()
{
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}

AssignedPressure::~AssignedPressure()
{

}

void AssignedPressure::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,6,34);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPRESSURE,7,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRELEDELTAUNIT,8,1);
	
	//50~61
	ms_Transient.Instance(s_StateName,50);

	m_bitmap.LoadBitmap(IDB_ASSIGNPRESS);
	s_typeName.LoadString(IDS_STRASSIGNPRESS);
}

Component* AssignedPressure::CreatAssignedPressure()
{
	AssignedPressure *pAssignedPressure = new AssignedPressure;
	pAssignedPressure->Init();
	pAssignedPressure->SetSpecial(-1);
	return pAssignedPressure;
}

ScenarioObject* AssignedPressure::DoClone()
{
	return new AssignedPressure(*this);
}

int AssignedPressure::GetID()
{
	return m_nTypeID;
}

CString AssignedPressure::GetTypeName()
{
    return s_typeName;
}

BOOL AssignedPressure::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	AssignPressPerisist *pAssignPressPerisist = dynamic_cast<AssignPressPerisist*>(pPersistent);
	ASSERT(pAssignPressPerisist != NULL);
	ms_PipeInfo.SetData(pAssignPressPerisist->PipeInfo());
	ms_DistanceUnit.SetValue(pAssignPressPerisist->DistanceUnit());
	ms_Pressure.SetData(pAssignPressPerisist->Pressure());
	ms_Transient.Read(pAssignPressPerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL AssignedPressure::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
    AssignPressPerisist *pAssignPressPerisist = dynamic_cast<AssignPressPerisist*>(pPersistent);
	ASSERT(pAssignPressPerisist != NULL);

	pAssignPressPerisist->PipeInfo(ms_PipeInfo.GetData(),m_nLinkPipeNum);
	pAssignPressPerisist->DistanceUnit(ms_DistanceUnit.GetValue());
	pAssignPressPerisist->Pressure(ms_Pressure.GetData());
	ms_Transient.Save(pAssignPressPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	return bRet;
}

BOOL AssignedPressure::Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnly)
{
	DlgAssigPress dlg(UnitSys,*pManager,this);
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

void AssignedPressure::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_PipeInfo,6);
	GetValue(ms_Pressure,7);
	GetValue(ms_DistanceUnit,8);
	ms_Transient.InitData(this);
	
}

void AssignedPressure::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_PipeInfo,6);
	SetValue(ms_Pressure,7);
	SetValue(ms_DistanceUnit,8);
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL AssignedPressure::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 25)
	{
		return TRUE;
	}
	return FALSE;
}

void AssignedPressure::AddLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	AddPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,6);
}

void AssignedPressure::DelLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	DelPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,6);
}

void AssignedPressure::EmptyPipeInfo()
{
	ms_PipeInfo.Empty();
	SetValue(ms_PipeInfo,6);
}

Transient* AssignedPressure::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void AssignedPressure::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
	if(ms_Pressure.GetnValue()==1&&ms_PipeID.GetCount()>1)
		ref.Add(5);//静止压力只能与一跟管道连接
	if(ms_Pressure.GetValue(2).CompareNoCase(_T("None"))==0
		||ms_Pressure.GetValue(1).IsEmpty())
	{
		ref.Add(7);
	}
}
