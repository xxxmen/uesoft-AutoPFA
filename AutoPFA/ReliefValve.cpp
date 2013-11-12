// ReliefValve.cpp: implementation of the ReliefValve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "ReliefValve.h"
#include "DlgReliefValve.h"
#include "reliefperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray ReliefValve::s_StateName;
CBitmap ReliefValve::m_bitmap;
const int ReliefValve::m_nTypeID = 21;
CString ReliefValve::s_typeName;

StrFlyWeight ReliefValve::ms_Type;
ArrayFlyWeight<13> ReliefValve::ms_Curve;
ArrayFlyWeight<5>  ReliefValve::ms_CrackExitPress;
StrFlyWeight ReliefValve::ms_KOrCv;
ArrayFlyWeight<3> ReliefValve::ms_BasisArea;
Transient    ReliefValve::ms_Transient;

ReliefValve::ReliefValve()
{
	m_nCurve = 5;
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}

ReliefValve::~ReliefValve()
{

}

void ReliefValve::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,7,23);
	ScenarioObject::InitAttr(s_StateName,IDS_STR_CRACKEXITPRESS,8,15);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,9,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STBASISAREA,10,13);
	ms_Transient.Instance(s_StateName,50);//50~61
	m_bitmap.LoadBitmap(IDB_RELIEF);
	s_typeName.LoadString(IDS_STRRELIEF);
}


Component* ReliefValve::CreatReliefValve()
{
	ReliefValve *pReliefValve = new ReliefValve;
	pReliefValve->Init();

	ms_Type.SetValue(1);
	pReliefValve->SetValue(ms_Type,6);
	return pReliefValve;
}

ScenarioObject* ReliefValve::DoClone()
{
	return new ReliefValve(*this);
}

int ReliefValve::GetID()
{
	return m_nTypeID;
}

CString ReliefValve::GetTypeName()
{
	return s_typeName;
}

BOOL ReliefValve::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	ReliefPerisist *pReliefPerisist = dynamic_cast<ReliefPerisist*>(pPersistent);
	ASSERT(pReliefPerisist != NULL);
	ms_Type.SetValue(pReliefPerisist->Type());
	ms_Curve.SetData(pReliefPerisist->Curve());
	ms_CrackExitPress.SetData(pReliefPerisist->CrackExitPress());
	ms_KOrCv.SetValue(pReliefPerisist->KOrCv());
	ms_BasisArea.SetData(pReliefPerisist->BasisArea());
	ms_Transient.Read(pReliefPerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL ReliefValve::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	ReliefPerisist *pReliefPerisist = dynamic_cast<ReliefPerisist*>(pPersistent);
	ASSERT(pReliefPerisist != NULL);
	ms_Curve.SetValue(m_nCurve,7);//子工况应用父工况数据需要保存参数个数。
	
	pReliefPerisist->Type(ms_Type.GetValue());
	pReliefPerisist->Curve(ms_Curve.GetData());
	pReliefPerisist->CrackExitPress(ms_CrackExitPress.GetData());
	pReliefPerisist->KOrCv(ms_KOrCv.GetValue());
	pReliefPerisist->BasisArea(ms_BasisArea.GetData());
	ms_Transient.Save(pReliefPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	return bRet;
}


BOOL ReliefValve::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgReliefValve dlg(UnitSys,*pManager,this);
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

void ReliefValve::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Type,6);
	GetValue(ms_Curve,7);
	GetValue(ms_CrackExitPress,8);
	GetValue(ms_KOrCv,9);
	GetValue(ms_BasisArea,10);
	ms_Transient.InitData(this);
}

void ReliefValve::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Type,6);
	SetValue(ms_Curve,7);
	SetValue(ms_CrackExitPress,8);
	SetValue(ms_KOrCv,9);
	SetValue(ms_BasisArea,10);
	m_nCurve = ms_Curve.GetnValue(7);//曲线参数个数，子工况需要
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL ReliefValve::CanLink(int nMaxLink,int nKey)
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

void ReliefValve::AddLinkPipeInfo(UINT nKey)
{
//Empty
}

void ReliefValve::DelLinkPipeInfo(UINT nKey)
{
//Empty
}

void ReliefValve::EmptyPipeInfo()
{
//Empty
}

Transient* ReliefValve::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void ReliefValve::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_Type.GetnValue()==2)
	{
		if(!IsExistInPipe()||IsExistOutPipe())
			ref.Add(5);
	}
	else
	{
		if(ms_PipeID.GetCount()<2)
			ref.Add(5);
	}
	if(ms_CrackExitPress.GetValue(2).CompareNoCase(_T("None"))==0
		||ms_CrackExitPress.GetValue(1).IsEmpty())
	{
		ref.Add(_T("破裂压力"));
	}
	if(ms_Type.GetnValue()!=1
		&&(ms_CrackExitPress.GetValue(4).CompareNoCase(_T("None"))==0
		||ms_CrackExitPress.GetValue(3).IsEmpty()))
	{
		ref.Add(_T("出口压力"));
	}

	if(ms_Curve.GetnValue()==2)
	{
		if(ms_RawData.Data().GetCount()==0)
			ref.Add(_T("变流量系数数据"));
	}
	else
	{
		if( ms_KOrCv.GetfValue()<= 0 || ms_KOrCv.IsEmpty() )
			ref.Add(9);
	}
}
