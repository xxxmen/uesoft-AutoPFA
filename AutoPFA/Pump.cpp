// Pump.cpp: implementation of the Pump class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Pump.h"
#include "DlgPump.h"
#include "pumpperisist.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
const CmbDataItem  Pump::ms_TransModel1[]=
{
	    CmbDataItem(0,"none"),
		CmbDataItem(1,"Whitout Inertia")
};

const CmbDataItem  Pump::ms_TransModel2[]=
{
	    CmbDataItem(0,"正常运行"),
		CmbDataItem(7,"正常运行-四象限特性曲线"),
		CmbDataItem(1,"非惯性"),
		CmbDataItem(2,"惯性停泵不存在倒流或反转"),
		CmbDataItem(3,"惯性停泵-四象限特性曲线"),
		CmbDataItem(5,"惯性启动不存在倒流或反转"),
		CmbDataItem(6,"惯性启动-四象限特性曲线"),
		CmbDataItem(4,"已知转速启动-四象限特性曲线")
};

NameArray Pump::s_StateName;
CBitmap Pump::m_bitmap;
const int Pump::m_nTypeID = 17;
CString Pump::s_typeName;

StrFlyWeight      Pump::ms_PumpType;			
ArrayFlyWeight<3> Pump::ms_PumpFlow;			
StrFlyWeight      Pump::ms_SpeedRatio;			
ArrayFlyWeight<4> Pump::ms_PumpControl;			
StrFlyWeight      Pump::ms_ControlApply;            
StrFlyWeight      Pump::ms_PressType;			
ArrayFlyWeight<4> Pump::ms_SubmergePump;           
StrFlyWeight      Pump::ms_ExitCheck;			
NumFlyWeight      Pump::ms_CloseVel;		       
StrFlyWeight      Pump::ms_antiReverse;			
ArrayFlyWeight<3> Pump::ms_ReOpenPress;	
StrFlyWeight      Pump::ms_PumpSet;	
PumpTransient     Pump::ms_Transient;	
Configuration     Pump::ms_Configuration;

Pump::Pump()
{
	m_nCurve1 = 0;
	m_nCurve2 = 0;
	m_nCurve3 = 0;
	m_nTran1Num = 0;				//瞬变数据表1数据数量
	m_nTran2Num = 0;				//瞬变数据表2数据数量
	m_nFourQuadNum = 0;
}

Pump::~Pump()
{

}

void Pump::Instance()
{
	Jun::Instance(s_StateName);
	ScenarioObject::InitAttr(s_StateName,IDS_STRTYPE,6,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRFLOWRATE,7,13);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSPEEDRATIO,8,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCONTROLSET,9,14);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCONTROLAPPLY,10,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCONTROLPRESSTYPE,11,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRSUBMERGEPRESS,12,14);
	ScenarioObject::InitAttr(s_StateName,IDS_STREXITCHECK,13,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRCLOSEVALVE,14,2);
	ScenarioObject::InitAttr(s_StateName,IDS_STRANTIREVERSE,15,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRREOPENPRESS,16,13);
    ScenarioObject::InitAttr(s_StateName,17,1);

	ms_Transient.Instance(s_StateName,50);
	ms_Configuration.Instance(s_StateName,200);
	m_bitmap.LoadBitmap(IDB_PUMP);
	s_typeName.LoadString(IDS_STRPUMP);
}


Component* Pump::CreatPump()
{
	Pump *pPump = new Pump;
	pPump->Init();
	ms_SpeedRatio.SetValue(_T("1"));
	ms_antiReverse.SetValue(-1);
	pPump->SetValue(ms_SpeedRatio,8);
	pPump->SetValue(ms_antiReverse,15);
	return pPump;
}

ScenarioObject* Pump::DoClone()
{
	return new Pump(*this);
}

int Pump::GetID()
{
	return m_nTypeID;
}

CString Pump::GetTypeName()
{
	return s_typeName;
}

BOOL Pump::Read(Junperisist *pPersistent)
{
	// TODO: Add extra Read here
	PumpPerisist *pPumpPerisist = dynamic_cast<PumpPerisist*>(pPersistent);
	ASSERT(pPumpPerisist != NULL);
	ms_PumpType.SetValue(pPumpPerisist->PumpType());
	ms_PumpFlow.SetData(pPumpPerisist->PumpFlow());
	ms_SpeedRatio.SetValue(pPumpPerisist->SpeedRatio());
	ms_PumpControl.SetData(pPumpPerisist->PumpControl());
	ms_ControlApply.SetValue(pPumpPerisist->ControlApply());
	ms_PressType.SetValue(pPumpPerisist->PressType());
	ms_SubmergePump.SetData(pPumpPerisist->SubmergePump());
	ms_ExitCheck.SetValue(pPumpPerisist->ExitCheck());
	ms_CloseVel.SetData(pPumpPerisist->CloseVel());
	ms_antiReverse.SetValue(pPumpPerisist->AntiReverse());
	ms_ReOpenPress.SetData(pPumpPerisist->ReOpenPress());
	ms_PumpSet.SetValue(pPumpPerisist->PumpSet());
	ms_Transient.Read(pPumpPerisist->m_TransPersistent);
	ms_Configuration.Read(pPumpPerisist->m_ConfigPerisist);
	return Jun::Read(pPersistent);
}

