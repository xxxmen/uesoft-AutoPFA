// ControlValve.cpp: implementation of the ControlValve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "ControlValve.h"
#include "DlgControlValve.h"
#include "controlperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray ControlValve::s_StateName;
CBitmap ControlValve::m_bitmap;
const int ControlValve::m_nTypeID = 9;
CString ControlValve::s_typeName;
ArrayFlyWeight<5> ControlValve::ms_ControlSet;										
StrFlyWeight ControlValve::ms_ModelType;			
StrFlyWeight ControlValve::ms_KOrCv;				
ArrayFlyWeight<4> ControlValve::ms_failAction;
Transient    ControlValve::ms_Transient;
Transient    ControlValve::ms_FailTransient;
TransDataTable<3> ControlValve::ms_KorCvData;
	
ControlValve::ControlValve()
{
	m_nTran1Num = 0;
	m_nTran2Num = 0;
	m_nFailTran1Num = 0;
	m_nFailTran2Num = 0;
	m_nKorCvData = 0;
}

ControlValve::~ControlValve()
{

}

void ControlValve::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCONTROLSET,6,15);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,7,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCVTABLE,9,14,FALSE);
	ScenarioObject::InitAttr(s_StateName,10,13);
	ScenarioObject::InitAttr(s_StateName,11,33);

	ms_Transient.Instance(s_StateName,50);//50~61
	ms_FailTransient.Instance(s_StateName,62);//62~73
	m_bitmap.LoadBitmap(IDB_CONTROL);
	s_typeName.LoadString(IDS_STRCONTROL);
}


Component* ControlValve::CreatControlValve()
{
	ControlValve *pControlValve = new ControlValve;
	pControlValve->Init();
	ms_ControlSet.SetValue(1,2);
	pControlValve->SetValue(ms_ControlSet,6);
	ms_failAction.SetValue(1,1);
	ms_failAction.SetValue(1,3);
	pControlValve->SetValue(ms_failAction,9);
	return pControlValve;
}

ScenarioObject* ControlValve::DoClone()
{
	return new ControlValve(*this);
}

int ControlValve::GetID()
{
	return m_nTypeID;
}

CString ControlValve::GetTypeName()
{
	return s_typeName;
}

BOOL ControlValve::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	ControlPerisist *pControlPerisist = dynamic_cast<ControlPerisist*>(pPersistent);
	ASSERT(pControlPerisist != NULL);
	ms_ControlSet.SetData(pControlPerisist->ControlSet());
	ms_ModelType.SetValue(pControlPerisist->ModelType());
	ms_KOrCv.SetValue(pControlPerisist->KOrCv());
	ms_failAction.SetData(pControlPerisist->FailAction());
	ms_Transient.Read(pControlPerisist->m_TransPersistent);
	ms_FailTransient.Read(pControlPerisist->m_FailTransPersistent);
	ms_KorCvData.Read(pControlPerisist->m_KOrCvData);
	return Jun::Read(pPersistent);
}

BOOL ControlValve::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	ControlPerisist *pControlPerisist = dynamic_cast<ControlPerisist*>(pPersistent);
	ASSERT(pControlPerisist != NULL);
	

	pControlPerisist->ControlSet(ms_ControlSet.GetData());
	pControlPerisist->ModelType(ms_ModelType.GetValue());
	pControlPerisist->KOrCv(ms_KOrCv.GetValue());
	pControlPerisist->FailAction(ms_failAction.GetData());
	ms_Transient.Save(pControlPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	ms_FailTransient.Save(pControlPerisist->m_FailTransPersistent,m_nFailTran1Num,m_nFailTran2Num);
	ms_KorCvData.Save(pControlPerisist->m_KOrCvData,m_nKorCvData);
	return bRet;
}

BOOL ControlValve::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgControlValve dlg(UnitSys,*pManager,this);
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

void ControlValve::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_ControlSet,6);
	GetValue(ms_ModelType,7);
	GetValue(ms_KOrCv,8);
	GetValue(ms_failAction,9);
	GetValue(ms_KorCvData.m_Unit,10);
	GetValue(ms_KorCvData.m_Data,11);
	ms_Transient.InitData(this);
	ms_FailTransient.InitData(this);
}

void ControlValve::SaveData()
{
	// TODO: Add extra SaveData here

    SetValue(ms_ControlSet,6);
	SetValue(ms_ModelType,7);
	SetValue(ms_KOrCv,8);
	SetValue(ms_failAction,9);
	SetValue(ms_KorCvData.m_Unit,10);
	SetValue(ms_KorCvData.m_Data,11);
	m_nKorCvData = ms_KorCvData.Data().GetCount();
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
	ms_FailTransient.SaveData(this,m_nFailTran1Num,m_nFailTran2Num);

   Jun::SaveData();
}

BOOL ControlValve::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 2)
	{
		if(nKey >0 && !IsExistInPipe())
			return TRUE;
		if(nKey<0 && !IsExistOutPipe())
			return TRUE;
	}
	return FALSE;
}

void ControlValve::AddLinkPipeInfo(UINT nKey)
{

}

void ControlValve::DelLinkPipeInfo(UINT nKey)
{

}

void ControlValve::EmptyPipeInfo()
{

}

Transient* ControlValve::GetTransient()
{
	ms_FailTransient.InitData(this);
	return &ms_FailTransient;
}

void ControlValve::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<2)
		ref.Add(5);
	if(ms_ControlSet.GetValue(4).CompareNoCase(_T("None"))==0
		||ms_ControlSet.GetValue(3).IsEmpty())
		ref.Add(6);
	if(ms_ControlSet.GetnValue()!=3)
	{
		if(ms_ModelType.GetnValue()<0)
		{
			if(ms_KorCvData.Data().GetCount()==0)
				ref.Add(9);
		}
		else
		{
			if( ms_KOrCv.GetfValue()< 0 )
				ref.Add(8);
		}
	}
	
}
