// VacuumBreaker.cpp: implementation of the VacuumBreaker class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "VacuumBreaker.h"
#include "DlgVacuumBreaker.h"
#include "breakerperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray VacuumBreaker::s_StateName;
CBitmap VacuumBreaker::m_bitmap;
const int VacuumBreaker::m_nTypeID = 25;
CString VacuumBreaker::s_typeName;

ArrayFlyWeight<3> VacuumBreaker::ms_CrackPress;		
NumFlyWeight      VacuumBreaker::ms_OrificeInCdA;			
NumFlyWeight      VacuumBreaker::ms_OrificeOutCdA;		
ArrayFlyWeight<3> VacuumBreaker::ms_LiquidTemp;		     
ArrayFlyWeight<9> VacuumBreaker::ms_GasProperty;	
StrFlyWeight      VacuumBreaker::ms_ConnectPipe;		
StrFlyWeight      VacuumBreaker::ms_ValveType;			    
NumFlyWeight      VacuumBreaker::ms_InterMediateCdA;		 
ArrayFlyWeight<3> VacuumBreaker::ms_MediateActivation;	

VacuumBreaker::VacuumBreaker()
{

}

VacuumBreaker::~VacuumBreaker()
{

}

void VacuumBreaker::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCRACKPRESS,6,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRORIFICEINCDA,7,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRORIFICEOUTCDA,8,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLIQUIDTEMP,9,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STR_GASPROPORTY,10,19);
	ScenarioObject::InitAttr(s_StateName,IDS_STR_CONNECTPIPENUM,11,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,12,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STR_INTERMEDIATECDA,13,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STR_MEDIUMACTIVATION,14,13);
	m_bitmap.LoadBitmap(IDB_BREAKER);
	s_typeName.LoadString(IDS_STRBREAKER);
}


Component* VacuumBreaker::CreatVacuumBreaker()
{
	VacuumBreaker *pVacuumBreaker = new VacuumBreaker;
	pVacuumBreaker->Init();
	ms_CrackPress.SetValue(1);
	pVacuumBreaker->SetValue(ms_CrackPress,6);
	return pVacuumBreaker;
}

ScenarioObject* VacuumBreaker::DoClone()
{
	return new VacuumBreaker(*this);
}

int VacuumBreaker::GetID()
{
	return m_nTypeID;
}

CString VacuumBreaker::GetTypeName()
{
    return s_typeName;
}

BOOL VacuumBreaker::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	BreakerPerisist *pBreakerPerisist = dynamic_cast<BreakerPerisist*>(pPersistent);
	ASSERT(pBreakerPerisist != NULL);
	ms_CrackPress.SetData(pBreakerPerisist->CrackPress());
	ms_OrificeInCdA.SetData(pBreakerPerisist->OrificeInCdA());
	ms_OrificeOutCdA.SetData(pBreakerPerisist->OrificeOutCdA());
	ms_LiquidTemp.SetData(pBreakerPerisist->LiquidTemp());
	ms_GasProperty.SetData(pBreakerPerisist->GasProperty());
	ms_ConnectPipe.SetValue(pBreakerPerisist->ConnectPipe());
	ms_ValveType.SetValue(pBreakerPerisist->ValveType());
	ms_InterMediateCdA.SetData(pBreakerPerisist->InterMediateCdA());
	ms_MediateActivation.SetData(pBreakerPerisist->MediateActivation());
	return Jun::Read(pPersistent);
}

BOOL VacuumBreaker::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	BreakerPerisist *pBreakerPerisist = dynamic_cast<BreakerPerisist*>(pPersistent);
	ASSERT(pBreakerPerisist != NULL);
	pBreakerPerisist->CrackPress(ms_CrackPress.GetData());
	pBreakerPerisist->OrificeInCdA(ms_OrificeInCdA.GetData());
	pBreakerPerisist->OrificeOutCdA(ms_OrificeOutCdA.GetData());
	pBreakerPerisist->LiquidTemp(ms_LiquidTemp.GetData());
	pBreakerPerisist->GasProperty(ms_GasProperty.GetData());
	pBreakerPerisist->ConnectPipe(ms_ConnectPipe.GetValue());
	pBreakerPerisist->ValveType(ms_ValveType.GetValue());
	pBreakerPerisist->InterMediateCdA(ms_InterMediateCdA.GetData());
	pBreakerPerisist->MediateActivation(ms_MediateActivation.GetData());
	return bRet;
}


BOOL VacuumBreaker::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgVacuumBreaker dlg(UnitSys,*pManager,this);
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

void VacuumBreaker::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_CrackPress,6);
	GetValue(ms_OrificeInCdA,7);
	GetValue(ms_OrificeOutCdA,8);
	GetValue(ms_LiquidTemp,9);
	GetValue(ms_GasProperty,10);
	GetValue(ms_ConnectPipe,11);
	GetValue(ms_ValveType,12);
	GetValue(ms_InterMediateCdA,13);
	GetValue(ms_MediateActivation,14);
}

void VacuumBreaker::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_CrackPress,6);
	SetValue(ms_OrificeInCdA,7);
	SetValue(ms_OrificeOutCdA,8);
	SetValue(ms_LiquidTemp,9);
	SetValue(ms_GasProperty,10);
	SetValue(ms_ConnectPipe,11);
	SetValue(ms_ValveType,12);
	SetValue(ms_InterMediateCdA,13);
	SetValue(ms_MediateActivation,14);
   Jun::SaveData();
}

BOOL VacuumBreaker::CanLink(int nMaxLink,int nKey)
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

void VacuumBreaker::AddLinkPipeInfo(UINT nKey)
{

}

void VacuumBreaker::DelLinkPipeInfo(UINT nKey)
{

}

void VacuumBreaker::EmptyPipeInfo()
{

}

void VacuumBreaker::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_ConnectPipe.GetnValue()==0)
	{
		if(ms_PipeID.GetCount()!=2)
			ref.Add(5);
	}
	else
	{
		if(ms_PipeID.GetCount()!=1)
			ref.Add(5);
	}
	switch(ms_ValveType.GetnValue())
	{
	case 0:
		if(ms_OrificeInCdA.GetfValue()<=0)
			ref.Add(7);
		if(ms_OrificeOutCdA.GetfValue()<=0)
			ref.Add(8);
		break;
	case 1:
		if(ms_OrificeInCdA.GetfValue()<=0)
			ref.Add(7);
		break;
	case 2:
		if(ms_OrificeOutCdA.GetfValue()<=0)
			ref.Add(8);
	    break;
	case 3:
		if(ms_OrificeInCdA.GetfValue()<=0)
			ref.Add(7);
		if(ms_OrificeOutCdA.GetfValue()<=0)
			ref.Add(8);
		if(ms_InterMediateCdA.GetfValue()<=0)
			ref.Add(_T("媒介流出面积"));
	    break;
	default:
	    break;
	}
}
