// Configuration.cpp: implementation of the Configuration class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "Configuration.h"
#include "onfigItemPerisist.h"
#include "Jun.h"
#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


Configuration::Configuration()
{
	m_nKey = 200;
}

Configuration::~Configuration()
{

}

BOOL Configuration::Read(ConfigPerisist &Persistent)
{
	m_PressType.SetValue(Persistent.PressType());		
	m_PressUnit.SetValue(Persistent.PressUnit());			
	m_FlowType.SetValue(Persistent.FlowType());			
	m_FlowUnit.SetValue(Persistent.FlowUnit());		
	m_PowerType.SetValue(Persistent.PowerType());		
	m_PowerUnit.SetValue(Persistent.PowerUnit());
	ConfigItemPerisist *pItem = Persistent.GetHead();
	if(pItem != NULL)
	{
		m_Num.SetValue(1);
		m_Name.SetValue(pItem->Name());				
		m_RPM.SetValue(pItem->RPM());					
		m_ImpellerDia.SetData(pItem->ImpellerDia());		
		m_MaxFlow.SetValue(pItem->MaxFlow());			
		m_Curve1.SetData(pItem->Curve1());	
		m_ID.SetValue(pItem->ID());				
		m_Curve2.SetData(pItem->Curve2());					
		m_Affiniity.SetValue(pItem->Affiniity());		
		m_Curve3.SetData(pItem->Curve3());								
		m_CurveEndFlow.SetData(pItem->CurveEndFlow());	
		m_BEP.SetData(pItem->BEP());
		m_RawData.Read(pItem->m_RawData);
		Jun::AddID(pItem->ID());
	}
	else
	{
		m_Num.SetValue(0);
	}
	
	return TRUE;
}

BOOL Configuration::Save(ConfigPerisist &Persistent,int num1,int num2,int num3)
{
	Persistent.PressType(m_PressType.GetValue());		
	Persistent.PressUnit(m_PressUnit.GetValue());			
	Persistent.FlowType(m_FlowType.GetValue());			
	Persistent.FlowUnit(m_FlowUnit.GetValue());		
	Persistent.PowerType(m_PowerType.GetValue());		
	Persistent.PowerUnit(m_PowerUnit.GetValue());
	int n = m_Num.GetnValue();
    if(1 == n)
	{
		ConfigItemPerisist *pItem = Persistent.CreatConfigItem();
		pItem->Name(m_Name.GetValue());				
		pItem->RPM(m_RPM.GetValue());					
		pItem->ImpellerDia(m_ImpellerDia.GetData());		
		pItem->MaxFlow(m_MaxFlow.GetValue());			
		pItem->Curve1(m_Curve1.GetData());	
		pItem->ID(m_ID.GetValue());				
		pItem->Curve2(m_Curve2.GetData());					
		pItem->Affiniity(m_Affiniity.GetValue());		
		pItem->Curve3(m_Curve3.GetData());								
		pItem->CurveEndFlow(m_CurveEndFlow.GetData());	
		pItem->BEP(m_BEP.GetData());
		m_RawData.Save(pItem->m_RawData,pItem->m_RawData.Data().GetCount());
	}
	m_Curve1.SetValue(num1,1);
	m_Curve2.SetValue(num2,1);
	m_Curve3.SetValue(num3,1);
	return TRUE;
}
	
int Configuration::Instance(NameArray &array,int nKey)
{
	m_nKey = nKey;
	ScenarioObject::InitAttr(array,nKey++,1);//m_PressType
	ScenarioObject::InitAttr(array,nKey++,1);//m_PressUnit
	ScenarioObject::InitAttr(array,nKey++,1);//m_FlowType
	ScenarioObject::InitAttr(array,nKey++,1);//m_FlowUnit
	ScenarioObject::InitAttr(array,nKey++,1);//m_PowerType
	ScenarioObject::InitAttr(array,nKey++,1);//m_PowerUnit
	ScenarioObject::InitAttr(array,nKey++,1);//m_Num
	ScenarioObject::InitAttr(array,nKey++,1);//m_Name
	ScenarioObject::InitAttr(array,nKey++,1);//m_RPM
	ScenarioObject::InitAttr(array,nKey++,2);//m_ImpellerDia
	ScenarioObject::InitAttr(array,nKey++,1);//m_MaxFlow
	ScenarioObject::InitAttr(array,nKey++,17);//m_ID
	ScenarioObject::InitAttr(array,nKey++,1);//m_MaxFlow
	ScenarioObject::InitAttr(array,nKey++,17);//m_Curve2
	ScenarioObject::InitAttr(array,nKey++,1);//m_Affiniity
	ScenarioObject::InitAttr(array,nKey++,17);//m_Curve3
	ScenarioObject::InitAttr(array,nKey++,13);//m_CurveEndFlow
	ScenarioObject::InitAttr(array,nKey++,2);//m_BEP
	ScenarioObject::InitAttr(array,nKey++,14);//m_RawData.Unit
	ScenarioObject::InitAttr(array,nKey++,34);//m_RawData.Data
	return nKey;
}



