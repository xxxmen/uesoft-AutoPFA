// General.cpp: implementation of the General class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "General.h"
#include "DlgGeneral.h"
#include "generalperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray General::s_StateName;
CBitmap General::m_bitmap;
const int General::m_nTypeID = 20;
CString General::s_typeName;

StrFlyWeight General::ms_Type;
ArrayFlyWeight<13> General::ms_Curve;
StrFlyWeight General::ms_KOrCv;
ArrayFlyWeight<3> General::ms_BasisArea;


General::General()
{
	m_nCurve = 5;
}

General::~General()
{

}

void General::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,7,23);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STBASISAREA,9,13);

	m_bitmap.LoadBitmap(IDB_GENERAL);
	s_typeName.LoadString(IDS_STRGENERAL);
}


Component* General::CreatGeneral()
{
	General *pGeneral = new General;
	pGeneral->Init();
	pGeneral->SetSpecial(-1);
	return pGeneral;
}

ScenarioObject* General::DoClone()
{
	return new General(*this);
}

int General::GetID()
{
	return m_nTypeID;
}

CString General::GetTypeName()
{
	return s_typeName;
}

BOOL General::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	GeneralPerisist *pGeneralPerisist = dynamic_cast<GeneralPerisist*>(pPersistent);
	ASSERT(pGeneralPerisist != NULL);
	ms_Type.SetValue(pGeneralPerisist->Type());
	ms_Curve.SetData(pGeneralPerisist->Curve());
	ms_KOrCv.SetValue(pGeneralPerisist->KOrCv());
	ms_BasisArea.SetData(pGeneralPerisist->BasisArea());
	return Jun::Read(pPersistent);
}

BOOL General::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	GeneralPerisist *pGeneralPerisist = dynamic_cast<GeneralPerisist*>(pPersistent);
	ASSERT(pGeneralPerisist != NULL);
	ms_Curve.SetValue(m_nCurve,7);//子工况应用父工况数据需要保存参数个数。

	pGeneralPerisist->Type(ms_Type.GetValue());
	pGeneralPerisist->Curve(ms_Curve.GetData());
	pGeneralPerisist->KOrCv(ms_KOrCv.GetValue());
	pGeneralPerisist->BasisArea(ms_BasisArea.GetData());
	return bRet;
}

BOOL General::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgGeneral dlg(UnitSys,*pManager,this);
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

void General::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Type,6);
	GetValue(ms_Curve,7);
	GetValue(ms_KOrCv,8);
	GetValue(ms_BasisArea,9);
}

void General::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Type,6);
	SetValue(ms_Curve,7);
	SetValue(ms_KOrCv,8);
	SetValue(ms_BasisArea,9);
	m_nCurve = ms_Curve.GetnValue(7);//曲线参数个数，子工况需要
   Jun::SaveData();
}

BOOL General::CanLink(int nMaxLink,int nKey)
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

void General::AddLinkPipeInfo(UINT nKey)
{

}

void General::DelLinkPipeInfo(UINT nKey)
{

}

void General::EmptyPipeInfo()
{

}



void General::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<2)
		ref.Add(5);
	if(ms_Curve.GetnValue()==1)
	{
		if(ms_KOrCv.GetfValue()<0)
			ref.Add(8);
	}
	else
	{
		if(ms_RawData.Data().GetCount()==0)
			ref.Add(8);
	}
}
