// Reservoir.cpp: implementation of the Reservoir class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Reservoir.h"
#include "DlgReservoir.h"
#include "reservoirperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray Reservoir::s_StateName;
CBitmap Reservoir::m_bitmap;
const int Reservoir::m_nTypeID = 2;
CString Reservoir::s_typeName;
TableFlyWeight<6> Reservoir::ms_PipeInfo;
NumFlyWeight Reservoir::ms_EleOrDepthUnit;         
NumFlyWeight Reservoir::ms_SurfacePress;			
NumFlyWeight Reservoir::ms_Teamperature;			   
NumFlyWeight Reservoir::ms_Density;	
StrFlyWeight Reservoir::ms_EleOrDepthType;	
Transient    Reservoir::ms_Transient;			

Reservoir::Reservoir()
{
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}

Reservoir::~Reservoir()
{

}

void Reservoir::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,6,36);
	ScenarioObject::InitAttr(s_StateName,7,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSURFACEPRESS,8,2);
	ScenarioObject::InitAttr(s_StateName,IDS_FUILDTEMP,9,2);
	ScenarioObject::InitAttr(s_StateName,IDS_FUILDDEN,10,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPIPEDEPTH,11,1);
	ms_Transient.Instance(s_StateName,50);//50~61
	m_bitmap.LoadBitmap(IDB_RESVIOR);
	s_typeName.LoadString(IDS_STRRESERVIOR);
}


Component* Reservoir::CreatReservoir()
{
	Reservoir *pReservoir = new Reservoir;
	pReservoir->Init();
	pReservoir->SetSpecial(-1);
	return pReservoir;
}

ScenarioObject* Reservoir::DoClone()
{
	return new Reservoir(*this);
}

int Reservoir::GetID()
{
	return m_nTypeID;
}

CString Reservoir::GetTypeName()
{
	return s_typeName;
}

BOOL Reservoir::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	ReservoirPerisist *pReservoirPerisist = dynamic_cast<ReservoirPerisist*>(pPersistent);
	ASSERT(pReservoirPerisist != NULL);
	ms_PipeInfo.SetData(pReservoirPerisist->PipeInfo());
	ms_EleOrDepthUnit.SetData(pReservoirPerisist->EleOrDepth());
	ms_SurfacePress.SetData(pReservoirPerisist->SurfacePress());
	ms_Teamperature.SetData(pReservoirPerisist->Teamperature());
	ms_Density.SetData(pReservoirPerisist->Density());
	ms_EleOrDepthType.SetValue(pReservoirPerisist->EleOrDepthType());
	ms_Transient.Read(pReservoirPerisist->m_TransPersistent);
	return Jun::Read(pPersistent);
}

BOOL Reservoir::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	ReservoirPerisist *pReservoirPerisist = dynamic_cast<ReservoirPerisist*>(pPersistent);
	ASSERT(pReservoirPerisist != NULL);
	pReservoirPerisist->PipeInfo(ms_PipeInfo.GetData(),m_nLinkPipeNum);
	pReservoirPerisist->EleOrDepth(ms_EleOrDepthUnit.GetData());
	pReservoirPerisist->SurfacePress(ms_SurfacePress.GetData());
	pReservoirPerisist->Teamperature(ms_Teamperature.GetData());
	pReservoirPerisist->Density(ms_Density.GetData());
	pReservoirPerisist->EleOrDepthType(ms_EleOrDepthType.GetValue());
	ms_Transient.Save(pReservoirPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	return bRet;
}


BOOL Reservoir::Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnly)
{
	DlgReservoir dlg(UnitSys,*pManager,this);
	dlg.ReadOnly( bReadOnly );
	if(IDOK == dlg.DoModal())
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

void Reservoir::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_PipeInfo,6);
	GetValue(ms_EleOrDepthUnit,7);
	GetValue(ms_SurfacePress,8);
	GetValue(ms_Teamperature,9);
	GetValue(ms_Density,10);
	GetValue(ms_EleOrDepthType,11);
	ms_Transient.InitData(this);
}

void Reservoir::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_PipeInfo,6);
	SetValue(ms_EleOrDepthUnit,7);
	SetValue(ms_SurfacePress,8);
	SetValue(ms_Teamperature,9);
	SetValue(ms_Density,10);
	SetValue(ms_EleOrDepthType,11);
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL Reservoir::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 25)
	{
		return TRUE;
	}
	return FALSE;
}

void Reservoir::AddLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	nKey = abs((int)nKey);
	StrArray<6> item(nKey);
	ms_PipeInfo.AddItem(item,nKey);
	SetValue(ms_PipeInfo,6);
}

void Reservoir::DelLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,6);
	if(!(ms_PipeID.IsExist(nKey)||ms_PipeID.IsExist(-nKey)))
	{
		nKey = abs((int)nKey);
		ms_PipeInfo.DelItem(nKey);
		ms_PipeInfo.DelItem(-nKey);
	}
	SetValue(ms_PipeInfo,6);
}

void Reservoir::EmptyPipeInfo()
{
	ms_PipeInfo.Empty();
	SetValue(ms_PipeInfo,6);
}

Transient* Reservoir::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void Reservoir::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
	if(ms_SurfacePress.GetValue().IsEmpty()||ms_SurfacePress.GetUnit().CollateNoCase(_T("None"))==0)
		ref.Add(8);
	if(ms_InletEle.GetValue().IsEmpty()||ms_InletEle.GetUnit().CollateNoCase(_T("None"))==0)
		ref.Add(_T("表面标高"));
}
