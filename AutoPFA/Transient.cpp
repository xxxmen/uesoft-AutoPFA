// Transient.cpp: implementation of the Transient class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "Transient.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

Transient::Transient()
{
	m_nKey = 50;
}

Transient::~Transient()
{

}

BOOL Transient::Read(TransDataPersistent &Persistent)
{
	m_ValueType.SetValue(Persistent.ValueType());
	m_Special.SetValue(Persistent.Special());
	m_Repeat1.SetValue(Persistent.Repeat1());
	m_Repeat2.SetValue(Persistent.Repeat2());
	m_TranType.SetValue(Persistent.TranType());
	m_Periodic.SetData(Persistent.Periodic());
	m_TranTriger1.SetData(Persistent.TranTriger1());
	m_TranTriger2.SetData(Persistent.TranTriger2());
	m_Trans1Table.Read(Persistent.m_Trans1Table);
	m_Trans2Table.Read(Persistent.m_Trans2Table);
	return TRUE;
}

BOOL Transient::Save(TransDataPersistent &Persistent,int num1,int num2)
{
	Persistent.ValueType(m_ValueType.GetValue());
	Persistent.Special(m_Special.GetValue());
	Persistent.Repeat1(m_Repeat1.GetValue());
	Persistent.Repeat2(m_Repeat2.GetValue());
	Persistent.TranType(m_TranType.GetValue());
	Persistent.Periodic(m_Periodic.GetData());
	Persistent.TranTriger1(m_TranTriger1.GetData());
	Persistent.TranTriger2(m_TranTriger2.GetData());
	m_Trans1Table.Save(Persistent.m_Trans1Table,num1);
	m_Trans2Table.Save(Persistent.m_Trans2Table,num2);
	return TRUE;
}

int Transient::Instance(NameArray &array,int nKey)
{
	m_nKey = nKey;
	ScenarioObject::InitAttr(array,IDS_STRTRANVALUETYPE,nKey++,1);//ValueType
	ScenarioObject::InitAttr(array,IDS_STRTRAN_SPECIAL,nKey++,1);//Special
	ScenarioObject::InitAttr(array,IDS_STRTRAN_REPEAT1,nKey++,1);//Repeat1
	ScenarioObject::InitAttr(array,IDS_STRTRAN_REPEAT2,nKey++,1);//Repeat2
	ScenarioObject::InitAttr(array,IDS_STRTRAN_TRTYPE,nKey++,1);//TranType
	ScenarioObject::InitAttr(array,IDS_STRTRAN_PERIODIC,nKey++,15);//Periodic
	ScenarioObject::InitAttr(array,IDS_STRFRISTEVENT,nKey++,18);//TranTriger1
	ScenarioObject::InitAttr(array,IDS_STRSECONDEVENT,nKey++,18);//TranTriger2
	ScenarioObject::InitAttr(array,nKey++,12);//m_Trans1Table.Unit
	ScenarioObject::InitAttr(array,nKey++,32);//m_Trans1Table.Data
	ScenarioObject::InitAttr(array,nKey++,12);//m_Trans2Table.Unit
	ScenarioObject::InitAttr(array,nKey++,32);//m_Trans2Table.Data
	return nKey;
}

void Transient::InitData(ScenarioObject *pObject,int &nKey)
{
	ASSERT(pObject != NULL);
	pObject->GetValue(m_ValueType,nKey++);
	pObject->GetValue(m_Special,nKey++);
	pObject->GetValue(m_Repeat1,nKey++);
	pObject->GetValue(m_Repeat2,nKey++);
	pObject->GetValue(m_TranType,nKey++);
	pObject->GetValue(m_Periodic,nKey++);
	pObject->GetValue(m_TranTriger1,nKey++);
	pObject->GetValue(m_TranTriger2,nKey++);
	pObject->GetValue(m_Trans1Table.m_Unit,nKey++);
	pObject->GetValue(m_Trans1Table.m_Data,nKey++);
	pObject->GetValue(m_Trans2Table.m_Unit,nKey++);
	pObject->GetValue(m_Trans2Table.m_Data,nKey++);
}
BOOL Transient::SaveData(ScenarioObject *pObject,int &num1,int &num2,int &nKey)
{
	ASSERT(pObject != NULL);
	pObject->SetValue(m_ValueType,nKey++);
	pObject->SetValue(m_Special,nKey++);
	pObject->SetValue(m_Repeat1,nKey++);
	pObject->SetValue(m_Repeat2,nKey++);
	pObject->SetValue(m_TranType,nKey++);
	pObject->SetValue(m_Periodic,nKey++);
	pObject->SetValue(m_TranTriger1,nKey++);
	pObject->SetValue(m_TranTriger2,nKey++);
	pObject->SetValue(m_Trans1Table.m_Unit,nKey++);
	pObject->SetValue(m_Trans1Table.m_Data,nKey++);
	pObject->SetValue(m_Trans2Table.m_Unit,nKey++);
	pObject->SetValue(m_Trans2Table.m_Data,nKey++);
	num1 = m_Trans1Table.m_Data.GetCount();
	num2 = m_Trans2Table.m_Data.GetCount();
	return TRUE;
}

void Transient::InitData(ScenarioObject *pObject)
{
	ASSERT(pObject != NULL);
	int nKey = m_nKey;
	InitData(pObject,nKey);
	
}
BOOL Transient::SaveData(ScenarioObject *pObject,int &num1,int &num2)
{
	ASSERT(pObject != NULL);
	int nKey = m_nKey;
	SaveData(pObject,num1,num2,nKey);
	return TRUE;
}