// PumpTransient.cpp: implementation of the PumpTransient class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "autopfa.h"
#include "PumpTransient.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PumpTransient::PumpTransient()
{

}

PumpTransient::~PumpTransient()
{

}

BOOL PumpTransient::Read(TransDataPersistent &Persistent)
{
	Transient::Read(Persistent);
	m_TranModel.SetValue(Persistent.TranModel());
	m_RotateInertia.SetData(Persistent.RotateInertia());
	m_Speed.SetValue(Persistent.Speed());
	m_FourQuadrantData.SetData(Persistent.FourQuadrant());
	m_FourquadTable.Read(Persistent.m_FourquadTable);
	return TRUE;
}

BOOL PumpTransient::Save(TransDataPersistent &Persistent,int num1,int num2,int num3)
{
	Transient::Save(Persistent,num1,num2);
	Persistent.TranModel(m_TranModel.GetValue());
	Persistent.RotateInertia(m_RotateInertia.GetData());
	Persistent.Speed(m_Speed.GetValue());
	Persistent.FourQuadrant(m_FourQuadrantData.GetData());
	m_FourquadTable.Save(Persistent.m_FourquadTable,num3);
	return TRUE;
}

void PumpTransient::Instance(NameArray &array,int nKey)
{
	nKey = Transient::Instance(array,nKey);
	ScenarioObject::InitAttr(array,nKey++,1);//m_TranModel
	ScenarioObject::InitAttr(array,IDS_STRROTATEINERIA,nKey++,2);//m_RotateInertia
	ScenarioObject::InitAttr(array,IDS_STRINITSPEED,nKey++,1);//m_Speed
	ScenarioObject::InitAttr(array,nKey++,13);//m_FourQuadrantData
	ScenarioObject::InitAttr(array,nKey++,13);//m_FourquadTable.Unit
	ScenarioObject::InitAttr(array,nKey++,33);//m_FourquadTable.Data
}

void PumpTransient::InitData(ScenarioObject *pObject)
{
	ASSERT(pObject != NULL);
	int nKey = m_nKey;
	Transient::InitData(pObject,nKey);
	pObject->GetValue(m_TranModel,nKey++);
	pObject->GetValue(m_RotateInertia,nKey++);
	pObject->GetValue(m_Speed,nKey++);
	pObject->GetValue(m_FourQuadrantData,nKey++);
	pObject->GetValue(m_FourquadTable.m_Unit,nKey++);
	pObject->GetValue(m_FourquadTable.m_Data,nKey++);
}
BOOL PumpTransient::SaveData(ScenarioObject *pObject,int &num1,int &num2,int &num3)
{
	ASSERT(pObject != NULL);
	int nKey = m_nKey;
	Transient::SaveData(pObject,num1,num2,nKey);
	pObject->SetValue(m_TranModel,nKey++);
	pObject->SetValue(m_RotateInertia,nKey++);
	pObject->SetValue(m_Speed,nKey++);
	pObject->SetValue(m_FourQuadrantData,nKey++);
	pObject->SetValue(m_FourquadTable.m_Unit,nKey++);
	pObject->SetValue(m_FourquadTable.m_Data,nKey++);
	num3 = m_FourquadTable.Data().GetCount();
	return TRUE;
}