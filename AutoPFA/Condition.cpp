// Condition.cpp: implementation of the Condition class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Condition.h"
#include "SysProperty.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NameArray Condition::s_StateName;
StrFlyWeight Condition::ms_Gravity;
StrFlyWeight Condition::ms_ReTransLam;
StrFlyWeight Condition::ms_ReTransTurb;
NumFlyWeight Condition::ms_AtmosphericPress;
NumFlyWeight Condition::ms_AtmosphericTemp;

void Condition::Instance()
{
	ScenarioObject::InitAttr(s_StateName,IDS_STRGRAVITY,1,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRRETRANSLAM,2,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRRETRANSTURB,3,1);
	ScenarioObject::InitAttr(s_StateName,IDS_STRATMOSPHERICPRESS,4,2);
	ScenarioObject::InitAttr(s_StateName,5,2);
}

Condition::Condition()
{

}

Condition::~Condition()
{

}

ScenarioObject* Condition::DoClone()
{
	return new Condition(*this);
}

ScenarioObject* Condition::CreatCondition()
{
	Condition *pCondition = new Condition;
	pCondition->Init();
	ms_Gravity.SetValue(_T("1"));
	ms_ReTransLam.SetValue(_T("2300"));
	ms_ReTransTurb.SetValue(_T("4000"));
	ms_AtmosphericPress.SetValue(1);
	ms_AtmosphericPress.SetUnit("atm");
	ms_AtmosphericTemp.SetValue(_T("293.15"));
	pCondition->SetValue(ms_Gravity,1);
	pCondition->SetValue(ms_ReTransLam,2);
	pCondition->SetValue(ms_ReTransTurb,3);
	pCondition->SetValue(ms_AtmosphericPress,4);
	pCondition->SetValue(ms_AtmosphericTemp,5);
	return pCondition;
}

void Condition::InitData()
{
	GetValue(ms_Gravity,1);
	GetValue(ms_ReTransLam,2);
	GetValue(ms_ReTransTurb,3);
	GetValue(ms_AtmosphericPress,4);
	GetValue(ms_AtmosphericTemp,5);
}

void Condition::SaveData()
{
	SetValue(ms_Gravity,1);
	SetValue(ms_ReTransLam,2);
	SetValue(ms_ReTransTurb,3);
	SetValue(ms_AtmosphericPress,4);
	SetValue(ms_AtmosphericTemp,5);
}

BOOL Condition::Read(PropertyPersistent &persistent)
{
	ms_Gravity.SetValue(persistent.Gravity());
	ms_ReTransLam.SetValue(persistent.ReTransLam());
	ms_ReTransTurb.SetValue(persistent.ReTransTurb());
	ms_AtmosphericPress.SetData(persistent.AtmosphericPress());
	SaveData();
	return TRUE;
}

BOOL Condition::Save(PropertyPersistent &persistent)
{
	InitData();
	persistent.Gravity(ms_Gravity.GetValue());
	persistent.ReTransLam(ms_ReTransLam.GetValue());
	persistent.ReTransTurb(ms_ReTransTurb.GetValue());
	persistent.AtmosphericPress(ms_AtmosphericPress.GetData());
	
	return TRUE;
}

double Condition::Gravity()
{
	GetValue(ms_Gravity,1);
	return GA*ms_Gravity.GetfValue();
}
