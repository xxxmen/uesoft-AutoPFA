// LiquidAccumulator.cpp: implementation of the LiquidAccumulator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "LiquidAccumulator.h"
#include "DlgLiquidAccum.h"
#include "liquidaccumperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const int LiquidAccumulator::m_nTypeID = 23;
NameArray LiquidAccumulator::s_StateName;
CBitmap LiquidAccumulator::m_bitmap;
CString LiquidAccumulator::s_typeName;

NumFlyWeight LiquidAccumulator::ms_Elastic;
NumFlyWeight LiquidAccumulator::ms_InitVolume;

LiquidAccumulator::LiquidAccumulator()
{

}

LiquidAccumulator::~LiquidAccumulator()
{

}

void LiquidAccumulator::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRELASTIC,6,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRINITVOLUME,7,2);
	m_bitmap.LoadBitmap(IDB_LIQUIDACUM);
	s_typeName.LoadString(IDS_STRLIQUIDACCUM);
}


Component* LiquidAccumulator::CreatLiquidAccumulator()
{
	LiquidAccumulator *pLiquidAccumulator = new LiquidAccumulator;
	pLiquidAccumulator->Init();
	return pLiquidAccumulator;
}

ScenarioObject* LiquidAccumulator::DoClone()
{
	return new LiquidAccumulator(*this);
}

int LiquidAccumulator::GetID()
{
	return m_nTypeID;
}

CString LiquidAccumulator::GetTypeName()
{
	return s_typeName;
}

BOOL LiquidAccumulator::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	LiquidAccumPerisist *pLiquidAccumPerisist = dynamic_cast<LiquidAccumPerisist*>(pPersistent);
	ASSERT(pLiquidAccumPerisist != NULL);
	ms_Elastic.SetData(pLiquidAccumPerisist->Elastic());
	ms_InitVolume.SetData(pLiquidAccumPerisist->InitVolume());
	return Jun::Read(pPersistent);
}

BOOL LiquidAccumulator::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	LiquidAccumPerisist *pLiquidAccumPerisist = dynamic_cast<LiquidAccumPerisist*>(pPersistent);
	ASSERT(pLiquidAccumPerisist != NULL);
	pLiquidAccumPerisist->Elastic(ms_Elastic.GetData());
	pLiquidAccumPerisist->InitVolume(ms_InitVolume.GetData());
	return bRet;
}

BOOL LiquidAccumulator::Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnly)
{
	DlgLiquidAccum dlg(UnitSys,*pManager,this);
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

void LiquidAccumulator::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Elastic,6);
	GetValue(ms_InitVolume,7);
}

void LiquidAccumulator::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Elastic,6);
	SetValue(ms_InitVolume,7);
	Jun::SaveData();
}

BOOL LiquidAccumulator::CanLink(int nMaxLink,int nKey)
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

void LiquidAccumulator::AddLinkPipeInfo(UINT nKey)
{

}

void LiquidAccumulator::DelLinkPipeInfo(UINT nKey)
{

}

void LiquidAccumulator::EmptyPipeInfo()
{

}

void LiquidAccumulator::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<2)
		ref.Add(5);
	if(ms_Elastic.GetfValue()<=0)
		ref.Add(6);
	if(ms_InitVolume.GetfValue()<=0)
		ref.Add(7);
}