void Configuration::InitData(ScenarioObject *pObject)
{
	ASSERT(pObject != NULL);
	int nKey = m_nKey;
	pObject->GetValue(m_PressType,nKey++);
	pObject->GetValue(m_PressUnit,nKey++);
	pObject->GetValue(m_FlowType,nKey++);
	pObject->GetValue(m_FlowUnit,nKey++);
	pObject->GetValue(m_PowerType,nKey++);
	pObject->GetValue(m_PowerUnit,nKey++);
	pObject->GetValue(m_Num,nKey++);
	pObject->GetValue(m_Name,nKey++);
	pObject->GetValue(m_RPM,nKey++);
	pObject->GetValue(m_ImpellerDia,nKey++);
	pObject->GetValue(m_MaxFlow,nKey++);
	pObject->GetValue(m_Curve1,nKey++);
	pObject->GetValue(m_ID,nKey++);
	pObject->GetValue(m_Curve2,nKey++);
	pObject->GetValue(m_Affiniity,nKey++);
	pObject->GetValue(m_Curve3,nKey++);
	pObject->GetValue(m_CurveEndFlow,nKey++);
	pObject->GetValue(m_BEP,nKey++);
	pObject->GetValue(m_RawData.m_Unit,nKey++);
	pObject->GetValue(m_RawData.m_Data,nKey++);
}
BOOL Configuration::SaveData(ScenarioObject *pObject,int &num1,int &num2,int &num3)
{
	ASSERT(pObject != NULL);
	int nKey = m_nKey;
	pObject->SetValue(m_PressType,nKey++);
	pObject->SetValue(m_PressUnit,nKey++);
	pObject->SetValue(m_FlowType,nKey++);
	pObject->SetValue(m_FlowUnit,nKey++);
	pObject->SetValue(m_PowerType,nKey++);
	pObject->SetValue(m_PowerUnit,nKey++);
	pObject->SetValue(m_Num,nKey++);
	pObject->SetValue(m_Name,nKey++);
	pObject->SetValue(m_RPM,nKey++);
	pObject->SetValue(m_ImpellerDia,nKey++);
	pObject->SetValue(m_MaxFlow,nKey++);
	pObject->SetValue(m_Curve1,nKey++);
	pObject->SetValue(m_ID,nKey++);
	pObject->SetValue(m_Curve2,nKey++);
	pObject->SetValue(m_Affiniity,nKey++);
	pObject->SetValue(m_Curve3,nKey++);
	pObject->SetValue(m_CurveEndFlow,nKey++);
	pObject->SetValue(m_BEP,nKey++);
	pObject->SetValue(m_RawData.m_Unit,nKey++);
	pObject->SetValue(m_RawData.m_Data,nKey++);
	num1 = m_Curve1.GetnValue(1);
	num2 = m_Curve2.GetnValue(1);
	num3 = m_Curve3.GetnValue(1);
	return TRUE;
}



CString Configuration::CreatID()
{
	CString strId = Jun::CreatID();
	m_ID.SetValue(strId);
	return strId;
}

CString Configuration::FlowTitle()
{
	CString strName =  FlowName(m_FlowType.GetnValue());
	return GetTitle(strName,m_FlowUnit.GetValue());
}

CString Configuration::PressTitle()
{
	
	CString strName =  PressName(m_PressType.GetnValue());
	return GetTitle(strName,m_PressUnit.GetValue());
}

CString Configuration::PowerTitle()
{
	CString strName =  PowerName(m_PowerType.GetnValue());
	return GetTitle(strName,m_PowerUnit.GetValue());
}

void Configuration::GetPrame(ArrayFlyWeight<7>& curve,double dPrame[])
{
	for(int i=0;i<5;i++)
	{
		dPrame[i] = curve.GetfValue(i+2);
	}
}
