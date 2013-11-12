// Surge.cpp: implementation of the Surge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Surge.h"
#include "DlgSurge.h"
#include "surgeperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray Surge::s_StateName;
CBitmap Surge::m_bitmap;
const int Surge::m_nTypeID = 24;
CString Surge::s_typeName;
TableFlyWeight<4>Surge::ms_PipeInfo;
StrFlyWeight Surge::ms_DistanceUnit;
NumFlyWeight Surge::ms_SurgeHeight;					
NumFlyWeight Surge::ms_ConstArea;					
NumFlyWeight Surge::ms_SurfacePress;			
ArrayFlyWeight<5>  Surge::ms_Orifice;			
ArrayFlyWeight<10> Surge::ms_ShortPipe;			
StrFlyWeight       Surge::ms_OneWay;					
ArrayFlyWeight<4>  Surge::ms_Vessel;				
StrFlyWeight       Surge::ms_Variable;		
ArrayFlyWeight<3>  Surge::ms_InitSurfaceH;		
ArrayFlyWeight<5>  Surge::ms_CheckValve;
TransDataTable<2>  Surge::ms_AreaTable;				
Transient          Surge::ms_Transient;	

Surge::Surge()
{
	m_nTran1Num = 0;
	m_nTran2Num = 0;
	m_VariableAreaNum = 0;
}

Surge::~Surge()
{

}

void Surge::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,6,34);
	ScenarioObject::InitAttr(s_StateName,IDS_STRELEDELTAUNIT,7,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSURGEHEIGH,8,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCONSTAREA,9,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSURFACEPRESS,10,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRORIFICE,11,15,FALSE);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSHORTPIPE,12,20,FALSE);
	ScenarioObject::InitAttr(s_StateName,IDS_STRONEWAYTANK,13,1);
	ScenarioObject::InitAttr(s_StateName,14,14);
	ScenarioObject::InitAttr(s_StateName,15,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRINITHEIGHT,18,13);
	ScenarioObject::InitAttr(s_StateName,19,15);
	ScenarioObject::InitAttr(s_StateName,IDS_STRVARABLEAREA,20,12,FALSE);//TransDataTable     Surge::m_AreaTable;			
	ScenarioObject::InitAttr(s_StateName,21,32);//TransDataTable     Surge::m_AreaTable;			
	
	ms_Transient.Instance(s_StateName,50);//50~61
	m_bitmap.LoadBitmap(IDB_SURGE);
	s_typeName.LoadString(IDS_STRSURGE);
}


Component* Surge::CreatSurge()
{
	Surge *pSurge = new Surge;
	pSurge->Init();
	return pSurge;
}

ScenarioObject* Surge::DoClone()
{
	return new Surge(*this);
}

int Surge::GetID()
{
	return m_nTypeID;
}

CString Surge::GetTypeName()
{
    return s_typeName;
}

