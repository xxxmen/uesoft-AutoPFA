// AreaChange.cpp: implementation of the AreaChange class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "AreaChange.h"
#include "DlgAreaChange.h"
#include "areachangeperisist.h"
#include "AreaChangeLossCalc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NameArray AreaChange::s_StateName;
CBitmap AreaChange::m_bitmap;
const int AreaChange::m_nTypeID = 5;
CString AreaChange::s_typeName;
StrFlyWeight AreaChange::ms_Type;		
StrFlyWeight AreaChange::ms_Dir;			
StrFlyWeight AreaChange::ms_Angle;		
StrFlyWeight AreaChange::ms_K;			
ArrayFlyWeight<3> AreaChange::ms_BasisArea;	

AreaChange::AreaChange()
{

}

AreaChange::~AreaChange()
{

}

void AreaChange::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,7,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRANGLE,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,9,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STBASISAREA,10,13);
	m_bitmap.LoadBitmap(IDB_AREACHANGE);
	s_typeName.LoadString(IDS_STRAREACHANGE);
}


Component* AreaChange::CreatAreaChange()
{
	AreaChange *pAreaChange = new AreaChange;
	pAreaChange->Init();
	pAreaChange->SetSpecial(-1);
	return pAreaChange;
}

ScenarioObject* AreaChange::DoClone()
{
	return new AreaChange(*this);
}

int AreaChange::GetID()
{
	return m_nTypeID;
}

CString AreaChange::GetTypeName()
{
	return s_typeName;
}

BOOL AreaChange::Read(Junperisist *pPersistent)
{
	// TODO: Add extra initialization here
	AreaChangePerisist *pAreaChangePerisist = dynamic_cast<AreaChangePerisist*>(pPersistent);
	ASSERT(pAreaChangePerisist != NULL);
	ms_Type.SetValue(pAreaChangePerisist->Type());
	ms_Dir.SetValue(pAreaChangePerisist->Dir());
	ms_Angle.SetValue(pAreaChangePerisist->Angle());
	ms_K.SetValue(pAreaChangePerisist->K());
	ms_BasisArea.SetData(pAreaChangePerisist->BasisArea());
	return Jun::Read(pPersistent);
}


BOOL AreaChange::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra initialization here
	AreaChangePerisist *pAreaChangePerisist = dynamic_cast<AreaChangePerisist*>(pPersistent);
	ASSERT(pAreaChangePerisist != NULL);
	pAreaChangePerisist->Type(ms_Type.GetValue());
	pAreaChangePerisist->Dir(ms_Dir.GetValue());
	pAreaChangePerisist->Angle(ms_Angle.GetValue());
	pAreaChangePerisist->K(ms_K.GetValue());
	pAreaChangePerisist->BasisArea(ms_BasisArea.GetData());
	return bRet;
}

BOOL AreaChange::Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnly)
{
	DlgAreaChange dlg(UnitSys,*pManager,this);
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

void AreaChange::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_Type,6);
	GetValue(ms_Dir,7);
	GetValue(ms_Angle,8);
	GetValue(ms_K,9);
	GetValue(ms_BasisArea,10);
}

void AreaChange::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Type,6);
	SetValue(ms_Dir,7);
	SetValue(ms_Angle,8);
	SetValue(ms_K,9);
	SetValue(ms_BasisArea,10);
   Jun::SaveData();
}

BOOL AreaChange::CanLink(int nMaxLink,int nKey)
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

void AreaChange::AddLinkPipeInfo(UINT nKey)
{

}

void AreaChange::DelLinkPipeInfo(UINT nKey)
{

}

void AreaChange::EmptyPipeInfo()
{

}

void AreaChange::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<2)
		ref.Add(5);
	if(ms_Type.GetnValue()==0
		&&(ms_Angle.GetfValue()<=0||ms_Angle.GetfValue()>180))
		ref.Add(8);
	if(ms_K.GetfValue()<0)
		ref.Add(9);
}

void AreaChange::CalcK(double dAreaUp, double dAreaDown,int nRetype,double BaseArea)
{
	int nType = ms_Type.GetnValue();
	if(nType==0 || nType==1)
	{
		AreaChangeLossCalc calc;
		calc.AreaUp(dAreaUp);
		calc.AreaDown(dAreaDown);
		calc.Type(nType);
		calc.nRetype(nRetype);
		calc.BaseArea(BaseArea);
		calc.Angel(ms_Angle.GetfValue());
		double dK = calc.CalcK();
		ms_K.SetValue(float(dK));
	}
}
int AreaChange::AreaType(double dAreaUp,double dAreaDown)
{
	int nRet = 0;
	int nType = ms_Type.GetnValue();
	if(nType==0 || nType==1)
	{
		AreaChangeLossCalc calc;
		calc.AreaUp(dAreaUp);
		calc.AreaDown(dAreaDown);
		calc.Type(nType);
		calc.Angel(ms_Angle.GetfValue());
		nRet = calc.GetType();
	}
	return nRet;
}