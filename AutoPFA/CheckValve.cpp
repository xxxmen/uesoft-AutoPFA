// CheckValve.cpp: implementation of the CheckValve class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "CheckValve.h"
#include "DlgCheckValve.h"
#include "checkperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray CheckValve::s_StateName;
CBitmap CheckValve::m_bitmap;
const int CheckValve::m_nTypeID = 10;
CString CheckValve::s_typeName;

ArrayFlyWeight<13> CheckValve::ms_Curve;
ArrayFlyWeight<3>  CheckValve::ms_ReOpenPress;
StrFlyWeight CheckValve::ms_KOrCv;
ArrayFlyWeight<3> CheckValve::ms_BasisArea;
NumFlyWeight CheckValve::ms_CloseVel;
Transient    CheckValve::ms_Transient;

CheckValve::CheckValve()
{
	m_nCurve = 5;
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}

CheckValve::~CheckValve()
{

}

void CheckValve::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,6,23);
	ScenarioObject::InitAttr(s_StateName,IDS_STRREOPENPRESS,7,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STBASISAREA,9,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCLOSEVALVE,10,2);
	ms_Transient.Instance(s_StateName,50);//50~61

	m_bitmap.LoadBitmap(IDB_CHECK);
	s_typeName.LoadString(IDS_STRCHECK);
}


Component* CheckValve::CreatCheckValve()
{
	CheckValve *pCheckValve = new CheckValve;
	pCheckValve->Init();
	return pCheckValve;
}

ScenarioObject* CheckValve::DoClone()
{
	return new CheckValve(*this);
}

int CheckValve::GetID()
{
	return m_nTypeID;
}

CString CheckValve::GetTypeName()
{
	return s_typeName;
}

BOOL CheckValve::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	CheckPerisist *pCheckPerisist = dynamic_cast<CheckPerisist*>(pPersistent);
	ASSERT(pCheckPerisist != NULL);
	ms_Curve.SetData(pCheckPerisist->Curve());
	ms_ReOpenPress.SetData(pCheckPerisist->ReOpenPress());
	ms_KOrCv.SetValue(pCheckPerisist->KOrCv());
	ms_BasisArea.SetData(pCheckPerisist->BasisArea());
	ms_CloseVel.SetData(pCheckPerisist->CloseVel());
	ms_Transient.Read(pCheckPerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL CheckValve::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	CheckPerisist *pCheckPerisist = dynamic_cast<CheckPerisist*>(pPersistent);
	ASSERT(pCheckPerisist != NULL);
	ms_Curve.SetValue(m_nCurve,7);//子工况应用父工况数据需要保存参数个数。
	
	pCheckPerisist->Curve(ms_Curve.GetData());
	pCheckPerisist->ReOpenPress(ms_ReOpenPress.GetData());
	pCheckPerisist->KOrCv(ms_KOrCv.GetValue());
	pCheckPerisist->BasisArea(ms_BasisArea.GetData());
	pCheckPerisist->CloseVel(ms_CloseVel.GetData());
	ms_Transient.Save(pCheckPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	return bRet;
}

BOOL CheckValve::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgCheckValve dlg(UnitSys,*pManager,this);
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

void CheckValve::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Curve,6);
	GetValue(ms_ReOpenPress,7);
	GetValue(ms_KOrCv,8);
	GetValue(ms_BasisArea,9);
	GetValue(ms_CloseVel,10);
	ms_Transient.InitData(this);
}

void CheckValve::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Curve,6);
	SetValue(ms_ReOpenPress,7);
	SetValue(ms_KOrCv,8);
	SetValue(ms_BasisArea,9);
	SetValue(ms_CloseVel,10);
	m_nCurve = ms_Curve.GetnValue(7);//曲线参数个数，子工况需要
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL CheckValve::CanLink(int nMaxLink,int nKey)
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

void CheckValve::AddLinkPipeInfo(UINT nKey)
{

}

void CheckValve::DelLinkPipeInfo(UINT nKey)
{

}

void CheckValve::EmptyPipeInfo()
{

}

Transient* CheckValve::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void CheckValve::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<2)
		ref.Add(5);
	if( ms_KOrCv.GetfValue()<= 0 || ms_KOrCv.IsEmpty() )
		ref.Add(8);
	if(ms_ReOpenPress.GetfValue(1)<=0)
		ref.Add(7);

}
