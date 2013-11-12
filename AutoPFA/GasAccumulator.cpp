// GasAccumulator.cpp: implementation of the GasAccumulator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "GasAccumulator.h"
#include "DlgGasAccum.h"
#include "gasaccumperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray GasAccumulator::s_StateName;
CBitmap GasAccumulator::m_bitmap;
const int GasAccumulator::m_nTypeID = 22;
CString GasAccumulator::s_typeName;

StrFlyWeight GasAccumulator::ms_Polytropic;				
NumFlyWeight GasAccumulator::ms_InitVolume;				
ArrayFlyWeight<5> GasAccumulator::ms_Orifice;			
ArrayFlyWeight<10> GasAccumulator::ms_ShortPipe;											
ArrayFlyWeight<4> GasAccumulator::ms_InitPress;	
StrFlyWeight GasAccumulator::ms_MaxVolume;					
StrFlyWeight GasAccumulator::ms_MinVolume;					
ArrayFlyWeight<3> GasAccumulator::ms_GasVolume;	

GasAccumulator::GasAccumulator()
{

}

GasAccumulator::~GasAccumulator()
{

}

void GasAccumulator::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRPOLYTROPIC,6,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRGASVOLUME,7,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRORIFICE,8,15,FALSE);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSHORTPIPE,9,20,FALSE);
	ScenarioObject::InitAttr(s_StateName,IDS_STRINITPRESS,10,14);
	ScenarioObject::InitAttr(s_StateName,IDS_STRMAXVOLUME,11,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRMINVOLUME,12,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRGASPRESS,13,13);
	m_bitmap.LoadBitmap(IDB_GASACUM);
	s_typeName.LoadString(IDS_STRGASACCUM);
}


Component* GasAccumulator::CreatGasAccumulator()
{
	GasAccumulator *pGasAccumulator = new GasAccumulator;
	pGasAccumulator->Init();
	return pGasAccumulator;
}

ScenarioObject* GasAccumulator::DoClone()
{
	return new GasAccumulator(*this);
}

int GasAccumulator::GetID()
{
	return m_nTypeID;
}

CString GasAccumulator::GetTypeName()
{
	return s_typeName;
}

BOOL GasAccumulator::Read(Junperisist *pPersistent)
{
	// TODO: Add extra initialization here
	GasAccumPerisist *pGasAccumPerisist = dynamic_cast<GasAccumPerisist*>(pPersistent);
	ASSERT(pGasAccumPerisist != NULL);
	ms_Polytropic.SetValue(pGasAccumPerisist->Polytropic());
	ms_InitVolume.SetData(pGasAccumPerisist->InitVolume());
	ms_Orifice.SetData(pGasAccumPerisist->Orifice());
	ms_ShortPipe.SetData(pGasAccumPerisist->ShortPipe());
	ms_InitPress.SetData(pGasAccumPerisist->InitPress());
	ms_MaxVolume.SetValue(pGasAccumPerisist->MaxVolume());
	ms_MinVolume.SetValue(pGasAccumPerisist->MinVolume());
	ms_GasVolume.SetData(pGasAccumPerisist->GasVolume());
	
	return Jun::Read(pPersistent);
}

BOOL GasAccumulator::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra initialization here
	GasAccumPerisist *pGasAccumPerisist = dynamic_cast<GasAccumPerisist*>(pPersistent);
	ASSERT(pGasAccumPerisist != NULL);
	pGasAccumPerisist->Polytropic(ms_Polytropic.GetValue());
	pGasAccumPerisist->InitVolume(ms_InitVolume.GetData());
	pGasAccumPerisist->Orifice(ms_Orifice.GetData());
	pGasAccumPerisist->ShortPipe(ms_ShortPipe.GetData());
	pGasAccumPerisist->InitPress(ms_InitPress.GetData());
	pGasAccumPerisist->MaxVolume(ms_MaxVolume.GetValue());
	pGasAccumPerisist->MinVolume(ms_MinVolume.GetValue());
	pGasAccumPerisist->GasVolume(ms_GasVolume.GetData());
	return bRet;
}

BOOL GasAccumulator::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgGasAccum dlg(UnitSys,*pManager,this);
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

void GasAccumulator::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Polytropic,6);
	GetValue(ms_InitVolume,7);
	GetValue(ms_Orifice,8);
	GetValue(ms_ShortPipe,9);
	GetValue(ms_InitPress,10);
	GetValue(ms_MaxVolume,11);
	GetValue(ms_MinVolume,12);
	GetValue(ms_GasVolume,13);

}

void GasAccumulator::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Polytropic,6);
	SetValue(ms_InitVolume,7);
	SetValue(ms_Orifice,8);
	SetValue(ms_ShortPipe,9);
	SetValue(ms_InitPress,10);
	SetValue(ms_MaxVolume,11);
	SetValue(ms_MinVolume,12);
	SetValue(ms_GasVolume,13);
   Jun::SaveData();
}

BOOL GasAccumulator::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 25)
	{
		return TRUE;
	}
	return FALSE;
}

void GasAccumulator::AddLinkPipeInfo(UINT nKey)
{

}

void GasAccumulator::DelLinkPipeInfo(UINT nKey)
{

}

void GasAccumulator::EmptyPipeInfo()
{

}

void GasAccumulator::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
	if(ms_Polytropic.GetfValue()<=0)
		ref.Add(6);
	if(ms_InitVolume.GetfValue()<=0)
		ref.Add(7);
	if(ms_GasVolume.GetnValue()==1
		&&(ms_GasVolume.GetValue(2).CompareNoCase(_T("None"))==0
		||ms_GasVolume.GetValue(1).IsEmpty()))
	{
		ref.Add(13);
	}
	if(abs(ms_Orifice.GetnValue())==1)
	{
		if(ms_Orifice.GetfValue(1)<=0
		||ms_Orifice.GetfValue(2)<=0
		||ms_Orifice.GetfValue(3)<=0)
		{
			ref.Add(8);
		}
	}
	if(abs(ms_ShortPipe.GetnValue())==1)
	{
		if(ms_ShortPipe.GetfValue(1)<=0
		||ms_ShortPipe.GetfValue(2)<=0
		||ms_ShortPipe.GetfValue(4)<=0
		||ms_ShortPipe.GetfValue(6)<=0)
		{
			ref.Add(9);
		}
	}
	if(ms_SpecialMark.GetnValue()==1
		&&ms_InitPress.GetfValue()==0)
	{
		ref.Add(10);
	}
}
