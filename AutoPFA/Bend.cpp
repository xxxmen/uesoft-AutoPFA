// Bend.cpp: implementation of the Bend class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "Bend.h"
#include "dlgbend.h"
#include "BendPerisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const int Bend::m_nTypeID = 6;
NameArray Bend::s_StateName;
CBitmap Bend::m_bitmap;
CString Bend::s_typeName;
StrFlyWeight Bend::ms_Type;
StrFlyWeight Bend::ms_AngleType;
StrFlyWeight Bend::ms_Angle;
StrFlyWeight Bend::ms_RD;		
StrFlyWeight Bend::ms_K;
NumFlyWeight Bend::ms_RestriFlowArea;			
ArrayFlyWeight<3> Bend::ms_BasisArea;	

Bend::Bend()
{

}

Bend::~Bend()
{

}

void Bend::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,7,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRANGLE,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRRDNUM,9,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,10,1);
	ScenarioObject::InitAttr(s_StateName,11,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STBASISAREA,12,13);
	m_bitmap.LoadBitmap(IDB_BEND);
	s_typeName.LoadString(IDS_STRBEND);
}


Component* Bend::CreatBend()
{
	Bend *pBend = new Bend;
	pBend->Init();
	pBend->SetSpecial(-1);
	return pBend;
}

ScenarioObject* Bend::DoClone()
{
	return new Bend(*this);
}

int Bend::GetID()
{
	return m_nTypeID;
}

CString Bend::GetTypeName()
{
	return s_typeName;
}

BOOL Bend::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgBend dlg(UnitSys,*pManager,this);
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
void Bend::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Type,6);
	GetValue(ms_AngleType,7);
	GetValue(ms_Angle,8);
	GetValue(ms_RD,9);
	GetValue(ms_K,10);
	GetValue(ms_RestriFlowArea,11);
	GetValue(ms_BasisArea,12);
}

void Bend::SaveData()
{
	// TODO: Add extra SaveData here
	SetValue(ms_Type,6);
	SetValue(ms_AngleType,7);
	SetValue(ms_Angle,8);
	SetValue(ms_RD,9);
	SetValue(ms_K,10);
	SetValue(ms_RestriFlowArea,11);
	SetValue(ms_BasisArea,12);
   Jun::SaveData();
}
BOOL Bend::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	BendPerisist *pBendPerisist = dynamic_cast<BendPerisist*>(pPersistent);
	ASSERT(pBendPerisist != NULL);
	ms_Type.SetValue(pBendPerisist->Type());
	ms_Angle.SetValue(pBendPerisist->Angle());		
	ms_RD.SetValue(pBendPerisist->RD());
	ms_K.SetValue(pBendPerisist->K());
	ms_RestriFlowArea.SetData(pBendPerisist->RestriFlowArea());			
	ms_BasisArea.SetData(pBendPerisist->BasisArea());
//	if(abs(ms_Angle.GetfValue()*100-1.570796*100)>5)
	if(abs(ms_Angle.GetnValue()-90)>1)
		ms_AngleType.SetValue(1);
	else
		ms_AngleType.SetValue(0);
	return Jun::Read(pPersistent);
}

BOOL Bend::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	BendPerisist *pBendPerisist = dynamic_cast<BendPerisist*>(pPersistent);
	ASSERT(pBendPerisist != NULL);
	pBendPerisist->Type(ms_Type.GetValue());
	pBendPerisist->Angle(ms_Angle.GetValue());
	pBendPerisist->RD(ms_RD.GetValue());
	pBendPerisist->K(ms_K.GetValue());
	pBendPerisist->RestriFlowArea(ms_RestriFlowArea.GetData());
	pBendPerisist->BasisArea(ms_BasisArea.GetData());
	return bRet;
}
BOOL Bend::CanLink(int nMaxLink,int nKey)
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

void Bend::AddLinkPipeInfo(UINT nKey)
{

}

void Bend::DelLinkPipeInfo(UINT nKey)
{

}

void Bend::EmptyPipeInfo()
{

}

void Bend::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<2)
		ref.Add(5);
	if(ms_K.GetfValue()<0)
		ref.Add(8);
}