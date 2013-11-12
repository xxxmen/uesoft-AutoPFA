// MOCTriger.cpp: implementation of the MOCTriger class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MOCTriger.h"
#include "CalcTriger.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MOCTriger::MOCTriger()
{
	m_nEventType = 0;                
	m_nConditionType = 0;			 
	m_dValue = 0;				
	m_nPort1 = 0;				
	m_nComponentID1 = 0;		
	m_nPort2 = 0;					
	m_nComponentID2 = 0;			
	m_bRepeat = FALSE;
	m_bTriger = FALSE;
}

MOCTriger::~MOCTriger()
{
	
}

void MOCTriger::Repeat(BOOL bValue)
{
	m_bRepeat = bValue;
}

void MOCTriger::Read(CalcTriger &triger, TransTable &table)
{
	m_nEventType = triger.EventType();                
	m_nConditionType = triger.ConditionType();			 
	m_dValue = triger.Value();				
	m_nPort1 = triger.Port1();				
	m_nComponentID1 = triger.ComponentID1();		
	m_nPort2 = triger.Port2();					
	m_nComponentID2 = triger.ComponentID2();
	m_table.SetData(table.GetData());
}

void MOCTriger::Tran(PFUNTRAN pTran)
{
	m_table.Tran(pTran);
}

void MOCTriger::Tran(PFUNTRAN2 pTran, double d)
{
	m_table.Tran(pTran,d);
}

void MOCTriger::InitFixTrans(MOCComponentMgr &mgr,int nKey,int nEventType,int nConditionType)
{
	m_nEventType = nEventType;
	m_nConditionType = nConditionType;
	m_nComponentID1 = nKey;
}

void MOCTriger::Init(MOCComponentMgr &mgr)
{
	m_mgr.EventType(m_nEventType);
	m_mgr.ConditionType(m_nConditionType);
	m_mgr.Value(m_dValue);
	m_mgr.ComponentID1(m_nComponentID1);
	m_mgr.ComponentID2(m_nComponentID2);
	m_mgr.Port1(m_nPort1);
	m_mgr.Port2(m_nPort2);
	m_mgr.HasTranData(HasData());
	m_mgr.ModelMgr(&mgr);
}

BOOL MOCTriger::HasData()
{
	return m_table.HasData();
}

double MOCTriger::GetTransY(double dX,double dStmY)
{
	if(!HasData())
		return dStmY;
	return m_table.GetValue(dX,m_bRepeat);
}
double MOCTriger::GetTransY(double dX,double dStmY,double dStart)
{
	if(m_bTriger||m_mgr.IsTriger(dX,dStart))
	{
		m_bTriger = TRUE;
		double dTrigerTime = m_mgr.TrigerTime();
		return GetTransY(dX-dTrigerTime,dStmY);
	}
	return GetTransY(0,dStmY);//未触发使用瞬变第一数据
}

BOOL MOCTriger::IsTriger()
{
	return m_bTriger;
}

void MOCTriger::Triger(BOOL bTriger)
{
	m_bTriger = bTriger;
}

BOOL MOCTriger::TrigerStatus(double dTime,double dStart)
{
	if(m_bTriger||m_mgr.IsTriger(dTime,dStart))
	{
		m_bTriger = TRUE;
	}
	return m_bTriger;
}

double MOCTriger::GetTransY(double dX)
{
	return m_table.GetValue(dX);
}