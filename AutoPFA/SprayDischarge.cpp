// SprayDischarge.cpp: implementation of the SprayDischarge class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "SprayDischarge.h"
#include "DlgSprayDischarge.h"
#include "sprayperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

NameArray SprayDischarge::s_StateName;
CBitmap SprayDischarge::m_bitmap;
const int SprayDischarge::m_nTypeID = 16;
CString SprayDischarge::s_typeName;

StrFlyWeight SprayDischarge::ms_Type;
ArrayFlyWeight<13> SprayDischarge::ms_Curve;
ArrayFlyWeight<3> SprayDischarge::ms_ExitArea;
StrFlyWeight SprayDischarge::ms_KOrCv;
ArrayFlyWeight<3>  SprayDischarge::ms_ExitPress;
Transient    SprayDischarge::ms_Transient;

TableFlyWeight<4>SprayDischarge::ms_PipeInfo;
StrFlyWeight SprayDischarge::ms_DistanceUnit;

SprayDischarge::SprayDischarge()
{
	m_nCurve = 5;
	m_nTran1Num = 0;
	m_nTran2Num = 0;
}

SprayDischarge::~SprayDischarge()
{

}

void SprayDischarge::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,7,23);
	ScenarioObject::InitAttr(s_StateName,8,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRLOSSFACTOR,9,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STREXITPRESS,10,13);
	ms_Transient.Instance(s_StateName,50);//50~61
	
	m_bitmap.LoadBitmap(IDB_SPRAY);
	s_typeName.LoadString(IDS_STRSPRAY);
}


Component* SprayDischarge::CreatSprayDischarge()
{
	SprayDischarge *pSprayDischarge = new SprayDischarge;
	pSprayDischarge->Init();
	ms_ExitPress.SetValue(1);
	pSprayDischarge->SetValue(ms_ExitPress,10);
	InitCurve(ms_Curve);
	pSprayDischarge->SetValue(ms_Curve,7);
	return pSprayDischarge;
}

ScenarioObject* SprayDischarge::DoClone()
{
	return new SprayDischarge(*this);
}

int SprayDischarge::GetID()
{
	return m_nTypeID;
}

CString SprayDischarge::GetTypeName()
{
    return s_typeName;
}

BOOL SprayDischarge::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	SprayPerisist *pSprayPerisist = dynamic_cast<SprayPerisist*>(pPersistent);
	ASSERT(pSprayPerisist != NULL);
	ms_Curve.SetValue(m_nCurve,7);//子工况应用父工况数据需要保存参数个数。
	
	ms_Type.SetValue(pSprayPerisist->Type());
	ms_Curve.SetData(pSprayPerisist->Curve());
	ms_ExitArea.SetData(pSprayPerisist->ExitArea());
	ms_KOrCv.SetValue(pSprayPerisist->KOrCv());
	ms_ExitPress.SetData(pSprayPerisist->ExitPress());
	ms_Transient.Read(pSprayPerisist->m_TransPersistent);
	//6.0下管道流向多加入了K系数和管道端口与节点标高
	ms_PipeInfo.SetData(pSprayPerisist->PipeInfo());
	ms_DistanceUnit.SetValue(pSprayPerisist->DistanceUnit());
	return Jun::Read(pPersistent);
}

BOOL SprayDischarge::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	SprayPerisist *pSprayPerisist = dynamic_cast<SprayPerisist*>(pPersistent);
	ASSERT(pSprayPerisist != NULL);
	pSprayPerisist->Type(ms_Type.GetValue());
	pSprayPerisist->Curve(ms_Curve.GetData());
	pSprayPerisist->ExitArea(ms_ExitArea.GetData());
	pSprayPerisist->KOrCv(ms_KOrCv.GetValue());
	pSprayPerisist->ExitPress(ms_ExitPress.GetData());
	ms_Transient.Save(pSprayPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num);
	//6.0下管道流向多加入了K系数和管道端口与节点标高
	pSprayPerisist->PipeInfo(ms_PipeInfo.GetData(),m_nLinkPipeNum);
	pSprayPerisist->DistanceUnit(ms_DistanceUnit.GetValue());
	return bRet;
}


BOOL SprayDischarge::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgSprayDischarge dlg(UnitSys,*pManager,this);
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

void SprayDischarge::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here

	GetValue(ms_Type,6);
	GetValue(ms_Curve,7);
	GetValue(ms_ExitArea,8);
	GetValue(ms_KOrCv,9);
	GetValue(ms_ExitPress,10);
	//6.0下管道流向多加入了K系数和管道端口与节点标高
	GetValue(ms_PipeInfo,11);	
	GetValue(ms_DistanceUnit,12);
	ms_Transient.InitData(this);
}

void SprayDischarge::SaveData()
{
	// TODO: Add extra SaveData here

	SetValue(ms_Type,6);
	SetValue(ms_Curve,7);
	SetValue(ms_ExitArea,8);
	SetValue(ms_KOrCv,9);
	SetValue(ms_ExitPress,10);
	//6.0下管道流向多加入了K系数和管道端口与节点标高
 	SetValue(ms_PipeInfo,11);
 	SetValue(ms_DistanceUnit,12);

	m_nCurve = ms_Curve.GetnValue(7);//曲线参数个数，子工况需要
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num);
   Jun::SaveData();
}

BOOL SprayDischarge::CanLink(int nMaxLink,int nKey)
{
	if(nMaxLink < 25)
	{
//		if(nMaxLink == 0)
//			return TRUE;
//		if(nKey >0 && IsExistInPipe())
//			return TRUE;
//		if(nKey<0 && IsExistOutPipe())
			return TRUE;
	}
	return FALSE;
}

//6.0下管道流向多加入了K系数和管道端口与节点标高
void SprayDischarge::AddLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,11);
	AddPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,11);
}

void SprayDischarge::DelLinkPipeInfo(UINT nKey)
{
	GetValue(ms_PipeInfo,11);
	DelPipeInfo(ms_PipeInfo,nKey);
	SetValue(ms_PipeInfo,11);
}

void SprayDischarge::EmptyPipeInfo()
{
	ms_PipeInfo.Empty();
	SetValue(ms_PipeInfo,11);
}

Transient* SprayDischarge::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void SprayDischarge::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(ms_PipeID.GetCount()<1)
		ref.Add(5);
	if(ms_KOrCv.GetfValue()<=0)
		ref.Add(9);
	if(ms_ExitPress.GetValue(2).CompareNoCase(_T("None"))==0
		||ms_ExitPress.GetValue(1).IsEmpty())
	{
		ref.Add(10);
	}
	if(ms_Curve.GetnValue()==0)
	{
		if(ms_ExitArea.GetfValue()<=0)
			ref.Add(_T("孔口面积"));
		if(ms_Type.GetnValue()==1&&ms_ExitArea.GetnValue(2)<=0)
			ref.Add(_T("孔口数量"));
	}
	else
	{
		if(ms_ExitArea.GetnValue(2)<=0)
			ref.Add(_T("孔口数量"));
	}
}