BOOL Pump::Save(Junperisist *pPersistent)
{
	BOOL bRet = Jun::Save(pPersistent);
	// TODO: Add extra Save here
	PumpPerisist *pPumpPerisist = dynamic_cast<PumpPerisist*>(pPersistent);
	ASSERT(pPumpPerisist != NULL);
	pPumpPerisist->PumpType(ms_PumpType.GetValue());
	pPumpPerisist->PumpFlow(ms_PumpFlow.GetData());
	pPumpPerisist->SpeedRatio(ms_SpeedRatio.GetValue());
	pPumpPerisist->PumpControl(ms_PumpControl.GetData());
	pPumpPerisist->ControlApply(ms_ControlApply.GetValue());
	pPumpPerisist->PressType(ms_PressType.GetValue());
	pPumpPerisist->SubmergePump(ms_SubmergePump.GetData());
	pPumpPerisist->ExitCheck(ms_ExitCheck.GetValue());
	pPumpPerisist->CloseVel(ms_CloseVel.GetData());
	pPumpPerisist->AntiReverse(ms_antiReverse.GetValue());
	pPumpPerisist->ReOpenPress(ms_ReOpenPress.GetData());
	pPumpPerisist->PumpSet(ms_PumpSet.GetValue());
	ms_Transient.Save(pPumpPerisist->m_TransPersistent,m_nTran1Num,m_nTran2Num,m_nFourQuadNum);
	ms_Configuration.Save(pPumpPerisist->m_ConfigPerisist,m_nCurve1,m_nCurve2,m_nCurve3);
	return bRet;
}

//第三个参数表示在显示节点属性的对话框里不能修改节点任何属性
BOOL Pump::Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bReadOnly)
{
	DlgPump dlg(UnitSys,*pManager,this);
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

void Pump::InitData()
{
	Jun::InitData();
	// TODO: Add extra initialization here
	GetValue(ms_PumpType,6);
	GetValue(ms_PumpFlow,7);
	GetValue(ms_SpeedRatio,8);
	GetValue(ms_PumpControl,9);
	GetValue(ms_ControlApply,10);
	GetValue(ms_PressType,11);
	GetValue(ms_SubmergePump,12);
	GetValue(ms_ExitCheck,13);
	GetValue(ms_CloseVel,14);
	GetValue(ms_antiReverse,15);
	GetValue(ms_ReOpenPress,16);
	GetValue(ms_PumpSet,17);
	ms_Transient.InitData(this);
	ms_Configuration.InitData(this);
}

void Pump::SaveData()
{
	// TODO: Add extra SaveData here
	SetValue(ms_PumpType,6);
	SetValue(ms_PumpFlow,7);
	SetValue(ms_SpeedRatio,8);
	SetValue(ms_PumpControl,9);
	SetValue(ms_ControlApply,10);
	SetValue(ms_PressType,11);
	SetValue(ms_SubmergePump,12);
	SetValue(ms_ExitCheck,13);
	SetValue(ms_CloseVel,14);
	SetValue(ms_antiReverse,15);
	SetValue(ms_ReOpenPress,16);
	SetValue(ms_PumpSet,17);
	ms_Transient.SaveData(this,m_nTran1Num,m_nTran2Num,m_nFourQuadNum);
	ms_Configuration.SaveData(this,m_nCurve1,m_nCurve2,m_nCurve3);
   Jun::SaveData();
}

BOOL Pump::CanLink(int nMaxLink,int nKey)
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

void Pump::AddLinkPipeInfo(UINT nKey)
{

}

void Pump::DelLinkPipeInfo(UINT nKey)
{

}

void Pump::EmptyPipeInfo()
{

}
Transient* Pump::GetTransient()
{
	ms_Transient.InitData(this);
	return &ms_Transient;
}

void Pump::Status(ComponentStatus &ref, BOOL bTrans)
{
	Jun::Status(ref,bTrans);
	if(abs(ms_SubmergePump.GetnValue())==1)
	{
		if(IsExistInPipe()||!IsExistOutPipe())
			ref.Add(5);
	}
	else
	{
		if(ms_PipeID.GetCount()<2)
			ref.Add(5);
	}
	if(ms_PumpType.GetnValue()==0)
	{
		if(ms_Configuration.m_Num.GetnValue()==0)
			ref.Add(_T("泵曲线"));
	}
	else
	{
		if(ms_PumpFlow.GetfValue(1)<=0)
			ref.Add(7);
	}
	if(ms_PumpControl.GetnValue()!=0
		&&ms_PumpControl.GetValue(2).IsEmpty())
	{
		ref.Add(9);
	}
	if(abs(ms_SubmergePump.GetnValue())==1
		&&ms_SubmergePump.GetValue(2).IsEmpty())
	{
		ref.Add(12);
	}
	if(abs(ms_ExitCheck.GetnValue())==1)
	{
		if(ms_CloseVel.GetValue().IsEmpty())
			ref.Add(14);
		if(ms_ReOpenPress.GetfValue(1)<=0)
			ref.Add(16);
	}
}
