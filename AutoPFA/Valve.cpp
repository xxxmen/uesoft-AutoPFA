// Valve.cpp: implementation of the Valve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Valve.h"
#include "DlgValve.h"
#include "valveperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray Valve::s_StateName;
CBitmap Valve::m_bitmap;
const int Valve::m_nTypeID = 8;
CString Valve::s_typeName;

StrFlyWeight Valve::ms_Type;
ArrayFlyWeight<13> Valve::ms_Curve;
ArrayFlyWeight<3>  Valve::ms_ExitPress;
StrFlyWeight Valve::ms_KOrCv;
ArrayFlyWeight<3> Valve::ms_BasisArea;
Transient    Valve::ms_Transient;

Valve::Valve()
{
	m_nCurve = 5;
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}

Valve::~Valve()
{

}

void Valve::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,7,23);
	ScenarioObject::InitAttr(s_StateName,IDS_STREXITPRESS,8,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,9,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STBASISAREA,10,13);
	ms_Transient.Instance(s_StateName,50);//50~61
	m_bitmap.LoadBitmap(IDB_VALVE);
	s_typeName.LoadString(IDS_STRVALVE);
}


Component* Valve::CreatValve()
{
	Valve *pValve = new Valve;
	pValve->Init();
	InitCurve(ms_Curve);
	pValve->SetValue(ms_Curve,7);
	return pValve;
}

ScenarioObject* Valve::DoClone()
{
	return new Valve(*this);
}

int Valve::GetID()
{
	return m_nTypeID;
}

CString Valve::GetTypeName()
{
    return s_typeName;
}

BOOL Valve::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	ValvePerisist *pValvePerisist = dynamic_cast<ValvePerisist*>(pPersistent);
	ASSERT(pValvePerisist != NULL);
	ms_Type.SetValue(pValvePerisist->Type());
	ms_Curve.SetData(pValvePerisist->Curve());
	ms_ExitPress.SetData(pValvePerisist->ExitPress());
	ms_KOrCv.SetValue(pValvePerisist->KOrCv());
	ms_BasisArea.SetData(pValvePerisist->BasisArea());
	ms_Transient.Read(pValvePerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL Valve::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	ValvePerisist *pValvePerisist = dynamic_cast<ValvePerisist*>(pPersistent);
	ASSERT(pValvePerisist != NULL);
	ms_Curve.SetValue(m_nCurve,7);//子工况引用父工况数据需要保存参数个数。
	
	pValvePerisist->Type(ms_Type.GetValue());
	pValvePerisist->Curve(ms_Curve.GetData());
	pValvePerisist->ExitPress(ms_ExitPress.GetData());
	pValvePerisist->KOrCv(ms_KOrCv.GetValue());
	pValvePerisist->BasisArea(ms_BasisArea.GetData());
	ms_Transient.Save(pValvePerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	return bRet;
}


BOOL Valve::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgValve dlg(UnitSys,*pManager,this);
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

void Valve::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Type,6);
	GetValue(ms_Curve,7);
	GetValue(ms_ExitPress,8);
	GetValue(ms_KOrCv,9);
	GetValue(ms_BasisArea,10);
	ms_Transient.InitData(this);

}

void Valve::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Type,6);
	SetValue(ms_Curve,7);
	SetValue(ms_ExitPress,8);
	SetValue(ms_KOrCv,9);
	SetValue(ms_BasisArea,10);
	m_nCurve = ms_Curve.GetnValue(7);//曲线参数个数，子工况需要
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL Valve::CanLink(int nMaxLink,int nKey)
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

void Valve::AddLinkPipeInfo(UINT nKey)
{

}

void Valve::DelLinkPipeInfo(UINT nKey)
{

}

void Valve::EmptyPipeInfo()
{

}

Transient* Valve::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void Valve::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(abs(ms_Type.GetnValue())==1)
	{
		if(!IsExistInPipe()||IsExistOutPipe())
			ref.Add(5);
		if(ms_ExitPress.GetValue(2).CompareNoCase(_T("None"))==0
		||ms_ExitPress.GetValue(1).IsEmpty())
		{
			ref.Add(8);
		}
	}
	else
	{
		if(ms_PipeID.GetCount()<2)
			ref.Add(5);
	}
	
	if ( ms_Curve.GetnValue() == 0 )
	{
		if(ms_KOrCv.GetfValue()<=0 || ms_KOrCv.IsEmpty() )
		ref.Add(9);
	}
	else
	{
		if(ms_KOrCv.GetfValue()<0 || ms_KOrCv.IsEmpty() )
		ref.Add(9);
	}
}
