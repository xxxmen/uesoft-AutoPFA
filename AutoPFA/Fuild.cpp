// Fuild.cpp: implementation of the Fuild class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "Fuild.h"
#include "SysProperty.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
NameArray Fuild::s_StateName;
StrFlyWeight Fuild::ms_Name;
NumFlyWeight Fuild::ms_Density;
NumFlyWeight Fuild::ms_Temperature;
NumFlyWeight Fuild::ms_Viscos;
NumFlyWeight Fuild::ms_BulkModulus;
NumFlyWeight Fuild::ms_VaporPressure;

void Fuild::Instance()
{
	ScenarioObject::InitAttr(s_StateName,IDS_FUILDNAME,1,1);
	ScenarioObject::InitAttr(s_StateName,IDS_FUILDDEN ,2,2);
	ScenarioObject::InitAttr(s_StateName,IDS_FUILDTEMP,3,2);
	ScenarioObject::InitAttr(s_StateName,IDS_FUILDVISCOS,4,2);
	ScenarioObject::InitAttr(s_StateName,IDS_BULKMDULUS,5,2);
	ScenarioObject::InitAttr(s_StateName,IDS_VAPORPRESSURE,6,2);
}

Fuild::Fuild()
{

}

Fuild::~Fuild()
{

}

ScenarioObject* Fuild::CreatFuild()
{
	Fuild *pFuild = new Fuild;
	pFuild->Init();

	return pFuild;
}

ScenarioObject* Fuild::DoClone()
{
	return new Fuild(*this);
}

void Fuild::InitData()
{
	GetValue(ms_Name,1);
	GetValue(ms_Density,2);
	GetValue(ms_Temperature,3);
	GetValue(ms_Viscos,4);
	GetValue(ms_BulkModulus,5);
	GetValue(ms_VaporPressure,6);
}

void Fuild::SaveData()
{
	SetValue(ms_Name,1);
	SetValue(ms_Density,2);
	SetValue(ms_Temperature,3);
	SetValue(ms_Viscos,4);
	SetValue(ms_BulkModulus,5);
	SetValue(ms_VaporPressure,6);
}

BOOL Fuild::Read(PropertyPersistent &persistent)
{
	ms_Name.SetValue(persistent.Name());
	ms_Density.SetData(persistent.Density());
	ms_Temperature.SetData(persistent.Temperature());
	ms_Viscos.SetData(persistent.Viscos());
	ms_BulkModulus.SetData(persistent.Modulus());
	ms_VaporPressure.SetData(persistent.VaporPress());
	
	SaveData();
	return TRUE;
}

BOOL Fuild::Save(PropertyPersistent &persistent)
{
	InitData();
	
	persistent.Name(ms_Name.GetValue());
	persistent.Density(ms_Density.GetData());
	persistent.Temperature(ms_Temperature.GetData());
	persistent.Viscos(ms_Viscos.GetData());
	persistent.Modulus(ms_BulkModulus.GetData());
	persistent.VaporPress(ms_VaporPressure.GetData());

	return TRUE;
}

double Fuild::Density()
{
	GetValue(ms_Density,2);
	return ms_Density.GetNum();
}

double Fuild::BulkModulus()
{
	GetValue(ms_BulkModulus,5);
	return ms_BulkModulus.GetNum();
}

BOOL Fuild::IsDefine()
{
	InitData();
	if(ms_Density.GetfValue()<=0)
		return FALSE;
	return TRUE;
}