BOOL Surge::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Save here
	SurgePerisist *pSurgePerisist = dynamic_cast<SurgePerisist*>(pPersistent);
	ASSERT(pSurgePerisist != NULL);
	ms_PipeInfo.SetData(pSurgePerisist->PipeInfo());
	ms_DistanceUnit.SetValue(pSurgePerisist->DistanceUnit());
	ms_SurgeHeight.SetData(pSurgePerisist->SurgeHeight());
	ms_ConstArea.SetData(pSurgePerisist->ConstArea());
	ms_SurfacePress.SetData(pSurgePerisist->SurfacePress());
	ms_Orifice.SetData(pSurgePerisist->Orifice());
	ms_ShortPipe.SetData(pSurgePerisist->ShortPipe());
	ms_OneWay.SetValue(pSurgePerisist->OneWay());
	ms_Vessel.SetData(pSurgePerisist->Vessel());
	ms_Variable.SetValue(pSurgePerisist->Variable());
	ms_InitSurfaceH.SetData(pSurgePerisist->InitSurfaceH());
	ms_CheckValve.SetData(pSurgePerisist->Check());
	ms_AreaTable.Read(pSurgePerisist->m_AreaTable);
	ms_Transient.Read(pSurgePerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL Surge::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	SurgePerisist *pSurgePerisist = dynamic_cast<SurgePerisist*>(pPersistent);
	ASSERT(pSurgePerisist != NULL);
	pSurgePerisist->PipeInfo(ms_PipeInfo.GetData(),m_nLinkPipeNum);
	pSurgePerisist->DistanceUnit(ms_DistanceUnit.GetValue());
	pSurgePerisist->SurgeHeight(ms_SurgeHeight.GetData());
	pSurgePerisist->ConstArea(ms_ConstArea.GetData());
	pSurgePerisist->SurfacePress(ms_SurfacePress.GetData());
	pSurgePerisist->Orifice(ms_Orifice.GetData());
	pSurgePerisist->ShortPipe(ms_ShortPipe.GetData());
	pSurgePerisist->OneWay(ms_OneWay.GetValue());
	pSurgePerisist->Vessel(ms_Vessel.GetData());
	pSurgePerisist->Variable(ms_Variable.GetValue());
	pSurgePerisist->InitSurfaceH(ms_InitSurfaceH.GetData());
	pSurgePerisist->Check(ms_CheckValve.GetData());
	ms_AreaTable.Save(pSurgePerisist->m_AreaTable,m_VariableAreaNum);
	ms_Transient.Save(pSurgePerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	return bRet;
}


BOOL Surge::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgSurge dlg(UnitSys,*pManager,this);
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

void Surge::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_PipeInfo,6);
	GetValue(ms_DistanceUnit,7);
	GetValue(ms_SurgeHeight,8);
	GetValue(ms_ConstArea,9);
	GetValue(ms_SurfacePress,10);
	GetValue(ms_Orifice,11);
	GetValue(ms_ShortPipe,12);
	GetValue(ms_OneWay,13);
	GetValue(ms_Vessel,14);
	GetValue(ms_Variable,15);
	GetValue(ms_InitSurfaceH,18);
	GetValue(ms_CheckValve,19);
	GetValue(ms_AreaTable.m_Unit,20);
	GetValue(ms_AreaTable.m_Data,21);
	ms_Transient.InitData(this);
}

void Surge::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_PipeInfo,6);
	SetValue(ms_DistanceUnit,7);
	SetValue(ms_SurgeHeight,8);
	SetValue(ms_ConstArea,9);
	SetValue(ms_SurfacePress,10);
	SetValue(ms_Orifice,11);
	SetValue(ms_ShortPipe,12);
	SetValue(ms_OneWay,13);
	SetValue(ms_Vessel,14);
	SetValue(ms_Variable,15);
	SetValue(ms_InitSurfaceH,18);
	SetValue(ms_CheckValve,19);
	SetValue(ms_AreaTable.m_Unit,20);
	SetValue(ms_AreaTable.m_Data,21);
	m_VariableAreaNum = ms_AreaTable.m_Data.GetCount();
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL Surge::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 25)
	{
		return TRUE;
	}
	return FALSE;
}

void Surge::AddLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	AddPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,6);
}

void Surge::DelLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	DelPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,6);
}

void Surge::EmptyPipeInfo()
{
	ms_PipeInfo.Empty();
	SetValue(ms_PipeInfo,6);
}

Transient* Surge::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void Surge::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
	if(ms_Variable.GetnValue()==0)
	{
		if(ms_ConstArea.GetfValue()<=0)
			ref.Add(9);
	}
	else
	{
		if(ms_AreaTable.Data().GetCount()==0)
			ref.Add(20);
	}
	if(ms_SurfacePress.GetUnit().CompareNoCase(_T("None"))==0
		||ms_SurfacePress.GetValue().IsEmpty())
	{
		ref.Add(10);
	}
	
	if(abs(ms_Orifice.GetnValue())==1)
	{
		if(ms_Orifice.GetfValue(1)<=0
		||ms_Orifice.GetfValue(2)<=0
		||ms_Orifice.GetfValue(3)<=0)
		{
			ref.Add(11);
		}
	}
	if(abs(ms_ShortPipe.GetnValue())==1)
	{
		if(ms_ShortPipe.GetfValue(1)<=0
		||ms_ShortPipe.GetfValue(2)<=0
		||ms_ShortPipe.GetfValue(4)<=0
		||ms_ShortPipe.GetfValue(6)<=0)
		{
			ref.Add(12);
		}
	}

	if(abs(ms_OneWay.GetnValue())==1)
	{
		if(ms_CheckValve.GetfValue(3)<=0)
			ref.Add(13);
		if(abs(ms_InitSurfaceH.GetnValue())==0
			||ms_InitSurfaceH.GetfValue(1)<=0)
		{
			ref.Add(18);
		}
	}
}
